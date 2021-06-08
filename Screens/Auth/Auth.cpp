//
// Created by Test-notebook on 5/23/2021.
//

#include "Auth.h"
#include "../App/app.h"


using namespace std;
using namespace CoolichWithYou;

vector<string> passwordsList;
vector<string> nicknamesList;

void connectDatabaseToVector() {
    fstream passwords("passwords.txt");

    if (!passwords) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; !passwords.eof(); i++){
            passwordsList.emplace_back("-");
            getline(passwords, passwordsList[i]);
        }
    }
    passwords.close();

    fstream nicknames("nicknames.txt");

    if (!nicknames) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; !nicknames.eof(); i++){
            nicknamesList.emplace_back("-");
            getline(nicknames, nicknamesList[i]);
        }
    }
    nicknames.close();

    fstream firstNames("FirstName.txt");

    string helpString;
}

//auth
void greeting(){
    cout << "EOS" << endl;
}
void auth(){
    CMenuItem items[2]{CMenuItem{"Создать аккаунт", regIn},
                       CMenuItem{"Авторизоваться", logIn}};
    CMenu menu("My console menu", items, 2);

    menu.runCommand();
}

int logIn(){
    string nickname;
    string password;

    cout << "nickname:\t";
    cin >> nickname;

    cout << "password\t";
    cin >> password;

    for(int i = 0; i < nicknamesList.size(); i++){
        if(nickname == nicknamesList[i]){
            if(password == passwordsList[i]){
                login = nickname;
            }
            else{
                cout << "логин, либо пароль были введены неправильно\n\n 1";
                EXIT_FAILURE;
            }
        }
    }

}
int regIn(){
    string nickname;
    string password;

    cout << "nickname:\t";
    cin >> nickname;

    cout << "password\t";
    cin >> password;

    nicknamesList.push_back(nickname);
    passwordsList.push_back(password);

    fstream passwords("passwords.txt", ios_base::app);
    passwords.seekg(0, ios_base::end);

    if(passwords.is_open()){
        passwords << password;
        passwords << "\n";
    }
    passwords.close();

    fstream nicknames("nicknames.txt", ios_base::app);
    nicknames.seekg(0, ios_base::end);

    if(nicknames.is_open()){
        nicknames << nickname;
        nicknames << "\n";
    }
    nicknames.close();
}