#include <iostream>
#include <array>
#include <ostream>
#include <vector>

#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"

class PanouIluminare {
    bool aprins;
    int brightness;
    std::string firma;

public:
    PanouIluminare(bool aprins, int brightness, const std::string &firma)
        : aprins(aprins),
          brightness(brightness),
          firma(firma) {
    }

    friend std::ostream &operator<<(std::ostream &os, const PanouIluminare &obj) {
        return os
               << "aprins: " << obj.aprins
               << " brightness: " << obj.brightness
               << " firma: " << obj.firma;
    }
};

class GrupIluminare {
    std::vector<PanouIluminare> panouri;

public:
    explicit GrupIluminare(const std::vector<PanouIluminare> &panouri)
        : panouri(panouri) {
    }

    friend std::ostream &operator<<(std::ostream &os, const GrupIluminare &grup) {
        os << "panouri:\n";
        for (const PanouIluminare &panou: grup.panouri) {
            os << panou << "\n";
        }
        return os;
    }
};

class Cuier {
    int m_nr_haine;
    int m_nr_randuri;

public:
    Cuier(int nr_haine, int nr_randuri) : m_nr_haine(nr_haine), m_nr_randuri(nr_randuri) {
        std::cout << "Cuier nr_haine: " << nr_haine << "\n";
    }

    ~Cuier() {
        std::cout << "~Cuier nr_randuri: " << m_nr_randuri << "\n";
    }

    Cuier(const Cuier &originalu) : m_nr_haine(originalu.m_nr_haine), m_nr_randuri(originalu.m_nr_randuri) {
        std::cout << "Constr de copiere cuier " << originalu.m_nr_haine << "\n";
    }

    Cuier &operator=(const Cuier &originalu) {
        if (this == &originalu) {
            return *this;
        }
        m_nr_haine = originalu.m_nr_haine;
        m_nr_randuri = originalu.m_nr_randuri;
        std::cout << "op= cuier\n";
        return *this;
    }

    [[nodiscard]] int get_nr_haine() const {
        return m_nr_haine;
    }

    void set_nr_haine(int nr_haine) {
        this->m_nr_haine = nr_haine;
    }

    int get_nr_randuri() const {
        return m_nr_randuri;
    }

    void set_nr_randuri(int nr_randuri) {
        this->m_nr_randuri = nr_randuri;
    }

    friend std::ostream &operator<<(std::ostream &os, const Cuier &cuier) {
        os << cuier.m_nr_haine << " " << cuier.m_nr_randuri;
        return os;
    }
};


class Sala {
    std::vector<GrupIluminare> grupLumina;
    int numar;
    double zgomot;
    Cuier m_cuier;

public:
    friend std::ostream &operator<<(std::ostream &os, const Sala &sala) {
        os << "grupLumina:\n";
        for (const auto &corp: sala.grupLumina) {
            os << corp << "\n";
        }
        os
                << " numar: " << sala.numar
                << " zgomot: " << sala.zgomot
                << " m_cuier: " << sala.m_cuier;
        return os;
    }

    Sala(const Cuier &cuier) : m_cuier(cuier) {
    }

    Sala(const std::vector<GrupIluminare> &grup_lumina, const Cuier &m_cuier)
        : grupLumina(grup_lumina),
          m_cuier(m_cuier) {
    }

    Sala(const Sala &other)
        : grupLumina(other.grupLumina),
          numar(other.numar),
          zgomot(other.zgomot),
          m_cuier(other.m_cuier) {
    }

    Sala &operator=(const Sala &other) {
        if (this == &other)
            return *this;
        grupLumina = other.grupLumina;
        numar = other.numar;
        zgomot = other.zgomot;
        m_cuier = other.m_cuier;
        return *this;
    }

    Sala(const std::vector<GrupIluminare> &grup_lumina, int numar, double zgomot, const Cuier &m_cuier)
        : grupLumina(grup_lumina),
          numar(numar),
          zgomot(zgomot),
          m_cuier(m_cuier) {
    }

    [[nodiscard]] std::vector<GrupIluminare> get_grup_lumina() const {
        return grupLumina;
    }

    void set_grup_lumina(const std::vector<GrupIluminare> &grup_lumina) {
        grupLumina = grup_lumina;
    }

    [[nodiscard]] int get_numar() const {
        return numar;
    }

    void set_numar(int numar) {
        this->numar = numar;
    }

    [[nodiscard]] double get_zgomot() const {
        return zgomot;
    }

    void set_zgomot(double zgomot) {
        this->zgomot = zgomot;
    }

    [[nodiscard]] Cuier get_cuier() const {
        return m_cuier;
    }

    void set_cuier(const Cuier &cuier) {
        this->m_cuier = cuier;
    }
};


int main() {
    Cuier c1{2, 2}, c2{4, 3}, c4 = c2;
    std::cout << c1 << c2;
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
