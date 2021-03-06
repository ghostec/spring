#ifndef BLOCKH
#define BLOCKH

#include <vector>
#include <unordered_map>
#include <string>

namespace Block {

typedef std::vector<int> Block;

class Blocks {
private:
  std::unordered_map<std::string, Block> blocks;
  size_t block_size;
public:
  Blocks(const size_t _block_size);
  void SetBlock(const std::string name, const Block block);
  Block GetBlock(const std::string name);
  std::string GetRandomBlockName();
  size_t BlockSize() const;
};

Block Generate(size_t size);

}

#endif
