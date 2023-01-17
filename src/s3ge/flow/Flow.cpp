//
// Created by chudonghao on 22-10-22.
//

#include "Flow.h"

namespace s3ge::flow {

Flow::Flow(void *user_data) : _user_data(user_data) {}

unsigned Flow::operator()() {
  if (empty()) {
    return 0;
  }
  for (auto iter = begin();;) {
    // no end
    if (iter == end()) {
      return NODE_ERROR;
    }

    // run node and get next
    auto index = iter->second();

    // if done, we go next node
    if (index == NODE_DONE) {
      ++iter;
      // if last, flow done
      if (iter == end()) {
        break;
      }
      continue;
    }
    // error
    if (index == NODE_ERROR) {
      return NODE_ERROR;
    }

    // find next node
    iter = find(index);

    // if no that node, error
    if (iter == end()) {
      return NODE_ERROR;
    }
  }

  return 0;
}

} // namespace s3ge::flow
