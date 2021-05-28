

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "App/app.h"

#pragma region функции-заглушки

using namespace CoolichWithYou;
using namespace std;

bool endProgram = false;

int main();

#pragma endregion
int main() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    connectDatabaseToVector();
    fillVectorOfSubject();
    greeting();
    while(login == "-") {
        auth();
    }

//    for(int i = 0; i < nicknamesList.size(); i++){
//        cout << nicknamesList[i] << endl;
//    }
//    cout << endl;

    while(true)  {         //исправить
        if(login == "admin") {
            CMenuItem items[3]{CMenuItem{"Открыть список предметов", SubjectList},
                               CMenuItem{"Вернуться к авторизации", nothing},
                               CMenuItem{"Открыть список пользователей", userList}};
            CMenu menu("My console menu", items, 3);

            menu.runCommand();
        }
        else{
            CMenuItem items[2]{CMenuItem{"Открыть список предметов", SubjectList},
                               CMenuItem{"Вернуться к авторизации", nothing}};
            CMenu menu("My console menu", items, 2);

            menu.runCommand();
        }
    }
    return 0;
}
