#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    char playerCharacter;
    char computerCharacter;
    char headsOrTails;
    cout << "This is a game of noughts and crosses.\nEnter X to play as crosses and O to play as noughts." << endl;
    cin >> playerCharacter;
    if (playerCharacter == 'X' || playerCharacter == 'x'){
    	computerCharacter = 'O';
    	playerCharacter = 'X';
    }
    else{
    	computerCharacter = 'X';
    	playerCharacter = 'O';
    }
    char AIinput;
    cout << "Would you like the computer to have AI? (Y/N): ";
    cin >> AIinput;
    cout << "Heads or tails? If you win you play first.\nEnter H for heads and T for tails." << endl;
    cin >> headsOrTails;
    int AIturnedOn;
    int x = 0;
    if (AIinput == 'Y' || AIinput == 'y'){
        AIturnedOn = 1;
        x = 1;
    }
    else{
        AIturnedOn = 0;
        x = 0;
    }
    srand(time(NULL));
    int coinFlip = rand()%2;
    int sideChoice;
    if (coinFlip == 0) cout << "HEADS" << endl;
    else cout << "TAILS" << endl;
    int first;
    if (headsOrTails == 'H' || headsOrTails == 'h'){
        sideChoice = 0;
    	if (sideChoice == coinFlip) first = 1;
        else first = 0;
    }
    else if (headsOrTails != 'H' || headsOrTails != 'h'){
        sideChoice = 1;
        if (sideChoice == coinFlip) first = 1;
        else first = 0;
    } 
    char spaces[9];
    for (int i = 0; i < 9; i++) spaces[i] = ' ';
    bool endOfGame = false;
    int spaceChoice;
    int computerSpaceChoice;
    bool validSpace = false;
    srand(time(NULL));
    int a;
    if (first == 0 && AIturnedOn == 0) spaces[rand()%9] = computerCharacter;
    if (first == 0 && AIturnedOn == 1){
        a = rand()%4;
        if (a == 0) spaces[0] = computerCharacter;
        if (a == 1) spaces[2] = computerCharacter;
        if (a == 2) spaces[6] = computerCharacter;
        if (a == 3) spaces[8] = computerCharacter;
        x = 1;
    }
    int finished;
    int q;
    int r;
    int z;
    while (endOfGame == false){
        finished = 0;
        q = 0;
        cout << endl << endl << "     " << spaces[0] << "|" << spaces[1] << "|" << spaces[2] << "\n     -----\n     " << spaces[3] << "|" << spaces[4] << "|"
            << spaces[5] << "\n     -----\n     " << spaces[6] << "|" << spaces[7] << "|" << spaces[8] << endl << endl << "---------------";
        if (spaces[0] != ' ' && spaces[1] != ' ' && spaces[2] != ' ' && spaces[3] != ' ' && spaces[4] != ' '
            && spaces[5] != ' ' && spaces[6] != ' ' && spaces[7] != ' ' && spaces[8] != ' '){
            cout << "You got a tie with the computer." << endl;
            endOfGame = true;
            if (endOfGame == true) break;
        }
    	if ((spaces[0] == playerCharacter && spaces[1] == playerCharacter && spaces[2] == playerCharacter) ||
    	    (spaces[3] == playerCharacter && spaces[4] == playerCharacter && spaces[5] == playerCharacter) ||
    	    (spaces[6] == playerCharacter && spaces[7] == playerCharacter && spaces[8] == playerCharacter) ||
    	    (spaces[0] == playerCharacter && spaces[3] == playerCharacter && spaces[6] == playerCharacter) ||
    	    (spaces[1] == playerCharacter && spaces[4] == playerCharacter && spaces[7] == playerCharacter) ||
    	    (spaces[2] == playerCharacter && spaces[5] == playerCharacter && spaces[8] == playerCharacter) ||
    	    (spaces[0] == playerCharacter && spaces[4] == playerCharacter && spaces[8] == playerCharacter) ||
    	    (spaces[2] == playerCharacter && spaces[4] == playerCharacter && spaces[6] == playerCharacter)){
    	    cout << "You beat the computer. :D" << endl;
    	    endOfGame = true;
            if (endOfGame == true) break;
    	}
    	if ((spaces[0] == computerCharacter && spaces[1] == computerCharacter && spaces[2] == computerCharacter) ||
    	    (spaces[3] == computerCharacter && spaces[4] == computerCharacter && spaces[5] == computerCharacter) ||
    	    (spaces[6] == computerCharacter && spaces[7] == computerCharacter && spaces[8] == computerCharacter) ||
    	    (spaces[0] == computerCharacter && spaces[3] == computerCharacter && spaces[6] == computerCharacter) ||
    	    (spaces[1] == computerCharacter && spaces[4] == computerCharacter && spaces[7] == computerCharacter) ||
    	    (spaces[2] == computerCharacter && spaces[5] == computerCharacter && spaces[8] == computerCharacter) ||
    	    (spaces[0] == computerCharacter && spaces[4] == computerCharacter && spaces[8] == computerCharacter) ||
    	    (spaces[2] == computerCharacter && spaces[4] == computerCharacter && spaces[6] == computerCharacter)){
    	    cout << "You lost to the computer. :(" << endl;
    	    endOfGame = true;
            if (endOfGame == true) break;
    	}
        cout << "  From left-right-top-bottom, enter which space you want to place your " << playerCharacter << ": ";
        while (validSpace == false){
            cin >> spaceChoice;
            spaceChoice -= 1;
            if (spaces[spaceChoice] == 'O' || spaces[spaceChoice] == 'X'){
    	        cout << "You cannot choose a space which is already occupied." << endl;
            }
            else{
    	       spaces[spaceChoice] = playerCharacter;
    	       validSpace = true;
    	    }
        }
    	validSpace = false;
        cout << endl << endl << "     " << spaces[0] << "|" << spaces[1] << "|" << spaces[2] << "\n     -----\n     " << spaces[3] << "|" << spaces[4] << "|"
            << spaces[5] << "\n     -----\n     " << spaces[6] << "|" << spaces[7] << "|" << spaces[8] << endl << endl << "---------------";
        if ((spaces[0] == playerCharacter && spaces[1] == playerCharacter && spaces[2] == playerCharacter) ||
            (spaces[3] == playerCharacter && spaces[4] == playerCharacter && spaces[5] == playerCharacter) ||
            (spaces[6] == playerCharacter && spaces[7] == playerCharacter && spaces[8] == playerCharacter) ||
            (spaces[0] == playerCharacter && spaces[3] == playerCharacter && spaces[6] == playerCharacter) ||
            (spaces[1] == playerCharacter && spaces[4] == playerCharacter && spaces[7] == playerCharacter) ||
            (spaces[2] == playerCharacter && spaces[5] == playerCharacter && spaces[8] == playerCharacter) ||
            (spaces[0] == playerCharacter && spaces[4] == playerCharacter && spaces[8] == playerCharacter) ||
            (spaces[2] == playerCharacter && spaces[4] == playerCharacter && spaces[6] == playerCharacter)){
            cout << "You beat the computer. :D" << endl;
            endOfGame = true;
            if (endOfGame == true) break;
        }
        if ((spaces[0] == computerCharacter && spaces[1] == computerCharacter && spaces[2] == computerCharacter) ||
            (spaces[3] == computerCharacter && spaces[4] == computerCharacter && spaces[5] == computerCharacter) ||
            (spaces[6] == computerCharacter && spaces[7] == computerCharacter && spaces[8] == computerCharacter) ||
            (spaces[0] == computerCharacter && spaces[3] == computerCharacter && spaces[6] == computerCharacter) ||
            (spaces[1] == computerCharacter && spaces[4] == computerCharacter && spaces[7] == computerCharacter) ||
            (spaces[2] == computerCharacter && spaces[5] == computerCharacter && spaces[8] == computerCharacter) ||
            (spaces[0] == computerCharacter && spaces[4] == computerCharacter && spaces[8] == computerCharacter) ||
            (spaces[2] == computerCharacter && spaces[4] == computerCharacter && spaces[6] == computerCharacter)){
            cout << "You lost to the computer. :(" << endl;
            endOfGame = true;
            if (endOfGame == true) break;
        }
    	while (validSpace == false && AIturnedOn == 0){
            srand(time(NULL));
    	    computerSpaceChoice = rand()%9;
            if (spaces[computerSpaceChoice] != 'O' && spaces[computerSpaceChoice] != 'X'){
    	        spaces[computerSpaceChoice] = computerCharacter;
    	        validSpace = true;
            }
        }
        while (validSpace == false && AIturnedOn == 1){
            srand(time(NULL));
            computerSpaceChoice = rand()%4;
            if (x == 0) switch (computerSpaceChoice){
                case 0:
                    if (spaces[computerSpaceChoice] == ' '){
                        spaces[0] = computerCharacter;
                        finished = 1;
                        x = 1;
                        validSpace = true;
                    }
                case 1:
                    if (spaces[computerSpaceChoice] == ' '){
                        spaces[6] = computerCharacter;
                        finished = 1;
                        x = 1;
                        validSpace = true;
                    }
                case 2:
                    if (spaces[computerSpaceChoice] == ' '){
                        spaces[2] = computerCharacter;
                        finished = 1;
                        x = 1;
                        validSpace = true;
                    }
                case 3:
                    if (spaces[computerSpaceChoice] == ' '){
                        spaces[8] = computerCharacter;
                        finished = 1;
                        validSpace = true;
                    }
            }
            if (finished == 1) break;
            while (finished == 0){
                if (spaces[0] == computerCharacter && spaces[2] == computerCharacter && spaces[1] != playerCharacter){
                    spaces[1] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[0] == computerCharacter && spaces[6] == computerCharacter && spaces[3] != playerCharacter){
                    spaces[3] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[0] == computerCharacter && spaces[8] == computerCharacter && spaces[4] != playerCharacter){
                    spaces[4] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[2] == computerCharacter && spaces[8] == computerCharacter && spaces[5] != playerCharacter){
                    spaces[5] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[6] == computerCharacter && spaces[8] == computerCharacter && spaces[7] != playerCharacter){
                    spaces[7] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[0] == playerCharacter && spaces[2] == playerCharacter && spaces[1] != computerCharacter){
                    spaces[1] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[0] == playerCharacter && spaces[6] == playerCharacter && spaces[3] != computerCharacter){
                    spaces[3] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[0] == playerCharacter && spaces[8] == playerCharacter && spaces[4] != computerCharacter){
                    spaces[4] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[2] == playerCharacter && spaces[8] == playerCharacter && spaces[5] != computerCharacter){
                    spaces[5] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[6] == playerCharacter && spaces[8] == playerCharacter && spaces[7] != computerCharacter){
                    spaces[7] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                if (spaces[2] == playerCharacter && spaces[6] == playerCharacter && spaces[4] != computerCharacter){
                    spaces[4] = computerCharacter;
                    validSpace = true;
                    finished = 1;
                    break;
                }
                for (q = 0; q < 6; q++){
                    while (q < 3){
                        if (spaces[q] == playerCharacter && spaces[q+3] == playerCharacter && spaces[q+6] != computerCharacter){
                            spaces[q+6] = computerCharacter;
                            validSpace = true;
                            finished = 1;
                            break;
                        }
                    }
                    if (finished == 1) break;
                    while (q >= 3){
                        if (spaces[q] == playerCharacter && spaces[q+3] == playerCharacter && spaces[q-3] != computerCharacter){
                            spaces[q-3] = computerCharacter;
                            validSpace = true;
                            finished = 1;
                            break;
                        }
                    }
                    if (finished == 1) break;
                }
                if (finished == 1) break;
                while (spaces[1] != playerCharacter && spaces[3] != playerCharacter && spaces[5] != playerCharacter && spaces[7] != playerCharacter && finished == 0){
                    for (r = 0; r < 9; r++){
                        if (spaces[r] == computerCharacter && (r == 0 || r == 2 || r == 6 || r == 8)){
                            srand(time(NULL));
                            z = rand()%12;
                            if (r == 0 && spaces[2] != playerCharacter && spaces[6] != playerCharacter && spaces[8] != playerCharacter){
                                if (z == 0){
                                    spaces[2] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (z == 1){
                                    spaces[6] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (spaces[4] != playerCharacter) if (z == 2){
                                    spaces[8] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                            }
                            if (r == 2 && spaces[0] != playerCharacter && spaces[6] != playerCharacter && spaces[8] != playerCharacter){
                                if (z == 3){
                                    spaces[0] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (z == 4){
                                    spaces[8] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (spaces[4] != playerCharacter) if (z == 5){
                                    spaces[6] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                            }
                            if (r == 6 && spaces[0] != playerCharacter && spaces[2] != playerCharacter && spaces[8] != playerCharacter){
                                if (z == 6){
                                    spaces[0] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (z == 7){
                                    spaces[8] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (spaces[4] != playerCharacter) if (z == 8){
                                    spaces[2] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                            }
                            if (r == 8 && spaces[0] != playerCharacter && spaces[2] != playerCharacter && spaces[6] != playerCharacter){
                                if (z == 9){
                                    spaces[2] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (z == 10){
                                    spaces[6] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                                if (spaces[4] != playerCharacter) if (z == 11){
                                    spaces[0] = computerCharacter;
                                    validSpace = true;
                                    finished = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        validSpace = false;
    }
    return 0;
}
