#include "symbole.h"
#include <iostream>
#include <string>

string Symbole::Affiche() {
   return(Etiquettes[ident]);
}

string Entier::Affiche() {
   
   return(Symbole::Affiche()+"("+std::to_string(valeur)+")");
}

double Expr::eval(){
   return valeur;
}

string Expr::Affiche() {
   return(Symbole::Affiche()+"("+std::to_string(valeur)+")");
}
