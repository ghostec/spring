#include <vector>
#include <iostream>
#include "circuit.h"

Circuit::Circuit() {}

int Circuit::Compute(Block acc00, Block acc01, Block cur) {
  Calculator calculator;
  std::vector<CalculatorOps> vec;

  while(!computation.empty()) {
    auto op = computation.top(); computation.pop();
    if(op == CircuitOps::AND) vec.push_back(CalculatorOps::AND);
    else if(op == CircuitOps::OR) vec.push_back(CalculatorOps::OR);
    else if(op == CircuitOps::XOR) vec.push_back(CalculatorOps::XOR);
    else if(op == CircuitOps::NOT) vec.push_back(CalculatorOps::NOT);
    else if(op == CircuitOps::ACC00_0) vec.push_back(toCalculatorOps(acc00[0]));
    else if(op == CircuitOps::ACC00_1) vec.push_back(toCalculatorOps(acc00[1]));
    else if(op == CircuitOps::ACC00_2) vec.push_back(toCalculatorOps(acc00[2]));
    else if(op == CircuitOps::ACC00_3) vec.push_back(toCalculatorOps(acc00[3]));
    else if(op == CircuitOps::ACC01_0) vec.push_back(toCalculatorOps(acc01[0]));
    else if(op == CircuitOps::ACC01_1) vec.push_back(toCalculatorOps(acc01[1]));
    else if(op == CircuitOps::ACC01_2) vec.push_back(toCalculatorOps(acc01[2]));
    else if(op == CircuitOps::ACC01_3) vec.push_back(toCalculatorOps(acc01[3]));
    else if(op == CircuitOps::CUR_0) vec.push_back(toCalculatorOps(cur[0]));
    else if(op == CircuitOps::CUR_1) vec.push_back(toCalculatorOps(cur[1]));
    else if(op == CircuitOps::CUR_2) vec.push_back(toCalculatorOps(cur[2]));
    else if(op == CircuitOps::CUR_3) vec.push_back(toCalculatorOps(cur[3]));
  }

  std::stack<CalculatorOps> stk;
  for(int i = vec.size() - 1; i >= 0; i--) stk.push(vec[i]);

  calculator.SetComputation(stk);
  return calculator.Compute();
}

void Circuit::SetComputation(std::stack<CircuitOps> _computation) {
  computation = _computation;
}
