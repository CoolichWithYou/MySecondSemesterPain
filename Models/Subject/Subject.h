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

    Subject(string title)
            : m_title(std::move(title)) {
    }

    void setName(const string title) {
        m_title = title;
    }

    string getName() {
        return m_title;
    }

    void print() {
        cout << m_title << endl;
    }

    static void print(vector<Subject>::iterator i, vector<class Subject>& subject){
        i->print();
    }

private:
    string m_title{};
};

//std::vector<Subject> subjectList;

#endif //TRY2_SUBJECT_H
