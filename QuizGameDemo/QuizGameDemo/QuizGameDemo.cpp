#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h> 


using namespace std;

//The player's struct:
/*
struct question {
	string author;
	string question;
	string falseAns1;
	string falseAns2;
	string falseAns3;
	string trueAns;

};
*/

struct player {
	string firstName;
	string lastName;
	string username;
	long password;
	int socre=0;
	//question listOfQuestions[10];
	int availableQuestions=0;
};


/*Decalring functions : */

//Shows the user "all" his personal information:
void profileData(player &user);

//Main function of profile modification:
void mainProfile(player &user);

//The modification function:
void modifyProfile(player& user);
//you can change your password if you forgot
void forgot();

//void createQuiz(string username, question questions[], int numOfQuestionsAvailable);



//Local database:
player listOfPlayers[10] = {};
enum dashBoradOptions {profile,run,create,logout};
string row = "-------------------------------------------------------------------------\n";
int userchecksu(string user, player data[]) {//the "su" in the end of the name means that is a function for "signup" system.
	for (size_t i = 0; i < 10; i++)
	{
		if (user == data[i].username)
		{
			return 10;
		}
	}
	
}
//check if the user is already in the system
int userCheck(string user, player data[]) {
	for (size_t i = 0; i < 10; i++)
	{
		if (user == data[i].username)
		{
			return i;
		}
	}
	return 10;
}
//check if the password is correct
int passwordCheck(int password, player data[], int index) {
	if (password == data[index].password)
	{
		return 1;
	}
	return 10;
}

enum firstAsteps
{
	login,
	signup,
	changePassword,
	quit,
};
//-------------------public variables------------------//
int numOfPlayers = 0;
//-----------------------------------------------------//

int main() {
	system("Color 0E");//change the color of the texet/background 
	//-------------------local variables-------------------//
	int playersIndexPosition = 0,choice;
	bool isPlaying;
	string username;
	long password;
	bool loginend = true;
	int checkvar;//variable to use if we need to check things 
	//-----------------------------------------------------//

	
	/* Main game loop: */
	do {

		cout << "Hi, and welcome to trevia world (:" << endl;
		
		cout << "_________________________________________________________________________\n\n";
		cout << "                        welcome to the trevia world                               \n\n";
		
		
		isPlaying = true;
		loginend = true;

		while (loginend)
		{
												/* Main Window */
			
			cout << "___________________________________Menu__________________________________\n\n";
			cout << "\t\t|          press 0 to login.               |" << endl;
			cout << "\t\t|          prees 1 to signup.              |" << endl;
			cout << "\t\t|          prees 2 to change password.     |" << endl;
			cout << "\t\t|          prees 3 to exit.               |\n" << endl;

			cout << "please enter your choice:\n";
			cin >> choice;
			
			//Checks if the number is valid:
			while (choice < 0 || choice>3)
			{
				cout << "please select from the options given above\n";
				cin >> choice;
			}
			
			//Optional usage: 
			switch (choice)
			{

			case login:
				system("cls");
				cout << "Enter your username:" << endl;
				cin >> username;
				
				playersIndexPosition = userCheck(username, listOfPlayers);
				checkvar = userCheck(username, listOfPlayers);
				
				while (checkvar== 10)
				{
					cout << "cant found your username please try again" << endl;
					cin >> username;
					playersIndexPosition = userCheck(username, listOfPlayers);
					checkvar = userCheck(username, listOfPlayers);
				}
				
				cout << "Hi " << listOfPlayers[playersIndexPosition].username << " please enter your password:" << endl;
				cin >> password;
				checkvar = passwordCheck(password, listOfPlayers, playersIndexPosition);
				
				while (checkvar == 10)
				{
					cout << "the password not match the username please try again" << endl;
					cin >> password;
					checkvar = passwordCheck(password, listOfPlayers, playersIndexPosition);
				}
				loginend = false;
				break;

			case signup:
				
				system("cls");
				cout << "please enter your first name:" << endl;
				cin >> listOfPlayers[numOfPlayers].firstName;
				
				system("cls");
				cout << "please enter your last name:" << endl;
				cin >> listOfPlayers[numOfPlayers].lastName;
				
				system("cls");
				cout << "please enter username:" << endl;
				cin >> username;
				checkvar = userchecksu(username, listOfPlayers);
				
				system("cls");
				
				while (checkvar == 10)
				{
					cout << "This username is used by other player pls try diffrent user name" << endl;
					cin >> username;
					checkvar = userchecksu(username, listOfPlayers);
					system("cls");
				}
				listOfPlayers[numOfPlayers].username = username;
				cout << "please enter a strong password:" << endl;
				cout << "0-8 letters, no capital letters/numbers" << endl;
				cin >> listOfPlayers[numOfPlayers].password;
				numOfPlayers++;
				system("cls");
				break;

			case changePassword:
				forgot();
				break;

			case quit:
				system("cls");
				cout << "\t\t\t  have a nice day :)" << endl;
				return 0;
			
			default:
				break;
			}
		}
		
		
												/*Player's dashboard:*/

		//Welcome message:
		player* currentPlayer = &listOfPlayers[playersIndexPosition];
		system("cls");
		cout << row;
		cout << "Hello " << (*(currentPlayer)).firstName << "" << endl;
		cout << "Your current score: " << (*(currentPlayer)).socre << "." << endl;
		
		
		//Main gateway:
		do {
			//Player's options:
			cout << row;
			cout << "|Press 0 to see and modify your personal information.                   |" << endl;
			cout << "|Press 1 to run a quiz.                                                 |" << endl;
			cout << "|Press 2 to creare a quiz.                                              |" << endl;
			cout << "|Press 3 to logout.                                                     |" << endl;
			cout << row;
			
			cout << ">>>";
			cin >> choice;

			switch (choice) {
			case profile:
				
				mainProfile((*(currentPlayer)));
				break;
			case run:
				break;
			case create:
				//createQuiz(currentPlayer.username, currentPlayer.listOfQuestions, currentPlayer.availableQuestions);
				break;
			case logout:
				break;
			default:
				cout << "Please choose a number between 0 to 3" << endl;
				break;
			}

		} while (choice != logout);
		cout << "Have a nice day " << (*(currentPlayer)).firstName << "." << endl;

	} while (isPlaying);


	return 0;
}
void forgot() {
	char choiceC;//the capital 'c' in the end mean that is a char variable
	int choice1;
	int indexPos;
	int check1;
	string username1;
	system("cls");
	cout << "\t\t\tForget your password ? no problem :)\n";
	cout << "\t\t\tPress 1 to search your id by username" << endl;
	cout << "\t\t\tPress 2 to go back to tha main menu" << endl;
	cout << "Enter your choice:" ;
	cin >> choice1;
	cout << row << endl;
	system("cls");
	switch (choice1)
	{
	case 1:
		cout << "enter your username:" << endl;
		cin >> username1;
		system("cls");
		check1 = userCheck(username1, listOfPlayers);
		indexPos = userCheck(username1, listOfPlayers);
		if (check1==10)
		{
			cout << "cant find your username :(";
			system("cls");
			main();
		}
		else
		{
			cout << "your account is found!" << endl;
			cout << "your password is: " << listOfPlayers[indexPos].password << endl;
			
			
			
			do
			{
				
				cout << "do you wont to change it or keep it like that ? (y/n) " << endl;
				cin >> choiceC;
				system("cls");
				switch (choiceC)
				{
				case 'y':
					cout << "pls choose a new password:";
					cin >> listOfPlayers[indexPos].password;
					system("cls");
					cout << "\nYour password has been successfully changed.\n";
					main();
					break;
				case 'n':
					cout << "You'll return to the dashboard with no time.";
					main();
					break;
				default:
					cout << "Please choose y or n." << endl;
					
					break;
				}
				system("cls");
			} while (choiceC != 'n');
			
		}
		break;
	case 2:
		system("cls");
		main();
	default:
		break;
	}
}

//Main function of profile modification:
void mainProfile(player& user) {
	char choice;
	system("cls");
	cout << "Loading info ..." << endl;
	profileData(user);

	//User's choice handler:
	do {
		cout << "Would you like to change and modify any of your personl information? (y/n)\n>>>";
		cin >> choice;
		
		switch (choice) {
		
		case 'y':
			cout << "Right a way ..." << endl;
			modifyProfile(user);
			profileData(user);
			break;
		
		case 'n':
			cout << "You'll return to the dashboard with no time." << endl;
			break;
		
		default:
			cout << "Please choose y or n." << endl;
			break;
		}
	} while (choice != 'n');
	cout << "Returning to the dashboard ... " << endl;
}

//Shows the user "all" his personal information:
void profileData(player& user) {
	//User's profile
	cout << row;
	cout << "This is " << user.firstName << "'s profile." << endl;
	cout << "Full name: " << user.firstName<< " " << user.lastName << '.' << endl;
	cout << "Username: " << user.username << "." << endl;
	cout << "Total score: " << user.socre << '.' << endl;
	cout << row;
}

//The modification function:
void modifyProfile(player& user) {
	/* TODO: add a enum dictionary for the user's options.*/
	enum OPTIONS {Firstname,Lastname,Password,Username,Exit};
	int choice, newPassword;
	string newUsername;
	do {
		//Showing instructions:
		cout << row;
		cout << "Press 0 to change your first name." << endl;
		cout << "Press 1 to change your last name." << endl;
		cout << "Press 2 to change your password." << endl;
		cout << "Press 3 to change your username." << endl;
		cout << "Press 4 to exit the editing mode." << endl;
		cout << row;


		//The gateway to the profile database:
		cout << ">>>";
		cin >> choice;

		switch (choice) {
		case Firstname:
			cout << "Enter your new first name: ";
			cin >> user.firstName;
			break;
		case Lastname:
			cout << "Enter your new last name: ";
			cin >> user.lastName;
			break;
		case Password:
			cout << "Enter your new password: ";
			cin >> newPassword;
			/* Check if the password is valid. */
			user.password = newPassword;
			break;
		case Username:
			cout << "Enter your new username: ";
			cin >> newUsername;
			/* Check if the username is valid. */
			user.username = newUsername;
			break;

		case Exit:
			cout << "Saving changes ... " << endl;
			break;

		default:
			cout << "Please choose a number between 0 to 3." << endl;
			break;
		}
	} while (choice != 4);


}

/*
void createQuiz(string username,question questions[],int numOfQuestionsAvailable) {
	int numOfQuestions;
	
	//Getting number of questions:
	do {
		cout << "How many questions would you like to create?" << endl;
		cout << ">>>";
		cin >> numOfQuestions;

		//Can't have more then 10 questions on his account:
		if (numOfQuestions + numOfQuestionsAvailable > 10)
			cout << "Sorry but you can't add more then " << 10 - numOfQuestionsAvailable <<" Questions to your profile. Please try again." << endl;

	} while (numOfQuestions + numOfQuestionsAvailable > 10);
	
	//Setting up the questions:
	for (int i = 0; i < numOfQuestions; i++) {
		//Setting an easier variable:
		question currentQuestion = questions[numOfQuestionsAvailable + i];
		
		//Getting info:
		currentQuestion.author = username;
		
		//Adding the question title:
		cout << "Enter your questions:" << endl;
		cout << ">>>";
		cin >> currentQuestion.question;

		//Adding the false answers:
		cout << "Enter the first false answer for that question:" << endl;
		cout << ">>>";
		cin >> currentQuestion.falseAns1;

		cout << "Enter the second false answer for that question:" << endl;
		cout << ">>>";
		cin >> currentQuestion.falseAns2;

		cout << "Enter the third false answer for that question:" << endl;
		cout << ">>>";
		cin >> currentQuestion.falseAns3;

		//Adding the true answer.
		cout << "Enter the correct answer for that question:" << endl;
		cout << ">>>";
		cin >> currentQuestion.trueAns;

		cout << "Adding question to the system ..." << endl;
	}
}

*/