#pragma once
#include <string>
#include "symbole.h"
#include "lexer.h"
#include <vector>

class Etat;
using namespace std;

class Automate{
   public:
      Automate(string chaine);
      ~Automate() { }
      void decalage(Symbole * s, Etat * e);
      void reduction(int n, Symbole * s);
      Symbole* popSymbol();
      void popAndDestroySymbol();
   protected:
      vector <Symbole*> pileSymbole;
      vector <Etat*> pileEtat;
      Lexer * lexer;
      string chaine;
};