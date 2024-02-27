#include "llrec.h"
#include <iostream>
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == nullptr){
    if(smaller == nullptr && larger == nullptr){
      cout << "Empty list" << endl;
      return;
    }
    larger = nullptr;
    smaller = nullptr;
    return;
  }
  if(head->val > pivot){
    larger = head;
    head = head->next;
    return llpivot(head, smaller, larger->next, pivot);
  }
  else{
    smaller = head;
    head = head->next;
    return llpivot(head, smaller->next, larger, pivot);
  }
}
