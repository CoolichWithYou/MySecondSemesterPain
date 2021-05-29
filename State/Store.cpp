#include "Store.h"
#include "../App/app.h"

using namespace std;

void fillVectorOfSubject(){
    string subjectName;
    fstream subjects("subjects.txt");

    if (!subjects) {
        cout << "файл не удалось открыть!\n";
    }
    else{
        for(int i = 0; !subjects.eof(); i++){
            getline(subjects, subjectName);
            if(subjectName != "\n") {
                Subject a(subjectName);
                subjectList.push_back(a);
            }
        }
    }
    subjects.close();
}

