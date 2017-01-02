#include <iostream>
#include "calculator.h"
#include "block.h"

int main() {
  Calculator::Expression expr;
  expr.push(Calculator::Ops::ONE);
  expr.push(Calculator::Ops::ZERO);
  expr.push(Calculator::Ops::OR);
  expr.push(Calculator::Ops::ONE);
  expr.push(Calculator::Ops::AND);
  expr.push(Calculator::Ops::NOT);
  std::cout << Calculator::Calculate(expr) << std::endl;
  return 0;
}
