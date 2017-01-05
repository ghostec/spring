#include <algorithm>
#include "population.h"
#include "spring.h"

namespace Population {

Population NextGeneration(Population population, const Block::Blocks blocks, const File::File original_file, Block::Block seed, const size_t file_size, const size_t remaining_generations) {
  Population new_population = population;
  // mate random choices
  for(auto i = 0; i < population.Size; i++) {
    const auto i1 = population.individuals[rand() % population.Size];
    const auto i2 = population.individuals[rand() % population.Size];
    new_population.individuals[i] = Individual::Mate(i1, i2, blocks);
  }
  // selection of fittest
  population = CalculateAbsFitness(population, blocks, original_file, seed, file_size);
  new_population = CalculateAbsFitness(population, blocks, original_file, seed, file_size);

  auto max_abs_fitness = std::max(MaxAbsFitness(population), MaxAbsFitness(new_population));
  auto rfit = RelativeFitness(population, max_abs_fitness);
  auto new_rfit = RelativeFitness(new_population, max_abs_fitness);

  new_population = Darwin(population, new_population, rfit, new_rfit);

  if(remaining_generations == 0) return new_population;
  else return NextGeneration(new_population, blocks, original_file, seed, file_size, remaining_generations - 1);
}

size_t MaxAbsFitness(const Population population) {
  size_t max_abs_fitness = 0;
  for(auto i = 0; i < population.Size; i++) {
    auto fit = population.individuals[i].AbsFitness;
    if(fit > max_abs_fitness) max_abs_fitness = fit;
  }
  return max_abs_fitness + 1; 
}

std::vector<float> RelativeFitness(const Population population, const size_t max_abs_fitness) {
  std::vector<float> fitness(population.Size);
  for(auto i = 0; i < population.Size; i++) {
    fitness[i] = population.individuals[i].AbsFitness / max_abs_fitness;
  }
  return fitness;
}

Population Darwin(const Population p1, const Population p2, const std::vector<float> f1, const std::vector<float> f2) {
  Population fittest = p1;
  // fittest has relative fitness closer to 0
  for(auto i = 0; i < p1.Size; i++) {
    if(rand() % 100 < 20) fittest.individuals[i] = (f1[i] > f2[i] ? p1.individuals[i] : p2.individuals[i]);
    else fittest.individuals[i] = (f1[i] < f2[i] ? p1.individuals[i] : p2.individuals[i]);
  }
  return fittest;
}

Population CalculateAbsFitness(const Population population, Block::Blocks blocks, const File::File original_file, Block::Block seed, const size_t file_size) {
  Population new_population = population;
  for(auto& i : new_population.individuals) {
    auto recreated_file = Spring::Recreate(i, blocks, seed, file_size);
    i.AbsFitness = Spring::CalculateAbsFitness(i, original_file, recreated_file);
  }
  return new_population;
}

}
