#ifndef CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
#define CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_

#include <vector>

#include <cdhGE/export.h>

namespace cdhGE::universe {

class CDHGE_EXPORT Entity {
public:
  virtual void evolve() = 0;

  template <class T>
  T *getUniverseDataPointer() const {
    return reinterpret_cast<T *>(_universeDataPointer);
  }

  template <class T>
  void setUniverseDataPointer(T *p) {
    _universeDataPointer = p;
  }

private:
  void *_universeDataPointer;
};

} // namespace cdhGE::universe

#endif // CDHGE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
