
#include "Octree.h"

const int OCTREE_POINT_CAPACITY = 4;
const int MAX_SUBDIVIDE_ORDER = 8;

std::vector<OctTree::Point3D> OctTree::GetOctTreePoints()
{
  return points;
}

void OctTree::SetOctTreePoints(const OctTree::Point3D point)
{
  points.push_back(point);
}

bool OctTree::AxisAlignedBBox::IsAxisAlignedBoxContainsPoint(const OctTree::AxisAlignedBBox& boundary,
    const OctTree::Point3D point)
{
  std::cout << "Point to be inserted" << "X : " << point.x << "   Y : " << point.y << "   Z : " << point.z <<
            std::endl;
  if (point.x < (boundary.centre.x - boundary.halfDimentionsX) ||
      point.x > boundary.centre.x + boundary.halfDimentionsX)
  {
    return false;
  }

  if (point.y < (boundary.centre.y - boundary.halfDimentionsY) ||
      point.y > boundary.centre.y + boundary.halfDimentionsY)
  {
    return false;
  }

  if (point.z < (boundary.centre.z - boundary.halfDimentionsZ) ||
      point.z > boundary.centre.z + boundary.halfDimentionsZ)
  {
    return false;
  }

  std::cout << "Yes Bounding Box contain above point . " << std::endl;
  return true;
}

void OctTree::OctTreeSubdivide()
{
  subdivideOrder++;
  std::cout << "subdivideOrder value is = : " << subdivideOrder << std::endl;

  if (subdivideOrder == MAX_SUBDIVIDE_ORDER)
  {
    return;
  }

  float halfDimX = boundary.halfDimentionsX / 2;
  float halfDimY = boundary.halfDimentionsY / 2;
  float halfDimZ = boundary.halfDimentionsZ / 2;

  // Top Left Front
  const Point3D topLeftFront = Point3D(boundary.centre.x - halfDimX, boundary.centre.y - halfDimY,
                                       boundary.centre.z + halfDimZ);
  AxisAlignedBBox bBox = AxisAlignedBBox(topLeftFront, halfDimX, halfDimY, halfDimZ);
  topLeftFrontNode = std::make_shared<OctTree>(bBox);

  // Top Right Front
  const Point3D topRightFront = Point3D(boundary.centre.x + halfDimX, boundary.centre.y - halfDimY,
                                        boundary.centre.z + halfDimZ);
  bBox = AxisAlignedBBox(topRightFront, halfDimX, halfDimY, halfDimZ);
  topRightFrontNode = std::make_shared<OctTree>(bBox);

  // Down Right Front
  Point3D downRightFront = Point3D(boundary.centre.x + halfDimX, boundary.centre.y - halfDimY,
                                   boundary.centre.z - halfDimZ);
  bBox = AxisAlignedBBox(downRightFront, halfDimX, halfDimY, halfDimZ);
  downRightFrontNode = std::make_shared<OctTree>(bBox);

  // Down Left Front
  Point3D downLeftFront = Point3D(boundary.centre.x - halfDimX, boundary.centre.y - halfDimY,
                                  boundary.centre.z - halfDimZ);
  bBox = AxisAlignedBBox(downLeftFront, halfDimX, halfDimY, halfDimZ);
  downLeftFrontNode = std::make_shared<OctTree>(bBox);

  // Top Left Back
  Point3D topLeftBack = Point3D(boundary.centre.x - halfDimX, boundary.centre.y + halfDimY,
                                boundary.centre.z + halfDimZ);
  bBox = AxisAlignedBBox(topLeftBack, halfDimX, halfDimY, halfDimZ);
  topLeftBackNode = std::make_shared<OctTree>(bBox);

  // Top Right Back
  Point3D topRightBack = Point3D(boundary.centre.x + halfDimX, boundary.centre.y + halfDimY,
                                 boundary.centre.z + halfDimZ);
  bBox = AxisAlignedBBox(topRightBack, halfDimX, halfDimY, halfDimZ);
  topRightBackNode = std::make_shared<OctTree>(bBox);

  // Down Right Back
  Point3D downRightBack = Point3D(boundary.centre.x + halfDimX, boundary.centre.y + halfDimY,
                                  boundary.centre.z - halfDimZ);
  bBox = AxisAlignedBBox(downRightBack, halfDimX, halfDimY, halfDimZ);
  downRightBackNode = std::make_shared<OctTree>(bBox);

  // Down Left Back
  Point3D downLeftBack = Point3D(boundary.centre.x - halfDimX, boundary.centre.y + halfDimY,
                                 boundary.centre.z - halfDimZ);
  bBox = AxisAlignedBBox(downLeftBack, halfDimX, halfDimY, halfDimZ);
  downLeftBackNode = std::make_shared<OctTree>(bBox);

  std::cout << "****** OcTree Subdivided ****** " << std::endl;
}

bool OctTree::Insert(const OctTree::Point3D point)
{
  if (!boundary.IsAxisAlignedBoxContainsPoint(boundary, point))
  {
    std::cout << " Point can not be inserted because point is outside boundary of OcTree..... " << std::endl;
    return false;
  }

  std::vector<Point3D> points = GetOctTreePoints();
  std::cout << "Before insertion Points size is : " << points.size() << std::endl;
  if ((points.size() < OCTREE_POINT_CAPACITY &&
       topLeftFrontNode == nullptr) ||
      subdivideOrder == MAX_SUBDIVIDE_ORDER)   // if less than point capacity and it is leaf node
  {
    this->SetOctTreePoints(point);
    std::cout << "Point inserted ..... " << std::endl;
    std::vector<Point3D> pts = GetOctTreePoints();
    std::cout << "After insertion Points size is : " << pts.size() << std::endl;

    if (pts.size() != 0)
    {
      for (auto i : pts)
      {
        std::cout << "points are : " << "X : " << i.x << "   Y : " << i.y << "   Z : " << i.z << std::endl;
      }
    }

    return true;
  }

  if (topLeftFrontNode == nullptr)   // if it is leaf node
  {
    OctTreeSubdivide();
  }

  if (topLeftFrontNode->Insert(point)) { std::cout << "inserted into TopLeftFront " << std::endl; return true; }
  if (topRightFrontNode->Insert(point)) { std::cout << "inserted into TopRightFront " << std::endl;  return true; }
  if (downRightFrontNode->Insert(point)) { std::cout << "inserted into DownRightFront " << std::endl;  return true; }
  if (downLeftFrontNode->Insert(point)) { std::cout << "inserted into DownLeftFront " << std::endl;  return true; }
  if (topLeftBackNode->Insert(point)) { std::cout << "inserted into TopLeftBack " << std::endl;  return true; }
  if (topRightBackNode->Insert(point)) { std::cout << "inserted into TopRightBack " << std::endl;  return true; }
  if (downRightBackNode->Insert(point)) { std::cout << "inserted into DownRightBack " << std::endl;  return true; }
  if (downLeftBackNode->Insert(point)) { std::cout << "inserted into DownLeftBack " << std::endl;  return true; }

  std::cout << "Point is not inserted " << std::endl;
  return false;
}

bool OctTree::AxisAlignedBBox::AABB_intersects_AABB(const OctTree::AxisAlignedBBox& self,
    const OctTree::AxisAlignedBBox& other)
{
  if (self.centre.x + self.halfDimentionsX > other.centre.x - other.halfDimentionsX)
  {
    return true;
  }

  if (self.centre.x - self.halfDimentionsX < other.centre.x + other.halfDimentionsX)
  {
    return true;
  }

  if (self.centre.y + self.halfDimentionsY > other.centre.y - other.halfDimentionsY)
  {
    return true;
  }

  if (self.centre.y - self.halfDimentionsY < other.centre.y + other.halfDimentionsY)
  {
    return true;
  }

  if (self.centre.z + self.halfDimentionsZ > other.centre.z - other.halfDimentionsZ)
  {
    return true;
  }

  if (self.centre.z - self.halfDimentionsZ < other.centre.z + other.halfDimentionsZ)
  {
    return true;
  }

  return false;

}

std::vector<OctTree::Point3D> OctTree::OctTreeQueryRange(const AxisAlignedBBox& bBox)
{
  std::vector<Point3D> result;

  if (!boundary.AABB_intersects_AABB(boundary, bBox))
  {
    std::cout << "it does not intersects...... " << std::endl;
    return result;
  }

  std::vector<Point3D> points = GetOctTreePoints();

  for (std::size_t i = 0; i < points.size(); i++)
  {
    if (boundary.IsAxisAlignedBoxContainsPoint(bBox, points[i]))
    {
      result.push_back(points[i]);
    }
  }

  if (topLeftFrontNode == nullptr)
  {
    return result;
  }

  std::vector<Point3D> topLeftFrontPoints = topLeftFrontNode->OctTreeQueryRange(bBox);
  for (const auto point : topLeftFrontPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> topRightFrontPoints = topRightFrontNode->OctTreeQueryRange(bBox);
  for (const auto point : topRightFrontPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> downRightFrontPoints = downRightFrontNode->OctTreeQueryRange(bBox);
  for (const auto point : downRightFrontPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> downLeftFrontPoints = downLeftFrontNode->OctTreeQueryRange(bBox);
  for (const auto point : downLeftFrontPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> topLeftBackPoints = topLeftBackNode->OctTreeQueryRange(bBox);
  for (const auto point : topLeftBackPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> topRightBackPoints = topRightBackNode->OctTreeQueryRange(bBox);
  for (const auto point : topRightBackPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> downRightBackPoints = downRightBackNode->OctTreeQueryRange(bBox);
  for (const auto point : downRightBackPoints)
  {
    result.push_back(point);
  }

  std::vector<Point3D> downLeftBackPoints = downLeftBackNode->OctTreeQueryRange(bBox);
  for (const auto point : downLeftBackPoints)
  {
    result.push_back(point);
  }

  return result;
}

int main()
{
  OctTree::Point3D centerPoint = { 0.0f, 0.0f, 0.0f };
  OctTree::AxisAlignedBBox bBox(centerPoint, 4.0f, 4.0f, 4.0f);

  std::shared_ptr<OctTree> Octree = std::make_shared<OctTree>(bBox);

  OctTree::Point3D point1 = OctTree::Point3D(1.0f, 1.5f, 1.7f);
  OctTree::Point3D point2 = OctTree::Point3D(1.3f, 1.8f, 1.9f);
  OctTree::Point3D point3 = OctTree::Point3D(2.0f, 0.5f, 0.7f);
  OctTree::Point3D point4 = OctTree::Point3D(2.0f, 0.5f, 1.7f);
  OctTree::Point3D point5 = OctTree::Point3D(1.9f, 3.5f, 1.7f);
  OctTree::Point3D point6 = OctTree::Point3D(2.5f, 3.5f, 1.7f);
  OctTree::Point3D point7 = OctTree::Point3D(2.6f, 3.6f, 1.8f);
  OctTree::Point3D point8 = OctTree::Point3D(2.5f, 3.6f, 2.0f);
  OctTree::Point3D point9 = OctTree::Point3D(2.5f, 3.5f, 1.7f);
  OctTree::Point3D point10 = OctTree:: Point3D(2.4f, 1.5f, 1.7f);

  Octree->Insert(point1);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point2);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point3);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point4);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point5);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point6);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point7);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point8);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point9);
  std::cout << "===========================================================================" << std::endl;
  Octree->Insert(point10);
  std::cout << "===========================================================================" << std::endl;

  OctTree::Point3D bBoxCenter = { 2.0f, 2.0f, 2.0f };
  OctTree::AxisAlignedBBox box(centerPoint, 2.0f, 2.0f, 2.0f);
  std::vector<OctTree::Point3D> points = Octree->OctTreeQueryRange(box);
  std::cout << "*****************************After Query Result****************************" << std::endl;
  for (auto i : points)
  {
    std::cout << "Point : x : " << i.x << " y : " << i.y << " z : " << i.z << std::endl;
  }
}

