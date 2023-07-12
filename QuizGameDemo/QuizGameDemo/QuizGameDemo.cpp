#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h> 
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
using namespace std;

//The quiz's components:
struct question {
	string author;
	char question[100];
	char** answers = new char*[4];

};

//The user's components:
struct player {
	string firstName;
	string lastName;
	string username;
	char safetyQuestion[100];
	char safetyAnswer[100];
	long password;
	int socre=0;
	question listOfQuestions[10];
	int availableQuestions=0;
};

//Global database:
player listOfPlayers[10] = {};

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

//Quiz play system:
void quizPlay(player& user);

//Password checker:
void passwordRecovery() {
	char choiceC;

	int choice1 = 0, indexPos, check1;



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

//The main heart of the play system:
void quizActive(player& user, int adminIndexPosition);

//Checks if the given index position is already been choosed:
bool indexChecker(int* indexes, int index, int size);

string row = "-------------------------------------------------------------------------\n";

//Little easter egg:
void printChabad() {
	cout << row;
	for (int i = 0; i < 770; i+=18) {
		cout << "Chabad all the way down" << endl;
	}
	cout << row;
	Sleep(300);
	system("cls");
}

//The "su" in the end of the name means that is a function for "signup" system.
int userchecksu(string user, player data[]) {
	for (int i = 0; i < 10; i++)
	{
		if (user == data[i].username)
		{
			return 10;
		}
	}
	return NULL;
	
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
	char saftyAnswer[100];
	int checkvar;//variable to use if we need to check things 
	//-----------------------------------------------------//

	/* Main game loop: */
	do {


		
		cout << "_________________________________________________________________________\n\n";
		cout << "                     Hi, and welcome to trevia world (:                    \n\n";
		
		
		isPlaying = true;
		userOnline = false;
		Sleep(300);
		system("cls");
		//Main frame loop: (Login/Signup/Password reset/Exit).
		while (!userOnline)
		{
												/* Main Window */
			
			cout << "___________________________________Menu__________________________________\n\n";
			cout << "\t\t|          press 0 to login.               |" << endl;
			cout << "\t\t|          prees 1 to signup.              |" << endl;
			cout << "\t\t|          prees 2 to exit.                |\n" << endl;
			Sleep(4);
			cout << "please enter your choice:\n";
			cout << ">>> ";
			cin >> choice;
			
			//Checks if the choice is valid:
			while (choice < 0 && choice != 770 || choice>3 && choice != 770 )
			{
				cout << "please select from the options given above\n";
				cout << ">>> ";
				cin >> choice;
			}
			
			switch (choice){

			case login:
				system("cls");
				cout << "Enter your username:" << endl;
				cout << ">>> ";
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
				cin >> password;
				checkvar = passwordCheck(password, listOfPlayers, playersIndexPosition);
				if (checkvar == 10) {
					cout << "The password not match.\nPress 1 to try again:\nPress 2 to change your password:\nPress 3 to back to the main menu" << endl;
					cout << ">>> ";
					cin >> choice;
					system("cls");
					switch (choice)
					{
					case 1:
						do {
							cout << "Enter your password:\n";
							cin >> password;
							checkvar = passwordCheck(password, listOfPlayers, playersIndexPosition);
							if (checkvar == 10)
								cout << "The password doesn't match pls try again:\n";
	
						} while (checkvar == 10);
						system("cls");
						break;
					case 2:
						cout << "In order to continue please answer the following safety question:" << endl;
						cout << listOfPlayers[playersIndexPosition].safetyQuestion << endl;
						cout << ">>> ";
						cin.ignore();
						cin.getline(saftyAnswer, 99);
						if (!stricmp(saftyAnswer, listOfPlayers[playersIndexPosition].safetyAnswer))
							passwordRecovery();
						else
							cout << "Sorry but the answer isn't right." << endl;
						break;
	
					
					default:
						break;
					}
				}
				//User is logged in:
				userOnline = (checkvar != 10) ?true:false;
				system("cls");
				
				break;

			case 770:
				printChabad();
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
				cout << "0-8 digits, only numbers." << endl;
				cin >> listOfPlayers[numOfPlayers].password;
				
				//Adding safety question:
				cout << "Please add a safety question to your account in order to get access to your account once you forget your password." << endl;
				cout << ">>> ";
				cin.ignore();
				cin.getline(listOfPlayers[numOfPlayers].safetyQuestion,99);
				
				//Adding safety question:
				cout << "Please enter the answer for that question:" << endl;
				cout << ">>> ";
				cin.getline(listOfPlayers[numOfPlayers].safetyAnswer, 99);

				cout << "Account created succefully." << endl;
				//Adding another player to our database:
				numOfPlayers++;
				system("cls");
				
				break;

			case quit:
				system("cls");
				cout << "\t\t\t Thank you for your time. Have a nice day :)" << endl;
				return 0;
			
			default:
				break;
			}
		}
		
		Sleep(300);
												/*Player's dashboard:*/

		//Welcome message:
		player* currentPlayer = &listOfPlayers[playersIndexPosition];
		system("cls");
		cout << row;
		cout << "Hello " << (*(currentPlayer)).firstName << "" << endl;
		cout << "Your current score: " << (*(currentPlayer)).socre << "." << endl;
		
		enum OPTIONS {profile,run,create,logout};
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
			
			system("cls");
			switch (choice) {
			
			//Profile modification:
			case profile:
				Sleep(300);
				mainProfile((*(currentPlayer)));
				system("cls");
				break;
			//Playing the quiz:
			case run:
				Sleep(300);
				quizPlay((*(currentPlayer)));
				system("cls");
				break;
			//Creating a quiz:
			case create:
				Sleep(300);
				quizCreate((*(currentPlayer)));
				system("cls");
				break;
			//Logging out:
			case logout:
				Sleep(300);
				system("cls");
				break;
			//None of the above:21+0-=00
			default:
				cout << "Please choose a number between 0 to 3" << endl;
				system("cls");
				break;
			}

		} while (choice != logout);
		cout << "Have a nice day " << (*(currentPlayer)).firstName << "." << endl;
		Sleep(300);
	} while (isPlaying);

	
	return 0;
}

//Main function of profile modification:
void mainProfile(player& user) {
	char choice;
	system("cls");
	cout << "Loading info ..." << endl;
	Sleep(300);
	profileData(user);

	//User's choice handler:
	do {
		cout << "Would you like to change and modify any of your personl information? (y/n)\n>>>";
		cin >> choice;
		
		switch (choice) {
		
		case 'y':
			cout << "Right a way ..." << endl;
			modifyProfile(user);
			system("cls");
			profileData(user);
			system("cls");
			break;
		
		case 'n':
			cout << "You'll return to the dashboard with no time." << endl;
			system("cls");
			break;
		
		default:
			cout << "Please choose y or n." << endl;
			system("cls");
			break;
		}
	} while (choice != 'n');
	cout << "Returning to the dashboard ... " << endl;
	system("cls");
}

//Shows the user "all" his personal information:
void profileData(player& user) {
	system("cls");
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
		cout << ">>> ";
		cin >> choice;
		system("cls");

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
			
			//Check if the username is valid.
			while (userchecksu(newUsername, listOfPlayers) == 10) {
				system("cls");
				cout << "Sorry but the username: " << newUsername << " already exsists. Please try different username." << endl;
				cout << ">>> ";
				cin >> newUsername;
			}
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

	cout << "How many questions would you like to add?" << endl;
	
	//Getting the question's amount:
	do {

		cout << ">>>";
		cin >> numOfQuestions;
		if (10 - (user.availableQuestions + numOfQuestions) < 0)
			cout << "Sorry but you can't add more then " << 10 - user.availableQuestions << " questions." << endl;

	} while (10 - (user.availableQuestions + numOfQuestions) < 0);
	
	
	//Setting the questions:
	for (int i = 0,k=0; i < numOfQuestions; i++,k=0) {
		question* currentQuestion = &user.listOfQuestions[user.availableQuestions + i];
		
		//Initionlizing the answer's strings variables in the array:
		for (int i = 0; i < 4; i++) {
			(*(currentQuestion)).answers[i] = new char[100];
		}

		//Writing the author's username as a refrence to that question:
		cout << "Initionlizing question number " << i + 1 << "/"<<numOfQuestions<<"." << endl;
		(*(currentQuestion)).author = user.username;
		
		//Filling the question's field:
		cout << "Please enter the question: (Max 49 letters)" << endl;
		cout << ">>>";
		cin.ignore();
		cin.getline((*(currentQuestion)).question, 99);
		
		//Filling the question's field:
		cout << "Please enter the first false answer for that question:" << endl;
		cout << ">>>";
		cin.getline((*(currentQuestion)).answers[k++], 99);
		
		//Filling the question's field:
		cout << "Please enter the second false answer for that question:" << endl;
		cout << ">>>";
		cin.getline((*(currentQuestion)).answers[k++], 99);
		
		//Filling the question's field:
		cout << "Please enter the third false answer for that question:" << endl;
		cout << ">>>";
		cin.getline((*(currentQuestion)).answers[k++], 99);

		//Filling the only true answer:
		cout << "Please enter the true answer for that question:" << endl;
		cout << ">>>";
		cin.getline((*(currentQuestion)).answers[k], 99);

		//Finishing:
		cout << "Saving the question ..." << endl;
		Sleep(300);
	}
	
	user.availableQuestions += numOfQuestions;
}

void quizPlay(player& user) {
	srand((unsigned int)time(NULL));
	enum quizPlayOptions {byRandom,byUser,exit};
	bool playing = true,invalidChoice =false;
	int choice,sourcePlayerIndexPosition;
	int quizSize = 0;
	int* indexes;

	//Getting user's choice:
	do {
		system("cls");
		//Instructions to the user:
		cout << "How would you like to choose your quiz?" << endl;
		cout << "Press 0 if you want to get a random quiz." << endl;
		cout << "Press 1 if you want to choose a specific user's quiz." << endl;
		cout << "Press 2 if you want to get back to the dashboard." << endl;
		cout << ">>>";
		cin >> choice;

		system("cls");
		invalidChoice = false;
		switch (choice) {
		case byRandom:
			
			//Getting random index position:
			for (sourcePlayerIndexPosition = rand() % numOfPlayers; listOfPlayers[sourcePlayerIndexPosition].username == user.username && listOfPlayers[sourcePlayerIndexPosition].availableQuestions <= 0; sourcePlayerIndexPosition = rand() % numOfPlayers);
			
			//Calling quiz fucntion:
			quizActive(user,sourcePlayerIndexPosition);
			break;
		case byUser:

			//Show list of users that have quizes available:
			indexes = new int[numOfPlayers];
			for (int i = 0; i < numOfPlayers; i++) {
				if (listOfPlayers[i].availableQuestions > 0 && listOfPlayers[i].username != user.username) {
					cout << "Player number " << i << " - " << listOfPlayers[i].username << " | " << listOfPlayers[i].availableQuestions << " questions available." << endl;
					indexes[quizSize++] = i;
				}
			}

			//Choice check:
			bool isValid;
			do {
				//User's choice:
				cout << "Please enter the player number that you want him to be your quiz source:" << endl;
				cout << ">>> ";
				cin >> sourcePlayerIndexPosition;
				isValid = indexChecker(indexes, sourcePlayerIndexPosition, quizSize);
				if (!isValid)
					cout << "Sorry but this user doesn't exists." << endl;
			} while (!isValid);
			
			//Deleting temp array:
			delete[] indexes;

			//Calling quiz fucntion:
			quizActive(user, sourcePlayerIndexPosition);
			break;
		case exit:
			break;
		default:
			cout << "Please choose either 0 or 1." << endl;
			invalidChoice = true;
				
		}
		Sleep(300);
	} while (invalidChoice);



}

//The main heart of the play system:
void quizActive(player& user, int adminIndexPosition) {
	srand((unsigned int)time(NULL));
	const int numOfAnswers = 4;
	int indexes[numOfAnswers]{}, randomIndex, choice;

	//The source player:
	player* adminPlayer = &listOfPlayers[adminIndexPosition];
	
	cout << "This quiz is made by " << (*(adminPlayer)).username << ". Enjoy." << endl;
	//The question generator:
	for (int rounds = 0; rounds < (*(adminPlayer)).availableQuestions; rounds++) {
		//Setting the temp array for the answers:
		char** answers = new char* [numOfAnswers];
		
		//Initionlizing the array:
		for (int i = 0; i < numOfAnswers; i++) {
			answers[i] = new char[100] {};
		}

		//Resetting index's array:
		for (int* ptr = indexes; ptr < indexes + numOfAnswers; ptr++)
			*ptr = 0;

		//Setting current question's variable:
		question* currentQuestion = &(*(adminPlayer)).listOfQuestions[rounds];
		
		//Getting random and valid position:
		for (int j = 0; j < numOfAnswers; j++) {
			
			do {
				randomIndex = rand() % 4 ;
			} while (indexChecker(indexes, randomIndex,j));
			
			//Copying the answers to the temp array of answers:
			strcpy(answers[j], (*(currentQuestion)).answers[randomIndex]);
			indexes[j] = randomIndex;

		}

									/* Starting to play :*/
		
		//Presenting the question:
		cout << "Question " << rounds + 1 << "/" << (*(adminPlayer)).availableQuestions << " - "<< (*(currentQuestion)).question<<endl;
		
		//Showing the optional answers:
		cout << "Available answers:" << endl;
		for (int i = 0; i < numOfAnswers; i++) {
			cout << i << " - "<<answers[i] << endl;
		}

		//Getting user's answer:
		cout << "Whats your answer?" << endl;
		do {
			cout << ">>>";
			cin >> choice;
			if (!indexChecker(indexes, randomIndex,4)) {
				cout << "Please choose a number between 0 to 3" << endl;
			}

		} while (!indexChecker(indexes, randomIndex,4));

		Sleep(300);
		//Checking the given answer.Displaying victory / lost message:
		if (!strcmp(answers[choice], (*(currentQuestion)).answers[numOfAnswers-1])) {
			cout << "Well done, you just earnd one point." << endl;
			user.socre++;
		}
		else
			cout << "Sorry, but the answer was: " << (*(adminPlayer)).listOfQuestions->answers[numOfAnswers - 1] << " unlike your answer which was: " << answers[choice] << "." << endl;

		Sleep(300);
		//Deleting the pointers:
		for (int i = 0; i < numOfAnswers; i++) {
			delete[] answers[i];
		}

		//Deleting pointers:
		delete [] answers;
	}

	cout << "Well done you finished the quiz." << endl;
	Sleep(300);
	cout << "Returning to the dashboard ..." << endl;
}

//Checks if the given index position is already been choosed:
bool indexChecker(int* indexes,int index,int size){
	for (int* ptr = indexes;ptr<indexes+size; ptr++) {
		if (*ptr == index)
			return true;
	}
	return false;
}
