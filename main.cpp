#include<iostream>
using namespace std;

//global variables
string inventory[5];
int turns = 0;
int fish = 0;

//function decleration
void shop();

int main() {

	int room = 1;
	string userInput = "beef"; //dummy value
	cout << endl << "____________________________________________________________________________" << endl << endl;
	cout << "                           WELCOME TO CAT QUEST" << endl;
	cout << "____________________________________________________________________________" << endl;

	while (userInput != "quit" && turns < 20) { // game loop
		//STUFF HERE RUNS EVERY TURN
		cout << endl << "-------------------------------------" << endl;
		cout << "your inventory:";
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " | ";
		cout << endl;
		turns++;
		cout << "you have " << 31 - turns << " turns left" << endl;

		switch(room) {
			case 1:
				cout << "You lay on your overly expensive bed as you look outside the window." << endl;
				cout << "You wish you could be like one of the birds in the sky, free and happy." << endl;
				cout << "As you lay there, wishing for just a chance to explore even once, you see the front door slowly peer open." << endl;
				cout << "You realize this is your chance to explore, to be free, do you go north and take it?" << endl;
				cin >> userInput;
				if (userInput == "north")
					cout << "you run towards the door, your tiny heart pounding with excitement" << endl;
					room = 2;
				if (userInput == "yes")
					cout << "you run towards the door, your tiny heart pounding with excitement" << endl;
					room = 2;
				break;


			case 2:
				cout << "you are in room 2(street 1), you can go to north, east, south, or west" << endl;
				cin >> userInput;
				if (userInput == "west")
					room = 3;
				else if (userInput == "east")
					room = 5;
				else if (userInput == "north")
					room = 6;
				else if (userInput == "south")
					room = 1;
				else
					cout << "sorry thats not a room" << endl;
				break;


			case 3:
				cout << "you are in room 3(bench), you can go further west or back east" << endl;
				cin >> userInput;
				if (userInput == "west")
					room = 4;
				else if (userInput == "east")
					room = 2;
				break;


			case 4:
				cout << "you are in room 4 (lake), you can go back east" << endl;
				cin >> userInput;
				if (userInput == "east")
					room = 3;
				break;


			case 5:
				cout << "you are in room 5(car), you can go back west" << endl;
				cin >> userInput;
				if (userInput == "west")
					room = 2;
				break;


			case 6:
				cout << "you are in room 6(street 2), you can go east, north, or south" << endl;
				cin >> userInput;
				if (userInput == "east")
					room = 7;
				else if (userInput == "north")
					room = 9;
				else if (userInput == "south")
					room = 2;
				break;


			case 7:
				cout << "you are in room 7(allyway), you can go west to go back to the street, or go north into the trash can." << endl;
				cin >> userInput;
				if (userInput == "west")
					room = 6;
				else if (userInput == "north")
					room = 8;
				break;


			case 8:
				cout << "You see a disheveled tuxedo cat sitting politely in the corner of the dumpster, staring at you." << endl;
				cout <<"The cat gets up and starts to slowly walk to you. You get ready to attack but he suddenly stops" << endl;
				cout << " 'You want to but something from me ?' " << endl;
				cout <<"You can talk to the cat or go south back into the alleyway." << endl;

				cin >> userInput;
				if (userInput == "south")
					room = 7;
				else if (userInput == "talk")
					shop();
				break;


			case 9:
				cout << "you are in room 9(bucher), you can go south back into the street or go north into the back of the bucher room" << endl;
				cin >> userInput;
				if (userInput == "south")
					room = 6;
				else if (userInput == "north")
					room = 10;
				break;


			case 10:
				cout << "you are in room 10(back room), you can go south back into the main butcher shop" << endl;
				cin >> userInput;
				if (userInput == "south")
					room = 9;
				break;

		}//end of switch staement

	}// end game loop
}// end main loop

void shop() {
	char input = 'p';
	cout << endl << endl << "-------------------------------------------------------------------------" << endl;
	cout << endl << "WELCOME TO MY SHOP" << endl;
	cout << endl << "-------------------------------------------------------------------------" << endl;
	while (input != 'q') {
		cout << "press (f) to buy 1 fish for 2 fishes" << endl;
		cout <<"press (b) to buy a bat for 3 fish" << endl;
		cout <<"press (c) to buy a piece of C4(5 Fish)" << endl;
		cout <<"press (q) to quit" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cin >> input;
		switch (input) {
		case 'f':
			if (fish >= 1) {
				cout << "you got a half-eaten piece of tuna" << endl;
				inventory[0] = "half-eaten tuna";
				fish -= 1;
			}
			else
				cout << "you don't have enough fish" << endl;
			break;
		case 'b':
			if (fish >= 3) {
				cout << "you bought a bat!" << endl;
				inventory[1] = "bat";
			}
			else
				cout << "you don't have enough fish" << endl;
			break;
		case 'c':
			if (fish >= 5) {
				cout << "you got 1 piece of C4" << endl;
				inventory[2] = "C4 ";
			}
			else
				cout << "you don't have enough fish" << endl;
			break;

		}


	}
	cout << endl << "-------------------------------------------------------------------------" << endl;

}
