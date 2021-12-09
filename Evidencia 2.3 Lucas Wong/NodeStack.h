#ifndef _NODEStack_H_
#define _NODEStack_H_

  #include<iostream>

  template <class T>
  class NodeStack { 
  public: 
      T data; 
      NodeStack<T>* next;
      NodeStack();
      NodeStack(T);        
  }; 

  template<class T>
  NodeStack<T>::NodeStack(){
      data = 0;
      next = NULL;
  }
  template<class T>
  NodeStack<T>::NodeStack(T val){
      data = val;
      next = NULL;
  }

#endif // _NODEStack_H_