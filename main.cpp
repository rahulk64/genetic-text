#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"Individual.cpp"

using namespace std;

#define POPULATION_SIZE 10
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

    cout << "Highest Fitness: " << population[0].getChromosome() << endl;

    //breeding
    int pop = population.size();
    for(int i = 0; i < pop; i+=2)
    {
      Individual* parent1 = &population[i];
      Individual* parent2 = &population[i+1];
      Individual child = parent1->mate(parent2);

      //cout << "Child Born: " << child.getChromosome() << endl;

      population.push_back(child);
    }

    //checks if match; if not, destroy 50% of current population
    for(int i = population.size()/8; i < population.size(); i++)
    {
      if(population[i].getChromosome() == TARGET)
      {
        cout << "Found at Gen " << generation << ": " << population[i].getChromosome() << endl;
        match = true;
        break;
      }

      double kill = (double)generateRandom(0, 100)/100.0;
      if(kill <= 0.5)
      {
        population.erase(population.begin() + i);
      }
    }

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
