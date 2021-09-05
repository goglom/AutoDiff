#include <iostream>

#include "Function.h"


int main() {
  auto a = Function::MakeVariableFunction(1, 0);
  auto b = Function::MakeVariableFunction(2, 1);
  auto c = a * a + b * b;

  std::cout << c.Eval({1, 2}) << " " << c.DeriveByIndVar(1, {1, 2});

  return 0;
}
