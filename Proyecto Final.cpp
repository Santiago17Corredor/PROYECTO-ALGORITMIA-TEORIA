#include "iostream"
#include "string"
//incluimos libreria para usar topper, funcion para mayusculas
#include "cctype"
using namespace std;
string PalabraMayus(const string& palabra);
void cifrar();
void descifrar();

int main(){
    int a=3;

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

cifrar();}}

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
    char matriz[26][26];
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int r, k;
    string palabra;
    string clave;
    string paci;
    string palabracifrada;
    string palabra2;
    int po = 0, longitudPalabra = 0, longitudClave = 0;

    cout << "-----------------------------------------" << endl;
    //crear matriz de vigenere

    for (int fila = 0; fila < 26; fila++) {
        r = fila;
        for (int columna = 0; columna < 26; columna++) {
            //sacamos %26 para que al llegar al tope, se repita la string
            matriz[fila][columna] = alf[r % 26];
            r++;
        }
    }

    cout << " digite la palabra a cifrar (sin espacios)" << endl;
    cin >> palabra;
//convertir palabra a mayusculas silenciosamente con funcion
    string PalabraMayuscula = PalabraMayus(palabra);

    //cout<<PalabraMayuscula<<endl;
    palabra=PalabraMayuscula;
    paci=palabra;


    cout << "digite la clave" << endl;
    cin >> clave;
    //convertir tambien clave a mayusculas usando funcion creada
     string ClaveMayuscula = PalabraMayus(clave);
     clave=ClaveMayuscula;
     //cout<<clave;

    longitudPalabra = palabra.length();
    longitudClave = clave.length();

//cuantos caracteres tiene la palabra que se quiere cifrar:
    //cout << "la palabra a cifrar tiene: " << longitudPalabra << " caracteres" << endl;

//arrastrar la clave conforme la palabra
    for (po = 0; po < longitudPalabra; po++) {
        paci[po] = clave[po % longitudClave];
    }

//impresiones de datos hasta el momento..
cout<<"REGISTRO DE DATOS INGRESADOS: "<<endl;
    cout << "la palabra original es: " << palabra << endl;
    cout << "la palabra medio cifrada es: " << paci << endl;
    cout << "------------es hora de cifrar------------" << endl;
    cout << endl;
    cout << "---------------matriz de vigenere---------------" << endl;

    //impresion de la matriz de vigenere creada anteriormente
    for (int fila = 0; fila < 26; fila++) {
        for (int columna = 0; columna < 26; columna++) {
            cout << matriz[fila][columna] << "|";
        }
        cout << endl;
    }
    cout << endl;
    cout <<"-----en base a la tabla anterior cifraremos el mensaje-----"<<endl;
    cout << endl;

    int posicioncol;
    int posicionfil;
    //proceso de cifrado del mensaje
    for (int h = 0; h < longitudPalabra; h++) {

        for (int columna = 0; columna < 26; columna++) {
            if (palabra[h] == matriz[0][columna]) {
                //cout << "encontraste " << matriz[0][columna] << "!!!" << endl;
                posicioncol = columna;
                //cout << posicioncol << endl;

                for (int fila = 0; fila < 26; fila++) {

                    if (paci[h] == matriz[fila][0]) {
                        //cout << "encontraste " << matriz[fila][0] << "!!!" << endl;
                        posicionfil = fila;
                        //cout << posicionfil << endl;
                    }
                }
                //imprimir caracter interseccion
                palabracifrada+= matriz[posicionfil][posicioncol];
            }
        }
    }
    cout<<"La palabra ciifrada es: "<<palabracifrada;
}

