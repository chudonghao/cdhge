#include "DevelopmentLow.h"
#include "Universe.h"

namespace cdhGE::universe {

std::map<std::string, std::shared_ptr<Entity>> &DevelopmentLow::getEntityList(cdhGE::universe::Universe &u) { return u._entityList; }

} // namespace cdhGE::universe
