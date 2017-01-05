#ifndef SPRINGH
#define SPRINGH

#include <vector>
#include "file.h"
#include "individual.h"
#include "circuit.h"

namespace Spring {

File::File Recreate(const Individual::Individual individual, Block::Blocks blocks, const Block::Block seed, const size_t file_size);
File::File Delta(const File::File original, const File::File recreated);
size_t CountOnes(const File::File file);
size_t CalculateAbsFitness(Individual::Individual individual, const File::File original, const File::File recreated);

Block::Block calculateBlock(const Block::Blocks blocks, const std::vector<Circuit::Circuit> circuits);

}

#endif
