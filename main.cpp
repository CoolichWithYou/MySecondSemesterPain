

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

    SetConsoleCP(0);
    SetConsoleOutputCP(0);

        restoreInFile();

        connectDatabaseToVector();

        greeting();

        authorizathion();

    CMenuItem items[1]{CMenuItem{"Затычка", nothing}};
    CMenu menu("My console menu", items, 1);

        return 0;
}
