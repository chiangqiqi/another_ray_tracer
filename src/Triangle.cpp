#include "Triangle.h"
#include <limits>
using namespace Raytracer148;
using namespace Eigen;
using namespace std;

HitRecord Triangle::intersect(const Ray &ray) {
  HitRecord result;
  result.t = -1;

  //norm of the plane
  Vector3d normal = ((v2-v1).cross(v3-v1)).normalized();
  
  double t = -((ray.origin-v1).dot(normal))
    /(ray.direction.dot(normal));
  Vector3d position = ray.origin + t * ray.direction;

  double d_1 = ((v2-v1).cross(position-v1)).dot(normal);
  double d_2 = ((v3-v2).cross(position-v2)).dot(normal);
  double d_3 = ((v1-v3).cross(position-v3)).dot(normal);

  if(!(d_1>0 && d_2>0 && d_3>0)) return result;//no hit
    
  result.t = t;
  result.position = position;
  result.normal = normal;

  return result;
}
