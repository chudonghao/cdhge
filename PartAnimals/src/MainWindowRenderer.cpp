//
// Created by chudonghao on 22-5-8.
//

#include "MainWindowRenderer.h"

#include <cdhge/system/vulkan.h>

#include <cdhlog.hpp>

MainWindowRenderer::MainWindowRenderer(cdhge::core::Engine *engine, QVulkanWindow *parent) : _engine(engine), _window(parent), QObject(parent) {
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
  _engine->Frame();

  _window->frameReady();
}

void MainWindowRenderer::physicalDeviceLost() {
  CLOG_FATAL << "physical device lost";
}

void MainWindowRenderer::logicalDeviceLost() {
  CLOG_FATAL << "logical device lost";
}
