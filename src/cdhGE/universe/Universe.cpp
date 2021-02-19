#include "Universe.h"

#include <cdhGE/core/Logger.h>

#include "DLEntityEvolution.h"

namespace cdhGE::universe
{

Universe::Universe() {
  _developmentLowList[20000] = std::make_shared<DLEntityEvolution>();
}

void Universe::evolve() {
  CDHGE_LOG_TRACE << "start";
  if (_evolving) {
    CDHGE_LOG_WARNING << "call evolve() twice";
    return;
  } else {
    _evolving = true;
  }
  /// 根据宇宙的发展规律来演化
  /// 开始演化
  /// 物理系统
  /// 自我演化
  /// 结束演化
  /// 上帝事件
  for (auto &[i, low] : _developmentLowList) {
    low->affect(*this);
  }
  _evolving = false;
  CDHGE_LOG_TRACE << "end";
}

}