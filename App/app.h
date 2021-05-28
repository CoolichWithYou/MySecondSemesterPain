

#ifndef TRY2_APP_H
#define TRY2_APP_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../MyConMenu/CMenu/CMenu.h"
#include "../MyConMenu/CMenuItem/CMenuItem.h"
#include "../Models/Human/Human.h"
#include "../Models/Subject/Subject.h"
#include "../State/Store.h"
#include "../State/State.h"
#include "../Screens/Auth/Auth.h"
#include "../Screens/InterfaceScreen.h"

extern string login;

extern std::vector<Subject> subjectList;
extern std::vector<Human> humanList;

int nothing();

bool sortAlgorithm();
bool sortSubjectAlgorithm();
//1)
int sortSubjectByName();
int editSubject();
int deleteSubject();
int addNewSubject();
int printSubjectList();

//2)
int addNewUser();
int printAllUsers();
int editUser();
int deleteUser();
int sortUserByName();
int showTeachers();
int showStudents();
int userList();

//runfunctions

#endif //TRY2_HUMAN_H