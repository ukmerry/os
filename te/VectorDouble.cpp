#include "VectorDouble.h"
#include <iostream>

using namespace std;

VectorDouble::VectorDouble() {
  arr = new double[50];
  max_count = 50;
  count = 0;
}

VectorDouble::VectorDouble(int max_count) {
  arr = new double[max_count];
  this->max_count = max_count;
  count = 0;
}

VectorDouble::VectorDouble(const VectorDouble& copy){
  arr = new double [copy.max_count];
  max_count = copy.max_count;
  count = copy.count;
  for(int i=0;i<copy.count; i++)
    arr[i] = copy.arr[i];
  
}

VectorDouble::~VectorDouble() {
  delete [] arr;
}

VectorDouble VectorDouble::operator =(VectorDouble& copy) {
  if (this != &copy){
    arr = new double [copy.max_count];
    count = copy.count;
    for(int i=0;i<copy.count; i++)
      arr[i] = copy.arr[i];
    
  }
  return *this;
}
bool VectorDouble::operator ==(VectorDouble b) const {
  if (this->count!=b.count)
  {
    return false;
  }
  for (int i=0; i<count; i++)
  {
    if (this->arr[i] != b.arr[i])
      return false;
  }
  
  return true;
}


void VectorDouble::push_back(double num) {
  if(count == max_count)
    reserve(max_count + 1);
  
  arr[count++] = num;
}

int VectorDouble::capacity() {
  return max_count;
}

int VectorDouble::size() {
  return count;
}

void VectorDouble::resize(unsigned int size, double defaultVal) {
  
  if (size>count)
  {
    double* old_arr = arr;
    
    max_count = size;
    arr = new double[size];
    
    for (int i=0;i<count;i++)
      arr[i] = old_arr[i];
    
    for (;count<max_count;count++)
      arr[count] = defaultVal;
    
    delete [] old_arr;
  }
  else if(size<count)
  {
    double * old_arr = arr;
    
    max_count = size;
    count = size;
    arr = new double[size];
    
    for (int i = 0; i < size; i++)
      arr[i] = old_arr[i];
    
    delete old_arr;
  }
}

void VectorDouble::reserve(unsigned int size)
{
  if(size > max_count)
  {
    if(size <= 2*max_count)
      size = 2*max_count;
    
    double* old_arr = arr;
    
    max_count = size;
    arr = new double[size];
    
    for (int i=0;i<count;i++)
      arr[i] = old_arr[i];
    
    delete [] old_arr;
  }
}

double VectorDouble::value_at(unsigned int i) {
  if(i<0||i>count)
  {
    throw logic_error("ERROR");
  }
  else
  {
    return arr[i];
  }
}

void VectorDouble::change_value_at(double newValue, unsigned int i) {
  if(i<0||i>count)
  {
    throw logic_error("ERROR");
  }
  else
  {
    arr[i] = newValue;
  }
}

ostream& operator<<(ostream& os, const VectorDouble &vd)
{
  for(int i = 0; i < vd.count; i++){
    os << vd.arr[i] << " ";
  }
  return os;
}
