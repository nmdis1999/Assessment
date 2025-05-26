#include "uri_parser.hpp"

URI parse_uri(const std::string& input) {
  URI result;
  const std::regex uri_regex(
    R"((?:(\w+):)?(?://([^@/\?#]*@)?([^:/\?#]+)?(?::(\d+))?)?([^\?#]*)?(?:\?([^#]*))?(?:#(.*))?)"
  );

  std::smatch match;
  if (std::regex_match(input, match, uri_regex)) {
    if (match[1].matched) result.scheme = match[1];
    if (match[2].matched) {
      std::string u = match[2];
      if (!u.empty() && u.back() == '@') u.pop_back();
      result.userinfo = u;
    }
    if (match[3].matched) result.host = match[3];
    if (match[4].matched) result.port = match[4];
    if (match[5].matched) result.path = match[5];
    if (match[6].matched) result.query = match[6];
    if (match[7].matched) result.fragment = match[7];
  } else {
    throw std::runtime_error("Invalid URI format");
  }

  return result;
}

void print_uri(const URI& uri) {
  std::map<std::string, std::optional<std::string>> parts = {
    {"Scheme", uri.scheme}, {"UserInfo", uri.userinfo}, {"Host", uri.host},
    {"Port", uri.port}, {"Path", uri.path}, {"Query", uri.query}, {"Fragment", uri.fragment}
  };
  for (const auto& [k, v] : parts) {
    std::cout << k << ": " << (v ? *v : "<none>") << '\n';
  }
}
