//Header files
#include <iostream>
using namespace std;

//enum types
enum Game {

        Stone, Paper, Scissors
};

int main() {

        //Variables
        int yourScore = 0;
        int computerScore = 0;
        int humanInput;
        int computerInput;
        char answer;

        Game humanTurn, computerTurn;

        cout << "STONE SCISSORS PAPER" << endl;
        cout << "====================" << endl;

        srand(time(0)); //Seed to generate random numbers for computer play

        //Loop as long as user wants to play
        do {

                //Use nested loop to keep looping until computer or player wins
                do {

                        cout << "Your choice (Stone=0/Scissors=1/Paper=2): ";
                        cin >> humanInput;

                        humanTurn = (Game)humanInput;

                        computerTurn = (Game)(rand() % 3 + 1); //Generate random numbers for computer from 1 - 3

                        //Print appropriate message depending on what compter chose
                        switch (computerTurn) {
                        case Stone:
                                cout << "Computer choose Stone " << endl;
                                break;
                        case Paper:
                                cout << "Computer choose Paper " << endl;
                                break;
                        case Scissors:
                                cout << "Computer choose Scissors " << endl;
                                break;
                        }

                        //Game is being played according to rules
                        if (humanTurn == Stone && computerTurn == Scissors) {
                                cout << "You won!" << endl;
                                yourScore++;
                        }
                        else if (humanTurn == Scissors && computerTurn == Paper) {
                                cout << "You won!" << endl;
                                yourScore++;
                        }
                        else if (humanTurn == Paper && computerTurn == Stone) {
                                cout << "You won!" << endl;
                                yourScore++;
                        }
                        else if (computerTurn == Stone && humanTurn == Scissors) {
                                cout << "Computer won!" << endl;
                                computerScore++;
                        }
                        else if (computerTurn == Scissors && humanTurn == Paper) {
                                cout << "Computer won!" << endl;
                                computerScore++;
                        }
                        else if (computerTurn == Paper && humanTurn == Stone) {
                                cout << "Computer won!" << endl;
                                computerScore++;
                        }
                        else {
                                cout << "Equal!" << endl;
                        }

                        //Print out current score
                        cout << "Score (you - computer): " << yourScore << " - " << computerScore << endl;

                } while (yourScore != 10 && computerScore != 10);

                //Print out results of winner
                if (yourScore == 10) {
                        cout << "You won with " << yourScore << " - " << computerScore << endl;
                }
                else {
                        cout << "Computer won with " << computerScore << " - " << yourScore << endl;
                }

                //Reset scores incase of reuse
                yourScore = 0;
                computerScore = 0;

                cout << endl;

                cout << "One more time (Y/N) ";
                cin >> answer;

                cout << endl;

        } while (toupper(answer) == 'Y');

        return 0;
}

