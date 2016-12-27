#include <iostream>
#include <stack>
#include "circuit.h"

int main() {
  Circuit c;
  std::stack<CircuitOps> computation;
  computation.push(CircuitOps::ACC00_0);
  computation.push(CircuitOps::ACC00_1);
  computation.push(CircuitOps::AND);
  computation.push(CircuitOps::NOT);
  c.SetComputation(computation);
  std::cout << c.Compute(Block{1,0,0,0}, Block{1,0,0,0}, Block{1,0,0,0}) << std::endl;

  return 0;
}
