/** 
* Ejemplo que implementa una lista ligada 
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "Registro.h"

dateTime pedirDatos(){
  string month, day, hour, minute,second;
  std::cout<<"Mes Dia Hora:Min:Seg"<<std::endl;
  getline(std::cin, month, ' ');
  getline(std::cin, day, ' ');
  getline(std::cin, hour, ':');
  getline(std::cin, minute, ':');
  getline(std::cin, second);
  dateTime fecha(month, stoi(day), stoi(hour), stoi(minute), stoi(second));
  string completeTime= hour+":"+minute+":"+second;
  Registro tmpRecord(month, day, completeTime, "", "", fecha);
  return fecha;
}


int main() {
  std::cout << "Ejemplo de listas ligadas\n";

  DoubleLinkedList<Registro> miLista;
  miLista.loadData();
  
  std::cout << "Imprimiendo la lista\n";
  miLista.printList();
  //Sorting
  miLista.quickSortIterative();
  miLista.createDoc("bitacora_ordenada");

  miLista.printList();

  //Busqueda
  dateTime d1=pedirDatos();
  dateTime d2=pedirDatos();
  int ini=miLista.binarySearch(d1);
  int fin=miLista.binarySearch(d2);
  miLista.printListLimites(ini, fin);

  return 0;
}
