#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

void operation(char *operation);
int calcul_operation(string operation[50]);
int search(int pos, char sens);
int longueur(const char *chaine);
int convert(const char *nombre);

string chaine;
string calcul[50];
int result;

int main(int argc, char** args){
    cout << "Entrez votre operation : " << endl;
    cin >> chaine;
    char* chaine2 = const_cast<char*>(chaine.c_str());
    operation(chaine2);
    int i=0;
    while(calcul[i] != ""){
        cout << calcul[i] << endl;
        i++;
    }
    result = calcul_operation(calcul);

    cout << "Le resultat est : " << result << endl;
}

void operation(char *operation){
    int i = 0;
    char temp[10];
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

int calcul_operation(string operation[50]){
    int result;
    int i=0;

    for(i = 0; i < 50; i++){
        if(operation[i] == "_" || operation[i] == ""){
            continue;
        }else if(operation[i] == "*"){
            result = convert(operation[search(i, 'd')].c_str()) * convert(operation[search(i, 'a')].c_str());
            operation[search(i, 'd')] = to_string(result);
            operation[i] = "_";
            operation[search(i, 'a')] = "_";
        }else if(operation[i] == "/"){
            if(convert(operation[search(i, 'a')].c_str()) == 0){
                cout << "Math error" << endl;
            }else{
                result = convert(operation[search(i, 'd')].c_str()) / convert(operation[search(i, 'a')].c_str());
                operation[search(i, 'd')] = to_string(result);
                operation[i] = "_";
                operation[search(i, 'a')] = "_";
            }
        }
        else if(operation[i] == "+"){
            result = convert(operation[search(i, 'd')].c_str()) + convert(operation[search(i, 'a')].c_str());
            operation[search(i, 'd')] = to_string(result);
            operation[i] = "_";
            operation[search(i, 'a')] = "_";
        }
        else if(operation[i] == "-"){
            result = convert(operation[search(i, 'd')].c_str()) - convert(operation[search(i, 'a')].c_str());
            operation[search(i, 'd')] = to_string(result);
            operation[i] = "_";
            operation[search(i, 'a')] = "_";
        }

    }

    return result;
}

int search(int pos, char sens){
    int position = pos;
    if(sens == 'a'){
        while(calcul[position] != ""){
            if(calcul[position] == "_"){
                position++;
                continue;
            }else{
                return position;
            }

            position++;
        }
    }else if(sens == 'd'){
        while(position >= 0){
            if(calcul[position] == "_"){
                position++;
                continue;
            }else{
                return position;
            }

            position--;
        }
    }
    return 0;
}

int convert(const char *nombre){
    const char *ptr = nombre;
    int lenght = longueur(nombre);
    int result = 0;

    while(*ptr != '\0'){
        result = result + ((*ptr - '0') * pow(10, lenght-1));
        ptr++;
        lenght--;
    }

    return result;
}

int longueur(const char *chaine){
    int lenght = 0;
    const char *ptr = chaine;

    while(*ptr != '\0'){
        lenght++;
        ptr++;
    }

    return lenght;
}