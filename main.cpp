

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
    greeting();
    while(login == "-") {
        auth();
    }

//    for(int i = 0; i < nicknamesList.size(); i++){
//        cout << nicknamesList[i] << endl;
//    }
//    cout << endl;

    while(true)  {         //исправить
        CMenuItem items[3]{CMenuItem{"Открыть список предметов", SubjectList},
                           CMenuItem{"Создать отчёт", createReport},
                           CMenuItem{"Открыть список пользователей", userList}};
        CMenu menu("My console menu", items, 3);

        menu.runCommand();
    }
    return 0;
}
