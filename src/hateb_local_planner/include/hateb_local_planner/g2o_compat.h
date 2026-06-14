#ifndef HATEB_LOCAL_PLANNER_G2O_COMPAT_H_
#define HATEB_LOCAL_PLANNER_G2O_COMPAT_H_

#include <cmath>

// Small g2o/stuff/misc.h helpers present in older and forked g2o but dropped from
// mainline g2o packaged on ROS 2 Jazzy (ros-jazzy-libg2o). Defined here so the
// existing g2o::average_angle / g2o::sign call sites build unchanged.
namespace g2o {

inline double average_angle(double theta1, double theta2) {
  const double x = std::cos(theta1) + std::cos(theta2);
  const double y = std::sin(theta1) + std::sin(theta2);
  if (x == 0.0 && y == 0.0) {
    return 0.0;
  }
  return std::atan2(y, x);
}

template <typename T>
inline T sign(T x) {
  return (x > T(0)) ? T(1) : ((x < T(0)) ? T(-1) : T(0));
}

}  // namespace g2o

#endif  // HATEB_LOCAL_PLANNER_G2O_COMPAT_H_
