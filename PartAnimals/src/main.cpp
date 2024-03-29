
#include <memory>

#include <QApplication>

#include <cdhlog_setup.hpp>

#include <cdhge/core/Engine.h>

#include "MainWindow.h"

MainWindow *CreateMainWindow() noexcept(false) {
  std::unique_ptr<QVulkanInstance> vi = std::make_unique<QVulkanInstance>();
  {
    QByteArrayList layers;
    auto sls = vi->supportedLayers();
    if (sls.contains("VK_LAYER_KHRONOS_validation")) {
      layers << "VK_LAYER_KHRONOS_validation";
    }
    vi->setLayers(layers);

    if (!vi->create()) {
      throw std::runtime_error("create qt vulkan instance failed");
    }
  }

  auto renderer = std::make_unique<cdhge::renderer::Renderer>();
  renderer->Init(vk::Instance(vi->vkInstance()));

  auto engine = std::make_unique<cdhge::core::Engine>();
  engine->set_renderer(std::move(renderer));

  auto main_window = new MainWindow(std::move(engine));
  main_window->setVulkanInstance(vi.release());

  return main_window;
}

int main(int argc, char *argv[]) {
  cdhlog::Setup();
  QApplication app(argc, argv);

  CreateMainWindow()->show();

  return QApplication::exec();
}
