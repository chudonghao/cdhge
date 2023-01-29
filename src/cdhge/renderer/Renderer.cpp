//
// Created by chudonghao on 22-5-28.
//

#include "Renderer.h"

#include <glm/glm.hpp>

namespace cdhge::renderer {

void Renderer::Init(vk::Instance instance) noexcept(false) {
  vk::DynamicLoader dl;
  auto vkGetInstanceProcAddr = dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
  if (!vkGetInstanceProcAddr) {
    throw std::runtime_error("can not get addr of vkGetInstanceProcAddr");
  }

  VULKAN_HPP_DEFAULT_DISPATCHER.init(vkGetInstanceProcAddr);
  VULKAN_HPP_DEFAULT_DISPATCHER.init(instance);
}

void Renderer::Frame(core::Engine &engine) {
//  vk::ClearValue cv[2];
//  cv[0].setColor(std::array{0.0f, 1.0f, 0.0f, 1.0f});
//  cv[1].setDepthStencil({1.f, 0});
//
//  vk::RenderPassBeginInfo rpbi;
//  rpbi.setRenderPass(context.render_pass);
//  rpbi.setFramebuffer(context.framebuffer);
//  rpbi.setRenderArea({{0, 0}, {(unsigned)context.size.x, (unsigned)context.size.y}});
//  rpbi.setClearValueCount(2);
//  rpbi.setPClearValues(cv);
//
//  vk::CommandBuffer cb = context.command_buffer;
//
//  cb.beginRenderPass(rpbi, vk::SubpassContents::eInline);
//  cb.endRenderPass();

  

  return;
}

} // namespace cdhge::renderer
