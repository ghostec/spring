#include "spring.h"

namespace Spring {

File::File Recreate(const Individual::Individual individual, Block::Blocks blocks, Block::Block seed, const size_t file_size) {
  auto block_size = blocks.BlockSize();
  Block::Block next, acc00, acc01;
  File::File result = seed;
  
  while(result.size() < file_size) {
    next = calculateBlock(blocks, individual.next);
    acc00 = calculateBlock(blocks, individual.acc00);
    acc01 = calculateBlock(blocks, individual.acc01);
    blocks.SetBlock("ACC00", acc00);
    blocks.SetBlock("ACC01", acc01);
    blocks.SetBlock("CUR", next);
    for(const auto e : next) result.push_back(e);
  }

  return result;
}

Block::Block calculateBlock(const Block::Blocks blocks, const std::vector<Circuit::Circuit> circuits) {
  auto block_size = blocks.BlockSize();
  Block::Block result(block_size);
  for(auto i = 0; i < block_size; i++) result[i] = Circuit::Calculate(circuits[i], blocks);
  return result;
}

}
