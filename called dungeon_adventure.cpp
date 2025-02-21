#include <iostream>
#include <string>
#include <limits>

using namespace std;

void invalidInput() {
    cout << "Invalid input, please try again!" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void intro() {
    cout << "Welcome to 'Escape the Dungeon'" << endl;
    cout << "You find yourself trapped in a dark dungeon." << endl;
    cout << "Your mission is to find a way out." << endl;
    cout << "The dungeon is filled with dangerous creatures, hidden passages, and tough decisions!" << endl;
    
    cout << "\n-------------------------------------------------------------------------------------" << endl;
}

int choosePath() {
    int choice;
    cout << "\nYou stand in a dark hallway with three paths in front of you..." << endl;
    cout << "\nPath 1) A dark tunnel that seems to lead deeper into the dungeon." << endl;
    cout << "Path 2) A wooden door that looks like it might lead outside." << endl;
    cout << "Path 3) A staircase leading upward, with faint light coming from above." << endl;
    cout << "Which path will you choose? (1-3): ";
    cin >> choice;
    
    cout << "\n-------------------------------------------------------------------------------------" << endl;
    
    if (cin.fail() || choice < 1 || choice > 3) {
        invalidInput();
        return -1;
    }
    
    return choice;
}

bool encounterMonster() {
    int fightChoice;
    cout << "\nA wild monster appears! You must decide quickly!" << endl;
    cout << "Do you fight the monster or run away?" << endl;
    cout << "1) Fight" << endl;
    cout << "2) Run" << endl;
    cout << "What will you do? (1-2): ";
    cin >> fightChoice;
    
    cout << "\n-------------------------------------------------------------------------------------" << endl;
    
    if (cin.fail() || (fightChoice != 1 && fightChoice != 2)) {
        invalidInput();
        return false;
    }

    switch (fightChoice) {
        case 1:
            cout << "You bravely fight the monster!" << endl;

            if (rand() % 2 == 0) {
                cout << "You defeated the monster and found a treasure!" << endl;
                return true;
            } else {
                cout << "The monster overpowers you... You lost!" << endl;
                return false;
                
    cout << "\n-------------------------------------------------------------------------------------" << endl;
                
            }
        case 2:
            cout << "You decide to run away!" << endl;
            cout << "But you find yourself trapped in a dead-end and eventually starve..." << endl;
            return false;
        default:
            return false;
            
    cout << "\n-------------------------------------------------------------------------------------" << endl;
    
    }
}

bool finalChoice() {
    int escapeChoice;
    cout << "\nYou find a secret passage that leads to a mysterious door." << endl;
    cout << "You now face the final decision: Should you open the door?" << endl;
    cout << "1) Open the door" << endl;
    cout << "2) Turn back" << endl;
    cout << "What will you do? (1-2): ";
    cin >> escapeChoice;
    
    if (cin.fail() || (escapeChoice != 1 && escapeChoice != 2)) {
        invalidInput();
        return false;
    }

    switch (escapeChoice) {
        case 1:
            cout << "You open the door and find your way to freedom!" << endl;
            cout << "Congratulations, you have escaped the dungeon!" << endl;
            return true;
        case 2:
            cout << "You turn back, only to be trapped by the dungeon's closing walls. You're stuck forever!" << endl;
            return false;
        default:
            return false;
            
    cout << "\n-------------------------------------------------------------------------------------" << endl;
            
    }
}

int main() {
    srand(time(0));
    
    intro();
    
    bool isGameOver = false;
    int pathChoice;
    
    while (!isGameOver) {
        pathChoice = choosePath();
        
        if (pathChoice == -1) {
            continue;
        }
        
        if (pathChoice == 1) {

            isGameOver = !encounterMonster();
        } else if (pathChoice == 2) {

            cout << "\nYou open the wooden door and find a treasure chest!" << endl;
            cout << "Congratulations, you win! You found the treasure!" << endl;
            isGameOver = true;
        } else if (pathChoice == 3) {

            isGameOver = !finalChoice();
        }
    }

    cout << "\nGame Over!" << endl;
    return 0;
}
