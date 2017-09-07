/*
  Ben Nagel
  u0806348
  A1: C++ Starter
  August 27, 2017
*/

#include <iostream>

using namespace std;

void updatePopulation(double g, double p, double c,
                      double m, double K, double& numRabbits,
                      double& numFoxes);
void plotCharacter(int num, char character);
void chartValues(double numOfRabbits, double numOfFoxes, double scale);
void incrementCounter(int* counter);

// Equation Constants
const double rabbitGrowth = .02;
const double predationRate = .0002;
const double foxPreyConversion = .6;
const double foxMortalityRate = .2;
const double carryCapacity = 1000.0;



int main(){
  /**
    Contains the main logic of program to plot Fox populations
    vs rabbit populations over time
   */
  double numOfRabbits;
  double numOfFoxes;

  cout << "Enter starting number of Foxes and then Rabbits" << endl;

  int counter;
  // If input sucessfully fills vars
  if(cin >> numOfFoxes >> numOfRabbits){

    for (counter = 0; counter <= 500;){
      if(numOfRabbits <=  0 || numOfFoxes <= 0){
        cout << "Population is Extinct\n";
        return 0;
      }
      else {
        chartValues(numOfRabbits, numOfFoxes, 0.1);
        updatePopulation(rabbitGrowth, carryCapacity,  predationRate,
                       foxMortalityRate, foxPreyConversion, numOfRabbits,
                       numOfFoxes);

        incrementCounter(&counter);
    }
  }
}
 else {
   cout << "Input Must be doubles" << endl;
   return 0;
   }
}


void incrementCounter(int* counter){
   /** Increments a counter and returns  */
   ++*counter;
}

void plotCharacter(int num, char character){
  /**
     Plots a character a certain number of spaces away
     param: num: Number of spaces to be plotted
     param: character: 'char' representation of what is plotted
   */
  int spaces;
  for(spaces = 0; spaces < num; spaces++){
    cout << " ";
  }
  cout << character << '\n';
}

void updatePopulation(double g, double p, double c,
                      double m, double K, double& numOfRabbits,
                      double& numOfFoxes){
  /**
     Updates the population of foxes and rabbits

     param: g: rabbit growth
     param: p: predation rate
     param: c: fox prey converson
     param: m: fox mortality rate
     param: K: carry capacity
     param: numOfRabbits: number of rabbits
     param: numOfFoxes: number of foxes
  */
  double deltaRabbit;
  double deltaFoxes;

  deltaRabbit = g * numOfRabbits * (1 - numOfRabbits / K) -
                p * numOfRabbits * numOfFoxes;
  deltaFoxes = c * p * numOfRabbits * numOfFoxes - (m * numOfFoxes);

  numOfRabbits = numOfRabbits + deltaRabbit;
  numOfFoxes = numOfFoxes + deltaFoxes;
  return;
}

void chartValues(double numOfRabbits, double numOfFoxes, double scale){
  /**
      Charting function that charts foxes / rabbit population to scale
      with 'r' representing rabbits and 'F' representing foxes

      param: numOfRabbits: Number of Rabbits
      param: numOfFoxes: Number of Foxes
      param: scale: Fractional Scale (0-1)
   */
  int rabbits;
  int foxes;

  rabbits = (int)(numOfRabbits * scale);
  foxes = (int)(numOfFoxes * scale);

  if(rabbits > foxes){
    plotCharacter(foxes, 'F');
    plotCharacter(rabbits, 'r');
  }
  else if (foxes > rabbits){
    plotCharacter(rabbits, 'r');
    plotCharacter(foxes, 'F');
  }
  else {
    plotCharacter(foxes, '*');
  }
  cout << endl;
}
