#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void operation(char *operation);
double calcul_operation(string operation[50]);
int search(int pos, char sens);

int n = 1;
string chaine;
string calcul[50];
double result;

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

double calcul_operation(string operation[50]){
    double result;
    int i=0;

    while(calcul[i] != ""){
        if(calcul[i] == "_"){
            continue;
        }else if(calcul[i] == "*"){
            result = atof(calcul[search(i, 'd')].c_str()) * atof(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
        }else if(calcul[i] == "/"){
            if(atof(calcul[search(i, 'a')].c_str()) == 0){
                cout << "Math error" << endl;
            }else{
                result = atof(calcul[search(i, 'd')].c_str()) / atof(calcul[search(i, 'a')].c_str());
                calcul[search(i, 'd')] = to_string(result);
                calcul[i] = "_";
                calcul[search(i, 'a')] = "_";
            }
        }
        else if(calcul[i] == "+"){
            result = atof(calcul[search(i, 'd')].c_str()) + atof(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
        }
        else if(calcul[i] == "-"){
            result = atof(calcul[search(i, 'd')].c_str()) - atof(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
        }

        i++;
    }

    return atof(calcul[0].c_str());
}

int search(int pos, char sens){
    int position = pos;
    if(sens == 'a'){
        while(calcul[position] != ""){
            if(calcul[position] == "_"){
                continue;
            }else{
                return position;
            }

            position++;
        }
    }else if(sens == 'd'){
        while(position >= 0){
            if(calcul[position] == "_"){
                continue;
            }else{
                return position;
            }

            position--;
        }
    }
    return 0;
}
