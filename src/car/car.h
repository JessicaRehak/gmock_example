#ifndef GMX_CAR_CAR_H_
#define GMX_CAR_CAR_H_

#include "tireI.h"

#include <memory>
#include <vector>

namespace gmx {

namespace car {

enum Axel { front, rear = 2 };
enum Side { left, right };

class Car {
 public:
  Car() = default;

  Car &InstallSpare(std::unique_ptr<TireI> tire);
  Car &InstallTire(std::unique_ptr<TireI> tire, Axel axel, Side side);
  
  float SparePressure() const { return spare_tire_->pressure(); };
  float TirePressure(Axel axel, Side side) const; 
 private:
  std::array<std::unique_ptr<TireI>, 4> tires_;
  std::unique_ptr<TireI> spare_tire_;
};

} //namespace car

} // namespace gmx

#endif //GMX_CAR_CAR_H_
