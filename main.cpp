#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

#include "Cuier.h"
#include "Sala.h"
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"


class Baza {
private: // (1)
protected:
    int x;
    void f() const { std::cout << "f" << x << "\n"; }

public:
    Baza(const Baza &other)
        : x(other.x) {
        std::cout << "Constructor copiere Baza: " << x << "\n";
        f();
    }

    Baza &operator=(const Baza &other) {
        if (this == &other)
            return *this;
        x = other.x;
        return *this;
    }

    explicit Baza(int x_) : x(x_) {
        std::cout << "Constructor Bază: " << x << "\n";
        f();
    }

    void g() {
        std::cout << "g\n";
        x++;
    }
};

class Derivata : protected Baza {
    int y{};

public:
    Derivata(const Derivata &other)
        : Baza(other),
          y(other.y) {
        std::cout << "Constr copiere Derivata: " << y << "\n";
    }

    Derivata &operator=(const Derivata &other) {
        if (this == &other)
            return *this;
        Baza::operator =(other);
        y = other.y;
        return *this;
    }

    Derivata() : Baza(1) {
        std::cout << "Constructor 1 Derivată: " << x << "\n";
        f();
    }

    explicit Derivata(int y)
        : Baza(2), y(y) {
    }
    static void f2() {
        std::cout << "f2\n";
    }
};

class Derivata2 : public Derivata {
    int k = 2;
    int abc = 5;

public:
    Derivata2(int y, int k, int abc)
        : Derivata(y),
          k(k),
          abc(abc) {
    }

    Derivata2(const Derivata2 &other)
        : Derivata(other) {
    }

    explicit Derivata2(const Derivata &other)
        : Derivata(other) {
    }

    explicit Derivata2(int y)
        : Derivata(y) {
    }

    Derivata2 &operator=(const Derivata2 &other) {
        if (this == &other)
            return *this;
        Derivata::operator =(other);
        this->k = other.k;
        this->abc = other.abc;
        std::cout << "operator= Derivata2 " << x << "\n";
        return *this;
    }

    Derivata2() : Derivata() {
        std::cout << "Constructor 1 Derivată2: " << x << "\n";
        f();
    }
};

class curs {
    std::string prof;
    int nr = 10;

public:
    explicit curs(std::string prof_) : prof(std::move(prof_)) { std::cout << "constructor curs: " << prof << "\n"; }

    curs(std::string prof_, int nr_) : prof(std::move(prof_)), nr(nr_) {
        std::cout << "constructor curs: " << prof << "\n";
    }

    curs(int nr_, std::string prof_) : prof(std::move(prof_)), nr(nr_) {
        std::cout << "constructor curs: " << prof << " " << nr << "\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const curs &c) {
        os << "curs: " << c.prof << " " << c.nr << "\n";
        return os;
    }
};


class curs_obligatoriu : public curs {
    using curs::curs;
};

int main() {
    curs_obligatoriu oop{"test"};
    Baza b(2);
    Derivata d;
    b.g();
    d.f2();
    Cuier c1{2, 2}, c2{4, 3}, c4 = c2;
    std::cout << c1 << c2 << c4 << c1.get_nr_haine() << c2.get_nr_haine() << c4.get_nr_haine() << "\n";
    c4.adauga_haine();
    // c4 = c2;
    // c4.operator=(c1);
    std::cout << "inainte de c3\n"; {
        std::cout << "inainte de c3 in bloc\n";
        Cuier c3{1, 1};
        std::cout << "dupa c3 in bloc\n";
    }
    std::cout << "dupa c3\n";
    Sala sala109{c1};
    Sala s107{{}, 2, 3, c1};
    sala109.set_grup_lumina({});
    sala109.set_numar(109);
    // sala109.set_zgomot(50);
    Sala sala106{c2};
    c1 = c2;
    sala106.set_grup_lumina({});
    sala106.set_numar(106);
    sala106.set_zgomot(70);
    std::cout << c1.get_nr_haine();

    std::cout << "\nHello, 1311 la 8 dimineata din terminal!!\n";
    Example e1;
    e1.g();

    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
