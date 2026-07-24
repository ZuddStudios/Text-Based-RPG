#include <iostream>  // cout, cin
#include <string>    // names, text
#include <cstdlib>   // rand()
#include <ctime>     // time() for random seed

using namespace std;

int main() {

    // Random number setup
    srand(time(0));
    bool enemyRanAway = false;
    // Player stats
    string playerName = "Player";
    int playerHealth = 100;
    int playerDamage = 10;

    // Enemy stats
    string enemyName = "Bandit";
    int enemyHealth = 50;
    int enemyDamage = 5;

    cout << "=== Adventure Game ===\n\n";

    cout << "Enter your name: ";
    cin >> playerName;

    cout << "\nWelcome, " << playerName << "!\n";

    // Main game loop
    while (playerHealth > 0 && enemyHealth > 0) {

        cout << "\nEnemy: " << enemyName << endl;
        cout << "Enemy HP: " << enemyHealth << endl;

        cout << "\nYour HP: " << playerHealth << endl;

        cout << "\nChoose an action:\n";
        cout << "1. Attack\n";
        cout << "2. Heal\n";
        cout << "3. Run\n";
        cout << "> ";

        int choice;
        cin >> choice;


        // Your code goes here
        
        // Make the choices do things
        if (choice == 1) {
            cout << "You attack the " << enemyName << "\n-" << playerDamage << " Health\n\n";
            enemyHealth -= playerDamage;
        }

        else if (choice == 2) {
            int roll = (rand() % 100) + 1;

            if (roll <= 2) {
                cout << "You healed the " << enemyName << "\n+15 Health\n+1 Damage\n\n";
                enemyHealth += 15;
                enemyDamage += 1;
            }
            else {
                cout << "You healed yourself +15 Health\n +1 Damage\n\n";
                playerHealth += 15;
                playerDamage += 1;
            }
        }
        else if (choice == 3) {
            int roll = (rand() % 100) + 1;

            if (roll <= 2) {
                cout << "You try to run but the " << enemyName << " ran faster. He killed you.\n\n";
                playerHealth -= 2147483647;
            }
            else {
                cout << "You run and get away, but the " << enemyName << " tripped and fell down a cliff\n\n";
                enemyHealth -= 2147483647;
            }
        }
        else { cout << "Input not detected, try again."; }

        if (choice == 1 || choice == 2 || choice == 3) { int rollEnemy = (rand() % 100) + 1; 
        if (rollEnemy <= 60) {
            playerHealth -= enemyDamage;
            cout << enemyName << " hit you\n-" << enemyDamage << " Health\n\n";
        }
        else if (rollEnemy >= 61 && rollEnemy <= 99) {
            cout << enemyName << " Healed\n+15 Health\n+1 Damage\n\n";
            enemyHealth += 15;
            enemyDamage += 1;
        }
        else if (rollEnemy == 100) {
            cout << enemyName << " ran away\n\n";
            enemyRanAway = true;
        }
        }
    }

    // End of battle
    if (playerHealth <= 0) {
        cout << "\nYou died.\n";
    }
    
    else if (enemyRanAway == true) { cout << "\n" << enemyName << " ran away, You won!\n"; }
    else if  (enemyHealth <= 0) {
        cout << "\nYou won!\n";
    }


    return 0;
}