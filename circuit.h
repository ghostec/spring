#ifndef CIRCUITH
#define CIRCUITH

#include <stack>
#include <vector>
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

inline bool isCircuitBinaryOp(CircuitOps op) {
  if(op == CircuitOps::AND ||
      op == CircuitOps::OR ||
      op == CircuitOps::XOR) return true;
  return false;
}

class Circuit {
private:
  std::stack<CircuitOps> computation;
  CalculatorOps circuitOpsToCalculatorOps(CircuitOps op, Block acc00, Block acc01, Block cur);
  std::stack<CalculatorOps> convertComputationToCalculatorOps(Block acc00, Block acc01, Block cur);
public:
  std::vector<CircuitOps> Computation;

  Circuit();
  int Compute(Block acc00, Block acc01, Block cur);
  void SetComputation(std::vector<CircuitOps> _Computation);
  bool IsComputationValid(Block acc00, Block acc01, Block cur);
  void Print();
};

#endif
