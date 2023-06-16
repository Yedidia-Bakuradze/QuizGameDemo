#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h> 
using namespace std;



//The quiz's components:
struct question {
	string author;
	string question;
	string falseAns1;
	string falseAns2;
	string falseAns3;
	string trueAns;

};

//The user's components:
struct player {
	string firstName;
	string lastName;
	string username;
	long password;
	int socre=0;
	question listOfQuestions[10];
	int availableQuestions=0;
};


/*Decalring functions : */

//Shows the user "all" his personal information:
void profileData(player &user);

//Main function of profile modification:
void mainProfile(player &user);

//The modification function:
void modifyProfile(player& user);

//Check if the user is already in the system
int userCheck(string user, player data[]) {
	for (int i = 0; i < 10; i++)
	{
		if (user == data[i].username)
		{
			return i;
		}
	}
	return 10;
}

//Global database:
player listOfPlayers[10] = {};

//Password checker:
void passwordRecovery() {
	char choiceC;
	int choice1,indexPos,check1;
	string username1;
	system("cls");
	
	cout << "Please enter your username:" << endl;
	cin >> username1;
	system("cls");
	check1 =  userCheck(username1, listOfPlayers);
	indexPos = check1;
	
	//Checks if the username is in out system:
	if (check1==10)
	{
		cout << "Sorry but the user that you are looking for - doesn't exists." << endl;
		system("cls");
		return;
	}
	//If the user exists:
	else
	{
		cout << "Your account had been found." << endl;
		cout << "Your password is: " << listOfPlayers[indexPos].password << endl;

		
		//Change the password:
		do {
			system("cls");
			cout << "do you wont to change it or keep it like that ? (y/n) >>>";
			cin >> choiceC;
			system("cls");
			
			switch (choiceC)
			{
			case 'y':
				cout << "Please choose a new password:";
				cin >> listOfPlayers[indexPos].password;
				system("cls");
				cout << "\nYour password has been successfully changed.\n";
				break;
			case 'n':
				cout << "Returning to the main window ...";
				break;
			default:
				cout << "Please choose either 'y' or 'n'." << endl;
				break;
			}

		} while (choiceC != 'n' && choiceC != 'y');
		system("cls");
		
	}
	
}

//Create a quiz:
void quizCreate(player& user);



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

//Check if the password is correct
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

	//Text color: 
	system("Color 0E");
	
	//-------------------local variables-------------------//
	int playersIndexPosition = 0,choice;
	bool isPlaying;
	string username;
	long password;
	bool userOnline = false;
	int checkvar;//variable to use if we need to check things 
	//-----------------------------------------------------//

	
	/* Main game loop: */
	do {

		cout << "Hi, and welcome to trevia world (:" << endl;
		
		cout << "_________________________________________________________________________\n\n";
		cout << "                        welcome to the trevia world                               \n\n";
		
		
		isPlaying = true;
		userOnline = false;

		//Main frame loop: (Login/Signup/Password reset/Exit).
		while (!userOnline)
		{
												/* Main Window */
			
			cout << "___________________________________Menu__________________________________\n\n";
			cout << "\t\t|          press 0 to login.               |" << endl;
			cout << "\t\t|          prees 1 to signup.              |" << endl;
			cout << "\t\t|          prees 2 to change password.     |" << endl;
			cout << "\t\t|          prees 3 to exit.               |\n" << endl;

			cout << "please enter your choice:\n";
			cin >> choice;
			
			//Checks if the choice is valid:
			while (choice < 0 || choice>3)
			{
				cout << "please select from the options given above\n";
				cin >> choice;
			}
			
			switch (choice){

			case login:
				system("cls");
				cout << "Enter your username:" << endl;
				cin >> username;
				
				playersIndexPosition = userCheck(username, listOfPlayers);
				checkvar = playersIndexPosition;
				
				while (checkvar== 10)
				{
					cout << "cant found your username please try again" << endl;
					cin >> username;
					playersIndexPosition = userCheck(username, listOfPlayers);
					checkvar = playersIndexPosition;
				}
				
				//If the password fits the user.password component's value:
				cout << "Hi, " << listOfPlayers[playersIndexPosition].username << " Please enter your password:" << endl;
				do {
					cin >> password;
					checkvar = passwordCheck(password, listOfPlayers, playersIndexPosition);
					if(checkvar == 10)
						cout << "the password not match the username please try again" << endl;
				} while (checkvar == 10);
				
				//User is logged in:
				userOnline = true;
				break;

			case signup:
				
				//Getting user's first name:
				system("cls");
				cout << "please enter your first name:" << endl;
				cin >> listOfPlayers[numOfPlayers].firstName;
				
				//Getting user's last name:
				system("cls");
				cout << "please enter your last name:" << endl;
				cin >> listOfPlayers[numOfPlayers].lastName;
				
				//Getting user's username:
				system("cls");
				cout << "please enter username:" << endl;
				cin >> username;

				//Checking if the username exists:
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
				
				//Getting user's password:
				cout << "please enter a strong password:" << endl;
				cout << "0-8 letters, no capital letters/numbers" << endl;
				cin >> listOfPlayers[numOfPlayers].password;
				
				//Adding another player to our database:
				numOfPlayers++;
				system("cls");
				
				break;

			case changePassword:
				passwordRecovery();
				break;

			case quit:
				system("cls");
				cout << "\t\t\t Thank you for your time. Have a nice day :)" << endl;
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
				quizCreate((*(currentPlayer)));
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

//Quiz create function:
void quizCreate(player& user) {

	int numOfQuestions;
	string header;
	cout << "How many questions would you like to add?" << endl;
	do {

		cout << ">>>";
		cin >> numOfQuestions;
		if (10 - (user.availableQuestions + numOfQuestions) < 0)
			cout << "Sorry but you can't add more then " << 10 - user.availableQuestions << " questions." << endl;

	} while (10 - (user.availableQuestions + numOfQuestions) < 0);
	
	for (int i = 0; i < numOfQuestions; i++) {
		cout << "Initionlizing question number " << i + 1 << "/"<<numOfQuestions<<"." << endl;
		user.listOfQuestions[user.availableQuestions +i].author = user.username;
		
		//Filling the question's field:
		cout << "Please enter the question: (Max 49 letters)" << endl;
		cin >> header;
		user.listOfQuestions[user.availableQuestions + i].question = header;
		
		//Filling the question's field:
		cout << "Please enter the first false answer for that question:" << endl;
		cin >> user.listOfQuestions[user.availableQuestions + i].falseAns1;
		
		//Filling the question's field:
		cout << "Please enter the second false answer for that question:" << endl;
		cin >> user.listOfQuestions[user.availableQuestions + i].falseAns2;
		
		//Filling the question's field:
		cout << "Please enter the third false answer for that question:" << endl;
		cin >> user.listOfQuestions[user.availableQuestions + i].falseAns3;

		//Filling the only true answer:
		cout << "Please enter the true answer for that question:" << endl;
		cin >> user.listOfQuestions[user.availableQuestions + i].trueAns;

		cout << "Saving the question" << endl;
	}
}
