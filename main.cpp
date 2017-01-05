#include <iostream>
#include <cstdlib>
#include <ctime>
#include "block.h"
#include "individual.h"
#include "file.h"
#include "spring.h"
#include "population.h"

int main() {
  srand(time(NULL));

  size_t block_size = 128;

  Block::Blocks blocks(block_size);
  blocks.SetBlock("ACC00", Block::Generate(block_size));
  blocks.SetBlock("ACC01", Block::Generate(block_size));
  blocks.SetBlock("CUR", Block::Generate(block_size));

  auto original_file = File::Read("file");
  auto population = Population::Population(blocks, 20);
  population = Population::NextGeneration(population, blocks, original_file, Block::Block(std::begin(original_file), std::begin(original_file) + block_size), original_file.size());
  auto max_abs_fitness = Population::MaxAbsFitness(population);
  auto rfit = Population::RelativeFitness(population, max_abs_fitness);

  size_t index = 0;
  auto fit = rfit[0];
  for(auto i = 0; i < population.Size; i++) {
    if(rfit[i] < fit) {
      index = i;
      fit = rfit[i];
    }
  }

  auto recreated_file = Spring::Recreate(population.individuals[index], blocks, Block::Block(std::begin(original_file), std::begin(original_file) + block_size), original_file.size());
  auto delta = Spring::Delta(original_file, recreated_file);

  std::cout << Spring::CountOnes(delta) << std::endl;
  for(const auto e : delta) std::cout << e << " ";
  std::cout << std::endl;


  return 0;
}
