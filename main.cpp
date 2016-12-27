#include <iostream>
#include <vector>
#include "circuit.h"

int main() {
  Circuit c;
  std::vector<CircuitOps> computation{CircuitOps::NOT, CircuitOps::AND, CircuitOps::ACC00_0, CircuitOps::ACC00_1};
  c.SetComputation(computation);
  std::cout << c.Compute(Block{0,1,0,0}, Block{1,0,0,0}, Block{1,0,0,0}) << std::endl;

  return 0;
}
