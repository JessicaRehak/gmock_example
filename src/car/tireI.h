#ifndef GMX_CAR_TIREI_H_
#define GMX_CAR_TIREI_H_

#include <string>

namespace gmx {

namespace car {

class TireI {
  // Wheel Interface
 public:
  virtual ~TireI() = default;
  // Getters for private variables
  virtual std::string brand() const = 0;       // Tire brand
  virtual float orientation() const = 0;       // Orientation
  virtual float pressure()    const = 0;      // Tire pressure

  // Methods
  virtual TireI &Turn(float degrees) = 0; // Change orientation by degrees
  virtual TireI &Pump(float pounds) = 0;  // Increase tire pressure

 private:
 
  
};

} // namespace car

} // namespace gmx

#endif //GMX_CAR_TIREI_H_
