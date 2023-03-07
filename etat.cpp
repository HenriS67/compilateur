#include "etat.h"
#include <iostream>

string Etat::Affiche() {
   return("("+name+")");
}

bool E0::transition(Automate &a, Symbole * s) {
    switch(*s) {
        case OPENPAR:
            a.decalage(s, new E2());
            break;

        case INT:
            a.decalage(s, new E3());
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        case EXPR:
            a.decalage(s, new E1());
            break;

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E1::transition(Automate &a, Symbole * s) {
    switch(*s) {

        case PLUS:
            a.decalage(s, new E4());
            break;

        case MULT:
            a.decalage(s, new E5());
            break;

        case FIN:
            cout << "on passe dedans" << endl;
            //return true;
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E2::transition(Automate &a, Symbole * s) {
    switch(*s) {
        case OPENPAR:
            a.decalage(s, new E2());
            break;

        case INT:
            a.decalage(s, new E3());
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        case EXPR:
            a.decalage(s, new E6());
            break;

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E3::transition(Automate &a, Symbole * s) {
    Expr * s1;
    switch(*s) {

        case CLOSEPAR:
            s1 = (Expr*) a.popSymbol();
            a.reduction(1, new Expr(s1->eval()));
            break;

        case PLUS:
            s1 = (Expr*) a.popSymbol();
            a.reduction(1, new Expr(s1->eval()));
            break;

        case MULT:
            s1 = (Expr*) a.popSymbol();
            a.reduction(1, new Expr(s1->eval()));
            break;

        case FIN:
            s1 = (Expr*) a.popSymbol();
            a.reduction(1, new Expr(s1->eval()));
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E4::transition(Automate &a, Symbole * s) {
    switch(*s) {
        case OPENPAR:
            a.decalage(s, new E2());
            break;

        case INT:
            a.decalage(s, new E3());
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        case EXPR:
            a.decalage(s, new E7());
            break;

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E5::transition(Automate &a, Symbole * s) {
    switch(*s) {
        case OPENPAR:
            a.decalage(s, new E2());
            break;

        case INT:
            a.decalage(s, new E3());
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        case EXPR:
            a.decalage(s, new E8());
            break;

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E6::transition(Automate &a, Symbole * s) {
    switch(*s) {

        case CLOSEPAR:
            a.decalage(s, new E9());
            break;

        case PLUS:
            a.decalage(s, new E4());
            break;

        case MULT:
            a.decalage(s, new E5());
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E7::transition(Automate &a, Symbole * s) {
    Expr * s1;
    Expr * s2;
    switch(*s) {

        case CLOSEPAR:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() + s1->eval()));
            break;

        case PLUS:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() + s1->eval()));
            break;

        case MULT:
            a.decalage(s, new E5());
            break;

        case FIN:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() + s1->eval()));
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E8::transition(Automate &a, Symbole * s) {
    Expr * s1;
    Expr * s2;
    switch(*s) {

        case CLOSEPAR:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() * s1->eval()));
            break;

        case PLUS:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() * s1->eval()));
            break;

        case MULT:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() * s1->eval()));
            break;

        case FIN:
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            s2 = (Expr*) a.popSymbol();
            a.reduction(3,new Expr(s2->eval() * s1->eval()));
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}

bool E9::transition(Automate &a, Symbole * s) {
    Expr * s1;;
    switch(*s) {

        case CLOSEPAR:
            a.popAndDestroySymbol();
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3,new Expr(s1->eval()));
            break;

        case PLUS:
            a.popAndDestroySymbol();
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3,new Expr(s1->eval()));
            break;

        case MULT:
            a.popAndDestroySymbol();
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3,new Expr(s1->eval()));
            break;

        case FIN:
            a.popAndDestroySymbol();
            s1 = (Expr*) a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3,new Expr(s1->eval()));
            break;

        case ERREUR:
            cout<<"terme invalide"<<endl;
            exit(EXIT_FAILURE);

        default:
            cout<<"expression invalide"<<endl;
            exit(EXIT_FAILURE);
    }
    return false;
}