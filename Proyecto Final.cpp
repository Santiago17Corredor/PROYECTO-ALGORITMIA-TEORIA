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

void matriz1(){
    char matriz[26][26];
   string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int r;
    string palabra;
    string clave;
    string paci;
    int po=0,longitudPalabra=0,longitudClave=0;

    cout<<"-----------------------------------------"<<endl;

    for(int fila = 0; fila < 26; fila++){
        r = fila;
        for(int columna = 0; columna < 26; columna++) {
            matriz[fila][columna] = alf[r % 26];
            r++;}}

    cout << " digite la palabra a cifrar" << endl;
    cin >> palabra;

    paci=palabra;

    cout << "digite la clave" << endl;
    cin >>clave;

    longitudPalabra = palabra.length();
    longitudClave = clave.length();

    cout<<"la palabra a cifrar tiene: "<<longitudPalabra<<" caracteres"<<endl;

    for ( po=0; po<longitudPalabra;po++) {

        paci[po]=clave[po%longitudClave];}

    cout<<"la palabra original es: "<<palabra<<endl;
    cout<<"la palabra cifrada es: "<<paci<<endl;
    cout<<"------------es hora de cifrar------------"<<endl;

    for(int fila = 0; fila < 26; fila++){
        for(int columna = 0; columna < 26; columna++){
            cout << matriz[fila][columna] << "|";}
        cout << endl;}}

