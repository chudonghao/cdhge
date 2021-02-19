#ifndef CDHGE_H_2021_2_19_D5ACC834CBCD46438B2E04AEFEF4A9AB_
#define CDHGE_H_2021_2_19_D5ACC834CBCD46438B2E04AEFEF4A9AB_

#include <cdhGE/export.h>

#include "DevelopmentLow.h"

namespace cdhGE::universe {

class CDHGE_EXPORT DLEntityEvolution : public DevelopmentLow {
  void affect(Universe &u) override;
};

} // namespace cdhGE::universe

#endif // CDHGE_H_2021_2_19_D5ACC834CBCD46438B2E04AEFEF4A9AB_
