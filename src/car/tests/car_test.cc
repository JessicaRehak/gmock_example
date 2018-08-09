#include "../car.h"
#include "../mocktire.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class CarTest : public ::testing::Test {
 protected:
  std::string tire_brand = "MockGoodyear";
  gmx::car::Car test_car{};
};

TEST_F(CarTest, InstallSpare) {
  auto mock_tire = std::make_unique<gmx::car::MockTire>();
  EXPECT_CALL(*mock_tire, pressure())
      .Times(1)
      .WillOnce(::testing::Return(30));
  auto spare_tire = std::unique_ptr<gmx::car::TireI>(std::move(mock_tire));
  
  test_car.InstallSpare(std::move(spare_tire));
  EXPECT_FLOAT_EQ(test_car.SparePressure(), 30.0);
}

