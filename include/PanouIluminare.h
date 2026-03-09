//
// Created by marius on 09.03.2026.
//

#ifndef OOP_PANOUILUMINARE_H
#define OOP_PANOUILUMINARE_H
#include <string>


class PanouIluminare {
    bool aprins;
    int brightness;
    std::string firma{};

public:
    PanouIluminare(bool aprins, int brightness, const std::string &firma);

    friend std::ostream &operator<<(std::ostream &os, const PanouIluminare &obj);
};


#endif //OOP_PANOUILUMINARE_H