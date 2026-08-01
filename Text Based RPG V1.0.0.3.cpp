#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    int turnCount = 1;

    srand(time(0));
    bool enemyRanAway = false;
    string playerName = "Player";
    int playerHealth = 100;
    int playerDamage = 10;

    string enemyName = "Bandit";
    int enemyHealth = 50;
    int enemyDamage = 5;

    cout << "=== Adventure Game ===\n\n";

    cout << "Enter your name: ";
    cin >> playerName;

    cout << "\nWelcome, " << playerName << "!\n";

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
  int appendicitis = rand() % 1000 + 1;
        if (appendicitis <= turnCount) {
            cout << "You got appendicitis and died cuz this is like 1700s or som idk";
        playerHealth -= 2147483647;
         }
        turnCount++;  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // End of battle
    if (playerHealth <= 0) {
        cout << "\nYou died.\n";
    }
    
    else if (enemyRanAway == true) { cout << "\n" << enemyName << " ran away, You won!\n"; }
    else if  (enemyHealth <= 0) {
        cout << "\nYou won!\n\n";
    }
    cout << "---------------------------------------\n"
        "Thank you for playing my game! V1.0.0.3\n"
        "Developed by Zudd Studios\n"
        "Licence: MIT License\n\n"
        "Copyright(c) 2026 Zudd Studios\n\n"
        "Permission is hereby granted, free of charge, to any person obtaining a copy\n"
        "of this software and associated documentation files(the \"Software\"), to deal\n"
        "in the Software without restriction, including without limitation the rights\n"
        "to use, copy, modify, merge, publish, distribute, sublicense, and /or sell\n"
        " copies of the Software, and to permit persons to whom the Software is\n"
        "furnished to do so, subject to the following conditions :\n\n"
        "The above copyright notice and this permission notice shall be included in all\n"
        "copies or substantial portions of the Software.\n\n"
        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
        "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
        "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE\n"
        "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
        "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
        "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
        "SOFTWARE.\n";
    
    return 0;
}
