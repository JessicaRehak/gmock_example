#include "car.h"

namespace gmx {

namespace car {
Car &Car::InstallSpare(std::unique_ptr<TireI> tire) {
  spare_tire_ = std::move(tire);
  return *this;
}

} // namespace car

} // namespace gmx
