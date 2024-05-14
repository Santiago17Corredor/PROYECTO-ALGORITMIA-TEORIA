#include "iostream"
#include "string"
//incluimos libreria para usar topper, funcion para mayusculas
#include "cctype"
using namespace std;
string PalabraMayus(const string& palabra);
void cifrar();
void descifrar();
int inicio();

int main(){
    int b= inicio();
    if(b==1){
        cifrar();
    }else if(b==2){
        descifrar();
    }
    }
string PalabraMayus(const string& palabra){
    string palabraMayuscula;
    palabraMayuscula = palabra;
    for(char& c:palabraMayuscula){
        if (islower(c)) {
            c = toupper(c);
        }
    }
    return palabraMayuscula;
}
void cifrar() {
    string alf = "ABCDEFGHIJKLMNOPQRSTXYZ";
    string paci;
    string palabracifrada;
    string palabra;
    string clave;
    string cifrada;

    cout<<"digite palabra"<<endl;
    cin>>palabra;

    string PalabraMayuscula = PalabraMayus(palabra);
    palabra=PalabraMayuscula;

    cout<<"digite clave"<<endl;
    cin>>clave;

    string ClaveMayuscula = PalabraMayus(clave);
    clave=ClaveMayuscula;


    for (int po = 0; po <palabra.length(); po++) {//pedro 5,
        paci += clave[po % clave.length()];
    }

    for(int h=0;h<palabra.length();h++){
        //cout<<(int(palabra[h])-65)<<" "<<(char(palabra[h]))<<" ";
        //cout<<(int(clave[h])-65)<<" "<<(char(clave[h]))<<" "<<endl;
        palabracifrada += char((((int(palabra[h]-65))+(int(paci[h]-65)))%26)+65);}
    cout<<"La palabra cifrada es: ";
    cout<<palabracifrada;}
void descifrar() {
    int pr=0;
    string pade;
    string palabracifrada;
    string clave;
    string clave2;
    cout<<"digite la palabra cifrada"<<endl;
    cin>>palabracifrada;

    string PalabraMayuscula = PalabraMayus(palabracifrada);
    palabracifrada=PalabraMayuscula;

    cout<<"digite clave"<<endl;
    cin>>clave;

    string ClaveMayuscula = PalabraMayus(clave);
    clave=ClaveMayuscula;

    for (int po = 0; po <palabracifrada.length(); po++) {//pedro 5,
        clave2 += clave[po % clave.length()];
    }
    for(int h=0;h<palabracifrada.length();h++){

        pade+=char(((((int(palabracifrada[h]-65))-(int(clave2[h]-65)))+26)%26)+65);
    }
    cout<<"la palabra descifrada es: "<<pade;
}
int inicio() {

    int a;
    while(a>3 || a<1){
        cout << "esa no es una opcion, escoja otra" <<endl;
        cout << "Que desea hacer?" <<endl;
        cout << " 1)Cifrar \n 2)Descifrar \n 3)Salir" <<endl;
        cin>>a;}
    return a;
}
      
