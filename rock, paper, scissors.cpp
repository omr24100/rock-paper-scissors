// rock, paper, scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File Name: Rock, paper, scissors
Programmer: Olivia Ruiz
Date: 4/25/25
Requirements: Write a program that makes a game of rock, paper, scissors. 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm> // For transform()

using namespace std;

string getComputerChoice() {
    int choice = rand() % 3;
    switch (choice) {
        case 0: return "rock";
        case 1: return "paper";
        default: return "scissors";
    }
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) return "It's a tie!";
    if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "paper" && computerChoice == "rock") ||
        (userChoice == "scissors" && computerChoice == "paper")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0)); 
    string playerName;
    string doAgain = "yes";
    int winCount = 0;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your name: ";
    getline(cin, playerName);

    while (doAgain != "no") {
        string userChoice;
        cout << "\n" << playerName << ", enter your choice (rock, paper, or scissors): ";
        cin >> userChoice;

     
        transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

        // Input validation
        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        if (result == "You win!") {
            winCount++;
        }

        cout << "Do you want to play again? (yes/no): ";
        cin >> doAgain;
        transform(doAgain.begin(), doAgain.end(), doAgain.begin(), ::tolower);
    }

    cout << "\nThanks for playing, " << playerName << "! You won " << winCount << " time(s)." << endl;

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
