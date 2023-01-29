//
// Created by chudonghao on 23-1-23.
//

#ifndef INC_23_1_23_2FB072133EF34E15BADDCF91FF4526C1_H
#define INC_23_1_23_2FB072133EF34E15BADDCF91FF4526C1_H

#include <memory>
#include <vector>

#include <boost/beast/core/span.hpp>

#include <glm/vec2.hpp>

namespace cdhge::world {

class Mesh {
public:
  class Array;

private:
  std::shared_ptr<Array> _vertex;
  std::shared_ptr<Array> _tex_coord;
  std::shared_ptr<Array> _normal;

public:
  std::shared_ptr<Array> vertex() const {
    return _vertex;
  }
  std::shared_ptr<Array> tex_coord() const {
    return _tex_coord;
  }
  std::shared_ptr<Array> normal() const {
    return _normal;
  }
};

class Mesh::Array {
public:
  enum Depth {
    DEPTH_I8 = 1u,
    DEPTH_U8 = 1u << 2u,
    DEPTH_I16 = 1u << 3u,
    DEPTH_U16 = 1u << 4u,
    DEPTH_I32 = 1u << 5u,
    DEPTH_U32 = 1u << 6u,
    DEPTH_I64 = 1u << 7u,
    DEPTH_U64 = 1u << 8u,
    DEPTH_FLOAT = 1u << 9u,
    DEPTH_DOUBLE = 1u << 10u,
  };

private:
  // usage
  Depth _depth{};
  int _dims{};
  int _size{};

  void *_data{};

public:
  int size() const {
    return _size;
  }
  Depth depth() const {
    return _depth;
  }
  int dims() const {
    return _dims;
  }
};

} // namespace cdhge::world

#endif // INC_23_1_23_2FB072133EF34E15BADDCF91FF4526C1_H
