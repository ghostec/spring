#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calculator.h"
#include "circuit.h"
#include "block.h"

int main() {
  srand(time(NULL));

  Calculator::Expression expr;
  expr.push(Calculator::Ops::ONE);
  expr.push(Calculator::Ops::ZERO);
  expr.push(Calculator::Ops::OR);
  expr.push(Calculator::Ops::ONE);
  expr.push(Calculator::Ops::AND);
  expr.push(Calculator::Ops::NOT);
  std::cout << Calculator::Calculate(expr) << std::endl;

  Circuit::Circuit circuit{
    {"AND"}, {"OR"}, {"ACC01", 0}, {"ACC00", 1}, {"CUR", 2}
  };

  Blocks blocks(4);
  blocks.CreateBlock("ACC00", {1,0,1,1});
  blocks.CreateBlock("ACC01", {1,1,1,1});
  blocks.CreateBlock("CUR", {1,1,1,1});

  std::cout << Circuit::IsValid(circuit) << std::endl;
  std::cout << Circuit::Calculate(circuit, blocks) << std::endl;

  circuit = Circuit::Generate(blocks);
  Circuit::Print(circuit);

  return 0;
}
