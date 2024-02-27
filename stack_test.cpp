#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;




int main()
{
  Stack<int> mystack;
  mystack.push(100);
  mystack.push(200);
  cout << mystack.top() << endl;
  mystack.pop();
  cout << mystack.top() << endl;
  mystack.pop();
  cout << mystack.top() << endl;
    
  return 0;

}
