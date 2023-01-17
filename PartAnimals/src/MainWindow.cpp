//
// Created by chudonghao on 22-5-8.
//

#include "MainWindow.h"

#include <s3ge/core/Engine.h>
#include <s3ge/renderer/Vulkan.h>

#include "MainWindowRenderer.h"

QVulkanWindowRenderer *MainWindow::createRenderer() {
  return new MainWindowRenderer(_engine.get(), this);
}

MainWindow::MainWindow(std::unique_ptr<s3ge::core::Engine> engine, QWindow *parent) : _engine(std::move(engine)), QVulkanWindow(parent) {
  assert(_engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine && _engine);
}

MainWindow::~MainWindow() = default;
