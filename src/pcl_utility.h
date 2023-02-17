#include <iostream>
#include <string>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

void print_pcl(pcl::PointCloud<pcl::PointXYZ> cloud) noexcept
{
    for (const auto& point: cloud)
    {
        std::cerr << "    " << point.x << " " << point.y << " " << point.z << std::endl;
    }
}

template <typename PCL_TYPE>
void write_pcl(const std::string& name, const PCL_TYPE& cloud)
{
    pcl::io::savePCDFileASCII (name, cloud);
}

template <typename... PCL_POINTER>
auto concatenate_points(const PCL_POINTER& ... cloud_pack)
{
    return (... + *cloud_pack );
}

auto remove_suffix(const std::string& name)
{
  auto pos = name.find(".");
  auto new_name = name.substr(0, pos);
  return new_name;
}

template <typename ... PACK>
auto concatenate_name(const PACK& ... names)
{
  return (... + names);
}

template <typename ... Args>
auto combine_name(Args&& ... args)
{
  auto names = std::vector<std::string>{std::forward<Args>(args)...};
  std::transform(begin(names), end(names), begin(names), remove_suffix);
  auto ret_name = std::string{};
  for (const auto& name : names)
  {
    ret_name += name;
  }
  return ret_name;
}