//
// Created by marius on 09.03.2026.
//

#ifndef OOP_GRUPILUMINARE_H
#define OOP_GRUPILUMINARE_H
#include <vector>

#include "PanouIluminare.h"


class GrupIluminare {
    std::vector<PanouIluminare> panouri;

public:
    explicit GrupIluminare(const std::vector<PanouIluminare> &panouri);

    friend std::ostream &operator<<(std::ostream &os, const GrupIluminare &grup);
};


#endif //OOP_GRUPILUMINARE_H