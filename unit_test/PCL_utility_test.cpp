#include "src/pcl_utility.h"

#include <memory>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(MergePCLTestCase, PrepartionsCompleted)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_a (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_b (new pcl::PointCloud<pcl::PointXYZ>);
  auto name_a = "test_a.pcd";
  auto name_b = "test_b.pcd";
  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_a, *cloud_a) != -1);
  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_b, *cloud_b) != -1);
  auto cloud_data = concatenate_points(cloud_a, cloud_b);
  auto output_name = std::string{"merged.pcd"};
  write_pcl(output_name, cloud_data);
  GTEST_SUCCEED();
}