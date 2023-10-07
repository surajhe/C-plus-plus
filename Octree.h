
#include <iostream>
#include <vector>
#include <memory>

class OctTree
{
public:
  struct Point3D
  {
    float x, y, z;
    Point3D(float a, float b, float c) : x(a), y(b), z(c) {}
  };

  struct AxisAlignedBBox
  {
    Point3D centre;
    float halfDimentionsX;        // Half of the BBox Width
    float halfDimentionsY;
    float halfDimentionsZ;
    AxisAlignedBBox(Point3D cent, float halfDmnX, float halfDmnY, float halfDmnZ) : centre(cent), halfDimentionsX(halfDmnX),
      halfDimentionsY(halfDmnY), halfDimentionsZ(halfDmnZ) {};

    bool AABB_intersects_AABB(const AxisAlignedBBox& self, const AxisAlignedBBox& other);
    bool IsAxisAlignedBoxContainsPoint(const AxisAlignedBBox& boundary, const Point3D point);
  };

  AxisAlignedBBox boundary;
  std::vector<Point3D> points;
  static std::size_t subdivideOrder;

  // pointers to children
  std::shared_ptr<OctTree> topLeftFrontNode = nullptr;
  std::shared_ptr<OctTree> topRightFrontNode = nullptr;
  std::shared_ptr<OctTree> downRightFrontNode = nullptr;
  std::shared_ptr<OctTree> downLeftFrontNode = nullptr;
  std::shared_ptr<OctTree> topLeftBackNode = nullptr;
  std::shared_ptr<OctTree> topRightBackNode = nullptr;
  std::shared_ptr<OctTree> downRightBackNode = nullptr;
  std::shared_ptr<OctTree> downLeftBackNode = nullptr;

  OctTree(AxisAlignedBBox bBoxBoundary) : boundary(bBoxBoundary) {}

  bool Insert(const Point3D point);

  void OctTreeSubdivide();

  std::vector<Point3D> OctTreeQueryRange(const AxisAlignedBBox& bBox);

  std::vector<OctTree::Point3D> GetOctTreePoints();
  void SetOctTreePoints(const Point3D point);

};

std::size_t OctTree::subdivideOrder = 1;
