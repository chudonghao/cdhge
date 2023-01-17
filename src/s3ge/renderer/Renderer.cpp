//
// Created by chudonghao on 22-5-28.
//

#include "Renderer.h"

#include <glm/glm.hpp>

namespace s3ge::renderer {

int Renderer::Init(vk::Instance instance) {
  vk::DynamicLoader dl;
  auto vkGetInstanceProcAddr = dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
  if (!vkGetInstanceProcAddr) {
    return -1;
  }

  VULKAN_HPP_DEFAULT_DISPATCHER.init(vkGetInstanceProcAddr);
  VULKAN_HPP_DEFAULT_DISPATCHER.init(instance);
  return 0;
}

int Renderer::operator()() {
  vk::ClearValue cv[2];
  cv[0].setColor(std::array{0.0f, 1.0f, 0.0f, 1.0f});
  cv[1].setDepthStencil({1.f, 0});

  struct RenderContext {
    vk::RenderPass render_pass;
    vk::Framebuffer frame_buffer;
    vk::CommandBuffer current_command_buffer;
    glm::ivec2 size;
  };

  vk::RenderPassBeginInfo rpbi;
  rpbi.setRenderPass(_window->defaultRenderPass());
  rpbi.setFramebuffer(_window->currentFramebuffer());
  auto size = _window->swapChainImageSize();
  rpbi.setRenderArea({{0, 0}, {(unsigned)size.width(), (unsigned)size.height()}});
  rpbi.setClearValueCount(2);
  rpbi.setPClearValues(cv);

  vk::CommandBuffer cb = _window->currentCommandBuffer();

  cb.beginRenderPass(rpbi, vk::SubpassContents::eInline);
  cb.endRenderPass();
  return 0;
}

} // namespace s3ge::renderer
