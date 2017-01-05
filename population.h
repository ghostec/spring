#ifndef POPULATIONH
#define POPULATIONH

#include <vector>
#include "individual.h"
#include "file.h"

namespace Population {

struct Population {
  std::vector<Individual::Individual> individuals;
  size_t Size;

  Population(const Block::Blocks blocks, const size_t _Size) : Size(_Size) {
    individuals.resize(_Size, Individual::Individual(_Size));
    for(auto& i : individuals) i = Individual::Generate(blocks);
  }
};

Population NextGeneration(Population population, const Block::Blocks blocks, const File::File original_file, Block::Block seed, const size_t file_size, const size_t remaining_generations = 5);
Population CalculateAbsFitness(const Population population, Block::Blocks blocks, const File::File original_file, Block::Block seed, const size_t file_size);
Population Darwin(const Population p1, const Population p2, const std::vector<float> f1, const std::vector<float> f2);
size_t MaxAbsFitness(const Population population);
std::vector<float> RelativeFitness(const Population population, const size_t max_abs_fitness);

}

#endif
