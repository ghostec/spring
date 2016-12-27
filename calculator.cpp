#include <iostream>
#include "calculator.h"

Calculator::Calculator() {}

int Calculator::Compute() {
  while(computation.size() > 1) {
    auto op = computation.top(); computation.pop();
    if(isUnaryOp(op)) unaryOp(op);
    else binaryOp(op);
  }

  auto ans = computation.top(); computation.pop();

  return toBinary(ans);
}

void Calculator::SetComputation(std::stack<CalculatorOps> _computation) {
  computation = _computation;
}

void Calculator::unaryOp(CalculatorOps unop) {
  std::stack<CalculatorOps> aux;
  auto v = CalculatorOps::NIL;

  while(v == CalculatorOps::NIL && !computation.empty()) {
    auto op = computation.top(); computation.pop();
    if(!isBinary(op)) aux.push(op);
    else v = op;
  }

  auto vv = toBinary(v);

  int ans = 0;

  if(unop == CalculatorOps::NOT) ans = !vv;

  computation.push(toCalculatorOps(ans));

  while(!aux.empty()) {
    auto op = aux.top(); aux.pop();
    computation.push(op);
  }
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

  if(binop == CalculatorOps::AND) ans = vv1 & vv2;
  else if(binop == CalculatorOps::OR) ans = vv1 | vv2;
  else if(binop == CalculatorOps::XOR) ans = vv1 ^ vv2;

  computation.push(toCalculatorOps(ans));

  while(!aux.empty()) {
    auto op = aux.top(); aux.pop();
    computation.push(op);
  }
}
