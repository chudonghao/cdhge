#ifndef CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
#define CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_

#include <cdhGE/export.h>

namespace cdhGE::universe {

class CDHGE_EXPORT Entity {
public:
  virtual void evolve() = 0;
};

} // namespace cdhGE::universe

#endif // CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
