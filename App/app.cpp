#include "app.h"

using namespace CoolichWithYou;
using namespace std;

string login = "-";

std::vector<Subject> subjectList;
std::vector<Human> humanList;

const string PATH_BIN_FILE = "subject.dir";
const string HUMAN_BIN_FILE = "human.dir";

int nothing(){ //костыль
    return 0;
}


bool saveInFile() {
    fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

    for (auto &it : subjectList) {
        it.parseInBinFile(io_file);
    }

    io_file.close();

    return true;
}
int printSubjectList(){
    if (!checkEmpty(subjectList)) {
        for (int i = 0; i < subjectList.size(); ++i) {
            setColor(Yellow,Black);
            cout << i;
            setColor(White,Black);
            cout << " " << subjectList[i].getName() << endl;

        }
        cout << "\n" << endl;
    }
    system("pause");
    SubjectList();
}
int addNewSubject(){
    string name;
    cout << "Введите название предмета:\n";
    cin >> name;

    Subject a(name);

    subjectList.push_back(a);

    fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

    for (auto &it : subjectList) {
        it.parseInBinFile(io_file);
    }

    io_file.close();

    cout << "Предмет успешно добавлен!\n\n";

    system("pause");
    SubjectList();
    return 1;
}
int sortSubjectByName(){
    if (!checkEmpty(subjectList)){
        sort(subjectList.begin(), subjectList.end());
        for (int i = 0; i < subjectList.size(); ++i) {
            setColor(Yellow,Black);
            cout << i;
            setColor(White,Black);
            cout << " " << subjectList[i].getName() << endl;
        }

        fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

        for (auto &it : subjectList) {
            it.parseInBinFile(io_file);
        }

        io_file.close();

        cout << "\n" << endl;
    }

    system("pause");
    SubjectList();
}
int editSubject(){
    if(!checkEmpty(subjectList)){
        auto it = subjectList.begin();

        for (int i = 0; i < subjectList.size(); ++i) {
            setColor(Yellow,Black);
            cout << i;
            setColor(White,Black);
            cout << " " << subjectList[i].getName() << endl;
        }
        cout << "\n\n";

        int changeSubjectId{};
        string newName, newSurname;
        cout << "Введите id предмета, который хотите изменить:\n->>";
        cin >> changeSubjectId;

        cout << "Введите новое название предмета:\n->>";
        cin >> newName;

        subjectList[changeSubjectId].setName(newName);

        fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

        for (auto &it : subjectList) {
            it.parseInBinFile(io_file);
        }

        io_file.close();

        cout << "Информация о предмете успешно изменена!\n\n";
    }

    system("pause");
    SubjectList();
    return 1;
}
int deleteSubject(){
    if(!checkEmpty(subjectList)){
        auto it = subjectList.begin();

        for (int i = 0; i < subjectList.size(); ++i) {
            cout << i << " " << subjectList[i].getName() << endl;
        }
        cout << "\n\n";

        int deleteSubjectId{};
        cout << "Введите id предмета, который хотите удалить:\n->>";
        cin >> deleteSubjectId;

        subjectList.erase(subjectList.begin() + deleteSubjectId);

        fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

        for (auto &it : subjectList) {
            it.parseInBinFile(io_file);
        }

        io_file.close();

        cout << "предмет успешно удалён!\n\n";
    }

    system("pause");
    SubjectList();
    return 1;
}

bool restoreInFile() {
    fstream io_file(PATH_BIN_FILE, ios::binary | ios::in);

    Subject subject{};
    while (subject.unparseFromBinFile(io_file)) {
        subjectList.push_back(subject);
    }

    io_file.close();

    fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::in);

    Human human{};
    while (human.unparseFromBinFileHuman(hu_file)) {
        humanList.push_back(human);
    }

    hu_file.close();

    return true;
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

    fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::out);

    for (auto &it : humanList) {
        it.parseInBinFileHuman(hu_file);
    }

    hu_file.close();


//    fstream firstNames("FirstName.txt", std::ofstream::out | std::ofstream::trunc);
//
//    if (!firstNames) {
//        cout << "файл не удалось открыть!\n";
//    }
//    else{
//        for(int i = 0; i < humanList.size(); i++){
//            firstNames << humanList[i].getName() << "\n";
//        }
//    }
//    firstNames.close();
//
//    fstream secondNames("SecondName.txt", std::ofstream::out | std::ofstream::trunc);
//
//    if (!secondNames) {
//        cout << "файл не удалось открыть!\n";
//    }
//    else{
//        for(int i = 0; i < humanList.size(); i++){
//            secondNames << humanList[i].getSurname() << "\n";
//        }
//    }
//    secondNames.close();

//    fstream accessLevel("AccessLvl.txt", std::ofstream::out | std::ofstream::trunc);
//
//    if (!accessLevel) {
//        cout << "файл не удалось открыть!\n";
//    }
//    else{
//        for(int i = 0; i < humanList.size(); i++){
//            accessLevel << humanList[i].getPost() << "\n";
//        }
//    }
//    accessLevel.close();
    system("pause");
    userList();
    return 1;
}
int printAllUsers(){
    if(!checkEmpty(humanList)){
        vector<Human>::iterator it = humanList.begin();

        int count{};

        for (it; it < humanList.end(); it++) {

            setColor(Yellow,Black);
            cout << count << "\t";
            setColor(White,Black);

            Human::printList(it, humanList);
            count++;
        }
        cout << "\n\n";
    }
    system("pause");
    userList();
    return 1;
}
int editUser(){
    if(!checkEmpty(humanList)){
        vector<Human>::iterator it = humanList.begin();

        int count{};

        for (it; it < humanList.end(); it++) {
            cout << count << "\t";
            Human::printList(it, humanList);
            count++;
        }
        cout << "\n\n";
    }
    system("pause");

    if(!checkEmpty(humanList)){

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

    system("pause");
    userList();
    return 1;
}
int deleteUser(){
    if(!checkEmpty(humanList)){
        vector<Human>::iterator it = humanList.begin();

        int count{};

        for (it; it < humanList.end(); it++) {

            setColor(Yellow,Black);
            cout << count << "\t";
            setColor(White,Black);

            Human::printList(it, humanList);
            count++;
        }
        cout << "\n\n";
    }
    system("pause");

    if(!checkEmpty(humanList)){

        int deleteUserId{};

        cout << "Введите id пользователя, которого хотите удалить:\n->>";
        cin >> deleteUserId;

        humanList.erase(humanList.begin() + deleteUserId + 1);

        fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::out);

        for (auto &it : humanList) {
            it.parseInBinFileHuman(hu_file);
        }

        hu_file.close();

        cout << "пользователь успешно удалён!\n\n";
    }
    system("pause");
    userList();
    return 1;
}
int sortUserByName(){
    sort(humanList.begin(), humanList.end());

    vector<Human>::iterator it = humanList.begin();

    int count{};

    for (it; it < humanList.end(); it++) {

        setColor(Yellow,Black);
        cout << count << "\t";
        setColor(White,Black);
        
        Human::printList(it, humanList);
        count++;
    }
    cout << "\n\n";

    system("pause");
    userList();
    return 1;
}
int showTeachers(){
    if(!checkEmpty(humanList)){
        for (int i = 0; i < humanList.size(); i++) {
            if (humanList[i].getPost() == 1) {
                humanList[i].print();
            }
        }
    }
    system("pause");
    userList();
    return 1;
}
int showStudents() {
    if(!checkEmpty(subjectList)){
        for (int i = 0; i < humanList.size(); i++) {
            if (humanList[i].getPost() == 0) {
                humanList[i].print();
            }
        }
    }
    system("pause");
    userList();
    return 1;
}