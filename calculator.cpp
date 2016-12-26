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

  return toBinary(ans);
}

void Calculator::binaryOp(CalculatorOps binop) {
  std::stack<CalculatorOps> aux;
  auto v1 = CalculatorOps::NIL;
  auto v2 = CalculatorOps::NIL;

  while((v1 == CalculatorOps::NIL || v2 == CalculatorOps::NIL) && !computation.empty()) {
    auto op = computation.top(); computation.pop();
    if(!isBinary(op)) {
      aux.push(op);
    } else {
      if(v1 == CalculatorOps::NIL) v1 = op;
      else v2 = op;
    }
  }

  auto vv1 = toBinary(v1);
  auto vv2 = toBinary(v2); 

  int ans = 0;

  switch(binop) {
    case CalculatorOps::AND:
      ans = vv1 & vv2;
      break;
    default:
      std::cout << "DEFAULT\n";
  }

  computation.push(toCalculatorOps(ans));

  while(!aux.empty()) {
    auto op = aux.top(); aux.pop();
    computation.push(op);
  }
}
