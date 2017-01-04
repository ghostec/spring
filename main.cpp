#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calculator.h"
#include "circuit.h"
#include "block.h"
#include "individual.h"
#include "file.h"
#include "spring.h"

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

  Block::Blocks blocks(4);
  blocks.SetBlock("ACC00", {1,0,1,1});
  blocks.SetBlock("ACC01", {1,1,1,1});
  blocks.SetBlock("CUR", {1,1,1,1});

  std::cout << Circuit::IsValid(circuit) << std::endl;
  std::cout << Circuit::Calculate(circuit, blocks) << std::endl;

  auto i1 = Individual::Generate(blocks);
  auto i2 = Individual::Generate(blocks);

  auto v = File::Read("file");

  auto result = Spring::Recreate(i1, blocks, {1,1,1,1}, 1024);

  for(const auto e : result) std::cout << e;
  std::cout << std::endl;

  return 0;
}
