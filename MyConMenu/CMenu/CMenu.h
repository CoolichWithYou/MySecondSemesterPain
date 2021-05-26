#ifndef MYMENU_CMENU_H
#define MYMENU_CMENU_H

#include "CMenuItem/CMenuItem.h"
#include <iostream>

namespace CoolichWithYou {
    class CMenu {
    public:
        CMenu(char *, CMenuItem *, size_t);
        int getSelect() const;
        bool isRun() const;
        char *getTitle();
        int getCount() const;
        CMenuItem *getItems();
        void print() const;
        int runCommand();

        friend std::ostream& operator<< (std::ostream &out, const CMenu &cmenu);
        friend std::istream& operator>> (std::istream &in, CMenu &cmenu);
        int operator()();

    private:
        int m_select{-1};       //последний ввод пользователя
        int m_count{};       //хранит количество пунктов меню
        bool m_running{};       //отвечает за выполнение меню
        char *m_title{};        //хранит заголовок нашего меню
        CMenuItem *m_items{};
    };
}

#endif //MYMENU_CMENU_H
