
#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include<vector>
#include<iostream>
#include <stdexcept>
#include <climits>
#include <fstream>
#include <string>
#include <cmath>
#include <unordered_map>
#include "RegistroIP.h"
#include "RegistroCantIP.h"

template<class T>
class MaxHeap {
  private:
    // contiene los elementos del heap
    std::vector<T> data; 
    // capacidad maxima del heap
    int maxSize;
    // tamaño actual del heap   
    int size;   
    unordered_map<std::string, int> ipRegistry;
    int parent(int i);
    int left(int i);
    int right(int i);
    string anterior;

  public:
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getSize();
    int getCapacity();
    void printMaxHeap();
    void printData();
    void push(T key);
    void pop();
    void heapify(int);
    void loadData();
    T top();
    //void heapify(int arr[], int n, int i);
    void heapSort();

    void get5Up();

};
  

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }

  template <class T> 
  void MaxHeap<T>::get5Up(){
    ofstream MyFile("ips_con_mayor_acceso.txt");
    for(int i=0;i<5;i++){
      MyFile<<top().getIp()<<": "<<top().getCant()<<endl;
      pop();
    }
  }


  template <class T> 
  void MaxHeap<T>::printData(){
    ofstream MyFile("bitacora_ordenada"); 
    for (int i = 0; i < data.size(); i++) {
      if(data[i].getSuma()==0){
          break;
        }
        MyFile << data[i].getFullText() << endl;
    }
  }

  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      
      std::cout << data[i].getIp() << ": "<<data[i].getCant()<< std::endl;
  }

  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T> 
  void MaxHeap<T>::push(T key) {
    if (size == maxSize) {
        std::cout << "Overflow: no se puede insertar la llave: " << key.getIp() << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getCant() < data[i].getCant()) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }

  template <class T> 
  T MaxHeap<T>::top() {
    T result = RegistroCantIP();
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }
//Se lee los datos de la bitacora_ordenada y se añaden al vector y MaxHeap
 template<class T>
  void MaxHeap<T>::loadData() {
    fstream newfile;
    newfile.open("bitacora_ordenada.txt", ios::in);
    if (newfile.is_open()) {
        string tp, fullText, ipDesc, month, day, completeTime, text, hour, minute, second, ip, msg, pasant;
        string anterior="";
        string num1,num2,num3,num4;
        int usa, suma;
        int cant=0;
        
        while (getline(newfile, tp)){
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
            
            if(anterior==ip2){
              cant++;
              anterior=ip2;
              continue;
            }
            else{
              cant++;
              RegistroCantIP tmpRecord(ip2, cant, suma);
              push(tmpRecord);
              anterior=ip2;
              cant=0;
            }
            //cout<<suma<<endl;
            //cout<<tmpRecord.getIp()<<endl;

        }
        newfile.close();
    }
}


///////////////////////////////////////////////////////////////
/*
template <class T> 
void MaxHeap<T>::heapify(int arr[], int n, int i)
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
/*
template <class T> 
void MaxHeap<T>::heapSort()
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
*/
  //Funcion de heapify asegura que nuestro vector siga siendo un heap
  //Se asegura de esto mediante un swap que ocurre si el valor del hijo es mayor que el del padre

  template <class T> 
  void MaxHeap<T>::heapify(int i){
          //Sacamos left y right
      int l = left(i);
      int r = right(i);

      //Inicializamos largest como el valor ingresado
      int largest = i;

      //Encontramos el valor mayor entre right y left
      if (l < getSize() && data[l].getCant() > data[i].getCant()) {
          largest = l;
      }

      if (r < getSize() && data[r].getCant() > data[largest].getCant()) {
          largest = r;
      }

      //Hace el swap con el hijo que tenga el valor mayor
      if (largest != i)
      {
          //Se hace el swap
          std::swap(data[i], data[largest]);
          //Se vuelve a llamar heapify (es recursivo) hasta que largest=i
          heapify(largest);
      }
  }
/*
  
template <class T>
  T MaxHeap<T>::pop(){
    T out = data[0];
    size--;
    std::swap(data[0], data[size]);
    data[size] = RegistroCantIP();

    int ref = 0;
    int l = left(ref);
    int r = right(ref);

    while(data[ref].getCant() < data[l].getCant() || data[ref].getCant() < data[r].getCant()){

      if(data[ref].getCant() < data[r].getCant()){
        std::swap(data[ref], data[r]);
        ref = r;
      } else if(data[ref].getCant() < data[l].getCant()){
        std::swap(data[ref], data[l]);
        ref = l;
      }
      l = left(ref);
      r = right(ref); 
    }
    return out;
  }
  */
  template <class T> 
  void MaxHeap<T>::pop(){
        try {
            //Si no hay elementos en el heap, lanza una excepcion
            if (isEmpty()){
                throw std::out_of_range("No hay suficientes elementos para hacer un pop");
            }
            //Movemos el ultimo elemento del heap hacia el root y borramos el ultimo elemento
            data[0] = data.back();
            data.pop_back();

            //Inicializamos el metodo de heapify desde el root
            heapify(0);
            size--;
        }
        //Se hace catch de la excepcion(en caso de quererle hacer pop a un heap vacio)
        catch (const std::out_of_range &oor) {
            std::cout << std::endl << oor.what();
        }
  }


#endif // __MAXHEAP_H_