//
// Created by Test-notebook on 5/14/2021.
//

#include "Subject.h"

bool Subject::operator<(const Subject &subject) const{
    return this->m_title[0] < subject.m_title[0];
}

bool Subject::operator<=(const Subject &subject) const{
    return this->m_title[0] <= subject.m_title[0];
}

bool Subject::operator>(const Subject &subject) const{
    return this->m_title[0] > subject.m_title[0];
}

bool Subject::operator>=(const Subject &subject) const{
    return this->m_title[0] >= subject.m_title[0];
}

bool Subject::operator==(const Subject &subject) const{
    return this->m_title[0] == subject.m_title[0];
}

bool Subject::operator!=(const Subject &subject) const{
    return this->m_title[0] != subject.m_title[0];
}