//
// Created by chudonghao on 22-5-28.
//

#ifndef INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_
#define INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_

#include <memory>

#include <s3ge/export.h>
#include <s3ge/renderer/Renderer.h>

namespace s3ge::core {

class S3GE_API Engine {
public:
  renderer::Renderer &renderer() {
    assert(_renderer);
    return *_renderer;
  }

  void set_renderer(std::unique_ptr<s3ge::renderer::Renderer> renderer) { _renderer = std::move(renderer); }

  void Frame();

protected:
  std::unique_ptr<s3ge::renderer::Renderer> _renderer;
};

} // namespace s3ge::core

#endif // INC_CHUDONGHAO_22_5_28_0F09E4FB964247568000709D8E66F4C6_
