#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void operation(char *operation);
int calcul_operation(string operation[50]);
int search(int pos, char sens);
double stringToDouble(const std::string& str);

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
        if(calcul[i] == "_" || calcul[i] == ""){
            continue;
        }else if(calcul[i] == "*"){
            result = atoi(calcul[search(i, 'd')].c_str()) * atoi(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
        }else if(calcul[i] == "/"){
            if(atoi(calcul[search(i, 'a')].c_str()) == 0){
                cout << "Math error" << endl;
            }else{
                result = atoi(calcul[search(i, 'd')].c_str()) / atoi(calcul[search(i, 'a')].c_str());
                calcul[search(i, 'd')] = to_string(result);
                calcul[i] = "_";
                calcul[search(i, 'a')] = "_";
            }
        }
        else if(calcul[i] == "+"){
            result = atoi(calcul[search(i, 'd')].c_str()) + atoi(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
        }
        else if(calcul[i] == "-"){
            result = atoi(calcul[search(i, 'd')].c_str()) - atoi(calcul[search(i, 'a')].c_str());
            calcul[search(i, 'd')] = to_string(result);
            calcul[i] = "_";
            calcul[search(i, 'a')] = "_";
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

double stringToDouble(const std::string& str) {
    double result = 0.0;
    bool negative = false;
    bool decimalFound = false;
    double decimalFactor = 1.0;

    size_t i = 0;

    // Gérer le signe
    if (str[i] == '-') {
        negative = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Parcourir la chaîne
    while (i < str.size()) {
        char current = str[i];

        // Gérer les chiffres
        if (current >= '0' && current <= '9') {
            result = result * 10.0 + (current - '0');
            if (decimalFound) {
                decimalFactor *= 10.0; // Ajuster le facteur décimal
            }
        }
        // Gérer le point décimal
        else if (current == '.') {
            if (decimalFound) {
                break; // Si un point a déjà été trouvé, sortir
            }
            decimalFound = true;
        }
        // Si un caractère non numérique est trouvé, sortir
        else {
            break;
        }
        i++;
    }

    // Ajuster le résultat pour la partie décimale
    if (decimalFound) {
        result /= decimalFactor;
    }

    // Appliquer le signe
    if (negative) {
        result = -result;
    }

    return result;
}
