#ifndef S3GE_H_2021_2_19_C0A44291733D485F9A604112D1F408C2_
#define S3GE_H_2021_2_19_C0A44291733D485F9A604112D1F408C2_

#include <map>
#include <memory>
#include <vector>

#include "Entity.h"

#include <s3ge/export.h>

namespace s3ge::universe {

/// \note
/// 专有名词:
/// Universe: 宇宙
/// Entity: 实体
///
/// 这是我的宇宙
/// 我的宇宙体现了我的宇宙观
/// 我认为我的宇宙是由若干实体组成的,一切皆实体
class S3GE_EXPORT Universe {
public:
  Universe();

  /// 宇宙每时每刻都在演化
  void evolve();

private:
  friend class DevelopmentLow;

  bool _evolving{false};
  /// 宇宙包含很多实体
  std::map<std::string, std::shared_ptr<Entity>> _entityList;

  struct {
    std::vector<std::vector<Entity *>> layerStack;
  } _evolutionTmpData;
};

} // namespace s3ge::universe

#endif // S3GE_H_2021_2_19_C0A44291733D485F9A604112D1F408C2_
