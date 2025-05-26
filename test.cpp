#include <cassert>
#include "uri_parser.hpp"

void run_test(const std::string& input, const URI& expected) {
  URI u = parse_uri(input);
  assert(u.scheme == expected.scheme);
  assert(u.userinfo == expected.userinfo);
  assert(u.host == expected.host);
  assert(u.port == expected.port);
  assert(u.path == expected.path);
  assert(u.query == expected.query);
  assert(u.fragment == expected.fragment);
}

int main() {
  run_test("http://user@host.com:8080/path?q=1#frag", {
    "http", "user", "host.com", "8080", "/path", "q=1", "frag"
  });

  run_test("mailto:adam.blake@threatspike.com", {
    "mailto", {}, {}, {}, "adam.blake@threatspike.com", {}, {}
  });

  run_test("https://www.example.org", {
    "https", {}, "www.example.org", {}, "", {}, {}
  });

  std::cout << "All tests passed.\n";
}
