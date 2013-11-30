#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

namespace Raytracer148 {
  class  Triangle: public Shape {
  public:
      Triangle(Eigen::Vector3d &p1,Eigen::Vector3d &p2,Eigen::Vector3d &p3)
	: v1(p1), v2(p2), v3(p3) {}
  
      virtual HitRecord intersect(const Ray &ray);
      
  private:
      Eigen::Vector3d v1;
      Eigen::Vector3d v2;
      Eigen::Vector3d v3;
  };
}

#endif
