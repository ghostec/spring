#ifndef CALCULATORH
#define CALCULATORH

#include <stack>

namespace Calculator {

enum class Ops {
  NIL, ZERO, ONE,
  OR, AND, XOR, NOT
};

typedef std::stack<Ops> Expression;

bool IsBinaryOp(Ops op);
int Calculate(Expression expr);
Expression CalculateOp(const Ops op, Expression expr);
Expression CalculateUnaryOp(const Ops op, Expression expr);
Expression CalculateUnaryOp(const Ops op, const Ops v, Expression expr);
Expression CalculateBinaryOp(const Ops op, Expression expr);
Expression CalculateBinaryOp(const Ops op, const Ops v1, Expression expr);
Expression CalculateBinaryOp(const Ops op, const Ops v1, const Ops v2, Expression expr);
int OpsToInt(const Ops op);
Ops IntToOps(const int v);

}

#endif
