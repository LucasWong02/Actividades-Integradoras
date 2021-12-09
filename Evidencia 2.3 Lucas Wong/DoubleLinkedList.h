#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_
#include <climits>
#include <fstream>
#include "Node.h"
#include "Registro.h"
#include "Stack.h"

  template <class T>
  class DoubleLinkedList {
      private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

      public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void printList();
        void printListLimites(int ini, int fin);
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        Registro getDataReg(int position);
        Node<T>* getNodo(int position);
        Node<T> *lastNode(Node<T> *root);
        Node<T>* partition(Node<T> *l, Node<T> *h);
        void swap (T &a, T &b);
        void quickSortIterative();
        void loadData();
        void createDoc(string n);
        int binarySearch(dateTime t);
  };

  template<class T>
  DoubleLinkedList<T>::DoubleLinkedList() {
      std::cout << "--->Creando una lista vacia " << this << std::endl;
      head = NULL;
      tail = NULL;
      numElements = 0;
  }
  
  template<class T>
  DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }
  template<class T>
  void DoubleLinkedList<T>::printListLimites(int ini, int fin){
    ofstream MyFile("resultado_busqueda"); 

    Node<T> *ptr = head;
    if(ini==0){
      for(int j=0;j<=fin-ini;j++) {
          std::cout << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
          MyFile << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
          ptr = ptr->next;
      }
    }
    else{
      for(int i=0;i<ini;i++){
        ptr=ptr->next;
      }
      for(int j=0;j<=fin-ini;j++) {
          std::cout << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
          MyFile << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
          ptr = ptr->next;
      }
    }
    std::cout << std::endl;
  }
//Complejidad Computacional: O(N) o O(N log(N))
  template<class T>
  int DoubleLinkedList<T>::binarySearch(dateTime t){
    int n=0;
    int r=numElements;
    Node<T> *temp=head;
    while(n<=r){
      int m=n+(r-n)/2;
      if(t==this->getDataReg(m).getFechaHora()){
        return m;
      }
      else if(t<this->getDataReg(m).getFechaHora()){
        r=m-1;
      }
      else{
        n=m+1;
      }
    }
    return -1;
  }

  template<class T>
  Node<T>* DoubleLinkedList<T>::getNodo(int position){
    Node<T>* res=head;
    for(int i=0;res!=NULL;i++){
      if(i==position){
        break;
      }
      res=res->next;
    }
    return res;
  }
//Complejidad Computacional: O(1)
  template<class T>
  Registro DoubleLinkedList<T>::getDataReg(int position){
    return this->getNodo(position)->data;
  }
  
  template<class T>
  void DoubleLinkedList<T>::createDoc(string n) {
    ofstream MyFile(n); 
    Node<T> *ptr = head;
    while (ptr != NULL) {
        MyFile << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
        ptr = ptr->next;
    }
  }

  template<class T>
  void DoubleLinkedList<T>::loadData() {
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
            this->addLast(tmpRecord);
        }
        newfile.close();
    }
}
////////////// ITERATIVE QUICKSORT //////////////
//Complejidad Computacional: O(N^2)
template<class T>
void DoubleLinkedList<T>::swap ( T &a, T &b )
{ T t = a; a = b; b = t; }
 

template<class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
    // Seteamos el pivot
    dateTime x = h->data.getFechaHora();
    
    Node<T> *i = l->prev;
 
 
    for (Node<T> *j = l; j != h; j = j->next){
        if (j->data.getFechaHora() <= x){
 
            i = (i == NULL)? l : i->next;
 
            swap(i->data, j->data);
        }
    }
    i = (i == NULL)? l : i->next; // Igual que i++
    swap(i->data, h->data);
    return i;
}

//Complejidad Computacional: O(N^2)
template<class T>
void DoubleLinkedList<T>::quickSortIterative(){
    // Creamos Stack

    Node<T> *l=head;
    Node<T> *h=tail;
    Stack<Node<T> *> auxiliar;


    //Hacemos push a valores iniciales de l y h a stack
    auxiliar.push(l);
    auxiliar.push(h);
 
    //Hacemos pop mientras que no este vacio el stack
    while (!auxiliar.isEmpty()) {
        // Pop h y l
        h = auxiliar.pop();
        l = auxiliar.pop();
 
        // Aplicamos la particion
        Node<T> *p = partition(l, h);
 
        //Si hay un elemento a la izquierda del pivot entonces hacemos push a la parte izquierda del stack
        if (p->data.getFechaHora() > l->data.getFechaHora()) {
            auxiliar.push(l);
            auxiliar.push(p->prev);
        }
 
        // Si hay un elemento a la derecha del pivot entonces hacemos push a la parte derecha del stack
        if (p->data.getFechaHora() < h->data.getFechaHora()) {
            auxiliar.push(p->next);
            auxiliar.push(h);
        }
    }
}
////////////// ITERATIVE QUICKSORT //////////////

//Complejidad Computacional: O(1)
  template<class T>
  int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data.getMes() << " " <<ptr->data.getDia() << " "<< ptr->data.getHora() << " " << ptr->data.getIp() << " "<<ptr->data.getFalla() << endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }
  
//Complejidad Computacional: O(N)
  template<class T>
  void DoubleLinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia 
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
//Complejidad Computacional: O(N)
  template<class T>
  void DoubleLinkedList<T>::addLast(T value) {
    // La lista esta vacia
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }
  }
  
  template<class T>
  bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL) {
      return false;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DoubleLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else { // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
T DoubleLinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    std::cout << "Indice fuera de rango" << std::endl;
    return -1;
  }
  else {
    if (position == 0)
      return head->data;
    Node<T> *p = head;
    int index = 0;
    while (p != NULL) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return -1;
  }
}
template<class T>
Node<T> DoubleLinkedList<T>::*lastNode(Node<T> *root){
    while (root && root->next)
        root = root->next;
    return root;
}
 




  
#endif // _DOUBLELINKEDLIST_H_