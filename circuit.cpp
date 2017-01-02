#include "circuit.h"
#include "reverse.h"

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

}
