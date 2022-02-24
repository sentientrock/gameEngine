#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::string;

char askUser(string question) {
    cout << question << "? (yes or no)\n";
    string answer = "";
    cin >> answer;
    if (answer == "y" || answer == "yes") return 'y';
    if (answer == "n" || answer == "no") return 'n';
    return 'b';
}

int main() {
    std::vector<std::string> philosophers = {"Kant", "Heidegger", "Plato", "Hume", "Spinoza"};
    philosophers[3] = "Deleuze";

    srand(std::time(nullptr));
    int random = std::rand() % 5;

    string q = "The philosopher who authored the Critique of Pure Reason is " + philosophers[random];
    char ans = askUser(q);
    
    while (true) {
        if (random == 0 && ans == 'y') {cout << "Correct!"; break;}
        else if (random != 0 && ans == 'n') {cout << "Correct!"; break;}
        else if (ans == 'b') {
            cout << "Please enter a valid answer.";
            ans = askUser(q);
        }
        else {cout << "Wrong!"; break;}
    }
    return 0;
 }