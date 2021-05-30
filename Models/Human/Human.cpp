//
// Created by Test-notebook on 5/15/2021.
//

#include "Human.h"

bool Human::parseInBinFileHuman(iostream &f_out) {
    // сохраняем размер строки
    auto size_str = (streamsize) m_name.size();
    f_out.write((char *) &size_str, sizeof size_str);

    // сохраняем саму строку
    f_out.write((char *) &m_name[0], size_str);




    size_str = (streamsize) m_surname.size();
    f_out.write((char *) &size_str, sizeof size_str);

    f_out.write((char *) &m_surname[0], size_str);



    f_out.write((char *) &m_post, sizeof(bool));

    return f_out.good();
}

bool Human::unparseFromBinFileHuman(iostream &f_in) {
    // считываем размер строки
    streamsize size_str{};
    f_in.read((char *) &size_str, sizeof size_str);

    // назначаем новую длину строки
    m_name.resize(size_str);

    // считываем строку
    f_in.read((char *) &m_name[0], size_str);


//    f_in.read((char *) &size_str, sizeof size_str);
//
//    f_in.read((char *) &m_post, sizeof(bool));
//    // назначаем новую длину строки
//    m_surname.resize(size_str);
//
//    // считываем строку
//    f_in.read((char *) &m_surname[0], size_str);

    f_in.read((char *) &size_str, sizeof size_str);

    m_surname.resize(size_str);

    f_in.read((char *) &m_surname[0], size_str);
    // назначаем новую длину строки

    // считываем строку

    // назначаем новую длину строки

    // считываем строку
    f_in.read((char *) &m_post, sizeof(bool));

    // говорим, что всё хорошо
    return f_in.good();
}


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