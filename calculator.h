#ifndef CALCULATORH
#define CALCULATORH

#include <stack>

enum class CalculatorOps {
  ZERO, ONE, AND, OR, XOR, NIL
};

class Calculator {
private:
  std::stack<CalculatorOps> computation;
  void binaryOp(CalculatorOps op);
public:
  Calculator();
  int Compute();
};

#endif
