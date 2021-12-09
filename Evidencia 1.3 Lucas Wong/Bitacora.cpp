#include "Bitacora.h"
#include "Registro.h"
#include "dateTime.h"
//Clase para poder almacenar los registros y poder ordenarlos y buscarlos
Bitacora::Bitacora() {
  listaRegistro.clear();
  totalRegistros = 0;
}
vector<Registro> Bitacora::getVector(){
  return listaRegistro;
}
//LOAD DATA
void Bitacora::loadData() {
    fstream newfile;
    newfile.open("bitacora.txt", ios::in);
    if (newfile.is_open()) {
        string tp, fullDate, ipDesc, month, day, completeTime, text, hour, minute, second, ip, msg;
        
        while (getline(newfile, tp))
        {
            month = tp.substr(0, 3);
            day = tp.substr(4, 2);
            completeTime = tp.substr(7, 8);
            text = tp.substr(16, -1);
            fullDate = tp.substr(0, 15);
            ipDesc = tp.substr(16, tp.size());
            ip = ipDesc.substr(0, ipDesc.find(" "));
            msg = ipDesc.substr(ipDesc.find(" ")+1);
            hour = completeTime.substr(0,2);
            minute = completeTime.substr(3,2);
            second = completeTime.substr(6,2);
            dateTime fecha(month, stoi(day), stoi(hour), stoi(minute), stoi(second));
            Registro tmpRecord(month, day, completeTime, ip, msg, fecha);
            listaRegistro.push_back(tmpRecord);
            totalRegistros++;
        }
        newfile.close();
    }
}
//QUICKSORT
void Bitacora::swap(Registro* a, Registro* b){
  Registro t = *a;
  *a = *b;
  *b = t;
}

int Bitacora::partition(int low, int high){
  dateTime pivot = listaRegistro[high].getFechaHora();
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++){
        dateTime dateIndx = listaRegistro[j].getFechaHora();
        if (dateIndx <= pivot){
            i++;    
            swap(&listaRegistro[i], &listaRegistro[j]);
        }
    }
    swap(&listaRegistro[i + 1], &listaRegistro[high]);
    return (i + 1);
}

void Bitacora::quickSort(int low, int high){
  if (low < high){
        int numLen = partition(low, high);
        quickSort(low, numLen - 1);
        quickSort(numLen + 1, high);
    }
}

//ORDENAMIENTO BINARY SEARCH

int Bitacora::binary_search(vector<Registro> &sorted_vec, string keyO) {
  string Mes;
  int seg, min, hor, dia;
  Mes=keyO.substr(0,3);
  dia=stoi(keyO.substr(4,2));
  hor=stoi(keyO.substr(7,2));
  min=stoi(keyO.substr(10,2));
  seg=stoi(keyO.substr(13,2));

  dateTime fecha(Mes,dia,hor,min,seg);
   size_t mid, left = 0 ;
   size_t right = sorted_vec.size();
   while (left < right) {
      mid = left + (right - left)/2;
      if (fecha > sorted_vec[mid].getFechaHora()){
          left = mid+1;
      }
      else if (fecha < sorted_vec[mid].getFechaHora()){        
        right = mid;
      }
      else if (fecha==sorted_vec[mid].getFechaHora()){
        return mid;
     }                                               
   }
   return 0;      
}