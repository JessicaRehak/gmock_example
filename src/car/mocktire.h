#ifndef GMX_CAR_MOCKTIRE_H_
#define GMX_CAR_MOCKTIRE_H_

#include "tireI.h"

#include <gmock/gmock.h>

namespace gmx {

namespace car {

class MockTire : public TireI {
 public:
  MOCK_CONST_METHOD0(brand, std::string());
  MOCK_CONST_METHOD0(orientation, float());
  MOCK_CONST_METHOD0(pressure, float());

  MOCK_METHOD1(Turn, TireI&(float degrees));
  MOCK_METHOD1(Pump, TireI&(float pounds));
};

} // namespace car

} // namespace gmx

#endif //GMX_CAR_MOCKTIRE
