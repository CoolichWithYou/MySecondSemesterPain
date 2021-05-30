//
// Created by Test-notebook on 5/15/2021.
//

#ifndef TRY2_HUMAN_H
#define TRY2_HUMAN_H

#include <iostream>
#include <string>
#include <vector>
#include "../Color/Color.h"
//#include "../App/app.h"

using namespace std;

class Human {
public:

    bool parseInBinFileHuman(iostream &f_out);
    // функция чтения из бинарного файла

    bool unparseFromBinFileHuman(iostream &f_in);

    Human(string name, string surname, bool id)
            : m_name(std::move(name)), m_surname(std::move(surname)), m_post(id) {
    }

    Human() : m_name("-"), m_surname("-"), m_post(0){}

    void setName(const string name) {
        m_name = name;
    }

    void setSurname(const string surname) {
        m_surname = surname;
    }

    void setId(size_t id) {
        m_id = id;
    }

    string getName() {
        return m_name;
    }

    string getSurname() {
        return m_surname;
    }

    size_t getId() {
        return m_id;
    }

    bool getPost(){
        return m_post;
    }

    void setPost(bool post){
        m_post = post;
    }

    static void printList(vector<Human>::iterator i, vector<class Human>& human){
        i->print();
    }

    void print() {
        if(m_post) {
            setColor(Red,Black);
            cout << "Преподаватель:\t";
            setColor(White,Black);
        }
        else{
            setColor(Green,Black);
            cout << "Студент:\t";
            setColor(White,Black);
        }
        cout << m_name
        << "\t\t"
        << m_surname
        << "\t"
        << endl;
    }

    bool operator<(const Human& human) const;
    bool operator<=(const Human& human) const;
    bool operator>(const Human& human) const;
    bool operator>=(const Human& human) const;
    bool operator==(const Human& human) const;
    bool operator!=(const Human& human) const;

    friend std::ostream& operator<< (std::ostream &out, Human &human);

private:
    string m_name{};
    string m_surname{};
    int m_id;
    bool m_post;
};



//std::vector<Human> humanList;

#endif //TRY2_HUMAN_H
