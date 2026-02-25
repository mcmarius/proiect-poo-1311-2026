#include <iostream>
#include <array>
#include <ostream>
#include <vector>

#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"

class Student {
    std::string nume;
    int grupa;
public:
Student(const std::string &nume, int grupa)
        : nume(nume),
          grupa(grupa) {
    }
 Student(const Student &other)
        : nume(other.nume),
          grupa(other.grupa) {
    }

    Student & operator=(const Student &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        grupa = other.grupa;
        return *this;
    }

    ~Student() = default;
 friend std::ostream & operator<<(std::ostream &os, const Student &obj) {
        return os
               << "nume: " << obj.nume
               << " grupa: " << obj.grupa;
    }
};

class Facultate {
    std::string nume = "FMI";
    std::vector<Student> studenti;

public:
    explicit Facultate(const std::vector<Student> &studenti)
        : studenti(studenti) {
    }
 Facultate(const std::string &nume, const std::vector<Student> &studenti)
        : nume(nume),
          studenti(studenti) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Facultate &obj) {
        os << "nume: " << obj.nume << "\n";
        os << "studenti:\n";
        for (const auto &student : obj.studenti) {
            os << student << "\n";
        }
        return os;
    }
};


int main() {
    std::cout << "Hello, 1311 la 8 dimineata!\n";
    Example e1;
    e1.g();
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
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
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
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
