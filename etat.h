#pragma once
#include <string>
#include "automate.h"
#include "symbole.h"
using namespace std;

class Etat {
    public:
        Etat() { }
        virtual ~Etat() { }
        virtual bool transition(Automate &a, Symbole * s)=0;
        string Affiche();
    protected:
        string name;
};

class E0 : public Etat {
    public:
        E0() { name = "E0"; }
        ~E0() { }
        bool transition(Automate &a, Symbole * s);
};

class E1 : public Etat {
    public:
        E1() { name = "E1"; }
        ~E1() { }
        bool transition(Automate &a, Symbole * s);
};

class E2 : public Etat {
    public:
        E2() { name = "E2"; }
        ~E2() { }
        bool transition(Automate &a, Symbole * s);
};

class E3 : public Etat {
    public:
        E3() { name = "E3"; }
        ~E3() { }
        bool transition(Automate &a, Symbole * s);
};

class E4 : public Etat {
    public:
        E4() { name = "E4"; }
        ~E4() { }
        bool transition(Automate &a, Symbole * s);
};

class E5 : public Etat {
    public:
        E5() { name = "E5"; }
        ~E5() { }
        bool transition(Automate &a, Symbole * s);
};

class E6 : public Etat {
    public:
        E6() { name = "E6"; }
        ~E6() { }
        bool transition(Automate &a, Symbole * s);
};

class E7 : public Etat {
    public:
        E7() { name = "E7"; }
        ~E7() { }
        bool transition(Automate &a, Symbole * s);
};

class E8 : public Etat {
    public:
        E8() { name = "E8"; }
        ~E8() { }
        bool transition(Automate &a, Symbole * s);
};

class E9 : public Etat {
    public:
        E9() { name = "E9"; }
        ~E9() { }
        bool transition(Automate &a, Symbole * s);
};

