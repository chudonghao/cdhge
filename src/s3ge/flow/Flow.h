//
// Created by chudonghao on 22-10-22.
//

#ifndef INC_CHUDONGHAO_22_10_22_B4E5F5D973B048FA8588487335A3A85F_
#define INC_CHUDONGHAO_22_10_22_B4E5F5D973B048FA8588487335A3A85F_

#include <functional>
#include <limits>
#include <map>

namespace s3ge::flow {

class Flow : std::map<unsigned, std::function<unsigned()>> {
public:
  enum : unsigned {
    NODE_ERROR = std::numeric_limits<unsigned>::max(),
    NODE_DONE = 0,
  };

  explicit Flow(void *user_data = nullptr);

  unsigned operator()();

private:
  void *_user_data;
};

} // namespace s3ge::flow

#endif // INC_CHUDONGHAO_22_10_22_B4E5F5D973B048FA8588487335A3A85F_
