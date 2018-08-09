#include <iostream>

#ifdef TEST
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#endif

int main(int argc, char* argv[]) {
#ifdef TEST
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
#else
  std::cout << "googlemock Example (GMX)" << std::endl;
  return 0;
#endif
}
