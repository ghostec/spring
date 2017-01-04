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

int Calculate(Circuit circuit, Block::Blocks blocks);
Circuit Generate(Block::Blocks blocks);
bool IsValid(Circuit circuit);
void Print(Circuit circuit);

Component randomOperation();
Component randomOperand(Block::Blocks blocks);
Circuit generateOperation(Block::Blocks blocks, Circuit circuit);

}

#endif
