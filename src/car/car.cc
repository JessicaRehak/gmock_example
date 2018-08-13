#include "car.h"

namespace gmx {

namespace car {
Car &Car::InstallSpare(std::unique_ptr<TireI> tire) {
  spare_tire_ = std::move(tire);
  return *this;
}

Car &Car::InstallTire(std::unique_ptr<TireI> tire, Axel axel, Side side) {
  if (tires_.at(axel + side) == nullptr) {
    tires_[axel + side] = std::move(tire);
  } else {
    //tires_[axel + side].reset(nullptr);
    tires_[axel + side] = std::move(tire);
  }
  return *this;
}

float Car::TirePressure(Axel axel, Side side) const {
  return tires_.at(axel + side)->pressure();
}

} // namespace car

} // namespace gmx
