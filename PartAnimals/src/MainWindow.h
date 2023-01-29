//
// Created by chudonghao on 22-5-8.
//

#ifndef INC_CHUDONGHAO_22_5_8_7E51E9ABB4604BDBB8C9893C7166A1D0_
#define INC_CHUDONGHAO_22_5_8_7E51E9ABB4604BDBB8C9893C7166A1D0_

#include <memory>

#include <QVulkanWindow>

namespace cdhge::core {

class Engine;

}

class MainWindow : public QVulkanWindow {
  Q_OBJECT
public:
  explicit MainWindow(std::unique_ptr<cdhge::core::Engine> engine, QWindow *parent = nullptr);

  ~MainWindow();

  QVulkanWindowRenderer *createRenderer() override;

protected:

  std::unique_ptr<cdhge::core::Engine> _engine;
};

#endif // INC_CHUDONGHAO_22_5_8_7E51E9ABB4604BDBB8C9893C7166A1D0_
