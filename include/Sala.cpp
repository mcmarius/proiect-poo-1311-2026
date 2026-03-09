//
// Created by marius on 09.03.2026.
//

#include "Sala.h"
#include <iostream>

Sala::Sala(const Cuier &cuier): m_cuier(cuier) {
}

Sala::Sala(const std::vector<GrupIluminare> &grup_lumina, const Cuier &m_cuier): grupLumina(grup_lumina),
    m_cuier(m_cuier) {
}

Sala::Sala(const Sala &other): grupLumina(other.grupLumina),
                               numar(other.numar),
                               zgomot(other.zgomot),
                               m_cuier(other.m_cuier) {
}

Sala & Sala::operator=(const Sala &other) {
    if (this == &other)
        return *this;
    grupLumina = other.grupLumina;
    numar = other.numar;
    zgomot = other.zgomot;
    m_cuier = other.m_cuier;
    return *this;
}

Sala::Sala(const std::vector<GrupIluminare> &grup_lumina, int numar, double zgomot, const Cuier &m_cuier): grupLumina(grup_lumina),
    numar(numar),
    zgomot(zgomot),
    m_cuier(m_cuier) {
}

void Sala::set_grup_lumina(const std::vector<GrupIluminare> &grup_lumina) {
    grupLumina = grup_lumina;
}

void Sala::set_zgomot(double zgomot_) {
    this->zgomot = zgomot_;
}

void Sala::set_numar(int numar_) {
    this->numar = numar_;
}

std::ostream & operator<<(std::ostream &os, const Sala &sala) {
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
