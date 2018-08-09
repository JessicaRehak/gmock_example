#ifndef GMX_CAR_CAR_H_
#define GMX_CAR_CAR_H_

#include "tireI.h"

#include <memory>
#include <vector>

namespace gmx {

namespace car {

class Car {
 public:
  Car() = default;
  
  Car &InstallSpare(std::unique_ptr<TireI> tire);
  float SparePressure() const { return spare_tire_->pressure(); };
  
 private:
  std::unique_ptr<TireI> spare_tire_;
};

} //namespace car

} // namespace gmx

#endif //GMX_CAR_CAR_H_
