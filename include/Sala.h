//
// Created by marius on 09.03.2026.
//

#ifndef OOP_SALA_H
#define OOP_SALA_H
#include <vector>

#include "Cuier.h"
#include "GrupIluminare.h"


class Sala {
    std::vector<GrupIluminare> grupLumina;
    int numar{};
    double zgomot{};
    Cuier m_cuier;

public:
    friend std::ostream &operator<<(std::ostream &os, const Sala &sala);

    explicit Sala(const Cuier &cuier);
    Sala(const std::vector<GrupIluminare> &grup_lumina, const Cuier &m_cuier);
    Sala(const Sala &other);
    Sala &operator=(const Sala &other);
    Sala(const std::vector<GrupIluminare> &grup_lumina, int numar, double zgomot, const Cuier &m_cuier);

    void set_grup_lumina(const std::vector<GrupIluminare> &grup_lumina);
    void set_zgomot(double zgomot_);
    void set_numar(int numar_);
};


#endif //OOP_SALA_H