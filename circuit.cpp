#include "circuit.h"
#include "reverse.h"
#include "random.h"

namespace Circuit {

Calculator::Ops stringToCalculatorOps(std::string label) {
  if(label == "OR") return Calculator::Ops::OR;
  else if(label == "AND") return Calculator::Ops::AND;
  else if(label == "XOR") return Calculator::Ops::XOR;
  else if(label == "NOT") return Calculator::Ops::NOT;
  else return Calculator::Ops::NIL;
}

int Calculate(Circuit circuit, Blocks blocks) {
  Calculator::Expression expr;

  for(const auto c : reverse(circuit)) {
    Calculator::Ops op;
    if((op = stringToCalculatorOps(c.Label)) != Calculator::Ops::NIL) expr.push(op);
    else {
      auto iv = blocks.GetBlock(c.Label)[c.Port];
      auto v = Calculator::IntToOps(iv);
      expr.push(v);
    } 
  }

  return Calculator::Calculate(expr);
}

Circuit Generate(Blocks blocks) {
  Circuit circuit;
  return generateOperation(blocks, circuit);
}

Circuit generateOperation(Blocks blocks, Circuit circuit) {
  Component op = randomOperation();
  circuit.push_back(op);

  if(rand() % 100 > 80) circuit = generateOperation(blocks, circuit);
  else circuit.push_back(randomOperand(blocks));

  if(op.Label == "NOT") return circuit;

  if(rand() % 100 > 80) circuit = generateOperation(blocks, circuit);
  else circuit.push_back(randomOperand(blocks));
  
  return circuit;
}

Component randomOperation() {
  Circuit operations{
    {"AND"}, {"OR"}, {"XOR"}, {"NOT"}
  };

  return *select_randomly(std::begin(operations), std::end(operations));
}

Component randomOperand(Blocks blocks) {
  int index = rand() % blocks.BlockSize();
  return {blocks.GetRandomBlockName(), index};
}

bool IsValid(Circuit circuit) {
  int sum = 0;
  bool pending_unary = false;

  for(const auto c : circuit) {
    if(sum < 0) return false;

    Calculator::Ops op;
    if((op = stringToCalculatorOps(c.Label)) != Calculator::Ops::NIL) {
      if(Calculator::IsBinaryOp(op)) sum += 2;
      else pending_unary = true;
    } else {
      sum -= 1;
      pending_unary = false;
    }
  }

  return ((sum == 1 && pending_unary == false) ? true : false);
}

void Print(Circuit circuit) {
  for(const auto c : circuit) {
    std::cout << c.Label << " ";
  }
  std::cout << std::endl;
}

}
