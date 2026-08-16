#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int turnCount = 1;

    srand(time(0));
    bool enemyRanAway = false;
    string playerName = "Player";
    int playerHealth = 100;
    int playerDamage = 10;

    int enemyType = (rand() % 100) + 1;

    int healthPotion = 1;
    int strengthPotion = 1;
    int damagePotion = 1;

    int goblin = 35;
    int bandit = 45;
    int orc = 50;
    int cyclops = 60;

    string enemyName;

    if (enemyType <= 25) {
        enemyType = goblin;
        enemyName = "Goblin";
    }
    else if (enemyType >= 26 && enemyType <= 50) {
        enemyType = bandit;
        enemyName = "Bandit";
    }
    else if (enemyType >= 51 && enemyType <= 75) {
        enemyType = orc;
        enemyName = "Orc";
    }
    else {
        enemyType = cyclops;
        enemyName = "Cyclops";
    }
  
    int enemyHealth = enemyType;
    int enemyDamage = (rand() % 20) + 1;
    int enemyLevel = (rand() % 100) + 1;

    cout << "=== Game ===\n\n";

    cout << "Enter your name: ";
    cin >> playerName;

    cout << "\nWelcome, " << playerName << "!\n";

    while (playerHealth > 0 && enemyHealth > 0) {

        cout << "\nEnemy: " << enemyName << endl;
        cout << "Enemy HP: " << enemyHealth << endl;
        cout << "Enemy Level: " << enemyLevel << endl;

        cout << "\nYour HP: " << playerHealth << endl;

        cout << "\nChoose an action:\n";
        cout << "1. Attack\n";
        cout << "2. Heal\n";
        cout << "3. Run\n";
        cout << "4. Drink Potion\n";
        cout << "> ";


        int potionChoice = 0;
        int choice;
        cin >> choice;


        if (choice == 1) {
            cout << "You attack the " << enemyName << "\n-" << playerDamage << " Health\n\n";
            enemyHealth -= playerDamage;
            int criticalHit = (rand() % 100) + 1;
            if (criticalHit >= 90 || criticalHit <= 100) { enemyHealth -= playerDamage; }
        }

        else if (choice == 2) {
            int roll = (rand() % 100) + 1;

            if (roll <= 2) {
                cout << "You healed the " << enemyName << "\n+15 Health\n+1 Damage\n\n";
                enemyHealth += 15;
                enemyDamage += 1;
            }
            else {
                cout << "You healed yourself\n +15 Health\n +1 Damage\n\n";
                playerHealth += 15;
                playerDamage += 1;
            }
        }
        else if (choice == 3) {
            int roll = (rand() % 100) + 1;


            if (roll <= 2) {
                cout << "You try to run but the " << enemyName << " ran faster. He killed you.\n\n";
                playerHealth = 0;
            }
            else {
                cout << "You run and get away, but the " << enemyName << " tripped and fell down a cliff\n\n";
                enemyHealth = 0;
            }
        }

        else if (choice == 4) {
            cout << "Choose a potion to drink:\n";
            cout << "1. health Potion\n";
            cout << "2. Damage Potion\n";
            cout << "3. Strength Potion\n";
            cout << "4. Mystery Potion \n";
            cout << "> ";
            cin >> potionChoice;
            int potion = (rand() % 100) + 1;
            switch (potionChoice) {
            case 1:

                if (healthPotion >= 1) {
                    playerHealth += 20;
                    cout << "You drank a health potion and restored 20 health.\n\n";
                    healthPotion -= 1;
                }
                else if (potion >= 60 && healthPotion >= 1) {
                    playerHealth += 20;
                    cout << "You give the Health Potion to your" << enemyName << ", who then drinks it and restores 20 health.\n\n";
                    enemyHealth += 20;
                    healthPotion -= 1;
                }

                else { cout << "You look at an empty Glass, You aleady drank it all.\n\n"; }
                break;

            case 2:
                playerDamage += 5;
                if (damagePotion >= 1) {
                    cout << "You drank a Damage potion and gained 5 damage.\n\n";
                    playerDamage += 5;
                    damagePotion -= 1;
                }
                else if (potion >= 60 && damagePotion >= 1) {
                    cout << "You give the Damage Potion to the " << enemyName << ", who then drinks it and gains 5 damage.\n\n";
                    enemyDamage += 5;
                    damagePotion -= 1;
                }
                else
                {
                    cout << "You look at an empty Glass, You aleady drank it all.\n\n";
                }
                break;

            case 3:
                if (strengthPotion >= 1) {
                    cout << "You drank a Damage potion and gained 4 defence.\n\n";
                    enemyDamage -= 4;
                }
                else if (potion >= 1 && strengthPotion >= 1) {
                    cout << "You give the Strength Potion to the " << enemyName << ", who then drinks it and gains 4 defence.\n\n";
                    playerDamage -= 4;
                    strengthPotion -= 1;
                }
                else { cout << "You look at an empty Glass, You aleady drank it all.\n\n"; }
                break;

            case 4:
				if (potion >= 60 && strengthPotion >= 1) {
					cout << "You give the Mystery Potion to the " << enemyName << ", who then drinks it and dies instantly.\n\n";
					enemyHealth = 0;
				}
                else {
                    cout << "You drink the Mystery Potion, your vision begins to blur and you fall dead... it was Rat Poison\n\n";
                    playerHealth = 0;
                    break;
                }
                

            default:
                cout << "Invalid potion choice.\n\n";
                break;
            }
        }

        else { cout << "Input not detected, try again.\n\n"; }
        if (enemyHealth >= 1) {
            if (choice == 1 || choice == 2 || choice == 3) {
                int rollEnemy = (rand() % 100) + 1;
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
        int appendicitis = rand() % 1000 + 1;
        if (appendicitis <= turnCount) {
            cout << "You got appendicitis and died cuz this is like 1700s or som idk";
            playerHealth = 0;
        }
        turnCount++;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (playerHealth <= 0) {
        cout << "\nYou died.\n";
    }

    else if (enemyRanAway == true) { cout << "\n" << enemyName << " ran away, You won!\n"; }
    else if (enemyHealth <= 0) {
        cout << "\nYou won!\n\n";
    }
    this_thread::sleep_for(std::chrono::seconds(5));
    cout << "---------------------------------------\n\n"
    "Thank you for playing my game! V1.0.0.5\n\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "---------------------------------------\n\n";
    cout << "Developed by Zudd Studios\n\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "---------------------------------------\n\n"
    << "Developed by Zudd Studios\n\n";;
        this_thread::sleep_for(chrono::seconds(2));
    cout << "---------------------------------------\n\n";
    cout << "Licence: MIT License\n\n"
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