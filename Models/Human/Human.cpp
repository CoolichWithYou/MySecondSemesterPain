//
// Created by Test-notebook on 5/15/2021.
//

#include "Human.h"

std::ostream &operator<<(std::ostream &out, Human &human) {
    human.print();
    return out;
}

bool Human::operator<(const Human &subject) const{
    return this->m_name[0] < subject.m_name[0];
}

bool Human::operator<=(const Human &subject) const{
    return this->m_name[0] <= subject.m_name[0];
}

bool Human::operator>(const Human &subject) const{
    return this->m_name[0] > subject.m_name[0];
}

bool Human::operator>=(const Human &subject) const{
    return this->m_name[0] >= subject.m_name[0];
}

bool Human::operator==(const Human &subject) const{
    return this->m_name[0] == subject.m_name[0];
}

bool Human::operator!=(const Human &subject) const{
    return this->m_name[0] != subject.m_name[0];
}