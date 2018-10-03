class Individual
{
public:
  /**Constant Variables**/
  //GENES is a set of all possibile characters in a chromosome
  const string GENES = "abcdefghijklmnopqrstuvwxyz .,!:;?/";
  //TARGET is the target chromosome to be generated
  const string TARGET = "this is a genetic algorithm!";

  /**Class Variables**/
  //chromosome is the current sequence of characters of genes
  string chromosome;
  //fitness is the score based on similarity to TARGET
  int fitness;

  /**Class Functions**/
  //Constructor that takes parameter of a chromosome
  Individual(string c);
  //Function to produce a child with current Individual and otherParent as parents
  Individual mate(Individual otherParent);
  //Function to calculate fitness score of current Individual
  int calcFitness();
}
