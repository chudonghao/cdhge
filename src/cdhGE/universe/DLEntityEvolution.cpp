#include "DLEntityEvolution.h"

#include "Entity.h"

#include <cdhGE/core/Logger.h>

namespace cdhGE::universe {

void DLEntityEvolution::affect(Universe &u) {
  CDHGE_LOG_TRACE << "start";
  auto &entityList = getEntityList(u);
  for (auto &[id, entity] : entityList) {
    entity->evolve();
  }
  CDHGE_LOG_TRACE << "end";
}

} // namespace cdhGE::universe
