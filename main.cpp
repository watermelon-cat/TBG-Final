#include<iostream>
#include<string> // needed for getline and compare
using namespace std;

//global variables
string inventory[10];
// 0 is fish from shop
// 1 is a bat
// 2 is C4
// 3,4,5,6 are all fish
// 7 is the fish from the car
// 8 is cardboard armor
// 9 is the golden key

int turns = 0;
int fish = 0;
int PlayerHealth = 200;
bool hasVisited[] = { false, false, false, false, false, false, false, false, false, false, false};
int room = 1;

//function decleration
void shop();
void moves();
void BattleSim();
void HELP();
void map();


int main() {

	srand(time(NULL)); // seeds rand() *keep this at the top of main
	string input = "beef"; //dummy value
	cout << endl << "____________________________________________________________________________" << endl << endl;
	cout <<"                           WELCOME TO CAT QUEST" <<endl << endl;
	cout <<"                          _..---...,\"\"-._     ,/}/)" << endl;
	cout <<"                       .\'\'        ,      \`\`..\'(/-<" << endl;
	cout <<"                      /   _      {      )         \\" << endl;
	cout <<"                     ;   _ \`.     \`.   <         a(" << endl;
	cout <<"                   ,\'   ( \\  )      \`.  \\ __.._ .: y" << endl;
	cout <<"                  (  <\\_-) )\'-.____...\\  \`._   //-'" << endl;
	cout <<"                   \`. \`-\' /-._)))      \`-._)))" << endl;
	cout <<"                     \`...\'         " << endl;
	cout <<"____________________________________________________________________________" << endl;

	while (input != "quit" && turns < 30) { // game loop
		//STUFF HERE RUNS EVERY TURN
		
		if (input == "help")
			HELP();
		if (input == "map")
			map();
		
		switch(room) {
			case 1:
				if (hasVisited[1] == false) {
					cout << "____________________________________________________________________________" << endl;
					cout << "A silly orange cat with a malicious smile, looks out the window awaiting to reenact his 'well-thought-out' plan" << endl;
					cout << "\"It's been a year since I fooled this human to let me take over his home.\"" << endl;
					cout << "\"It's been nice, all I have to do is lay here on this bed and eat. THE TYPE OF LIFE DESERVING OF A KING LIKE MYSELF.\"" << endl;
					cout << "\"Is what I would say if I didn't have to eat this disgusting food everyday.\"" << endl;
					cout << "\"This is why I have crafted a masterful plan to STEAL FROM THE FISH VENDOR.\"" << endl;
					cout << "\"As the human who feeds me leaves, I push my yarn ball between the door, stoping the door from shutting\"" << endl;
					cout << "\"An adventure awaits, it's time to venture north\"" << endl;
				}
				else {
					cout << "You stride back into the house." << endl << "After taking a quick power nap your full of energy again." << endl << "PATHS: NORTH" << endl;
					moves();
				}
				// getline lets you handle user input with spaces (like "get sword")
				getline(cin, input);
				
				if (input == "north" || input.compare("go north") == 0) {
					room = 4;
					hasVisited[1] = true;

				}
				break;


			case 2:
				cout << "____________________________________________________________________________" << endl;
				cout << "As you run out the house you're hit with a strong gust of wind." << endl;
				cout << "You hear the conversations of strangers, and the honking of cars as you look at the vast street in front of you" << endl;
				cout << "You notice the street continues north. East, you see a red truck with the window rolled down, you smell something fishy coming from it" << endl;
				cout << "To the west to see a bench litered with fishing equipment" << endl;
				cout << "PATHS: west, north, east, south" << endl;
				moves();
				cin >> input;
				if (input == "west" || input.compare("go west") == 0)
					room = 3;
				else if (input == "east" || input.compare("go east") == 0)
					room = 5;
				else if (input == "north" || input.compare("go north") == 0)
					room = 6;
				else if (input == "south" || input.compare("go south") == 0)
					room = 1;
				else
					cout << "sorry thats not a room" << endl;
				break;


			case 3:
				if (hasVisited[3] == false) {
					cout << "____________________________________________________________________________" << endl;
					cout << "As you near the bench you notice a gigantic lake further west." << endl;
					cout << "You decide to climb the bench to get a better view of the lake and notice a shine in the water about 10 meters out." << endl;
					cout << "Your curiousity starts the get the better of you and you get ready to jump in, but you then notice a warning sign saying \"ALLIGATOR INFESTED WATER DO NOT SWIM\"." << endl;
					cout << "Do you take the risk and jump into the lake or do you go back east to the street." << endl;
				}
				else {
					cout << "____________________________________________________________________________" << endl;
					cout << "You admire the nice view of the lake and the city behind it on the bench." << endl;
					cout << " You don't notice anything shiny in the lake anymore and are saddened by it." << endl;
					cout << "Your sense of adventure is not yet quenched. You should go east back into the street." << endl;

				}
				moves();
				cin >> input;
				if (input == "west" || input.compare("go west") == 0) {
					room = 4;
					hasVisited[3] = true;
				}
				else if (input == "east" || input.compare("go east") == 0)
					room = 2;
				break;


			case 4:
				if (hasVisited[4] == false) {
					cout << "____________________________________________________________________________" << endl;
					cout << "You're a cat, known for your agility, so you decide to go into the lake." << endl;
					cout << "You take a big breath and steel your nerves. You do a front flip into the lake with STYLE." << endl;
					cout << "Once your eyes ajust to the light and water you finally make out the shiny object to be a GOLD KEY." << endl;
					cout << "9 meters... 5 meters... 2 meters... as you get closer to the key you remember the warning sign about alligators." << endl;
					cout << "You look around fast and notice a HUGE 20 foot aligator rushing toward you from behind" << endl;
					cout << "You quickly do a back flip over the alligator in the water, dogeing it just barely." << endl;
					cout << "It quickly turns around and looks FURIOUS." << endl;
					cout << "Do you fight it or try to swim back" << endl;
				}
				else {
					cout << "____________________________________________________________________________" << endl;
					cout << "You swim with new found confidence and grab the golden key with your mouth. Your the king of this lake now." << endl;
					cout << "An alligator spots you but backs down after a feirce glare from your menecing eyes." << endl;
					cout << "You suddenly remember you don't like water and want to swim back east, toward the bench." << endl;
					
				}
				moves();
				cin >> input;
				if (input == "fight" || input.compare("fight it") == 0) {
					BattleSim();
					hasVisited[4] = true;
				}
				if (input == "east" || input.compare("go east") == 0)
					room = 3;
				break;


			case 5:
				if (hasVisited[5] == false) {
					cout << "____________________________________________________________________________" << endl;
					cout << "You jump trought the red trucks open window and are immediently hit with the smell of cigerates." << endl;
					cout << "You notice a fish fillet with a bite taken out of it on the dashboard." << endl;
					cout << "In the back seat you see a piece of cardboard. It reminds you of your home planet were warriors use a similar material as armor" << endl;
					cout << "PATHS: grab fish fillet, grab cardboard, go west." << endl;
					moves();
					cin >> input;
					if (input == "cardboard" || input.compare("grab cardboard") == 0) {
						inventory[8] = "cardboard armor";
						cout << "You grab the cardboard and make a 2 holes in it for your head and tail" << endl;
						cout << "You now look fabulous, adoning your cardbord armor with pride" << endl;
					}
					if (input == "fish" || input.compare("grab fish fillet") == 0) {
						inventory[7] = "fish fillet";
						cout << "You grabbed the fish fillet off the dashboard in hopes it becomes useful" << endl;
					}
				}
				else {
					cout << "You jump back into the truck put don't see anything interesting. You want to go west, back into the street." << endl;
				}
				cin >> input;
				if (input == "west" || input.compare("go west") == 0)
					room = 2;
					hasVisited[5] = true;
				break;


			case 6:
				cout << "____________________________________________________________________________" << endl;
				cout << "As you run through the busy street, you almost get hit by a car." << endl;
				cout << "You quickly dodge, but at the peak of your jump you see something magnificent." << endl;
				cout << "It's a bluefin tuna wrapped in GOLD LEAVES. You see it on a tray being brought to the backroom of the fish shop up north." << endl;
				cout << "A rock suddenly hits you, snapping you out of your daze. You see it came from the east allyway." << endl;
				cout << "PATHS: east, north, south." << endl;



				moves();
				cin >> input;
				if (input == "east" || input.compare("go east") == 0)
					room = 7;
				else if (input == "north" || input.compare("go north") == 0)
					room = 9;
				else if (input == "south" || input.compare("go south") == 0)
					room = 2;
				break;


			case 7:
				cout << "____________________________________________________________________________" << endl;
				cout << "You carefully strole trough the allyway, on guard. As you walk to start to notice all the cats laying around, staring at you." << endl;
				cout << "You suddenly feel a chill go down your spine. You snap your head ahead of you and see a greedy pair of eyes staring at you from inside a dumpster. " << endl;
				cout << "With a loud slam the cat in the dumpster hides and closes the lid." << endl;
				cout << "Do you go back west onto the street or go into the dumpster north of you?" << endl;


				moves();
				cin >> input;
				if (input == "west" || input.compare("go west") == 0)
					room = 6;
				else if (input == "north" || input == "dumpster" || input.compare("go north") == 0 || input.compare("go into dumpster") == 0)
					room = 8;
				break;


			case 8:
				cout << "____________________________________________________________________________" << endl;
				cout << "You kick a rock at lid to lift it up and jump into the dumpster." << endl;
				cout << "To your suprise your nose was hit with the smell of citris and not trash." << endl;
				cout << "You see a disheveled tuxedo cat sitting politely in the corner of the dumpster, staring at you." << endl;
				cout <<"The cat gets up and starts to slowly walk to you. You get ready to attack but he suddenly stops" << endl;
				cout << " \"You want to buy something from me ?\" " << endl;
				cout << "      ,_     _," << endl;
				cout << "      |\\\\___//|" << endl;
				cout << "      |=6   6=|" << endl;
				cout << "      \\=._Y_.=/" << endl;
				cout << "       )  \`  (    ," << endl;
				cout << "      /       \\  ((" << endl;
				cout << "      |       |   ))" << endl;
				cout << "     /| |   | |\\_//" << endl;
				cout << "     \\| |._.| |/-\`" << endl;
				cout << "      \'\"\'   \'\"\'" << endl;

				cout <<"You can talk to the cat or go south back into the alleyway." << endl;
				moves();

				cin >> input;
				if (input == "south" || input.compare("go south") == 0)
					room = 7;
				else if (input == "talk" || input.compare("talk to cat") == 0)
					shop();
				break;


			case 9:
				if (inventory[9] == "gold key") {
					cout << "____________________________________________________________________________" << endl;
					cout << "Your rush over to the fish shop as you try to calm your excitment, pushing open the door, but realize the door won't budge. The door is locked." << endl;
					cout << "You remember the key you grabbed from the lake and jump to the door handle, placing the key in the key hole and turing the knob." << endl;
					cout << "The place is clear of everyone, the door must've been locked because the workers were on break." << endl;
					cout << "It's like the lottery; samon, tuna, cod, shrimp and crab, all on ice to keep their freshness." << endl << "You waste no time stuffing your face and enjoying your prize." << endl;
					cout << "After you eat the majority of the fish you remember about the bluefin tuna wrapped in gold flakes that was taken to the backroom." << endl << "Do you go back before your caught or do you take the risk and go north into the backroom." << endl;
				 	if (input == "north" || input.compare("go north") == 0)
					room = 10;
				}
				else {
					cout << "You try to calm your excitment as you try to push open the door, but realize the door won't budge. The door is locked." << endl;
					cout << "YOUR DAY IS RUINED NOOOOOOOOOOOO. IF ONLY I HAD A KEY" << endl;
					cout << "PATHS: south" << endl;
				}
				moves();
				cin >> input;
				if (input == "south" || input.compare("go south") == 0)
					room = 6;
				break;


			case 10:
				if (inventory[2] == "C4") {
					cout << "____________________________________________________________________________" << endl;
					cout << "You come face to face with a huge dimonde enforced door; You learned your lesson the first time and realize that you won't be able to open this trought normal means." << endl;
					cout << "You grab the C4 you got from the shady cat vender and stick it onto the door." << endl;
					cout << "3..." << endl << "2.." << endl << "1." << endl << "BOOOMMMMMMMMMMM##############" << endl;
					cout << "The door blast open and you careful stroll in" << endl <<"That is untill you lay eyes on the masterpiece infront of you. The most expensive, luxuaeras, bluefin tuna with GOLD" << endl;
					cout << "This is why you escaped your home plant and came to earth. To have the freedom to do ANYTHING" << endl << "You take your time, carefully and elegently eating the bluefin tuna. ALL THE WAY TO THE BONE" << endl;
				
				}
				else{
					cout << "You stide up to the door but as you near you realize you aren't equipped to open it." << endl << "If only it could just explode and slam open" <<endl;
					cout << "PATHS: south" << endl;

				}
				moves();
				cin >> input;
				if (input == "south" || input.compare("go south") == 0)
					room = 9;
				break;
			default:
				cout << "sorry, that wasn't and option." << endl << "type 'help' for help" << endl;
				cin >> input;


		}//end of switch staement

	}// end game loop
}// end main loop

void shop() {
	char userinput = 'p';
	cout << endl << endl << "-------------------------------------------------------------------------" << endl;
	cout << endl << "WELCOME TO MY SHOP" << endl;
	cout << endl << "-------------------------------------------------------------------------" << endl;
	while (userinput != 'q') {
		cout << "press (f) to buy 1 fish for 2 fishes" << endl;
		cout <<"press (b) to buy a bat for 3 fish" << endl;
		cout <<"press (c) to buy a piece of C4(5 Fish)" << endl;
		cout <<"press (q) to quit" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cin >> userinput;
		switch (userinput) {
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

void moves() {
	cout << endl << "-------------------------------------" << endl;
	cout << "your inventory:";
	for (int i = 0; i < 10; i++)
		cout << inventory[i] << " | ";
	cout << endl;
	turns++;
	cout << "you have " << 31 - turns << " minutes to get back home before you're caught" << endl;
}
void BattleSim() {
	int MonsterHealth = 80; // local variale: this can only be seen and used by BattleSim
	int damage;
	int input;
	char dummy;
	cout << endl << endl << "------------------ BATTLE BEGINS------------------" << endl;
	cout << "The alligator rushes quickly at you." << endl;
	while (PlayerHealth > 0 && MonsterHealth > 0) { // battle  loop

		//monster fight section
		if (inventory[8] == "armor") {
			damage = rand() % 11 + 5; // monster can bite for 0-10 (+5 to make it 5-15
			cout << "##########################################" << endl;
			cout << "the alligator chomps at you but the armor protected you slightly. The aligator did " << damage << " dmg" << endl;
			PlayerHealth -= damage;
			cout << "press any key to continue........" << endl;
			cin >> dummy;
		}
		else {
			damage = rand() % 11 + 5; // monster can bite for 0-10 (+5 to make it 5-15
			cout << "##########################################" << endl;
			cout << "the alligator bites you for " << damage << " dmg" << endl;
			PlayerHealth -= damage;
			//cout << "press any key to continue........" << endl;
			//cin >> dummy;
		}

		cout << "press 1 to scratch it's eyes, press 2 to kick down on it's nose" << endl;
		cin >> input;
		switch (input) {
		case 1:
			//player fihts
			damage = rand() % 10 + 5; // player swings 5-9
			cout << "##########################################" << endl;
			cout << "you duck under the next bite and scratch the alligator in the eyes for " << damage << " damage" << endl;
			MonsterHealth -= damage;
			cout << "press any key to continue........" << endl;
			cin >> dummy;
			break;
		case 2:
			//player fihts
			damage = rand() % 10 + 8; // player swings 8-17
			cout << "##########################################" << endl;
			cout << "you lift your leg up and charge your power. In one quick motion you SLAM your foot into the alligators nose for " << damage << " damage" << endl;
			MonsterHealth -= damage;
			//cout << "press any key to continue........" << endl;
			//cin >> dummy;
			break;
		}

		if (PlayerHealth > 0)
			cout << "You're health is now: " << PlayerHealth << endl;
		else {
			cout << "You wake up in a daze, \"Good Morning Little Fluff Shiny Sparkels Jr.\"" << endl;
			cout << "You realize that it had all been a dream." << endl;
		}

		if (MonsterHealth > 0)
			cout << "The alligators health is now : " << MonsterHealth << endl;
		else
			cout << "The alligator realized he was no match for you and ran away crying" << endl;

		//cout << "press any key to continue........" << endl;
		//cin >> dummy;

	}
	if (PlayerHealth > 0) {
		cout << "You won!" << endl << "In your battle 4 of the fish around you died. You picked them up."<< endl << "You also swim down to grab the golden key with you mouth." << endl; // place of loot after kill
		fish += 4;
		inventory[3] = "half-eaten tuna";
		inventory[4] = "half-eaten tuna";
		inventory[5] = "half-eaten tuna";
		inventory[6] = "half-eaten tuna";
		inventory[9] = "gold key";
	}
	else
		cout << "you lost GAME OVER" << endl;
	cout << "---------------------------END OF BATTLE------------------------------" << endl << endl;
}

void HELP() {
	string type;
	cout << endl << "-------------------------------------" << endl;
	cout << "DIRECTIONS:" << endl << "north" << endl << "south" << endl << "north" << endl << "east" << endl;
	cout << endl << "-------------------------------------" << endl;
	cout << "PLAYER HEALTH: " << PlayerHealth << endl;
	cout << endl << "-------------------------------------" << endl;
	cout << "Type 'return' to go back to the game" << endl;
	cin >> type;
	if (type == "return") {
		return;
	}
}

void map() {
	string input = "potato";
	while (input != "back") {
		//stuff here happens every turn
		cout << endl << "                     MAP               " << endl;
		cout << "           you are the star(*)            " << endl;
		cout << "           type 'back' to go back            " << endl;

		switch(room) {
		case 1:
			cout << endl << "                              " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //   *   \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 2:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |   *   |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 3:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |   *  |       |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 4:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                    **           |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 5:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       | * |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 6:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |   **  |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 7:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |          **         |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 8:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|__**__|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                                 |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 9:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |                         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |   **  |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                    **           |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		case 10:
			cout << endl << "                                         " << endl;
			cout << "                                                                                               " << endl;
			cout << "                      __________________________              " << endl;
			cout << "                      |              **         |                      " << endl;
			cout << "                      |_________________________|                      " << endl;
			cout << "                                       |       |               _______       " << endl;
			cout << "                                       |_______|_______________|______|        " << endl;
			cout << "                                       |       |                     |        " << endl;
			cout << "__________                             |       |_____________________|      " << endl;
			cout << "          \\_________                   |       |                   " << endl;
			cout << "                     \\ ________________|_______|                       " << endl;
			cout << "                                 |      |       |___                " << endl;
			cout << "                                 |      |       |   |                      " << endl;
			cout << "                    **           |      |       |___|                       " << endl;
			cout << "                                 |______|_______|                        " << endl;
			cout << "                              ___|        ______                          " << endl;
			cout << "                      _______/         //       \\\\                       " << endl;
			cout << "       ______________/                //_________\\\\                   " << endl;
			cout << "______/                              //|   ___    |\\\\                            " << endl;
			cout << "                                       |   |  |   |               " << endl;
			cout << "                                       |___|__|___|             " << endl;
			cin >> input;
			break;
		}
	}
}
