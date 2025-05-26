#include "uri_parser.hpp"

int main(int argc, char* argv[]) {
  try {
    std::string input;
    if (argc > 1) {
      input = argv[1];
    } else {
      std::getline(std::cin, input);
    }
    URI uri = parse_uri(input);
    print_uri(uri);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
