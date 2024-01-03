Hds::Status LoadFromFile(Point3D& seedPoint, Vector3D& rayDirection, Hds::Array& points, Hds::Array& intensities)
{
  std::fstream dataFile;
  dataFile.open("D://Downloads//tmp_withporblem2.txt", std::fstream::in);

  if (!dataFile.is_open())
  { return Hds::STATUS_ERR_MSG("Can't open file with input data"); }

  dataFile >> rayDirection.x() >> rayDirection.y() >> rayDirection.z();
  dataFile >> seedPoint.x() >> seedPoint.y() >> seedPoint.z();

  std::size_t numPoints = 0;

  dataFile >> numPoints;

  std::vector<Hds::Dbl3> pointsVector(numPoints);
  for (std::size_t index = 0; index < numPoints; ++index)
  {
    Hds::Dbl3& point = pointsVector[index];

    dataFile >> point[0] >> point[1] >> point[2];
  }
  points.SetCapacityExternal(pointsVector.size(), pointsVector.data());
  points.MakeDeepCopy();

  std::vector<uint16_t> intensitiesVector(numPoints);
  for (std::size_t index = 0; index < numPoints; ++index)
  {
    dataFile >> intensitiesVector[index];
  }
  intensities.SetCapacityExternal(intensitiesVector.size(), intensitiesVector.data());
  intensities.MakeDeepCopy();

  return Hds::STATUS_SUCCESS;
}

========================================
  Data to read

-0.314664 -0.392221 0.864378 
-5.9335 -0.4285 -1.8435 
4549
-6.4535 -1.0425 -1.8545 
-6.4515 -1.0295 -1.8535 
-6.4265 -1.0375 -1.8545 
-6.4285 -1.0255 -1.8545 
-6.3995 -1.0335 -1.8535 
-6.3735 -1.0295 -1.8535 
-6.3555 -1.0265 -1.8535 
-6.4515 -1.0155 -1.8535 
15056
16136
14612
14880
14424
14316
13980
17248
15308
14912
15588
15076
15504
