//
// Created by marius on 09.03.2026.
//

#include "GrupIluminare.h"
#include <iostream>
GrupIluminare::GrupIluminare(const std::vector<PanouIluminare> &panouri): panouri(panouri) {
}

std::ostream & operator<<(std::ostream &os, const GrupIluminare &grup) {
    os << "panouri:\n";
    for (const PanouIluminare &panou: grup.panouri) {
        os << panou << "\n";
    }
    return os;
}
