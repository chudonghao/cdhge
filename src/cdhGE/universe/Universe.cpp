#include "Universe.h"

#include <algorithm>
#include <set>

#include <cdhGE/core/Logger.h>

#include "DLEntityEvolution.h"

namespace cdhGE::universe {

struct Universe_EntityData {
  std::set<Entity *> dependOn;
  struct {
    int layer;
  } evolutionTmpData;

  void resetEvolutionLayer() { evolutionTmpData.layer = -1; }
  int updateEvolutionLayer() {
    if (evolutionTmpData.layer < 0) {
      evolutionTmpData.layer = 0;
      for (auto e : dependOn) {
        evolutionTmpData.layer = std::max(evolutionTmpData.layer, e->getUniverseDataPointer<Universe_EntityData>()->updateEvolutionLayer() + 1);
      }
    }
    return evolutionTmpData.layer;
  }
};

Universe::Universe() {}

void Universe::evolve() {
  CDHGE_LOG_TRACE << "start";
  if (_evolving) {
    // TODO 多线程问题
    CDHGE_LOG_WARNING << "call evolve() twice";
    return;
  } else {
    _evolving = true;
  }
  /// 宇宙演化


  /// 根据依赖关系，按顺序完成实体演化
  // 重置依赖层级
  _evolutionTmpData.layerStack.clear();
  for (auto &[id, entity] : _entityList) {
    entity->getUniverseDataPointer<Universe_EntityData>()->resetEvolutionLayer();
  }

  // 根据依赖层级，创建更新列表
  for (auto &[id, entity] : _entityList) {
    auto ed = entity->getUniverseDataPointer<Universe_EntityData>();
    int l = ed->updateEvolutionLayer();
    if (l >= _evolutionTmpData.layerStack.size()) {
      _evolutionTmpData.layerStack.resize(l + 1);
    }
    _evolutionTmpData.layerStack[l].push_back(entity.get());
  }

  // 按依赖顺序更新
  for (auto &layer : _evolutionTmpData.layerStack) {
    for (auto e : layer) {
      e->evolve();
    }
  }

  _evolving = false;
  CDHGE_LOG_TRACE << "end";
}

} // namespace cdhGE::universe