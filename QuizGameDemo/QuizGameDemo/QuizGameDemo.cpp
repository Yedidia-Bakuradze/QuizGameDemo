#include <iostream>

using namespace std;

//The player's struct:
struct player {
	string firstName;
	string lastName;
	string username;
	int password;
	int socre;
};

//Local database:
player listOfPlayers[10] = {};
enum dashBoradOptions {profile,runQuiz,createQuiz,logout};
string row = "----------------------------------------------------\n";


int main() {
	int playersIndexPosition = 0,choice;
	bool isPlaying;
	
	/* Main game loop: */
	do {

		/* login / Sign up form: */
		isPlaying = false;
		
		
		
		/*Player's dashboard:*/
		
		//Welcome message:
		player currentPlayer = listOfPlayers[playersIndexPosition];
		cout << row;
		cout << "Hello " << currentPlayer.firstName << "" << endl;
		cout << "Your current score: " << currentPlayer.socre << "." << endl;
		cout << row;

		//Player's options:
		cout << "Press 0 to see and modify your personal information." << endl;
		cout << "Press 1 to run a quiz." << endl;
		cout << "Press 2 to creare a quiz." << endl;
		cout << "Press 3 to logout." << endl;
		cout << row;

		//Main gateway:
		do {
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

	return 0;
}


//Shows the user "all" his personal information:
void profileData(player user) {
	//User's profile
	cout << row;
	cout << "This is " << user.firstName << "'s profile." << endl;
	cout << "Full name: " << user.firstName << " " << user.lastName << '.' << endl;
	cout << "Username: " << user.username << "." << endl;
	cout << "Total score: " << user.socre << '.' << endl;
	cout << row;
}

//Main function of profile modification:
void mainProfile(player user) {
	char choice;

	cout << "Loading info ..." << endl;
	profileData(user);

	//User's choice handler:
	do {
		cout << "Would you like to change and modify any of your personl information? (y/n)";
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


//The modification function:
void modifyProfile(player user) {
	/* TODO: add a enum dictionary for the user's options.*/
	
	int choice, newPassword;
	string newUsername;
	//Showing instructions:
	cout << row;
	cout << "Press 0 to change your first name." << endl;
	cout << "Press 1 to change your last name." << endl;
	cout << "Press 2 to change your password." << endl;
	cout << "Press 3 to change your username." << endl;
	cout << "Press 4 to exit the editing mode." << endl;
	cout << row;


	//The gateway to the profile database:
	do {
		cout << ">>>";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Enter your new first name: ";
			cin >> user.firstName;
			break;
		case 1:
			cout << "Enter your new last name: ";
			cin >> user.lastName;
			break;
		case 2:
			cout << "Enter your new password: ";
			cin >> newPassword;
			/* Check is the password is valid. */
			user.password = newPassword;
			break;
		case 3:
			cout << "Enter your new username: ";
			cin >> newUsername;
			/* Check is the username is valid. */
			user.username = newUsername;
			break;

		case 4:
			cout << "Saving changes ... " << endl;
			break;

		default:
			cout << "Please choose a number between 0 to 3." << endl;
			break;
		}
	} while (choice != 4);

}