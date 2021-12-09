
#include "Bitacora.h"
#include <fstream>

using namespace std;

int main() {
  //Crear un File.txt nuevo llamado: Output
  ofstream MyFile("bitacora_ordenada.txt"); 
  Bitacora miLista;
  miLista.loadData();
  miLista.quickSort(0, miLista.getVector().size()-1);
  vector<Registro> Vec_ordenado = miLista.getVector();
  MyFile<<"Datos del Vector Ordenado"<<endl;
  for (int i = 0; i < Vec_ordenado.size(); i++){
        MyFile << Vec_ordenado[i].getMes() << " "<<Vec_ordenado[i].getDia() << " "<< Vec_ordenado[i].getHora() << " " << Vec_ordenado[i].getIp() << " "<<Vec_ordenado[i].getFalla() << endl;
    }
  //Pedir datos para poder realizar el Binary Search
  int input;
  string Mes,dia,hor,min,seg;
  string search;
  cout<<"Ponga los datos de la 1ra fecha que desee buscar:"<<endl;
  cout<<"Mes(###): ";
  cin>>Mes;
  cout<<"Dia(##): ";
  cin>>dia;
  cout<<"Hora(##): ";
  cin>>hor;
  cout<<"Minuto(##): ";
  cin>>min;
  cout<<"Segundo(##): ";
  cin>>seg;
  search=Mes+" "+dia+" "+hor+":"+min+":"+seg;
  cout<<search<<endl;
  input=miLista.binary_search(Vec_ordenado, search);

  //Oct 17 09:20:30
  cout<<"Ponga los datos de la 2da fecha que desee buscar:"<<endl;
  cout<<"Mes(###): ";
  cin>>Mes;
  cout<<"Dia(##): ";
  cin>>dia;
  cout<<"Hora(##): ";
  cin>>hor;
  cout<<"Minuto(##): ";
  cin>>min;
  cout<<"Segundo(##): ";
  cin>>seg;
  string search2=Mes+" "+dia+" "+hor+":"+min+":"+seg;
  int input2;
  input2=miLista.binary_search(Vec_ordenado, search2);
  MyFile<<"Datos del Binary Search"<<endl;
  for(int i=input; i<=input2;i++){
    MyFile << Vec_ordenado[i].getMes() << " "<<Vec_ordenado[i].getDia() << " "<< Vec_ordenado[i].getHora() << " " << Vec_ordenado[i].getIp() << " "<<Vec_ordenado[i].getFalla() << endl;
  }
  // sirve solo con listaRegistro publica
  //cout << miLista.listaRegistro[0].getFechaHora().getDate() << endl;
  //cout << miLista.listaRegistro[1].getFechaHora().getDate() << endl;
  
  
}