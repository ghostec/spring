#ifndef CALCULATORH
#define CALCULATORH

#include <stack>
#include "error.h"

enum class CalculatorOps {
  ZERO, ONE, NIL,
  AND, OR, XOR,
  NOT
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

inline bool isBinaryOp(CalculatorOps op) {
  if(op == CalculatorOps::AND ||
      op == CalculatorOps::OR ||
      op == CalculatorOps::XOR) return true;
  return false;
}

inline bool isUnaryOp(CalculatorOps op) {
  if(op == CalculatorOps::NOT) return true;
  return false;
}

class Calculator {
private:
  std::stack<CalculatorOps> computation;
  Error binaryOp(CalculatorOps op);
  Error unaryOp(CalculatorOps op);
public:
  Calculator();
  int Compute();
  void SetComputation(std::stack<CalculatorOps> _computation);
  bool IsComputationValid();
};

#endif
