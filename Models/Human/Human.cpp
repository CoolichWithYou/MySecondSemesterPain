//
// Created by Test-notebook on 5/15/2021.
//

#include "Human.h"

std::ostream &operator<<(std::ostream &out, Human &human) {
    human.print();
    return out;
}