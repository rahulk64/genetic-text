class Individual
{
public:
  const string GENES = "abcdefghijklmnopqrstuvwxyz .,!:;?/";
  const string TARGET = "this is a genetic algorithm!";

  string chromosome;
  int fitness;
  Individual(string c);
  Individual mate(Individual otherParent);
  int calcFitness();
}
