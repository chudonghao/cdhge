//
// Created by chudonghao on 22-5-8.
//

#include "MainWindow.h"

#include <cdhge/core/Engine.h>
#include <cdhge/system/vulkan.h>

#include "MainWindowRenderer.h"

QVulkanWindowRenderer *MainWindow::createRenderer() {
  return new MainWindowRenderer(_engine.get(), this);
}

MainWindow::MainWindow(std::unique_ptr<cdhge::core::Engine> engine, QWindow *parent) : _engine(std::move(engine)), QVulkanWindow(parent) {
  assert(_engine);
}

MainWindow::~MainWindow() = default;
