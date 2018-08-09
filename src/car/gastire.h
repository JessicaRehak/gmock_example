#ifndef GMX_CAR_AIRTIRE_H_
#define GMX_CAR_AIRTIRE_H_

#include "tireI.h"

namespace gmx {

namespace car {

class GasTire : public TireI {
 public:

  GasTire(std::string brand) : brand_(brand) {};
  ~GasTire() = default;
  
  std::string brand() const override {return brand_;};
  float orientation() const override {return orientation_;};
  float pressure()    const override {return pressure_;};

  GasTire &Turn(float degrees) override {orientation_ += degrees; return *this;};
  GasTire &Pump(float pounds)  override {pressure_ += pounds; return *this;};
  
 private:
  std::string brand_{""};
  float orientation_{0};
  float pressure_{0};
                        
};
} // namespace car

} // namespace gmx



#endif // GMX_CAR_AIRTIRE_H_
