#include "../car.h"
#include "../mocktire.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class CarTest : public ::testing::Test {
 protected:
  gmx::car::Car test_car{};
};

class CarTestOneTire : public CarTest {
 protected:
  void SetUp() override;
};

void CarTestOneTire::SetUp() {

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

TEST_F(CarTestOneTire, InstalledTirePressure) {
  auto mock_tire = std::make_unique<gmx::car::MockTire>();
  EXPECT_CALL(*mock_tire, pressure())
      .Times(1)
      .WillRepeatedly(::testing::Return(45));
  auto tire = std::unique_ptr<gmx::car::TireI>(std::move(mock_tire));

  test_car.InstallTire(std::move(tire),
                       gmx::car::Axel::front, gmx::car::Side::right);
  
  EXPECT_FLOAT_EQ(test_car.TirePressure(gmx::car::Axel::front,
                                        gmx::car::Side::right), 45);
}

TEST_F(CarTestOneTire, ReplaceInstalledTire) {
  auto mock_tire = std::make_unique<gmx::car::MockTire>();
  auto tire = std::unique_ptr<gmx::car::TireI>(std::move(mock_tire));

  test_car.InstallTire(std::move(tire),
                       gmx::car::Axel::front, gmx::car::Side::right);
  
  auto replacement_mock_tire = std::make_unique<gmx::car::MockTire>();
  EXPECT_CALL(*replacement_mock_tire, pressure())
      .Times(1)
      .WillOnce(::testing::Return(60.0));
  auto replacement_tire = std::unique_ptr<gmx::car::TireI>(std::move(replacement_mock_tire));
  
  test_car.InstallTire(std::move(replacement_tire),
                       gmx::car::Axel::front, gmx::car::Side::right);
  
  EXPECT_FLOAT_EQ(test_car.TirePressure(gmx::car::Axel::front,
                                        gmx::car::Side::right), 60);
}
