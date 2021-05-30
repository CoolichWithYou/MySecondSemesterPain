//
// Created by Test-notebook on 5/28/2021.
//

#include "InterfaceScreen.h"

using namespace CoolichWithYou;

int SubjectList() {
    system("cls");
    std::cout << "Открыть список предметов\n\n";
    if(login == "admin") {

        CMenuItem items[6]{
                CMenuItem{"Отобразить список предметов", printSubjectList},
                CMenuItem{"Сортировать по названию", sortSubjectByName},
                CMenuItem{"Добавить новый элемент", addNewSubject},
                CMenuItem{"Редактировать предмет по id", editSubject},
                CMenuItem{"Удалить предмет по id", deleteSubject},
                CMenuItem{"Вернуться назад", runMenu}
        };

        CMenu menu("Subject menu", items, 6);

        menu.runCommand();
    }
    else{
        CMenuItem items[4]{
                CMenuItem{"Отобразить список предметов", nothing},
                CMenuItem{"Сортировать по названию", nothing},
                CMenuItem{"Добавить новый элемент", nothing},
                CMenuItem{"Вернуться назад", nothing}
        };

        CMenu menu("Subject menu", items, 4);

        menu.runCommand();
    }
    return 1;
}

int userList() {
    system("cls");
    CMenuItem items[8]{
            CMenuItem{"Отобразить всех пользователей", printAllUsers}, CMenuItem{"Добавить пользователя", addNewUser},
            CMenuItem{"Редактировать пользователя", editUser}, CMenuItem{"Удалить пользователя", deleteUser},
            CMenuItem{"Сортировать по имени", sortUserByName}, CMenuItem{"Показать преподавателей", showTeachers},
            CMenuItem{"Показать студентов", showStudents}, CMenuItem{"Вернуться назад", runMenu}
    };

    CMenu menu("Subject menu", items, 8);

    menu.runCommand();
    return 1;
}

int authorizathion(){
    login = "-";
    while(login == "-") {
        auth();
    }

    runMenu();
}

int runMenu(){
    if(login == "admin"){
        adminRun();
    }
    else{
        usualRun();
    }
}

void adminRun(){
    system("cls");
    CMenuItem items[3]{CMenuItem{"Открыть список предметов", SubjectList},
                       CMenuItem{"Открыть список пользователей", userList},
                       CMenuItem{"Разлогиниться", authorizathion}};
    CMenu menu("My console menu", items, 3);

    menu.runCommand();
}

void usualRun(){
    system("cls");
    CMenuItem items[2]{CMenuItem{"Открыть список предметов", SubjectList},
                       CMenuItem{"Разлогиниться", authorizathion}};
    CMenu menu("My console menu", items, 2);

    menu.runCommand();
}