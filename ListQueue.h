#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "DblList.h"

template <typename T>
class ListQueue: private DblList<T>{ //inherit from the DL List but don't make an is-a relationship
public:
  ListQueue(bool isMin); //min queue or not
  virtual ~ListQueue();
  void add(T data);
  T remove();
  int size();
  bool isEmpty();
  T peek();

private:
  bool isMinQ;
};

template <typename T>
bool ListQueue<T>::isEmpty(){
  return DblList<T>::isEmpty();
}

template <typename T>
int ListQueue<T>::size(){
  return DblList<T>::size();
}

template <typename T>
ListQueue<T>::ListQueue(bool isMin){
  isMinQ = isMin;
}

template <typename T>
ListQueue<T>::~ListQueue(){
}

template <typename T>
T ListQueue<T>::remove(){
  if(isMinQ){
    return DblList<T>::removeFront(); //smallest always at front
  } else{
    return DblList<T>::removeBack(); //largest always at back
  }
}

template <typename T>
void ListQueue<T>::add(T d){
  if(isEmpty()){ //well, that's easy. Just add.
    DblList<T>::addFront(d);
    return;
  }
  ListNode<T>* newNode = new ListNode<T>(d);
  int currIdx = 0;
  ListNode<T>* currNode = DblList<T>::m_front;
  while(currNode != NULL && currNode->m_data < d){ //from front, find the right place to add. The < operator better be defined on the class.
    ++currIdx;
    currNode = currNode->m_next;
  }
  DblList<T>::add(currIdx,d); //this is a hack because it starts over looking from front. But doesn't change linear runtime. Just 2x as slow in practice.
}


#endif