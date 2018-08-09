#include "../gastire.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

class GasTireTest : public ::testing::Test {
 protected:
  std::string brand = "Goodyear";
  gmx::car::GasTire test_wheel{brand};
};

TEST_F(GasTireTest, Initialization) {
  EXPECT_FLOAT_EQ(test_wheel.pressure(), 0);
  EXPECT_FLOAT_EQ(test_wheel.orientation(), 0);
  EXPECT_EQ(test_wheel.brand(), brand);
}

TEST_F(GasTireTest, TurnTest) {
  EXPECT_EQ(test_wheel.Turn(30.0).orientation(), 30.0);
  EXPECT_EQ(test_wheel.orientation(), 30.0);
  EXPECT_FLOAT_EQ(test_wheel.Turn(-100.4).orientation(), -70.4);
  EXPECT_EQ(test_wheel.pressure(), 0.0);
};

TEST_F(GasTireTest, PumpTest) {
  EXPECT_EQ(test_wheel.Pump(30.0).pressure(), 30.0);
  EXPECT_EQ(test_wheel.pressure(), 30.0);
  EXPECT_EQ(test_wheel.orientation(), 0.0);
};
