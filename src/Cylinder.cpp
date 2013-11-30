#include "Cylinder.h"
#include <limits>
#include <cmath>
using namespace Raytracer148;
using namespace Eigen;
using namespace std;

HitRecord Cylinder::intersect(const Ray &ray) {
  HitRecord result;
  result.t = -1;

  Vector3d delta = ray.origin - p;
  // //compute the distance between the ray and the line
  // Vector3d n = ray.direction.cross(d);
  // double n_norm = n.squaredNorm();
  // double dist = (p - ray.origin).dot(n)/sqrt(n_norm);
  
  double A = (ray.direction- (ray.direction.dot(d))*d ).squaredNorm();
  double B = 2*((ray.direction- (ray.direction.dot(d))*d)
		.dot(delta-(delta.dot(d)*d)));
  
  double C = (delta-(delta.dot(d)*d)).squaredNorm()-r*r;
  double discriminant = B*B - 4*A*C;

  if (discriminant < numeric_limits<double>::epsilon()) return result; // no hit!

  
  double t0 = (-B - sqrt(discriminant)) / (2*A);
  double t1 = (-B + sqrt(discriminant)) / (2*A);
    
  if (t1 < numeric_limits<double>::epsilon()) return result; // no hit!
    
  // hit!
  if (t0 > numeric_limits<double>::epsilon()) result.t = t0; // use closer hit if it's in front
  else result.t = t1;

  result.position = ray.origin + result.t * ray.direction;
  result.normal = result.position-p-(result.position-p).dot(d.normalized())*d.normalized();

  return result;
}
