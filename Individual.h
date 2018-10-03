# if !defined(__INDIVIDUAL_H__)
# define __INDIVIDUAL_H__

#include<string>

/**Constant Variables**/
//GENES is a set of all possibile characters in a chromosome
const std::string GENES = "abcdefghijklmnopqrstuvwxyz .,!:;?/";
//TARGET is the target chromosome to be generated
const std::string TARGET = "this is a genetic algorithm!";

class Individual
{
public:
  /**Class Functions**/
  //Constructor that takes parameter of a chromosome
  Individual(std::string c);
  //Function to produce a child with current Individual and otherParent as parents
  Individual mate(Individual* otherParent);
  //Function to calculate fitness score of current Individual
  int calcFitness();
  //Function to return fitness score of current Individual
  int getFitness() const;
  //Function to return chromosome of current individual
  std::string getChromosome() const;

private:
  /**Class Variables**/
  //chromosome is the current sequence of characters of genes
  std::string chromosome;
  //fitness is the score based on similarity to TARGET
  int fitness;
};

# endif
