#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Registro.h"

using namespace std;

class Bitacora {
  private:
    //Vector para almacenar datos
    vector<Registro> listaRegistro;
    int totalRegistros;

  public:
    Bitacora();
    vector<Registro> getVector();
    // Leer datos
    void loadData();
    // Agregar metodo para ordenar
    void swap(Registro* a, Registro* b);
    int partition(int, int);
    void quickSort(int, int);
    // Agregar metodo para busqueda binaria
    int binary_search(vector<Registro> &sorted_vec, string keyO);
};

#endif // _BITACORA_H_