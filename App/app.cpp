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

int printSubjectList(){
    try {
        if (subjectList.empty()) {
            throw "Предметы отсутствуют!\n\n";
        }
        else{
            for (int i = 0; i < subjectList.size(); ++i) {
                setColor(Yellow, Black);
                cout << i;
                setColor(White, Black);
                cout << " " << subjectList[i].getName() << endl;
            }
            cout << "\n" << endl;
        }
    }
    catch(char * a){
        cerr << "Error: " << a;
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
    sortAnything(subjectList);

    if (!checkEmpty(subjectList)) {
        for (int i = 0; i < subjectList.size(); ++i) {
            setColor(Yellow,Black);
            cout << i;
            setColor(White,Black);
            cout << " " << subjectList[i].getName() << endl;
        }
        cout << "\n" << endl;
    }
    fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

    for (auto &it : subjectList) {
        it.parseInBinFile(io_file);
    }

    io_file.close();

    cout << "\n" << endl;
    system("pause");
    SubjectList();
}

int sortUserByName(){
    sortAnything(humanList);

    if(!checkEmpty(humanList)) {

        vector<Human>::iterator it = humanList.begin();

        int count{};

        for (it; it < humanList.end(); it++) {

            setColor(Yellow, Black);
            cout << count << "\t";
            setColor(White, Black);

            Human::printList(it, humanList);
            count++;
        }
        cout << "\n\n";
    }

    system("pause");
    userList();
    return 1;
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

        try {

            int changeSubjectId{};
            string newName, newSurname;
            cout << "Введите id предмета, который хотите изменить:\n->>";
            cin >> changeSubjectId;

            if((changeSubjectId >= subjectList.size()) || (changeSubjectId < 0))
                throw "Вы ввели число, большее чем кол-во элементов или меньшее ноля!\n\n";
            else {

                cout << "Введите новое название предмета:\n->>";
                cin >> newName;

                subjectList[changeSubjectId].setName(newName);

                fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

                for (auto &it : subjectList) {
                    it.parseInBinFile(io_file);
                }

                io_file.close();
            }
        }
        catch(const char* a){
            cerr << "Error: " << a;
        }

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

        try {

            cin >> deleteSubjectId;

            if((deleteSubjectId >= subjectList.size()) || (deleteSubjectId < 0))
                throw "Вы ввели число, большее чем кол-во элементов или меньшее ноля!\n\n";
            else {

                subjectList.erase(subjectList.begin() + deleteSubjectId);

                fstream io_file(PATH_BIN_FILE, ios::binary | ios::out);

                for (auto &it : subjectList) {
                    it.parseInBinFile(io_file);
                }

                io_file.close();
            }
        }
        catch(char * a){
            cerr << "Error: " << a;
        }

        cout << "предмет успешно удалён!\n\n";
    }

    system("pause");
    SubjectList();
    return 1;
}

bool restoreInFile() {
    try {
        fstream io_file(PATH_BIN_FILE, ios::binary | ios::in);
        if(!io_file.is_open()){
            throw "Файл не удалось открыть!\n\n";
        }

        Subject subject{};
        while (subject.unparseFromBinFile(io_file)) {
            subjectList.push_back(subject);
        }

        io_file.close();
    }
    catch(const char* a){
        cerr << "Error: " << a;
    }

    try {
        fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::in);

        if(!hu_file.is_open()){
            throw "Файл не удалось открыть!\n\n";
        }

        Human human{};
        while (human.unparseFromBinFileHuman(hu_file)) {
            humanList.push_back(human);
        }

        hu_file.close();
    }
    catch(const char* a){
        cerr << "Error: " << a;
    }
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

    try {
        fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::out);

        if(!hu_file.is_open()){
            throw "Файл не удалось открыть!\n\n";
        }

        for (auto &it : humanList) {
            it.parseInBinFileHuman(hu_file);
        }

        hu_file.close();
    }
    catch(const char* a){
        cerr << "Error: " << a;
    }

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


        try {
            fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::out);

            if(!hu_file.is_open()){
                throw "Файл не удалось открыть!\n\n";
            }

            for (auto &it : humanList) {
                it.parseInBinFileHuman(hu_file);
            }

            hu_file.close();
        }
        catch(const char* a){
            cerr << "Error: " << a;
        }

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

        try {
            fstream hu_file(HUMAN_BIN_FILE, ios::binary | ios::out);

            if(!hu_file.is_open()){
                throw "Файл не удалось открыть!\n\n";
            }

            for (auto &it : humanList) {
                it.parseInBinFileHuman(hu_file);
            }

            hu_file.close();
        }
        catch(const char* a){
            cerr << "Error: " << a;
        }

        cout << "пользователь успешно удалён!\n\n";
    }
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