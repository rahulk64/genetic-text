#include<string>
#include<cstdlib> //srand random number generation
#include<ctime>   // time random number generation
#include"Individual.h"

/**Helper Methods for Class Implementation**/
//Generates a random integer in the range [s, e)
int generateRandom(int s, int e)
{
  srand(time(NULL));
  int r = rand()%(e-s+1);
  return s + r;
}

//Generates a random character as a "mutation" from a set of genes
char makeMutation()
{
  int r = generateRandom(0, GENES.size()-1);
  return GENES[r];
}

/**Class Implementation Methods**/
//Constructor for Individual Class
Individual::Individual(string c)
{
  this->chromosome = c;
  fitness = calcFitness();
}

//Mates current Individual and otherParent to produce an offspring
//with a combination of the parent's chromosome
Individual Individual::mate(Individual otherParent)
{
  string childChromosome = "";
  for(int i = 0; i < chromosome.size(); i++)
  {
    int r = generateRandom(0, 100);
    double p = (double)r/100.0;

    //45% chance inherits from current Individual
    if(p < 0.45)
    {
      childChromosome += this->chromosome[i];
    }
    //45% chance inherits from other parent
    else if(p < 0.9)
    {
      childChromosome += otherParent[i];
    }
    //10% chance random mutation
    else
    {
      childChromosome += makeMutation();
    }
  }

  return Individual(childChromosome);
}

//Method to calculate fitness of a given Individual
//Calculated based on individual equality of characters
int Individual::calcFitness()
{
  int count = 0;
  for(int i = 0; i < this->chromosome.size(); i++)
  {
    //Fitness calculated on individual character equality
    if(this->chromosome[i] == TARGET[i])
    {
      count++;
    }
  }

  return count;
}
