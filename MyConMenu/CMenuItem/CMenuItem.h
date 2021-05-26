#ifndef MYMENU_CPP_CMENUITEM_H
#define MYMENU_CPP_CMENUITEM_H

#include "AbstractMenuItem/AbstractMenuItem.h"

namespace CoolichWithYou {
    class CMenuItem : public ItemMunu {
    public:
        CMenuItem(char *, Func);
        char * getName();
        void print();
        int run();
    };
}

#endif //MYMENU_CPP_CMENUITEM_H
