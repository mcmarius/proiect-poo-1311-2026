//
// Created by marius on 09.03.2026.
//

#ifndef OOP_CUIER_H
#define OOP_CUIER_H
#include <iosfwd>


class Cuier {
    int m_nr_haine;
    int m_nr_randuri;

public:
    Cuier(int nr_haine, int nr_randuri);
    ~Cuier();
    Cuier(const Cuier &originalu);
    Cuier &operator=(const Cuier &originalu);

    [[nodiscard]] int get_nr_haine() const;

    friend std::ostream &operator<<(std::ostream &os, const Cuier &cuier);
    void adauga_haine();
};


#endif //OOP_CUIER_H