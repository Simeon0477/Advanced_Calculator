#include <iostream>
#include <string>

using namespace std;

string chaine;

int main() {
    cout << "Entre la chaine de caractère : ";
    cin >> chaine;
    char* chaine2 = const_cast<char*>(chaine.c_str());

}

double add()

