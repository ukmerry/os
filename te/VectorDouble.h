#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

using namespace std;

class VectorDouble
{
private:
  
public:
  int max_count;
  int count;
  double* arr;
  
  VectorDouble();
  VectorDouble(int max_count);
  VectorDouble(const VectorDouble& copy);
  ~VectorDouble();
  VectorDouble operator =(VectorDouble& copy);
  
  bool operator ==(VectorDouble b) const ;
  void push_back(double num);
  int capacity();
  int size();
  void reserve(unsigned int size);
  void resize(unsigned size, double defaultVal = 0.0);
  double value_at(unsigned int i);
  void change_value_at(double newValue, unsigned int i);
  friend ostream& operator<<(ostream& os, const VectorDouble &vd);
  // DO NOT CHANGE THE FOLLOWING LINE OF CODE. It is for the testing framework
  // DO NOT IMPLEMENT THE FOLLOWING FUNCTION. It is implemented by the testing framework
};

#endif
