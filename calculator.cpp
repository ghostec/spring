#include <iostream>
#include "calculator.h"

Calculator::Calculator() {}

int Calculator::Compute() {
  computation.push(CalculatorOps::ONE);
  computation.push(CalculatorOps::ONE);
  computation.push(CalculatorOps::AND);

  while(computation.size() > 1) {
    auto op = computation.top(); computation.pop();
    binaryOp(op);
  }

  auto ans = computation.top(); computation.pop();

  if(ans == CalculatorOps::ZERO) return 0;
  if(ans == CalculatorOps::ONE) return 1;
}

void Calculator::binaryOp(CalculatorOps binop) {
  std::stack<CalculatorOps> aux;
  auto v1 = CalculatorOps::NIL;
  auto v2 = CalculatorOps::NIL;

  while((v1 == CalculatorOps::NIL || v2 == CalculatorOps::NIL) && !computation.empty()) {
    auto op = computation.top(); computation.pop();
    if(op != CalculatorOps::ZERO && op != CalculatorOps::ONE) {
      aux.push(op);
    } else {
      if(v1 == CalculatorOps::NIL) v1 = op;
      else v2 = op;
    }
  }

  auto vv1 = (v1 == CalculatorOps::ZERO ? 0 : 1);
  auto vv2 = (v2 == CalculatorOps::ZERO ? 0 : 1);

  int ans = 0;

  switch(binop) {
    case CalculatorOps::AND:
      ans = vv1 & vv2;
      break;
    default:
      std::cout << "DEFAULT\n";
  }

  computation.push(ans == 0 ? CalculatorOps::ZERO : CalculatorOps::ONE);

  while(!aux.empty()) {
    auto op = aux.top(); aux.pop();
    computation.push(op);
  }
}
