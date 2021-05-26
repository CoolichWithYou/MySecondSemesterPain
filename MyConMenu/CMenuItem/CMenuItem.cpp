#include "CMenuItem.h"
#include <iostream>

namespace CoolichWithYou {
    CMenuItem::CMenuItem(char *item_name, Func func) : ItemMunu (item_name, func) {}

    char * CMenuItem::getName() {
        return m_item_name;
    }

    void CMenuItem::print() {
        std::cout << m_item_name;
    }

    int CMenuItem::run() {
        return m_func();
    }
}