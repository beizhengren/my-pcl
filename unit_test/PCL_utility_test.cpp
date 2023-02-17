#include "src/pcl_utility.h"

#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(MergePCLTestCase, merge_2_PCL)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_a (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_b (new pcl::PointCloud<pcl::PointXYZ>);
  
  auto name_a = std::string{"test_a.pcd"};
  auto name_b = std::string{"test_b.pcd"};

  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_a, *cloud_a) != -1);
  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_b, *cloud_b) != -1);
  
  auto cloud_data = concatenate_points(cloud_a, cloud_b);
  auto output_name = concatenate_name(remove_suffix(name_a) + remove_suffix(name_b)) + ".pcd";
  write_pcl(output_name, cloud_data);
}

TEST(MergePCLTestCase, merge_3_PCL)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_a (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_b (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_c (new pcl::PointCloud<pcl::PointXYZ>);
  
  auto name_a = "test_a.pcd";
  auto name_b = "test_b.pcd";
  auto name_c = "test_c.pcd";

  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_a, *cloud_a) != -1);
  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_b, *cloud_b) != -1);
  ASSERT_TRUE(pcl::io::loadPCDFile<pcl::PointXYZ> (name_c, *cloud_c) != -1);
  
  auto cloud_data = concatenate_points(cloud_a, cloud_b, cloud_c);
  auto output_name = combine_name(name_a, name_b, name_c) + ".pcd";
  write_pcl(output_name, cloud_data);

}

TEST(CombineNameTestCase, combine_name)
{
  auto name_a = "test_a.pcd";
  auto name_b = "test_b.pcd";
  auto name_c = "test_c.pcd";
  auto name1 = concatenate_name(remove_suffix(name_a) + remove_suffix(name_b) + remove_suffix(name_c)) + ".pcd";
  auto name2 = combine_name(name_a, name_b, name_c) + ".pcd";
  EXPECT_EQ(name1, name2);

}