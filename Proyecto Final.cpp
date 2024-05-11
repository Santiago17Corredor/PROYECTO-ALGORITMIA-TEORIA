#include "iostream"
#include "string"
using namespace std;

void matriz1();

int main(){
    int a=2;

    cout<<"Que desea hacer?"<<endl;
    cout<<" 1)Cifrar \n 2)Descifrar \n 3)Salir"<<endl;
    cin>>a;

while(a>3 || a<1){
    cout << "esa no es una opcion, escoja otra" << endl;
    cout << "Que desea hacer?" << endl;
    cout << " 1)Cifrar \n 2)Descifrar \n 3)Salir" << endl;
cin>>a;}

    cout<<"usted escogio "<<a<<endl;

if(a==1){

matriz1();}}

void matriz1() {
    char matriz[26][26];
    //cin.ignore();
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int r, k;
    string palabra;
    string clave;
    string paci;
    string palabracifrada;
    int po = 0, longitudPalabra = 0, longitudClave = 0;

    cout << "-----------------------------------------" << endl;

    for (int fila = 0; fila < 26; fila++) {
        r = fila;
        for (int columna = 0; columna < 26; columna++) {
            matriz[fila][columna] = alf[r % 26];
            r++;
        }
    }

    cout << " digite la palabra a cifrar sin espacios" << endl;
    cin >> palabra;
    paci = palabra;

    cout << "digite la clave" << endl;
    cin >> clave;

    longitudPalabra = palabra.length();
    longitudClave = clave.length();

    cout << "la palabra a cifrar tiene: " << longitudPalabra << " caracteres" << endl;

//arrastrar la clave conforme la palabra
    for (po = 0; po < longitudPalabra; po++) {
        paci[po] = clave[po % longitudClave];
    }


    cout << "la palabra original es: " << palabra << endl;
    cout << "la palabra medio cifrada es: " << paci << endl;
    cout << "------------es hora de cifrar------------" << endl;
    cout << "------------matriz de vigenere------------" << endl;
    for (int fila = 0; fila < 26; fila++) {
        for (int columna = 0; columna < 26; columna++) {
            cout << matriz[fila][columna] << "|";
        }
        cout << endl;
    }
    
    int posicioncol;
    int posicionfil;

    for (int columna = 0; columna < 26; columna++) {

        if (palabra[0] == matriz[0][columna]) {
            cout << "encontraste " << matriz[0][columna] << "!!!" << endl;

            posicioncol = columna;
            cout << posicioncol << endl;
        }
    }
    for (int fila = 0; fila < 26; fila++) {

        if (paci[0] == matriz[fila][0]) {
            cout << "encontraste " << matriz[fila][0] << "!!!" << endl;
            posicionfil = fila;
            cout << posicionfil << endl;
        }


    }
    //imprimir caracter interseccion
    cout << matriz[posicionfil][posicioncol];


}