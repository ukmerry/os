#include <iostream>
#include <sstream>
#include "VectorDouble.h"

using namespace std;

/*
 * This is your main function - my hidden main() will execute this function
 * when you "Run", but execute the tests when you hit "Submit"
 */
int main() {
  
  bool all_values_set_correctly;
  
  // test 1, verify that default constructor initializes max_count
  VectorDouble v;
  if (v.max_count == 50)
  {
    std::cout << "1.1. default constructor: max_count = 50; test passed" << std::endl;
  }
  else
  {
    std::cout << "1.1. default constructor: max_count != 50; test failed" << std::endl;
  }
  
  // test 2, verify we can pass a size to the constructor
  VectorDouble v2(100);
  if (v2.max_count == 100)
  {
    std::cout << "2.1. constructor: max_count initialized to 100; test passed" << std::endl;
  }
  else
  {
    std::cout << "2.1. constructor: max_count not initialized to 100; test failed" << std::endl;
  }
  
  // test 4, test push_back()
  VectorDouble v4_1(3);
  float v4_1_values[] = {10, -4, 6.7, 15};
  // make sure all values inside the array were actually set correctly
  all_values_set_correctly = true;
  for (int i = 0; i < 4; i++)
  {
    // push_back the value
    v4_1.push_back(v4_1_values[i]);
    // check to make sure the value in the array matches
    if (v4_1.arr[i] != v4_1_values[i])
    {
      all_values_set_correctly = false;
    }
  }
  // check count
  if (v4_1.count == 4)
  {
    std::cout << "4.1. push_back(), correctly set count after pushing values; test passed" << std::endl;
  }
  else
  {
    std::cout << "4.1. push_back(), count not set correctly after pushing values; test failed" << std::endl;
  }
  // check max_count (resize/reserve should have been triggered)
  if (v4_1.max_count == 6)
  {
    std::cout << "4.2. push_back(), capacity was doubled upon pushing value with count == max_count; test passed"
    << std::endl;
  }
  else
  {
    std::cout << "4.2. push_back(), capacity was not doubled upon pushing value with count == max_count; test failed"
    << std::endl;
  }
  // check that push_back set values correctly
  if (all_values_set_correctly)
  {
    std::cout << "4.3. push_back(), all values set correctly using push_back(); test passed" << std::endl;
  }
  else
  {
    std::cout << "4.3. push_back(), values not set correctly using push_back(); test failed" << std::endl;
  }
  
  // test 5, test reserve()
  VectorDouble v5_1;
  VectorDouble v5_2;
  // fill with some content
  for (int i = 0; i < 10; i++)
  {
    v5_1.arr[i] = i;
  }
  v5_1.count = 3;
  v5_1.reserve(101);  // reserve more, max_count should increase
  v5_2.reserve(10);   // max_count should already by 50, so nothing happens
  if (v5_1.max_count == 101)
  {
    std::cout << "5.1. reserve(), max_count updated correctly after expanding capacity of array; test passed"
    << std::endl;
  }
  else
  {
    std::cout << "5.1. reserve(), max_count not updated correctly after expanding capacity of array; test failed"
    << std::endl;
  }
  // check that values were copied to the reserved array
  all_values_set_correctly = true;
  for (int i = 0; i < 3; i++)
  {
    if (v5_1.arr[i] != i)
    {
      all_values_set_correctly = false;
    }
  }
  // check that the previous values of the array were copied to the new array
  if (all_values_set_correctly)
  {
    std::cout << "5.2. reserve(), values correctly copied to newly allocated array; test passed" << std::endl;
  }
  else
  {
    std::cout << "5.2. reserve(), values not correctly copied to newly allocated array; test failed" << std::endl;
  }
  // check that reserve does nothing when the size argument is less than current capacity
  if (v5_2.max_count == 50)
  {
    std::cout
    << "5.3. reserve(), capacity did not change when size passed to reserve() is less than capacity; test passed"
    << std::endl;
  }
  else
  {
    std::cout
    << "5.3. reserve(), capacity should not change when size passed to reserve() is less than capacity; test failed"
    << std::endl;
  }
  
  // test 6, test resize()
  VectorDouble v6_1;
  VectorDouble v6_2(10);
  VectorDouble v6_3;
  // fill with some content
  for (int i = 0; i < 10; i++)
  {
    v6_1.arr[i] = i;
    v6_2.arr[i] = i + 20;
    v6_3.arr[i] = i + 100;
  }
  v6_1.count = v6_2.count = v6_3.count = 10;
  v6_1.resize(15, 15);  // resizing to amount greater than count, less than max_count
  v6_2.resize(15);      // resizing to amount greater than max_count
  v6_3.resize(5);       // resizing to amount less than count
  // for these tests, we'll use a stringstream object to store the contents of the array for comparison
  stringstream ss6_1, ss6_2, ss6_3;
  ss6_1 << v6_1;
  ss6_2 << v6_2;
  ss6_3 << v6_3;
  // check that the additional values were all initialized to 15
  if (ss6_1.str() == "0 1 2 3 4 5 6 7 8 9 15 15 15 15 15 ")
  {
    std::cout << "6.1. resize(), resized with default value of 15; test passed" << std::endl;
  }
  else
  {
    std::cout << "6.1. resize(), resized with default value of 15; test failed" << std::endl;
  }
  // check that the additional values were initialized to 0 with no argument passed
  if (ss6_2.str() == "20 21 22 23 24 25 26 27 28 29 0 0 0 0 0 ")
  {
    std::cout << "6.2. resize(), resized with default value of 0; test passed" << std::endl;
  }
  else
  {
    std::cout << "6.2. resize(), resized with default value of 0; test failed" << std::endl;
  }
  // check that the array shrunk when we passed a resize less than the current size
  if (ss6_3.str() == "100 101 102 103 104 ")
  {
    std::cout << "6.3. resize(), correcly shrunk when resizing to less than current size; test passed" << std::endl;
  }
  else
  {
    std::cout << "\n" << ss6_3.str() << "\n";
    std::cout << "6.3. resize(), did not correctly shrink when resizing to less than current size; test failed"
    << std::endl;
  }
  
  // test 7, test capacity();
  VectorDouble v7_1;
  VectorDouble v7_2(15);
  // should be 50 and 15
  if (v7_1.capacity() == 50)
  {
    std::cout << "7.1. capacity(), default constructor should be 50; test passed" << std::endl;
  }
  else
  {
    std::cout << "7.1. capacity(), default constructor should be 50 but is not; test failed" << std::endl;
  }
  if (v7_2.capacity() == 15)
  {
    std::cout << "7.2. capacity(), default constructor should be 50; test passed" << std::endl;
  }
  else
  {
    std::cout << "7.2. capacity(), default constructor should be 50 but is not; test failed" << std::endl;
  }
  
  // test 8, test size();
  VectorDouble v8_1;
  VectorDouble v8_2;
  VectorDouble v8_3;
  // fill with some content
  for (int i = 0; i < 10; i++)
  {
    v8_1.arr[i] = i;
    v8_2.arr[i] = i + 20;
  }
  v8_1.count = v8_2.count = 10;
  v8_1.push_back(15);
  if (v8_1.size() == 11)
  {
    std::cout << "8.1. size() correctly returns 11; test passed" << std::endl;
  }
  else
  {
    std::cout << "8.1. size() does not return 11; test failed" << std::endl;
  }
  if (v8_2.size() == 10)
  {
    std::cout << "8.2. size() correctly returns 10; test passed" << std::endl;
  }
  else
  {
    std::cout << "8.2. size() does not return 10; test failed" << std::endl;
  }
  if (v8_3.size() == 0)
  {
    std::cout << "8.3. size() correctly returns 0; test passed" << std::endl;
  }
  else
  {
    std::cout << "8.3. size() does not return 0; test failed" << std::endl;
  }
  
  // test 9, value_at()
  VectorDouble v9_1;
  VectorDouble v9_2;
  for (int i = 0; i < 10; i++)
  {
    v9_1.arr[i] = i;
    v9_2.arr[i] = i + 20;
  }
  v9_1.count = v9_2.count = 10;
  // check a value
  if (v9_1.value_at(6) == 6)
  {
    std::cout << "9.1. value_at(), correctly set 6th index to 6; test passed" << std::endl;
  }
  else
  {
    std::cout << "9.1. value_at(), did not correctly set 6th index to 6; test failed" << std::endl;
  }
  // check another value
  if (v9_2.value_at(3) == 23)
  {
    std::cout << "9.2. value_at(), correctly set 3rd index to 23; test passed" << std::endl;
  }
  else
  {
    std::cout << "9.2. value_at(), did not correctly set 3rd index to 23; test failed" << std::endl;
  }
  // make sure exception is thrown when accessing index out of bounds
  try
  {
    double v = v9_1.value_at(40);
    std::cout << "9.3. value_at(), did not throw std::logic_error when using value_at out of bounds; test failed"
    << std::endl;
  }
  catch (std::logic_error e)
  {
    std::cout << "9.3. value_at(), threw std::logic_error when using value_at out of bounds; test passed" << std::endl;
  }
  
  // test 10, change_value_at()
  VectorDouble v10;
  for (int i = 0; i < 10; i++)
  {
    v10.arr[i] = i;
  }
  v10.count = 10;
  // change a value and check that it changed
  v10.change_value_at(4.5, 2);
  if (v10.arr[2] == 4.5)
  {
    std::cout << "10.1. change_value_at(), correctly changed value; test passed" << std::endl;
  }
  else
  {
    std::cout << "10.1. change_value_at(), did not correctly changed value; test failed" << std::endl;
  }
  // change a value out of bounds, std::logic_error should be thrown
  try
  {
    v10.change_value_at(15.5, 24);
    std::cout << "10.2. change_value_at(), did not throw std::logic_error when using change_value_at out of bounds; test failed"
    << std::endl;
  }
  catch (std::logic_error e)
  {
    std::cout << "10.2. change_value_at(), threw std::logic_error when using change_value_at out of bounds; test passed"
    << std::endl;
  }
  
  // test 11, verify we can use a copy constructor
  VectorDouble v11_1;
  for (int i = 0; i < 10; i++)
  {
    v11_1.arr[i] = i;
  }
  v11_1.count = 10;
  VectorDouble v11_2(v11_1);
  // check that values were copied to the reserved array
  all_values_set_correctly = true;
  for (int i = 0; i < 3; i++)
  {
    if (v11_2.arr[i] != i)
    {
      all_values_set_correctly = false;
    }
  }
  // passed case if all values were copied, array pointers are different, and max_count and count set correclty
  if (all_values_set_correctly && v11_1.arr != v11_2.arr && v11_2.count == 10 && v11_2.max_count == 50)
  {
    std::cout << "11.1. copy constructor, correctly copied values and members from other array; test passed" << std::endl;
  }
  else
  {
    std::cout << "11.1. copy constructor, did not correctly copy values and members from other array; test failed"
    << std::endl;
  }
  
  // test 12, check assignment operator
  VectorDouble v12_1;
  for (int i = 0; i < 10; i++)
  {
    v12_1.arr[i] = i;
  }
  v12_1.count = 10;
  VectorDouble v12_2;
  v12_2 = v12_1;
  // check that values were copied to the reserved array
  all_values_set_correctly = true;
  for (int i = 0; i < 3; i++)
  {
    if (v12_2.arr[i] != i)
    {
      all_values_set_correctly = false;
    }
  }
  // passed case if all values were copied, array pointers are different, and max_count and count set correclty
  if (all_values_set_correctly && v12_1.arr != v12_2.arr && v12_2.count == 10 && v12_2.max_count == 50)
  {
    std::cout << "12.1. assignment operator, correctly assigned values and members from other array; test passed"
    << std::endl;
  }
  else
  {
    std::cout << "12.1. assignment operator, did not correctly assign values and members from other array; test failed"
    << std::endl;
  }
  
  // test 13, check comparison operator
  VectorDouble v13_1, v13_2, v13_3;
  for (int i = 0; i < 10; i++)
  {
    v13_1.arr[i] = i;
    v13_2.arr[i] = i;
    v13_3.arr[i] = i + 20;
  }
  v13_1.count = v13_2.count = v13_3.count = 10;
  // should be equal
  if (v13_1 == v13_2)
  {
    std::cout << "13.1. comparison operator, correctly compared two equal VectorDoubles; test passed" << std::endl;
  }
  else
  {
    std::cout << "13.1. comparison operator, did not correctly compar two equal VectorDoubles; test failed"
    << std::endl;
  }
  // should not be equal
  if (!(v13_1 == v13_3))
  {
    std::cout << "13.2. comparison operator, correctly compared two unequal VectorDoubles; test passed" << std::endl;
  }
  else
  {
    std::cout << "13.2. comparison operator, did not correctly compare two unequal VectorDoubles; test failed"
    << std::endl;
  }
  return 0;
}
