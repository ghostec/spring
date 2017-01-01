#include "calculator.h"

namespace Calculator {

bool IsBinaryOp(Ops op) {
  if(op == Ops::OR || op == Ops::AND || op == Ops::XOR) return true;
  return false;
}

int Calculate(Expression expr) {
  // expr: prefix expression, eg: &|100
  auto op = expr.top(); expr.pop();
  return OpsToInt(CalculateOp(op, expr).top());
}

Expression CalculateOp(const Ops op, Expression expr) {
  if(IsBinaryOp(op)) return CalculateBinaryOp(op, expr);
  return CalculateUnaryOp(op, expr);
}

Expression CalculateUnaryOp(const Ops op, Expression expr) {
  auto v = expr.top(); expr.pop();
  if(v == Ops::ZERO || v == Ops::ONE) return CalculateUnaryOp(op, v, expr);
  return CalculateUnaryOp(op, CalculateOp(v, expr));
}

Expression CalculateUnaryOp(const Ops op, const Ops v, Expression expr) {
  int r;
  int iv = OpsToInt(v);
  if(op == Ops::NOT) r = !iv;
  expr.push(IntToOps(r));
  return expr;
}

Expression CalculateBinaryOp(const Ops op, Expression expr) {
  auto v = expr.top(); expr.pop();
  if(v == Ops::ZERO || v == Ops::ONE) return CalculateBinaryOp(op, v, expr);
  return CalculateBinaryOp(op, CalculateOp(v, expr));
}

Expression CalculateBinaryOp(const Ops op, const Ops v1, Expression expr) {
  auto v = expr.top(); expr.pop();
  if(v == Ops::ZERO || v == Ops::ONE) return CalculateBinaryOp(op, v1, v, expr);
  return CalculateBinaryOp(op, v1, CalculateOp(v, expr));
}

Expression CalculateBinaryOp(const Ops op, const Ops v1, const Ops v2, Expression expr) {
  int r;
  int iv1 = OpsToInt(v1);
  int iv2 = OpsToInt(v2);
  if(op == Ops::OR) r = iv1 | iv2;
  else if(op == Ops::AND) r = iv1 & iv2;
  else if(op == Ops::XOR) r = iv1 ^ iv2;
  expr.push(IntToOps(r));
  return expr;
}

int OpsToInt(const Ops op) {
  return (op == Ops::ZERO ? 0 : 1);
}

Ops IntToOps(const int v) {
  return (v == 0 ? Ops::ZERO : Ops::ONE);
}

}
