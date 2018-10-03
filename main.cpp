#include<iostream>
#include<vector>
#include<string>
#include"Individual.cpp"

using namespace std;

#define POPULATION_SIZE 10
//Target String in Individual.h

string generateChromosome();

int main()
{
  vector<pair<Individual,int>> population;

  for(int i = 0; i < POPULATION_SIZE; i++)
  {
    Individual curr(generateChromosome());
    population.push_back(make_pair(curr, curr.getFitness()));
  }

  for(int i = 0; i < POPULATION_SIZE; i++) {
    cout << i << ": " << population[i].first.getChromosome() << " , " << population[i].second << endl;
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
