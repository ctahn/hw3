#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void print() const;

private:
  std::vector<T> vec;
  void trickle_down(int idx);
  void trickle_up(int loc);
  PComparator comp;
  int mary;
};

template <typename T, typename PComparator>
void Heap<T,PComparator>::print() const
{
  for(size_t i = 0; i < vec.size(); i++){
    std::cout << this->vec[i] << " ";
  }
  std::cout << std::endl;
}


// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  comp = c;
  mary = m;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickle_up(int loc)
{
  int parent = (int)((loc-1)/mary);
  if(loc == 1 && comp(vec[1], vec[0])){
    T temp = vec[1];
    vec[1] = vec[0];
    vec[0] = temp;
    return;
  }
  while(parent >= 0 && comp(vec[loc],vec[parent])){
    T temp = vec[loc];
    vec[loc] = vec[parent];
    vec[parent] = temp;
    loc = parent;
    parent = (int)((loc-1)/mary);
  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickle_down(int idx)
{
  int leftChild = mary*idx+1;
  int smallerChild = leftChild;
  if(smallerChild >= (int)(vec.size())){
    return;
  }
  for(int i = 1; i < mary;i++){
    if((leftChild+i) < (int)(vec.size())){
      int rChild = (leftChild + i);
      if(comp(vec[rChild],vec[smallerChild])){
        smallerChild = rChild;
      }
    }
  }
  if(comp(vec[smallerChild],vec[idx])){
    T temp = vec[idx];
    vec[idx] = vec[smallerChild];
    vec[smallerChild] = temp;
    this->trickle_down(smallerChild);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  T temp = vec[0];
  vec[0] = vec[vec.size()-1];
  vec[vec.size()-1] = temp;
  vec.pop_back();
  this->trickle_down(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return vec.std::vector<T>::empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return vec.std::vector<T>::size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec.push_back(item);
  this->trickle_up(vec.size()-1);
}

#endif

