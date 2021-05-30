//
// Created by Test-notebook on 5/14/2021.
//

#include "Subject.h"

bool Subject::operator<(const Subject &subject) const {
    return this->m_title[0] < subject.m_title[0];
}

bool Subject::operator<=(const Subject &subject) const {
    return this->m_title[0] <= subject.m_title[0];
}

bool Subject::operator>(const Subject &subject) const {
    return this->m_title[0] > subject.m_title[0];
}

bool Subject::operator>=(const Subject &subject) const {
    return this->m_title[0] >= subject.m_title[0];
}

bool Subject::operator==(const Subject &subject) const {
    return this->m_title[0] == subject.m_title[0];
}

bool Subject::operator!=(const Subject &subject) const {
    return this->m_title[0] != subject.m_title[0];
}

ostream &operator<<(ostream &out, const Subject &subject) {
    subject.print(out);

    return out;
}

void Subject::print(ostream &out) const {
    out << m_title << endl;
}

string Subject::getName() {
    return m_title;
}

void Subject::setName(const string &title) {
    m_title = title;
}

Subject::Subject(string title) : m_title(std::move(title)) {}

bool Subject::parseInBinFile(iostream &f_out) {
    // сохраняем размер строки
    auto size_str = (streamsize) m_title.size();
    f_out.write((char *) &size_str, sizeof size_str);

    // сохраняем саму строку
    f_out.write((char *) &m_title[0], size_str);

    // говорим, что всё хорошо
    return f_out.good();
}

bool Subject::unparseFromBinFile(iostream &f_in) {
    // считываем размер строки
    streamsize size_str{};
    f_in.read((char *) &size_str, sizeof size_str);

    // назначаем новую длину строки
    m_title.resize(size_str);

    // считываем строку
    f_in.read((char *) &m_title[0], size_str);

    // говорим, что всё хорошо
    return f_in.good();
}
