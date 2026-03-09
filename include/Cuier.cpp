//
// Created by marius on 09.03.2026.
//

#include "Cuier.h"

#include <iostream>

Cuier::Cuier(int nr_haine, int nr_randuri): m_nr_haine(nr_haine), m_nr_randuri(nr_randuri) {
    std::cout << "Cuier nr_haine: " << nr_haine << "\n";
}

Cuier::~Cuier() {
    std::cout << "~Cuier nr_randuri: " << m_nr_randuri << "\n";
}

Cuier::Cuier(const Cuier &originalu): m_nr_haine(originalu.m_nr_haine), m_nr_randuri(originalu.m_nr_randuri) {
    std::cout << "Constr de copiere cuier " << originalu.m_nr_haine << "\n";
}

Cuier & Cuier::operator=(const Cuier &originalu) {
    if (this == &originalu) {
        return *this;
    }
    m_nr_haine = originalu.m_nr_haine;
    m_nr_randuri = originalu.m_nr_randuri;
    std::cout << "op= cuier\n";
    return *this;
}

int Cuier::get_nr_haine() const {
    return m_nr_haine;
}

void Cuier::adauga_haine() {
    m_nr_haine++;
}

std::ostream & operator<<(std::ostream &os, const Cuier &cuier) {
    os << cuier.m_nr_haine << " " << cuier.m_nr_randuri;
    return os;
}
