#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXPR, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "EXPR", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int v):Symbole(EXPR), valeur(v) {}
      virtual ~Expr() {}
      double eval();
      void Affiche();
   protected:
      int valeur;
};


/*
class ExprCste : public Expr {
   public:
      ExprCste(int v):Expr() {
         valeur = v;
      }
      virtual ~ExprCste() {}
      double eval();
      virtual void Affiche();
   protected:
      int valeur;
};

class ExprBinaire : public Expr {
   public:
      ExprBinaire(Expr* s1,Expr* s2):Expr() {
         expr1=s1;
         expr2=s2;
      }
      virtual ~ExprBinaire() {}
      virtual double eval()=0;
      virtual void Affiche();
   protected:
      Expr expr1;
      Expr expr2;
};

class ExprPlus : public ExprBinaire {
   public:
      ExprPlus(Expr* s1,Expr* s2):ExprBinaire(s1,s2){}
      virtual ~ExprBinaire() {}
      double eval();
      virtual void Affiche();
   protected:
      Expr expr1;
      Expr expr2;
};

class ExprMult : public ExprBinaire {
   public:
      ExprMult(Expr* s1,Expr* s2):ExprBinaire(s1,s2){}
      virtual ~ExprBinaire() {}
      double eval();
      virtual void Affiche();
   protected:
      Expr expr1;
      Expr expr2;
};
*/