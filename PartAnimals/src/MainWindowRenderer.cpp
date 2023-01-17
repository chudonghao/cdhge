//
// Created by chudonghao on 22-5-8.
//

#include "MainWindowRenderer.h"

#include <s3ge/renderer/Vulkan.h>

#include <cdhlog.hpp>

MainWindowRenderer::MainWindowRenderer(s3ge::core::Engine *engine, QVulkanWindow *parent) : _engine(engine), _window(parent), QObject(parent) {
  CLOG_DEBUG << __FUNCTION__;
}

MainWindowRenderer::~MainWindowRenderer() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::preInitResources() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::initResources() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::initSwapChainResources() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::releaseSwapChainResources() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::releaseResources() {
  CLOG_DEBUG << __FUNCTION__;
}

void MainWindowRenderer::startNextFrame() {
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

  _engine->Frame();

  _window->frameReady();
}

void MainWindowRenderer::physicalDeviceLost() {
  CLOG_FATAL << "physical device lost";
}

void MainWindowRenderer::logicalDeviceLost() {
  CLOG_FATAL << "logical device lost";
}
