#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"Individual.cpp"

using namespace std;

#define POPULATION_SIZE 100
//Target String in Individual.h

string generateChromosome();
void printVector(vector<Individual> population);

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
  vector<Individual> population;
  vector<Individual> newGeneration;
  bool match = false;
  int generation = 1;

  for(int i = 0; i < POPULATION_SIZE; i++)
  {
    Individual curr(generateChromosome());
    population.push_back(curr);
  }

  while(!match)
  {
    cout << "Starting Generation " << generation << ":" << endl;
    //sorts based on fitness
    sort(population.begin(), population.end(), descending());

    cout << "Highest Fitness: " << population[0].getChromosome();
    cout << " score = " << population[0].getFitness() << endl;

    //10% fittest population moves on to next generation
    int s = (10*POPULATION_SIZE)/100;
    for(int i = 0; i < s; i++)
    {
      newGeneration.push_back(population[i]);
    }

    //breeding
    s = (90*POPULATION_SIZE)/100;
    for(int i = 0; i < s; i+=2)
    {
      Individual* parent1 = &population[i];
      Individual* parent2 = &population[i+1];
      Individual child = parent1->mate(parent2);

      //cout << "Child Born: " << child.getChromosome() << endl;

      newGeneration.push_back(child);
    }

    //checks if match; if not, destroy 50% of current population
    for(int i = 0; i < newGeneration.size(); i++)
    {
      if(newGeneration[i].getFitness() == TARGET.size())
      {
        cout << "Found at Gen " << generation << ": " << newGeneration[i].getChromosome() << endl;
        match = true;
        break;
      }
    }

    population = newGeneration;
    generation++;

  }

  return 0;
}

string generateChromosome()
{
  string chromosome = "";
  for(int i = 0; i < TARGET.size(); i++)
  {
    chromosome += makeMutation();
  }

  return chromosome;
}

//TESTER Method
void printVector(vector<Individual> population)
{
  for(int i = 0; i < POPULATION_SIZE; i++) {
    cout << i << ": " << population[i].getChromosome() << " , " << population[i].getFitness() << endl;
  }
}
