#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

namespace Raytracer148 {
  class Cylinder : public Shape {
  public:
  Cylinder(Eigen::Vector3d &point, Eigen::Vector3d &direction, double radius) :
    p(point),  d(direction), r(radius) {}
  
      virtual HitRecord intersect(const Ray &ray);
      
  private:
      //p for the point
      //d for the direction
      Eigen::Vector3d p;
      Eigen::Vector3d d;
      double r;
  };
}

#endif
