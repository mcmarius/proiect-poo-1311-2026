//
// Created by marius on 09.03.2026.
//

#include "PanouIluminare.h"
#include <iostream>

PanouIluminare::PanouIluminare(bool aprins, int brightness, const std::string &firma): aprins(aprins),
    brightness(brightness),
    firma(firma) {
}

std::ostream & operator<<(std::ostream &os, const PanouIluminare &obj) {
    return os
           << "aprins: " << obj.aprins
           << " brightness: " << obj.brightness
           << " firma: " << obj.firma;
}
