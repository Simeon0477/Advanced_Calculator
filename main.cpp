#include <iostream>
#include "calc.h"
#include <string>

using namespace std;

string chaine;

int main() {
    //char *chaine = "4+2";
    //char *chaine1 = "4*3";
    //char *chaine2 = "4+3-2+6-7";
    //char *chaine3 = "4+3*3+2*1+3*1+5"; // Ne prends pas en compte les negations

    cout << "Entre la chaine de caractère : ";
    cin >> chaine;
    char* chaine2 = const_cast<char*>(chaine.c_str());

    cout << charOperation(chaine2) << endl;
    //cout << charOperationMultiplyOrder(chaine2) << endl;
    //cout << charOperation(chaine2) << endl;
    //cout << charOperationMultiplyOrder(chaine2) + charOperationByRespectOrder(chaine2) << endl;

}



