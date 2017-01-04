#include <sstream>
#include "file.h"

namespace File {

File Read(std::string path) {
  std::ifstream filestr;
  filestr.open(path);

  auto ss = std::ostringstream{};
  ss << filestr.rdbuf();
  auto s = ss.str();

  filestr.close();

  std::vector<int> v; v.reserve(s.size());
  for(const auto c : s) v.push_back(c);

  return v;
}

}
