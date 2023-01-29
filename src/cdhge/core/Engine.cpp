//
// Created by chudonghao on 22-5-28.
//

#include "Engine.h"

namespace cdhge::core {

Engine::Engine() {
  _world = std::make_shared<world::World>();
}

void Engine::Frame() {
  assert(_renderer);
  assert(_world);

  // _logic->Advance(*_world, dt);

  _renderer->Frame(*this);
}

} // namespace cdhge::core
