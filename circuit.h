#ifndef CIRCUITH
#define CIRCUITH

#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "calculator.h"
#include "block.h"

namespace Circuit {

struct Component {
  std::string Label;
  int Port;
};

typedef std::vector<Component> Circuit; 

int Calculate(Circuit circuit, Blocks blocks);
Circuit Generate(Blocks blocks);
bool IsValid(Circuit circuit);
void Print(Circuit circuit);

Component randomOperation();
Component randomOperand(Blocks blocks);
Circuit generateOperation(Blocks blocks, Circuit circuit);

}

#endif
