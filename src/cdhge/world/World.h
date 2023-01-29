//
// Created by chudonghao on 23-1-23.
//

#ifndef INC_23_1_23_D7200997D5FB4F0E9E463B26B26D0361_H
#define INC_23_1_23_D7200997D5FB4F0E9E463B26B26D0361_H

#include <memory>
#include <string_view>

namespace cdhge::world {

class Object;

class World {
public:
  void AddObject(std::shared_ptr<Object> obj);
};

std::shared_ptr<World> LoadWorld(const std::string_view &id) noexcept(false);

} // namespace cdhge::world

#endif // INC_23_1_23_D7200997D5FB4F0E9E463B26B26D0361_H
