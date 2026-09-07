#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int userChoice = 0;
    int computerChoice = 0;

    cout << "=================================\n";
    cout << "  Rock, Paper, Scissors Game!    \n";
    cout << "=================================\n";
    cout << "1) Rock\n";
    cout << "2) Paper\n";
    cout << "3) Scissors\n";
    cout << "Choose your move (1-3): ";
    cin >> userChoice;

    if (userChoice < 1 || userChoice > 3) {
        cout << "Invalid choice! Please restart the game and choose between 1 and 3.\n";
        return 0;
    }

    computerChoice = (rand() % 3) + 1;

    cout << "\nYou chose: ";
    if (userChoice == 1) cout << "Rock\n";
    else if (userChoice == 2) cout << "Paper\n";
    else cout << "Scissors\n";

    cout << "Computer chose: ";
    if (computerChoice == 1) cout << "Rock\n";
    else if (computerChoice == 2) cout << "Paper\n";
    else cout << "Scissors\n";

    cout << "---------------------------------\n";

    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } 
    else if ((userChoice == 1 && computerChoice == 3) || 
             (userChoice == 2 && computerChoice == 1) || 
             (userChoice == 3 && computerChoice == 2)) {
        cout << "You win! Congratulations!\n";
    } 
    else {
        cout << "Computer wins! Better luck next time.\n";
    }

    cout << "=================================\n";

    return 0;
}
