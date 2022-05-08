#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

string randomName(){
    ifstream fileN("txtfiles/names.txt");
    string name, name_r;
    int random = rand()%1000+1;
    
    int counter = 1;
    while (getline(fileN, name)){
        if(counter == random){
            name_r = name;
        }
        counter++;
    }

    return name_r;
}

string randomCognome(){
    ifstream fileC("txtfiles/surnames.txt");
    string name, name_r;
    int random = rand()%1000+1;
    
    int counter = 1;
    while (getline(fileC, name)){
        if(counter == random){
            name_r = name;
        }
        counter++;
    }

    return name_r;
}


struct Scolaro{
    string Nome;
    string Cognome;
    int eta;
    int classe;
};

int main(){
    srand(time(NULL));
    int random;
    int N = 100;
    Scolaro umano[N];

    for(int i = 0; i < N; i++){
        umano[i].Nome = randomName();
        umano[i].Cognome = randomCognome();
        umano[i].classe = rand()%5+1;
        umano[i].eta = umano[i].classe + 13;
    }

    for(int i = 0; i < N; i++){
        cout << "Nome: " << umano[i].Nome << endl;
        cout << "Cognome: " << umano[i].Cognome << endl;
        cout << "Classe: " << umano[i].classe << endl;
        cout << "Eta: " << umano[i].eta << endl;
        cout << "---------------------" << endl;
    }
}