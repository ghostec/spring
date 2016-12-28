#ifndef INDIVIDUALH
#define INDIVIDUALH

#include "circuit.h"

class Individual {
private:
  Circuit circuit;
  size_t num_operations;
  size_t num_binops;
  size_t num_operands;

  CircuitOps randomOperation();
  CircuitOps randomOperand();
  void generateStep();
public:
  Individual();
  void Generate();
};

#endif
