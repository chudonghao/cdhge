//
// Created by chudonghao on 22-5-8.
//

#ifndef INC_CHUDONGHAO_22_5_8_E77C915D66404813B440DBF754A966C9_
#define INC_CHUDONGHAO_22_5_8_E77C915D66404813B440DBF754A966C9_

#include <QVulkanWindowRenderer>

#include <s3ge/core/Engine.h>

class MainWindowRenderer : public QObject, public QVulkanWindowRenderer {
public:
  MainWindowRenderer(s3ge::core::Engine *engine, QVulkanWindow *parent);
  ~MainWindowRenderer() override;
  void preInitResources() override;
  void initResources() override;
  void initSwapChainResources() override;
  void releaseSwapChainResources() override;
  void releaseResources() override;
  void startNextFrame() override;
  void physicalDeviceLost() override;
  void logicalDeviceLost() override;

private:
  QVulkanWindow *_window{};

  s3ge::core::Engine *_engine{};
};

#endif // INC_CHUDONGHAO_22_5_8_E77C915D66404813B440DBF754A966C9_
