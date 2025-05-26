#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <optional>
#include <map>
#include <array>

struct URI {
  std::optional<std::string> scheme;
  std::optional<std::string> userinfo;
  std::optional<std::string> host;
  std::optional<std::string> port;
  std::optional<std::string> path;
  std::optional<std::string> query;
  std::optional<std::string> fragment;

  bool is_ipv6_host = false;
};

URI parse_uri(const std::string& input);
void print_uri(const URI& uri);
bool is_valid_ipv4(const std::string& host);
bool is_valid_ipv6(const std::string& host);
