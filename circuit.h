#ifndef CIRCUITH
#define CIRCUITH

#include <stack>
#include "calculator.h"
#include "block.h"

enum class CircuitOps {
  ACC00_0, ACC00_1, ACC00_2, ACC00_3,
  ACC01_0, ACC01_1, ACC01_2, ACC01_3,
  CUR_0, CUR_1, CUR_2, CUR_3,
  ZERO, ONE, NIL,
  AND, OR, XOR,
  NOT
};

inline bool isCalculatorOps(CircuitOps op) {
  if(op == CircuitOps::ZERO ||
      op == CircuitOps::ONE ||
      op == CircuitOps::NIL ||
      op == CircuitOps::AND ||
      op == CircuitOps::OR ||
      op == CircuitOps::XOR ||
      op == CircuitOps::NOT) return true;
  return false;
}

class Circuit {
private:
  std::stack<CircuitOps> computation;
public:
  Circuit();
  int Compute(Block acc00, Block acc01, Block cur);
  void SetComputation(std::stack<CircuitOps> _computation);
};

#endif
