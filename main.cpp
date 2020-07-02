#include <clipp.h>

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  using namespace clipp;
  bool got_required = false;
  auto cli = required("--required").set(got_required) | option("--optional");
  if (!parse(argc, argv, cli)) {
    std::cerr << "Didn't parse!" << std::endl;
    return EXIT_FAILURE;
  } else if (got_required) {
    std::cout << "Required" << std::endl;
  } else {
    std::cout << "Optional" << std::endl;
  }

  return EXIT_SUCCESS;
}
