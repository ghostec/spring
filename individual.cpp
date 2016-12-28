#include <cstdlib>
#include <iostream>
#include "individual.h"
#include "calculator.h"
#include "random.h"

Individual::Individual() : num_operations(0), num_binops(0), num_operands(0) {
  Generate();
}

void Individual::generateStep() {
  auto pos = rand() % (num_operations + 1);
  auto op = randomOperation();
  circuit.Computation.insert(std::begin(circuit.Computation) + pos, op);
  if(num_operations == 0) {
    if(isCircuitBinaryOp(op)) {
      circuit.Computation.push_back(randomOperand());
      circuit.Computation.push_back(randomOperand());
      num_operands = 2;
      num_binops = 1;
    } else {
      circuit.Computation.push_back(randomOperand());
      num_operands = 1;
    }
    num_operations = 1;
  } else {
    if(isCircuitBinaryOp(op)) {
      num_operands++;
      num_binops++;
      circuit.Computation.push_back(randomOperand());
    }
    num_operations++; 
  }
}

void Individual::Generate() {
  do { generateStep(); } while(rand() % 100 < 50);
  circuit.Print();
}

CircuitOps Individual::randomOperation() {
  std::vector<CircuitOps> vec{
    CircuitOps::AND, CircuitOps::OR, CircuitOps::XOR,
      CircuitOps::NOT
  };
  return *select_randomly(std::begin(vec), std::end(vec));
}

CircuitOps Individual::randomOperand() {
  std::vector<CircuitOps> vec{
    CircuitOps::ACC00_0, CircuitOps::ACC00_1, CircuitOps::ACC00_2, CircuitOps::ACC00_3,
      CircuitOps::ACC01_0, CircuitOps::ACC01_1, CircuitOps::ACC01_2, CircuitOps::ACC01_3,
      CircuitOps::CUR_0, CircuitOps::CUR_1, CircuitOps::CUR_2, CircuitOps::CUR_3
  };
  return *select_randomly(std::begin(vec), std::end(vec));
}
