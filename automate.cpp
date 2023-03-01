#include <iostream>
#include "automate.h"
#include "etat.h"
#include "symbole.h"
#include "lexer.h"

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymbole.push_back(s);
    pileEtat.push_back(e);
    //if (s->isTerminal()) {
        lexer->Avancer();
    //}
}
Automate::Automate(string ch){
    chaine = ch;
    pileEtat.push_back(new E0());
    lexer = new Lexer(chaine);
    Symbole * s;

    while(*(s = lexer->Consulter()) != FIN ) {
        s->Affiche();
        cout << endl;
        pileEtat.back()->transition(*this,s);
        for (int i = 0; i < pileEtat.size(); i++) {
            pileEtat[i]->Affiche();
        }
        cout << endl;

        for (int i = 0; i < pileSymbole.size(); i++) {
            pileSymbole[i]->Affiche();
        }
        cout << endl;

        lexer->Avancer();
    }

    while(pileSymbole.size() != 1) {
        s->Affiche();
        cout << endl;
        pileEtat.back()->transition(*this,s);
        for (int i = 0; i < pileEtat.size(); i++) {
            pileEtat[i]->Affiche();
        }
        cout << endl;

        for (int i = 0; i < pileSymbole.size(); i++) {
            pileSymbole[i]->Affiche();
        }
        cout << endl;

        lexer->Avancer();
    }
}

void Automate::reduction(int n,Symbole * s) {
    lexer->Reculer();
    cout << "Reduction" << endl;
    for (int i=0;i<n;i++)
    {
        delete(pileEtat.back());
        pileEtat.pop_back();
    }
    cout << "Symbole ";
    s->Affiche();
    pileEtat.back()-> Affiche();
    cout << endl;
    pileEtat.back()->transition(*this,s);
}

Symbole* Automate::popSymbol() {
    Symbole* s1=pileSymbole.back();
    pileSymbole.pop_back();
    return s1;
}

void Automate::popAndDestroySymbol() {
    delete(pileSymbole.back());
    pileSymbole.pop_back();
}