#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;




int main()
{
  Heap<int> myheap;
  myheap.push(5);
	myheap.push(10);
	myheap.push(0);
  myheap.print();
	myheap.pop();
	myheap.pop();
    
  return 0;

}