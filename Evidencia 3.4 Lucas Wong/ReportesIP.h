/////////////Sirve para ordenar los registro de IPs/////////////
#ifndef __ReportesIP_H_
#define __ReportesIP_H_

#include<vector>
#include<iostream>
#include <stdexcept>
#include <climits>
#include <fstream>
#include <string>
#include <cmath>
#include <unordered_map>
#include "RegistroIP.h"

template<class T>
class ReportesIP {
  private:
    // contiene los elementos del heap
    std::vector<T> data; 
    // capacidad maxima del heap
    int maxSize;
    // tamaño actual del heap   
    int size;

  public:
    ReportesIP();
    ~ReportesIP();
    bool isEmpty();
    int getSize();
    int getCapacity();
    void printReportesIP();
    void writeData();
    void heapify(int, int);
    void loadData();
    //void heapify(int arr[], int n, int i);
    void heapSort();
};
  

  template <class T> 
  ReportesIP<T>::ReportesIP() {
      std::cout << "--->Creando un ReportesIP: " <<  this << std::endl;
      size = 0;

  }

  template <class T> 
  ReportesIP<T>::~ReportesIP() {
      std::cout << "--->Liberando memoria del ReportesIP: " <<  this << std::endl;
      data.clear();
  }


  template <class T> 
  void ReportesIP<T>::writeData(){
    ofstream MyFile("bitacora_ordenada.txt"); 
    for (int i = 0; i < data.size(); i++) {
      if(data[i].getSuma()==0){
          break;
        }
        MyFile << data[i].getFullText() << endl;
    }
  }

  template <class T> 
  bool ReportesIP<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int ReportesIP<T>::getSize() {
    return size;
  }

  template <class T> 
  int ReportesIP<T>::getCapacity() {
    return maxSize;
  }

  template <class T> 
  void ReportesIP<T>::printReportesIP() {
    for (int i=0; i < size; i++)
      std::cout << data[i].getFullText() << std::endl;
  }
//leo Datos del bitacoraHeap y los meto al vector
 template<class T>
  void ReportesIP<T>::loadData() {
    fstream newfile;
    newfile.open("bitacoraHeap.txt", ios::in);
    if (newfile.is_open()) {
        string tp, fullText, ipDesc, month, day, completeTime, text, hour, minute, second, ip, msg, pasant;
        string num1,num2,num3,num4;
        int usa, suma;
        
        while (getline(newfile, tp))
        {
            usa=tp.find(" ")+1;
            pasant = tp.substr(usa, -1);
            usa=pasant.find(" ")+1;
            hour = pasant.substr(usa, -1);
            usa=hour.find(" ")+1;
            minute = hour.substr(usa, -1);
            fullText=tp;

            //cout<<minute<<endl;
            usa=minute.find(" ")+1;
            msg= minute.substr(usa,-1);
            //cout<<msg<<endl;
            ip=minute.substr(0,usa);
            //cout<<ip<<endl;

            usa=ip.find(":");
            string ip2=ip.substr(0,usa);
            //cout<<ip2<<endl;

            usa=ip2.find(".")+1;
            num1=ip2.substr(0,usa-1);
            pasant= ip2.substr(usa,-1);
            //cout<<num1<<endl;
            
            usa=pasant.find(".")+1;
            num2=pasant.substr(0,usa-1);
            pasant= pasant.substr(usa,-1);
            //cout<<num2<<endl;

            usa=pasant.find(".")+1;
            num3=pasant.substr(0,usa-1);
            pasant= pasant.substr(usa,-1);
            //cout<<num3<<endl;

            usa=pasant.find(".")+1;
            num4=pasant.substr(0,usa-1);
            pasant= pasant.substr(usa,-1);
            //cout<<num4<<endl;
            long long int suma=(pow(256,3)*stoi(num1))+(pow(256,2)*stoi(num2))+(pow(256,1)*stoi(num3))+(pow(256,0)*stoi(num4));            
            //cout<<suma<<endl;            
            RegistroIP tmpRecord(fullText, ip, suma);
            data.push_back(tmpRecord);
            size++;
            //cout<<tmpRecord.getIp()<<endl;

        }
        newfile.close();
    }
}


///////////////////////////////////////////////////////////////
/*
template <class T> 
void ReportesIP<T>::heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l].getSuma() > arr[largest].getSuma())
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r].getSuma() > arr[largest].getSuma())
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 */
// main function to do heap sort
template <class T> 
void ReportesIP<T>::heapSort()
{
    // Build heap (rearrange array)
    int n=size;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(data[0], data[i]);
 
        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}

///////////////////////////////////////////////////////////////

  //Funcion de heapify asegura que nuestro vector siga siendo un heap
  //Se asegura de esto mediante un swap que ocurre si el valor del hijo es mayor que el del padre

  template <class T> 
  void ReportesIP<T>::heapify(int n, int i){
      
      //Inicializamos largest como el valor ingresado
      int largest = i;
      //Sacamos left y right
      int l = 2 * i + 1; // left = 2*i + 1
      int r = 2 * i + 2; // right = 2*i + 2

      //Encontramos el valor mayor entre right y left
      if (l < n && data[l].getSuma() > data[largest].getSuma()) {
          largest = l;
      }
      if (r < n && data[r].getSuma() > data[largest].getSuma()) {
          largest = r;
      }
      //Hace el swap con el hijo que tenga el valor mayor
      if (largest != i){
          //Se hace el swap
          std::swap(data[i], data[largest]);
          //Se vuelve a llamar heapify (es recursivo) hasta que largest=i
          heapify(n,largest);
      }
  }


#endif // __ReportesIP_H_