//
// Created by chudonghao on 23-1-23.
//

#include "World.h"
#include "Mesh.h"
#include "Object.h"

#include <stdexcept>

namespace cdhge::world {

std::shared_ptr<World> LoadWorld(const std::string_view &id) noexcept(false) {

  if (id == ":/cdhge/test") {
    auto world = std::make_shared<World>();
    // auto obj = std::make_shared<Object>();
    auto mesh = std::make_shared<Mesh>();
  }

  throw std::runtime_error("");
}

void World::AddObject(std::shared_ptr<Object> obj) {
}

} // namespace cdhge::world
