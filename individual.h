#ifndef INDIVIDUALH
#define INDIVIDUALH

#include "circuit.h"

namespace Individual {

struct Individual {
  std::vector<Circuit::Circuit> acc00, acc01, next;
  size_t BlockSize;

  Individual(size_t _BlockSize) : BlockSize(_BlockSize) {
    acc00.resize(BlockSize);
    acc01.resize(BlockSize);
    next.resize(BlockSize);
  }
};

Circuit::Circuit mateCircuits(Circuit::Circuit c1, Circuit::Circuit c2);
Individual Mate(Individual i1, Individual i2);
Individual Generate(Block::Blocks blocks);

}

#endif
