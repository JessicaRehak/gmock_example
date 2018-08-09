#include "../tireI.h"
#include "../gastire.h"
#include "../car.h"


#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

class CarIntegrationTest : public ::testing::Test {
 protected:
  std::string tire_brand = "Goodyear";
  gmx::car::Car test_car{};
};

TEST_F(CarIntegrationTest, InstallSpare) {
  auto spare_tire = std::unique_ptr<gmx::car::TireI>(new gmx::car::GasTire(tire_brand));
  spare_tire->Pump(30.0);
  test_car.InstallSpare(std::move(spare_tire));
  EXPECT_FLOAT_EQ(test_car.SparePressure(), 30.0);
}
