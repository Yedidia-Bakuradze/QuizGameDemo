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
	do {
		//login / Sign up form:
		isPlaying = false;
		
		
		/*Player's dashboard:*/
		
		//A welcome message:
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

		//Getting user's input:
		do {
			cout << ">>>";
			cin >> choice;

			switch (choice) {
			case profile:
				break;
			case runQuiz:
				break;
			case createQuiz:
				break;
			case logout:
				break;
			default:
				cout << "Please choose a number between 0 to 3" << endl;
			}

		} while (choice != logout);
		cout << "Have a nice day " << currentPlayer.firstName << "." << endl;

	} while (isPlaying);

	return 0;
}