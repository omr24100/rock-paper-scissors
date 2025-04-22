// rock, paper, scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File Name: Rock, paper, scissors
Programmer: Olivia Ruiz
Date: 4/22/25
Requirements: Write a program that makes a game of rock, paper, scissors. 
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>
#include <algorithm> 

using namespace std;


string getComputerChoice();
string getUserChoice();
string determineWinner(string userChoice, string computerChoice);

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    string userChoice, computerChoice, result;

    do {
        computerChoice = getComputerChoice();
        userChoice = getUserChoice();

        cout << "Computer chose: " << computerChoice << endl;

        result = determineWinner(userChoice, computerChoice);

        if (result == "tie") {
            cout << "It's a tie! Let's play again.\n" << endl;
        }
    } while (result == "tie");

    cout << result << " wins the game!" << endl;

    return 0;
}


string getComputerChoice() {
    int num = rand() % 3 + 1;

    switch (num) {
    case 1: return "rock";
    case 2: return "paper";
    case 3: return "scissors";
    default: return "rock"; 
    }
}


string getUserChoice() {
    string choice;
    while (true) {
        cout << "Enter your choice (rock, paper, scissors): ";
        cin >> choice;

       
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "rock" || choice == "paper" || choice == "scissors") {
            return choice;
        }
        else {
            cout << "Invalid input. Please enter rock, paper, or scissors.\n";
        }
    }
}


string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }

    if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "User";
    }
    else {
        return "Computer";
    }
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
