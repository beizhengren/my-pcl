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

template <typename PCL_TYPE>
PCL_TYPE concatenate_points(const PCL_TYPE& points_a, const PCL_TYPE& points_b)
{
    auto c = points_a;
    c = c + points_b;
    return c;
}
