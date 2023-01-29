//
// Created by chudonghao on 22-5-28.
//

#ifndef INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_
#define INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_

#include <map>
#include <memory>

#include <glm/vec2.hpp>

#include <cdhge/export.h>
#include <cdhge/system/vulkan.h>

#include "Pass.h"

namespace cdhge::core {
class Engine;
}

namespace cdhge::renderer {

struct Context {
  vk::RenderPass render_pass;
  vk::Framebuffer framebuffer;
  vk::CommandBuffer command_buffer;
  glm::ivec2 size;
};

class CDHGE_API Renderer {
public:
  enum PathType {
    FINAL_PASS,
  };

  void Init(vk::Instance) noexcept(false);

  void Frame(core::Engine &engine);

protected:
  std::map<int, std::unique_ptr<Pass>> _passes;
};

} // namespace cdhge::renderer

#endif // INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_
