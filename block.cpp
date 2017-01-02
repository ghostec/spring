#include "block.h"

Blocks::Blocks(const size_t _block_size) : block_size(_block_size) {}

void Blocks::CreateBlock(const std::string name, const Block block) {
  blocks[name] = block;
}

Block Blocks::GetBlock(const std::string name) {
  return blocks[name];
}

size_t Blocks::BlockSize() const {
  return block_size;
}
