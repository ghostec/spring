#ifndef CALCULATORH
#define CALCULATORH

#include <stack>

enum class CalculatorOps {
  ZERO, ONE, AND, OR, XOR, NIL
};

inline int toBinary(CalculatorOps v) {
  return (v == CalculatorOps::ZERO ? 0 : 1);
}

inline CalculatorOps toCalculatorOps(int v) {
  return (v == 0 ? CalculatorOps::ZERO : CalculatorOps::ONE);
}

inline bool isBinary(CalculatorOps v) {
  return (v == CalculatorOps::ZERO || v == CalculatorOps::ONE);
}

class Calculator {
private:
  std::stack<CalculatorOps> computation;
  void binaryOp(CalculatorOps op);
public:
  Calculator();
  int Compute();
};

#endif
