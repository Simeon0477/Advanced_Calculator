#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void operation(char *operation);

int n = 1;
string chaine;
string calcul[50];

int main() {
    cout << "Entrez votre operation : " << endl;
    cin >> chaine;
    char* chaine2 = const_cast<char*>(chaine.c_str());
    operation(chaine2);
    int i=0;
    while(calcul[i] != ""){
        cout << calcul[i] << endl;
        i++;
    }
}

void operation(char *operation){
    int i = 0;
    char temp[10];
    //for(i=0; i < taille; i++){

    //}
    while(*operation != '\0'){
        if(*operation >= '0' && *operation <= '9'){
            while(*operation >= '0' && *operation <= '9'){
                const char constchar[] = {*operation, '\0'};
                strcat(temp, constchar);
                operation++;
            }
            calcul[i] = temp;
            i++;
            memset(temp, '\0', 10);
        }
        if(*operation == '+' || *operation == '-' || *operation == '*' || *operation == '/'){
            calcul[i] = *operation;
            i++;
            operation++;
        }
    }
}


