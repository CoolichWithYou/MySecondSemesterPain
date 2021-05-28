//
// Created by Test-notebook on 5/6/2021.
//

#include "app.h"

using namespace CoolichWithYou;
using namespace std;

string login = "-";

std::vector<Subject> subjectList;
std::vector<Human> humanList;

int nothing(){ //костыль
    return 0;
}

int sortSubjectByName() {
        bool changeCatch = false;
        bool checkChanges = true;
        while(checkChanges){
            checkChanges = sortSubjectAlgorithm();
            changeCatch = false;
        }
        return 1;
}
int editSubject(){
    printSubjectList();

    if(!subjectList.empty()) {

        int changeSubjectId{};
        string newName, newSurname;
        cout << "Введите id предмета, который хотите изменить:\n->>";
        cin >> changeSubjectId;

        cout << "Введите новое название предмета:\n->>";
        cin >> newName;

        subjectList[changeSubjectId] = newName;

        fstream subjects("subjects.txt", std::ofstream::out | std::ofstream::trunc);

        if (!subjects) {
            cout << "файл не удалось открыть!\n";
        }
        else{
            for(int i = 0; i < subjectList.size(); i++){
                subjects << subjectList[i].getName() << "\n";
            }
        }
        subjects.close();

        cout << "Информация о предмете успешно изменена!\n\n";

    }
    return 1;
}
int deleteSubject(){
    printSubjectList();

    int deleteSubjectId{};
    cout << "Введите id предмета, который хотите удалить:\n->>";
    cin >> deleteSubjectId;

    subjectList.erase(subjectList.begin() + deleteSubjectId);

    fstream subjects("subjects.txt", std::ofstream::out | std::ofstream::trunc);


    if (!subjects) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; i < subjectList.size(); i++){
            subjects << subjectList[i].getName() << "\n";
        }
    }
    subjects.close();

    cout << "предмет успешно удалён!\n\n";

    return 1;
}
int addNewSubject(){
    string name;
    cout << "Введите название предмета:\n";
    cin >> name;

    Subject a(name);

    subjectList.push_back(a);

    fstream subjects("subjects.txt", ios_base::app);
    subjects.seekg(0, ios_base::end);

    if(subjects.is_open()){
        subjects << "\n";
        subjects << name;
    }
    subjects.close();

    cout << "Предмет успешно добавлен!\n\n";

    return 1;
}
int printSubjectList(){
    if(subjectList.empty()){
        cout << " Список предметов пуст!\n\n";
    }
    else {
        auto it = subjectList.begin();

        int count{};

        for (it; it < subjectList.end(); it++) {
            cout << count << setw(10);
            Subject::print(it, subjectList);
            count++;
        }
        cout << "\n\n";
    }
    return 1;
}

int SubjectList() {
    system("cls");
    std::cout << "Открыть список предметов\n\n";
    if(login == "admin") {

        CMenuItem items[6]{
                CMenuItem{"Отобразить список предметов", printSubjectList},
                CMenuItem{"Сортировать по названию", sortSubjectByName},
                CMenuItem{"Добавить новый элемент", addNewSubject},
                CMenuItem{"Редактировать предмет по id", editSubject},
                CMenuItem{"Удалить предмет по id", deleteSubject}, CMenuItem{"Вернуться назад", nothing}
        };

        CMenu menu("Subject menu", items, 6);

        menu.runCommand();
    }
    else{
        CMenuItem items[4]{
                CMenuItem{"Отобразить список предметов", printSubjectList},
                CMenuItem{"Сортировать по названию", sortSubjectByName},
                CMenuItem{"Добавить новый элемент", addNewSubject},
                CMenuItem{"Вернуться назад", nothing}
        };

        CMenu menu("Subject menu", items, 4);

        menu.runCommand();
    }
    return 1;
}

int addNewUser(){
    string name;
    string surname;
    bool accessLvl;
    cout << "Введите имя:\n";
    cin >> name;
    cout << "Введите фамилию:\n";
    cin >> surname;
    cout << "Если пользователь студент, нажмите 0, в ином случае 1: \t";
    cin >> accessLvl;
//обавить id в конструктор
    Human a(name, surname, accessLvl);

    humanList.push_back(a);

    humanList[humanList.size()-1].setId(humanList.size()-1);

    fstream firstNames("FirstName.txt", std::ofstream::out | std::ofstream::trunc);

    if (!firstNames) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; i < humanList.size(); i++){
            firstNames << humanList[i].getName() << "\n";
        }
    }
    firstNames.close();

    fstream secondNames("SecondName.txt", std::ofstream::out | std::ofstream::trunc);

    if (!secondNames) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; i < humanList.size(); i++){
            secondNames << humanList[i].getSurname() << "\n";
        }
    }
    secondNames.close();

    fstream accessLevel("AccessLvl.txt", std::ofstream::out | std::ofstream::trunc);

    if (!accessLevel) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; i < humanList.size(); i++){
            accessLevel << humanList[i].getPost() << "\n";
        }
    }
    accessLevel.close();

    return 1;
}
int printAllUsers(){
    if(humanList.empty()){
        cout << "В базе данных нет пользователей!\n\n";
    }
    else {
        vector<Human>::iterator it = humanList.begin();

        int count{};

        for (it; it < humanList.end(); it++) {
            cout << count << "\t";
            Human::printList(it, humanList);
            count++;
        }
        cout << "\n\n";
    }
    return 1;
}
int editUser(){
    printAllUsers();

    if(!humanList.empty()) {

        int changeHumanId{};
        string newName, newSurname;
        cout << "Введите id пользователя, которого хотите изменить:\n->>";
        cin >> changeHumanId;

        cout << "Введите новое имя:\n->>";
        cin >> newName;

        cout << "Введите новую фамилию:\n->>";
        cin >> newSurname;

        humanList[changeHumanId].setName(newName);

        humanList[changeHumanId].setSurname(newSurname);

        fstream firstNames("FirstName.txt", std::ofstream::out | std::ofstream::trunc);

        if (!firstNames) {
            cout << "файл не удалось открыть!\n";
        }
        else{
            for(int i = 0; i < humanList.size(); i++){
                firstNames << humanList[i].getName() << "\n";
            }
        }
        firstNames.close();

        fstream secondNames("SecondName.txt", std::ofstream::out | std::ofstream::trunc);

        if (!secondNames) {
            cout << "файл не удалось открыть!\n";
        }
        else{
            for(int i = 0; i < humanList.size(); i++){
                secondNames << humanList[i].getSurname() << "\n";
            }
        }
        secondNames.close();

        cout << "Информация о человеке успешно изменена!\n\n";
    }
    return 1;
}
int deleteUser(){
    printAllUsers();

    if(!humanList.empty()) {

        int deleteUserId{};

        cout << "Введите id пользователя, которого хотите удалить:\n->>";
        cin >> deleteUserId;

        humanList.erase(humanList.begin() + deleteUserId + 1);

        fstream firstNames("FirstName.txt", std::ofstream::out | std::ofstream::trunc);

        if (!firstNames) {
            cout << "файл не удалось открыть!\n";
        }
        else{
            for(int i = 0; i < humanList.size(); i++){
                firstNames << humanList[i].getName() << "\n";
            }
        }
        firstNames.close();

        fstream secondNames("SecondName.txt", std::ofstream::out | std::ofstream::trunc);

        if (!secondNames) {
            cout << "файл не удалось открыть!\n";
        }
        else{
            for(int i = 0; i < humanList.size(); i++){
                secondNames << humanList[i].getSurname() << "\n";
            }
        }
        secondNames.close();

        cout << "пользователь успешно удалён!\n\n";
    }
    return 1;
}
int sortUserByName(){

    if(humanList.empty()){
        cout << "Список пуст\n\n";
    }
    else {
        bool checkChanges = true;
        bool changeCatch = false;
        while (checkChanges) {
            checkChanges = sortAlgorithm();
            changeCatch = false;
        }
    }
    return 1;
}
int showTeachers(){
    if(humanList.empty()){
        cout << "Список пуст\n\n";
    }
    else {
        for (int i = 0; i < humanList.size(); i++) {
            if (humanList[i].getPost() == 0) {
                humanList[i].print();
            }
        }
    }
    return 1;
}
int showStudents() {
    if (humanList.empty()) {
        cout << "Список пуст\n\n";
    }
    else {
        for (int i = 0; i < humanList.size(); i++) {
            if (humanList[i].getPost() == 1) {
                humanList[i].print();
            }
        }
    }
    return 1;
}

int userList() {
    system("cls");
    CMenuItem items[8]{
            CMenuItem{"Отобразить всех пользователей", printAllUsers}, CMenuItem{"Добавить пользователя", addNewUser},
            CMenuItem{"Редактировать пользователя", editUser}, CMenuItem{"Удалить преподавателя", deleteUser},
            CMenuItem{"Сортировать по имени", sortUserByName}, CMenuItem{"Показать преподавателей", showTeachers},
            CMenuItem{"Показать студентов", showStudents}, CMenuItem{"Вернуться назад", nothing}};

    CMenu menu("Subject menu", items, 8);

    menu.runCommand();
    return 1;
}

bool sortAlgorithm(){
    string tradeString;
    bool changeCatch = false;
    for(int i = 0; i < humanList.size(); i++){
        for(int j = 0; j < humanList.size(); j++){
            if(humanList[i].getName()[0] > humanList[j].getName()[0]){
                tradeString = humanList[i].getName();
                humanList[i].setName(humanList[j].getName());
                humanList[j].setName(tradeString);
                changeCatch = true;
            }
        }
    }
    return changeCatch;
}
bool sortSubjectAlgorithm() {
    string tradeString;
    bool changeCatch = false;
    for(int i = 0; i < subjectList.size(); i++){
        for(int j = 0; j < subjectList.size(); j++){
            if(subjectList[i].getName()[0] > subjectList[j].getName()[0]){
                tradeString = subjectList[i].getName();
                subjectList[i].setName(subjectList[j].getName());
                subjectList[j].setName(tradeString);
                changeCatch = true;
            }
        }
    }
    return changeCatch;
}