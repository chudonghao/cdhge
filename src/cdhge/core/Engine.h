//
// Created by chudonghao on 22-5-28.
//

#ifndef INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_
#define INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_

#include <memory>

#include <cdhge/export.h>
#include <cdhge/renderer/Renderer.h>
#include <cdhge/world/World.h>

namespace cdhge::core {

class CDHGE_API Engine {
public:
  Engine();

  renderer::Renderer &renderer() {
    assert(_renderer);
    return *_renderer;
  }

  void set_renderer(std::unique_ptr<cdhge::renderer::Renderer> renderer) {
    _renderer = std::move(renderer);
  }

  void Frame();

protected:
  std::unique_ptr<renderer::Renderer> _renderer;
  std::shared_ptr<world::World> _world;
};

} // namespace cdhge::core

#endif // INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_
