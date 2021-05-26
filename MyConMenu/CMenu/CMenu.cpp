#include "CMenu.h"
#include "../App/app.h"

#include <iostream>

namespace CoolichWithYou {

    CMenu::CMenu(char *title, CMenuItem *items, size_t count) : m_title(title), m_items(items), m_count(count) {}

    int CMenu::getSelect() const {
        return m_select;
    }

    bool CMenu::isRun() const {
        return m_running;
    }

    int CMenu::getCount() const {
        return m_count;
    }

    char *CMenu::getTitle() {
        return m_title;
    }

    CMenuItem *CMenu::getItems() {
        return m_items;
    }

    void CMenu::print() const {
        for (size_t i{}; i < m_count; ++i) {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << std::endl;
        }
        std::cout << "0. exit" << std::endl;
    }

    int CMenu::runCommand() {
        std::cout << login << endl;
        print();
        std::cout << "\n   Select >> ";
        std::cin >> m_select;
        return m_items[m_select - 1].run();
    }

    std::ostream &operator<<(std::ostream &out, const CMenu &cmenu) {
        cmenu.print();
        return out;
    }

    std::istream &operator>>(std::istream &in, CMenu &cmenu) {
        std::cout << "\n   Select >> ";
        in >> cmenu.m_select;
        return in;
    }

    int CMenu::operator()() {
        return m_items[m_select - 1].run();
    }
}