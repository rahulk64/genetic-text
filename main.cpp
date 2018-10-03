#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Individual.cpp"

using namespace std;

#define POPULATION_SIZE 10
//Target String in Individual.h

string generateChromosome();

int main()
{
  
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
