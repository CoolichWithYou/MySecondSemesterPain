//
// Created by Test-notebook on 5/14/2021.
//

#ifndef TRY2_SUBJECT_H
#define TRY2_SUBJECT_H

#include <iostream>
#include <string>
#include <vector>

//#include "../App/app.h"

using namespace std;

class Subject {
public:

    Subject() = default;

    explicit Subject(string title);

    void setName(const string &title);

    string getName();

    void print(ostream &out = cout) const;

    // функция записи в бинарный файл
    bool parseInBinFile(iostream &f_out);
    // функция чтения из бинарного файла

    bool unparseFromBinFile(iostream &f_in);


    bool operator<(const Subject& subject) const;
    bool operator<=(const Subject& subject) const;
    bool operator>(const Subject& subject) const;
    bool operator>=(const Subject& subject) const;
    bool operator==(const Subject& subject) const;
    bool operator!=(const Subject& subject) const;

private:
    string m_title{};
};


//std::vector<Subject> subjectList;

#endif //TRY2_SUBJECT_H
