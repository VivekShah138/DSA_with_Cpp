v2.begin(); // It points to the first element at 0th index of the vector
  v2.end(); // It does point last element of vector but it points to the next position after to last element of vector, So when you deference it, it will give you some garbage value.

  // REVERSE ITERATORS
  v2.rbegin(); // It points to the last element of the vector
  v2.re