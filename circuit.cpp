#include <vector>
#include <iostream>
#include "circuit.h"

Circuit::Circuit() {}

int Circuit::Compute(Block acc00, Block acc01, Block cur) {
  computation = std::stack<CircuitOps>();
  for(int i = Computation.size() - 1; i >= 0; i--) computation.push(Computation[i]);

  Calculator calculator;
  calculator.SetComputation(convertComputationToCalculatorOps(acc00, acc01, cur));
  return calculator.Compute();
}

void Circuit::SetComputation(std::vector<CircuitOps> _Computation) {
  Computation = _Computation;
}

std::stack<CalculatorOps> Circuit::convertComputationToCalculatorOps(Block acc00, Block acc01, Block cur) {
  std::vector<CalculatorOps> vec;

  while(!computation.empty()) {
    auto op = computation.top(); computation.pop();
    auto calc_op = circuitOpsToCalculatorOps(op, acc00, acc01, cur);
    vec.push_back(calc_op);
  }

  std::stack<CalculatorOps> stk;
  for(int i = vec.size() - 1; i >= 0; i--) stk.push(vec[i]);
  return stk;
}

CalculatorOps Circuit::circuitOpsToCalculatorOps(CircuitOps op, Block acc00, Block acc01, Block cur) {
  if(op == CircuitOps::AND) return CalculatorOps::AND;
  else if(op == CircuitOps::OR) return CalculatorOps::OR;
  else if(op == CircuitOps::XOR) return CalculatorOps::XOR;
  else if(op == CircuitOps::NOT) return CalculatorOps::NOT;
  else if(op == CircuitOps::ACC00_0) return toCalculatorOps(acc00[0]);
  else if(op == CircuitOps::ACC00_1) return toCalculatorOps(acc00[1]);
  else if(op == CircuitOps::ACC00_2) return toCalculatorOps(acc00[2]);
  else if(op == CircuitOps::ACC00_3) return toCalculatorOps(acc00[3]);
  else if(op == CircuitOps::ACC01_0) return toCalculatorOps(acc01[0]);
  else if(op == CircuitOps::ACC01_1) return toCalculatorOps(acc01[1]);
  else if(op == CircuitOps::ACC01_2) return toCalculatorOps(acc01[2]);
  else if(op == CircuitOps::ACC01_3) return toCalculatorOps(acc01[3]);
  else if(op == CircuitOps::CUR_0) return toCalculatorOps(cur[0]);
  else if(op == CircuitOps::CUR_1) return toCalculatorOps(cur[1]);
  else if(op == CircuitOps::CUR_2) return toCalculatorOps(cur[2]);
  else if(op == CircuitOps::CUR_3) return toCalculatorOps(cur[3]);
}

bool Circuit::IsComputationValid(Block acc00, Block acc01, Block cur) {
  return (Compute(acc00, acc01, cur) == -1 ? false : true);
}
