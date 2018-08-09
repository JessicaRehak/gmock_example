#ifndef GMX_CAR_WHEELI_H_
#define GMX_CAR_WHEELI_H_

#include <string>

namespace gmx {

namespace car {

class WheelI {
  // Wheel Interface
 public:
  // Getters for private variables
  virtual float pressure() = 0;          // Tire pressure
  virtual std::string brand() = 0;       // Tire brand
  virtual float orientation() = 0;       // Orientation

  // Methods
  virtual WheelI &Turn(float degrees) = 0; // Change orientation by degrees

};

} // namespace car

} // namespace gmx

#endif //GMX_CAR_WHEELI_H_
