/***
# Author: Gagandeep Bhatia
# Assignment: Assignment #9 - Grade Calculator w pass by ref
# Date: December 2, 2023
# Description: This is a program using function modularity with pass by
reference variables to calculate a user’s grade for the class. Calculate
assignment scores from the user (60%) and calculate midterm and final exam
scores (20% each).
# Input: num_assignments, num, score, midterm and last
# Output: numerical and letter
# Sources: Assignment #9 - Grade Calculator Document
***/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// Constants
const double MID = 0.2;
const double FINAL = 0.2;
const double WEIGHT = 0.6;

// Function Prototypes
void welcome();
int readInt(string prompt);
void readscore(string prompt, double& num);
double assignAverage(int num_assignments);
void getInput(double& midterm, double& last);
double calcFinalScore(double assignavg, double last, double midterm);
void calcLetterGrade(double ovravg, char& letter);

int main() {
    // Variables
    int num_assignments = 0;
    char letter = ' ';
    double average = 0.0;
    double midterm = 0.0;
    double last = 0.0;
    double numerical = 0.0;

    // Function calls and output
    welcome();
    num_assignments = readInt("\nEnter the number of assignments (0 to 10): ");
    average = assignAverage(num_assignments);
    getInput(midterm, last);
    numerical = calcFinalScore(average, last, midterm);
    calcLetterGrade(numerical, letter);

    cout << "\nYour Final Numerical score is " << fixed << setprecision(1)
        << numerical << endl;
    cout << "Your Final Grade is " << letter << endl;

    // Thank you message
    cout << "\nThank you for using my Grade Calculator!" << endl;

    return 0;
}
// Welcome function
void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "\nPlease enter the following information and I will calculate your"
        << "\nFinal Numerical Grade and Letter Grade for you!" << endl;
    cout << "\nThe number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

// Function to read num_assignments
int readInt(string prompt) {
    int num_assignments = 0;
    cout << prompt;
    cin >> num_assignments;
    while (cin.fail() || num_assignments < 0 || num_assignments > 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again!!" << endl;
        cout << prompt;
        cin >> num_assignments;
    }
    return num_assignments;
}

// Function to read in assignment scores
void readscore(string prompt, double& num) {
    cout << prompt;
    cin >> num;
    while (cin.fail() || num < 0 || num > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid score! Please try again!" << endl;
        cout << prompt;
        cin >> num;
    }
}

// Function works hand in hand with readscore() to read in each score, then finds the average score of all assignments
double assignAverage(int num_assignments) {
    double scorecount = 0.0;
    double assignavg = 0.0;
    double score = 0.0;
    for (int i = 0; i < num_assignments; ++i) {
        readscore("Enter score " + to_string(i + 1) + ": ", score);
        scorecount += score;
    }
    assignavg = scorecount / num_assignments;
    return assignavg;
}

// Reads in midterm and final exam scores
void getInput(double& midterm, double& last) {
    readscore("\nEnter your midterm exam score: ", midterm);
    readscore("Enter your final exam score: ", last);
}

// Function calculates final overall score/average
double calcFinalScore(double assignavg, double midterm, double last) {
    double ovravg = 0.0;
    ovravg = (assignavg * WEIGHT) + (midterm * MID) + (last * FINAL);
    return ovravg;
}

// Function calculates/returns letter grade
void calcLetterGrade(double ovravg, char& letter) {
    if (ovravg >= 3.3) {
        letter = 'A';
    }
    else if (ovravg >= 2.8 && ovravg < 3.3) {
        letter = 'B';
    }
    else if (ovravg >= 2.0 && ovravg < 2.8) {
        letter = 'C';
    }
    else if (ovravg >= 1.2 && ovravg < 2.0) {
        letter = 'D';
    }
    else {
        letter = 'F';
    }
}