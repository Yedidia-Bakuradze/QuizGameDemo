#include <iostream>

using namespace std;

//The player's struct:
struct player {
	string firstName;
	string lastName;
	string username;
	long password;
	int socre;
};

/*Decalring functions : */

//Shows the user "all" his personal information:
void profileData(player &user);

//Main function of profile modification:
void mainProfile(player &user);

//The modification function:
void modifyProfile(player& user);




//Local database:
player listOfPlayers[10] = {};
enum dashBoradOptions {profile,runQuiz,createQuiz,logout};
string row = "----------------------------------------------------\n";
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
};
int main() {
	int playersIndexPosition = 0,choice;
	bool isPlaying;
	string username;
	long password;
	bool loginend = true;
	int numOfPlayers = 0;
	int checkvar;//variable to use if we need to check things 
	/* Main game loop: */
	do {

		/* login / Sign up form: */
		cout << "Hi welcome to trevia world (:" << endl;
		isPlaying = false;
		while (loginend)
		{
			
			cout << "press 0 to login" << endl;
			cout << "prees 1 to signup" << endl;
			cout << row;
			cin >> choice;
			switch (choice)
			{
			case login:
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
				cout << "please enter your first name:" << endl;
				cin >> listOfPlayers[numOfPlayers].firstName;
				cout << "please enter your last name:" << endl;
				cin >> listOfPlayers[numOfPlayers].lastName;
				cout << "please enter username:" << endl;
				cin >> username;
				checkvar = userchecksu(username, listOfPlayers);
				while (checkvar == 10)
				{
					cout << "This username is used by other player pls try diffrent user name" << endl;
					cin >> username;
					checkvar = userchecksu(username, listOfPlayers);
				}
				listOfPlayers[numOfPlayers].username = username;
				cout << "please enter a strong password:" << endl;
				cout << "0-8 letters, no capital letters/numbers" << endl;
				cin >> listOfPlayers[numOfPlayers].password;
				numOfPlayers++;
				break;
			default:
				break;
			}
		}
		
		
		/*Player's dashboard:*/

		//Welcome message:
		player currentPlayer = listOfPlayers[playersIndexPosition];
		cout << row;
		cout << "Hello " << currentPlayer.firstName << "" << endl;
		cout << "Your current score: " << currentPlayer.socre << "." << endl;
		
		
		//Main gateway:
		do {
			//Player's options:
			cout << row;
			cout << "Press 0 to see and modify your personal information." << endl;
			cout << "Press 1 to run a quiz." << endl;
			cout << "Press 2 to creare a quiz." << endl;
			cout << "Press 3 to logout." << endl;
			cout << row;
			
			cout << ">>>";
			cin >> choice;

			switch (choice) {
			case profile:
				mainProfile(currentPlayer);
				break;
			case runQuiz:
				break;
			case createQuiz:
				break;
			case logout:
				break;
			default:
				cout << "Please choose a number between 0 to 3" << endl;
				break;
			}

		} while (choice != logout);
		cout << "Have a nice day " << currentPlayer.firstName << "." << endl;

	} while (isPlaying);

	cout << "Thank your for playing out program.";

	return 0;
}


//Main function of profile modification:
void mainProfile(player& user) {
	char choice;

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