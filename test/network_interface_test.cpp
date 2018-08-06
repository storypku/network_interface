#include <network_utils.h>
#include <gtest/gtest.h>
#include <cstdio>
#include <vector>

TEST(TCPInterface, testReadBEFloat)
{
  // 123.4567 as binary float
  std::vector<uint8_t> bytes = { 0x42, 0xF6, 0xE9, 0xD5};
  ASSERT_FLOAT_EQ(123.45670318603515625, AS::Network::read_be<float>(bytes.begin(), 0));
}

TEST(TCPInterface, testReadBEDouble)
{
  // 123.4567 as binary double
  std::vector<uint8_t> bytes = { 0x40, 0x5E, 0xDD, 0x3A, 0x92, 0xA3, 0x05, 0x53};
  ASSERT_DOUBLE_EQ(123.4567, AS::Network::read_be<double>(bytes.begin(), 0));
}

TEST(TCPInterface, testReadBEInt)
{
  // 888888888 as  hex Int
  std::vector<uint8_t> bytes = { 0x34, 0xFB, 0x5E, 0x38};
  ASSERT_EQ(888888888, AS::Network::read_be<uint32_t>(bytes.begin(), 0));
}

TEST(TCPInterface, testReadLEFloat)
{
  // 123.4567 as binary float
  std::vector<uint8_t> bytes = { 0xD5, 0xE9, 0xF6, 0x42};
  ASSERT_FLOAT_EQ(123.45670318603515625, AS::Network::read_le<float>(bytes.begin(), 0));
}

TEST(TCPInterface, testReadLEDouble)
{
  // 123.4567 as binary double
  std::vector<uint8_t> bytes = { 0x53, 0x05, 0xA3, 0x92, 0x3A, 0xDD, 0x5E, 0x40};
  ASSERT_DOUBLE_EQ(123.4567, AS::Network::read_le<double>(bytes.begin(), 0));
}

TEST(TCPInterface, testReadLEInt)
{
  // 1234567891 as  hex Int
  std::vector<uint8_t> bytes = { 0xD3, 0x02, 0x96, 0x49};
  ASSERT_EQ(1234567891, AS::Network::read_le<uint32_t>(bytes.begin(), 0));
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
