#include "individual.h"

namespace Individual {

Circuit::Circuit mateCircuits(Circuit::Circuit c1, Circuit::Circuit c2) {
  // slice both, then insert at a random position
  int end = rand() % c1.size();
  int start = rand() % (end + 1);
  
  Circuit::Circuit child(std::begin(c1) + start, std::begin(c1) + end + 1);
  
  end = rand() % c2.size();
  start = rand() % (end + 1);

  child.insert(
      std::begin(child) + (rand() % child.size()),
      std::begin(c2) + start,
      std::begin(c2) + end + 1);

  return child;
}

Individual Mate(Individual i1, Individual i2) {
  Individual child = i1;
  for(auto i = 0; i < i1.BlockSize; i++) {
    child.acc00[i] = mateCircuits(i1.acc00[i], i2.acc00[i]);
    child.acc01[i] = mateCircuits(i1.acc01[i], i2.acc01[i]);
    child.next[i] = mateCircuits(i1.next[i], i2.next[i]);
  }
  return child;
}

Individual Generate(Block::Blocks blocks) {
  auto block_size = blocks.BlockSize();
  Individual individual(block_size);
  for(auto i = 0; i < block_size; i++) {
    individual.acc00[i] = Circuit::Generate(blocks);
    individual.acc01[i] = Circuit::Generate(blocks);
    individual.next[i] = Circuit::Generate(blocks);
  }
  return individual;
}

}
