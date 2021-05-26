#ifndef MYMENU_ABSTRACTMENUITEM_H
#define MYMENU_ABSTRACTMENUITEM_H

namespace CoolichWithYou {
    class ItemMunu {
    public:
        typedef int(*Func)();
        ItemMunu(char *item_name, Func func);
        virtual char *getName() = 0;
        virtual void print() = 0;
        virtual int run() = 0;

    protected:
        Func m_func{};
        char *m_item_name{};
    };
}

#endif //MYMENU_ABSTRACTMENUITEM_H
