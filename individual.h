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

Circuit::Circuit mateCircuits(const Circuit::Circuit c1, const Circuit::Circuit c2);
Individual Mate(const Individual i1, const Individual i2, const Block::Blocks blocks, size_t max_tries = 10);
Individual Generate(const Block::Blocks blocks);

}

#endif
