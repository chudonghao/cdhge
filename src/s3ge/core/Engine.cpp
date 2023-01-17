//
// Created by chudonghao on 22-5-28.
//

#include "Engine.h"

namespace s3ge::core {

void Engine::Frame() {
  assert(_renderer);

  (*_renderer)();
}

} // namespace s3ge::core
