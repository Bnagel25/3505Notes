//
//  EcoSim.cpp
//  Assignment 1
//  Simulates the population of rabbits and foxes.
//  Created by Nick Porter on 8/25/16. u0927946

#include <iostream>
#include <math.h>

using namespace std;

void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes);
void chartPopulations(double rabbitPop, double foxPop, double scaleFactor);
void plotCharacter(int spaces, char letter);
void incrementCounter(int *count);

int main(int argc, const char * argv[]) {

    // Init parameters
    double rabbitGrowth = 0.2;
    double predationRate = 0.002;
    double foxPreyConversion = 0.6;
    double foxMortalityRate = 0.2;
    double carryCapacity = 1000;

    // Prompt user for input
    double rabbitPop = 0;
    double foxPop = 0;

    cout << "Please enter an inital rabbit and fox population ";

    if (!(cin >> rabbitPop && cin >> foxPop)) {
        cout << "Invalid population(s), terminating. ";
        return 0;
    }

    // Begin simulation
    int count = 0;
    while(count < 500 && rabbitPop > 0 && foxPop > 0 ) {
        chartPopulations(rabbitPop, foxPop, 0.1);
        updatePopulations(rabbitGrowth, carryCapacity, predationRate, foxMortalityRate, foxPreyConversion, rabbitPop, foxPop);
        incrementCounter(&count);
    }

    return 0;
}

// Updates the delta's for both the rabbit and the fox
void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes)
{
    double deltaRabbit = g * numRabbits * (1 - numRabbits / K) - p * numRabbits * numFoxes;
    double deltaFox = c * p * numRabbits * numFoxes - (m * numFoxes);

    numRabbits += deltaRabbit;
    numFoxes += deltaFox;
}

// Plots the populations of the animals in standard out
void chartPopulations(double rabbitPop, double foxPop, double scaleFactor) {

    if (rabbitPop - foxPop == 0) {
        plotCharacter(floor(rabbitPop * scaleFactor), '*');
    } else if(rabbitPop < foxPop) {
        plotCharacter(floor(rabbitPop * scaleFactor), 'r');
        plotCharacter(floor(foxPop * scaleFactor) - floor(rabbitPop * scaleFactor), 'F');
    } else {
        plotCharacter(floor(foxPop * scaleFactor), 'F');
        plotCharacter(floor(rabbitPop * scaleFactor) - floor(foxPop * scaleFactor), 'r');
    }

    cout << endl;
}

// Prints the letter n(spaces) from the left
void plotCharacter(int spaces, char letter) {

    for(int i = 0; i < spaces - 1; i++ ) {
        cout << " ";
    }
    cout << letter;
}

// Takes a pointer to an int and incremnts it by one
void incrementCounter(int *count) {
    ++*count;
}
