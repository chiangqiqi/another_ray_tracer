#ifndef SHAPE_H
#define SHAPE_H

#include <Eigen/Dense>

namespace Raytracer148 {
  //c is the color using a vector3d with r g b
  //Vector3d c;
  
  struct Ray {
     Eigen::Vector3d origin, direction;
  };
  
  class Shape;
  
  struct HitRecord {
      Eigen::Vector3d position, normal;
      double t;
  };

  class Shape {
  public:
    //  Shape(Vector3d color) : c(color) {}
    virtual HitRecord intersect(const Ray &ray) = 0;
    //  Vector3d color();
  };
}

#endif
