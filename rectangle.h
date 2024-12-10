#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class rectangle
{
    int a;
    int b;

public:
  rectangle();
  virtual ~rectangle();
  int get_a() { return a; }
  void set_a(int val) { a = val; }
  int get_b() { return b; }
  void set_b(int val) { b = val; }
};

#endif // RECTANGLE_H