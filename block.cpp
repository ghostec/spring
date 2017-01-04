#include "block.h"
#include "random.h"

namespace Block {

Blocks::Blocks(const size_t _block_size) : block_size(_block_size) {}

void Blocks::SetBlock(const std::string name, const Block block) {
  blocks[name] = block;
}

Block Blocks::GetBlock(const std::string name) {
  return blocks[name];
}

std::string Blocks::GetRandomBlockName() {
  return select_randomly(std::begin(blocks), std::end(blocks))->first;
}

size_t Blocks::BlockSize() const {
  return block_size;
}

}
