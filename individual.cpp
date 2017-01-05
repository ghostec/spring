#include <iostream>
#include "individual.h"

namespace Individual {

Circuit::Circuit mateCircuits(const Circuit::Circuit c1, const Circuit::Circuit c2) {
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

Individual Mate(const Individual i1, const Individual i2, const Block::Blocks blocks, size_t max_tries) {
  Individual child = i1;
  size_t tries;
  for(auto i = 0; i < i1.BlockSize; i++) {
    if(tries > max_tries) return Generate(blocks); 
    while(tries < max_tries && Circuit::IsValid(child.acc00[i] = mateCircuits(i1.acc00[i], i2.acc00[i])));
    while(tries < max_tries && Circuit::IsValid(child.acc01[i] = mateCircuits(i1.acc01[i], i2.acc01[i])));
    while(tries < max_tries && Circuit::IsValid(child.next[i] = mateCircuits(i1.next[i], i2.next[i])));
  }
  return child;
}

Individual Generate(const Block::Blocks blocks) {
  auto block_size = blocks.BlockSize();
  Individual individual(block_size);
  for(auto i = 0; i < block_size; i++) {
    individual.acc00[i] = Circuit::Generate(blocks);
    individual.acc01[i] = Circuit::Generate(blocks);
    individual.next[i] = Circuit::Generate(blocks);
  }
  return individual;
}

void Print(const Individual individual) {
  std::cout << "ABS_FITNESS: " << individual.AbsFitness << std::endl;
  std::cout << "ACC00\n";
  for(const auto c : individual.acc00) Circuit::Print(c);
  std::cout << "ACC01\n";
  for(const auto c : individual.acc01) Circuit::Print(c);
  std::cout << "NEXT\n";
  for(const auto c : individual.next) Circuit::Print(c);
}

}
