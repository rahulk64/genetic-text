#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"Individual.cpp"

using namespace std;

//POPULATION_SIZE defines the population size across all generations
#define POPULATION_SIZE 1000
//Target String in Individual.h

/**Function Prototypes**/
string generateChromosome(); //creates a random chromosome
void printVector(vector<Individual> population); //unit testing function to print a vector

//for sorting in descending order
struct descending
{
  template<class T>
  bool operator()(T const &a, T const &b)
  {
    return a > b;
  }
};

int main()
{
  //defines current population and next generation
  vector<Individual> population;
  vector<Individual> newGeneration;
  bool match = false; //exit loop condition: !match
  int generation = 1; //the generation counter

  //Create a population of size POPULATION_SIZE with randomly-created chromosomes
  for(int i = 0; i < POPULATION_SIZE; i++)
  {
    Individual curr(generateChromosome());
    population.push_back(curr);
  }

  //Loop until there is a matching chromosome
  while(!match)
  {
    cout << "Starting Generation " << generation << ":" << endl;

    //sorts based on fitness
    sort(population.begin(), population.end(), descending());

    cout << "Highest Fitness: " << population[0].getChromosome();
    cout << " | score = " << population[0].getFitness() << endl;

    //10% fittest population moves on to next generation
    int s = (10*POPULATION_SIZE)/100;
    for(int i = 0; i < s; i++)
    {
      newGeneration.push_back(population[i]);
    }

    //Take the top 90% fit individuals and breed them randomly for new generation
    s = (90*POPULATION_SIZE)/100;
    for(int i = 0; i < s; i++)
    {
      int random = generateRandom(0, 20);
      Individual* parent1 = &population[i];
      Individual* parent2 = &population[random];
      Individual child = parent1->mate(parent2);

      newGeneration.push_back(child);
    }

    //checks if match
    for(int i = 0; i < newGeneration.size(); i++)
    {
      if(newGeneration[i].getFitness() == TARGET.size())
      {
        cout << "Found at Gen " << generation << ": " << newGeneration[i].getChromosome() << endl;
        match = true;
        break;
      }
    }

    //update new population
    population = newGeneration;
    newGeneration.clear();
    generation++;

  }

  return 0;
}

//generateChromosome() creates a string of characters randomly pooled from
//the GENES constant string to generate a chromosome
string generateChromosome()
{
  string chromosome = "";
  for(int i = 0; i < TARGET.size(); i++)
  {
    chromosome += makeMutation();
  }

  return chromosome;
}

//UNIT TESTER FUNCTION to print a vector
void printVector(vector<Individual> population)
{
  for(int i = 0; i < POPULATION_SIZE; i++) {
    cout << i << ": " << population[i].getChromosome() << " , " << population[i].getFitness() << endl;
  }
}
