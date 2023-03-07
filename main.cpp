#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   cout << "Entrez une expression +,*,(,),int"<<endl;
   string chaine;
   cin >> chaine;
   Automate * a = new Automate(chaine);

   return 0;
}

