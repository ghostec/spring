#include "individual.h"

namespace Individual {

Circuit::Circuit Mate(Circuit::Circuit c1, Circuit::Circuit c2) {
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

}
