#ifndef CDHGE_H_2021_2_19_6503A818B5A045948CD93D3A1D9E1791_
#define CDHGE_H_2021_2_19_6503A818B5A045948CD93D3A1D9E1791_

#include <map>
#include <string>

namespace cdhGE::universe {

class Universe;
class Entity;

class DevelopmentLow {
public:
  virtual void affect(Universe &) = 0;

protected:
  std::map<std::string, std::shared_ptr<Entity>> &getEntityList(Universe &);
};

} // namespace cdhGE::universe

#endif // CDHGE_H_2021_2_19_6503A818B5A045948CD93D3A1D9E1791_
