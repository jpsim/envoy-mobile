#include "gtest/gtest.h"
#include "library/common/data/utility.h"
#include "library/common/types/c_types.h"
#include "library/common/types/utility.h"

namespace Envoy {
namespace Types {

TEST(EnvoyMapConvenientInitializerTest, FromCppToCEmpty) {
  const auto map = Envoy::Types::makeEnvoyMap({});

  EXPECT_EQ(map.length, 0);
}

TEST(EnvoyMapConvenientInitializerTest, FromCppToC) {
  const auto map = Envoy::Types::makeEnvoyMap({{"foo", "bar"}});

  EXPECT_EQ(Data::Utility::copyToString(map.entries[0].key), "foo");
  EXPECT_EQ(Data::Utility::copyToString(map.entries[0].value), "bar");
  EXPECT_EQ(map.length, 1);
}

} // namespace Types
} // namespace Envoy
