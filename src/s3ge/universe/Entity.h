#ifndef S3GE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
#define S3GE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_

#include <vector>

#include <s3ge/export.h>

namespace s3ge::universe {

class S3GE_EXPORT Entity {
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

} // namespace s3ge::universe

#endif // S3GE_H_2021_2_19_2280B45DADAC42BF88472CD3BA8829BE_
