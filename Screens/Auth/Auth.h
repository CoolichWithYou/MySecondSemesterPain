//
// Created by Test-notebook on 5/23/2021.
//

#ifndef OPI_DZ_AUTH_H
#define OPI_DZ_AUTH_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern std::vector<string> passwordsList;
extern std::vector<string> nicknamesList;

void greeting();
void auth();
int logIn();
int regIn();
void connectDatabaseToVector();

class Auth {

};


#endif //OPI_DZ_AUTH_H
