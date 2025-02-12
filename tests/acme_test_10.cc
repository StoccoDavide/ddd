/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                     *
 * The ACME project                                                    *
 *                                                                     *
 * Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            *
 *                                                                     *
 * The ACME project and its components are supplied under the terms of *
 * the open source BSD 2-Clause License. The contents of the ACME      *
 * project and its components may not be copied or disclosed except in *
 * accordance with the terms of the BSD 2-Clause License.              *
 *                                                                     *
 * URL: https://opensource.org/licenses/BSD-2-Clause                   *
 *                                                                     *
 *    Davide Stocco                                                    *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: davide.stocco@unitn.it                                   *
 *                                                                     *
 *    Enrico Bertolazzi                                                *
 *    Department of Industrial Engineering                             *
 *    University of Trento                                             *
 *    e-mail: enrico.bertolazzi@unitn.it                               *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

///
/// file: test_10.cc
///

#include "acme.hh"

using namespace acme;

// Main function
int
main(void)
{
  // Try block
  try
  {

    // Print test main information
    std::cout
      << "---------------------------" << std::endl
      << "TEST 10 - AABBTREE INTERSECTION" << std::endl
      << std::endl;

    // Initialize vertices
    point V1[3];
    V1[0] = point(1.0, 0.0, 0.0);
    V1[1] = point(0.0, 1.0, 1.0);
    V1[2] = point(-1.0, 0.0, 0.0);

    point V2[3];
    V2[0] = point(-1.0, 0.0, 0.0);
    V2[1] = point(0.0, -1.0, -1.0);
    V2[2] = point(1.0, 0.0, 0.0);

    // Initialize triangle
    triangle Triangle1(V1);
    triangle Triangle2(V2);

    // Initialize boxes
    aabb Box1;
    aabb Box2;
    Box1.clamp(V1);
    Box2.clamp(V2);

    aabb::vecptr vecBox;
    vecBox.push_back(aabb::ptr(new aabb(Box1)));
    vecBox.push_back(aabb::ptr(new aabb(Box2)));

    AABBtree::ptr tree(new AABBtree());
    tree->build(vecBox);
    std::cout
        << "AABB tree 1" << std::endl;
    tree->print(std::cout);

    // Initialize a Boxes to check intersection
    aabb::vecptr vecBoxInt;
    vec3 min(0.0, 0.5, 0.5);
    vec3 max(0.0, 0.5, 0.5);
    vecBoxInt.push_back(aabb::ptr(new aabb(min, max, 0, 0)));

    AABBtree::ptr treeInt(new AABBtree());
    treeInt->build(vecBoxInt);
    std::cout
        << "AABB tree 2" << std::endl;
    treeInt->print(std::cout);

    // Perform intersection
    aabb::vecpairptr intBoxPair;
    tree->intersection(*treeInt, intBoxPair);

    for (size_t i = 0; i < intBoxPair.size(); ++i)
    {
      std::cout
          << "Intersection " << i << std::endl
          << "Box 1:" << std::endl
          << (*intBoxPair[i].first) << std::endl
          << "Box 2:" << std::endl
          << (*intBoxPair[i].second) << std::endl;
    }

    std::cout
      << std::endl
      << "Triangle 1:" << std::endl
      << Triangle1 << std::endl
      << std::endl
      << "Triangle 2:" << std::endl
      << Triangle2 << std::endl
      << std::endl
      << "Box 1:" << std::endl
      << Box1 << std::endl
      << std::endl
      << "Box 2:" << std::endl
      << Box2 << std::endl;

    // End of test
    std::cout
      << std::endl
      << "TEST 10: Completed" << std::endl
      << "---------------------------" << std::endl;

    // Exit the program
    return 0;
  }

  // Exception catch block
  catch (std::exception const &exc)
  {
    std::cerr << exc.what() << std::endl;
  }

  // Default catch block
  catch (...)
  {
    std::cerr
      << std::endl
      << "Aborted test: unknown error" << std::endl
      << "---------------------------" << std::endl;
  }
}

///
/// eof: test_10.cc
///
