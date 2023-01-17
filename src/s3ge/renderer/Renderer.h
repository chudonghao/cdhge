//
// Created by chudonghao on 22-5-28.
//

#ifndef INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_
#define INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_

#include <map>
#include <memory>

#include <s3ge/export.h>
#include <s3ge/renderer/Vulkan.h>

#include "Pass.h"

namespace s3ge::renderer {

class S3GE_API Renderer {
public:
  enum PathType {
    FINAL_PASS,
  };

  int Init(vk::Instance instance);

  int operator()();

protected:
  std::map<int, std::unique_ptr<Pass>> _passes;
};

} // namespace s3ge::renderer

#endif // INC_CHUDONGHAO_22_5_28_08620167A692464F9E071C859A472CDE_
