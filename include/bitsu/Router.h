#pragma once

#include <radix_tree.hpp>
#include <string>
#include <unordered_map>
#include <iostream>

namespace bitsu {

template <typename HandleType> class Router {
public:
  Router(const std::unordered_map<std::string, HandleType> &routes) {
    for (auto route : routes) {
      this->routes[route.first] = route.second;
    }
  };

  void checkRoutes(const std::string &basePath) {
    auto match = routes.longest_match(basePath);
    if (match != routes.end()) {
      match->second();
    }
  }

private:
  radix_tree<std::string, HandleType> routes;
};
}
