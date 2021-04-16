/*
(***********************************************************************)
(*                                                                     *)
(* The ACME computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The ACME computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the ACME computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_triangle.hh
///

#ifndef INCLUDE_ACME_TRIANGLE
#define INCLUDE_ACME_TRIANGLE

#include "acme.hh"
#include "acme_math.hh"
#include "acme_box.hh"
#include "acme_intersect.hh"

namespace acme
{

  class line;
  class ray;
  class plane;
  class segment;
  class circle;
  class frame;

  /*\
   |   _        _                   _      
   |  | |_ _ __(_) __ _ _ __   __ _| | ___ 
   |  | __| '__| |/ _` | '_ \ / _` | |/ _ \
   |  | |_| |  | | (_| | | | | (_| | |  __/
   |   \__|_|  |_|\__,_|_| |_|\__, |_|\___|
   |                          |___/        
  \*/

  /**
   * Triangle in 3D space. The triangle is defined by three arbitrary points.
   */
  class triangle
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<triangle const> ptr; //!< Shared pointer to triangle object
#else
    typedef triangle const *ptr; //!< Pointer to triangle object
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to triangle objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to triangle objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to triangle objects

  private:
    vec3 _vertex[3]; //!< Triangle vertices

  public:
    //! Triangle class destructor
    ~triangle() {}

    //! Triangle copy constructor
    triangle(triangle const &) = default;

    //! Triangle class constructor
    triangle() {}

    //! Triangle class constructor
    triangle(
        real_type x0, //<! Input x value of first triangle vertex
        real_type y0, //<! Input y value of first triangle vertex
        real_type z0, //<! Input z value of first triangle vertex
        real_type x1, //<! Input x value of second triangle vertex
        real_type y1, //<! Input y value of second triangle vertex
        real_type z1, //<! Input z value of second triangle vertex
        real_type x2, //<! Input x value of third triangle vertex
        real_type y2, //<! Input y value of third triangle vertex
        real_type z2  //<! Input z value of third triangle vertex
    );

    //! Triangle class constructor
    triangle(
        vec3 const &point0, //!< Input first triangle vertex point
        vec3 const &point1, //!< Input second triangle vertex point
        vec3 const &point2  //!< Input third triangle vertex point
    );

    //! Triangle class constructor
    triangle(
        vec3 const point[3] //!< Input triangle verices
    );

    //! Equality operator
    triangle &
    operator=(
        triangle const &input //!< Input triangle object
    );

    //! Check if objects are (almost) equal
    bool
    is_equal(
        triangle const &input //!< Input triangle object
    ) const;

    //! Check if triangle is degenerated to point or segment
    bool
    is_degenerated(void) const;

    //! Get first triangle vertex
    vec3 const &
    vertex_0(void) const;

    //! Set first triangle vertex
    void
    vertex_0(
        vec3 const &input //!< New triangle vertex
    );

    //! Get second triangle vertex
    vec3 const &
    vertex_1(void) const;

    //! Set second triangle vertex
    void
    vertex_1(
        vec3 const &input //!< New triangle vertex
    );

    //! Get third triangle vertex
    vec3 const &
    vertex_2(void) const;

    //! Set third triangle vertex
    void
    vertex_2(
        vec3 const &input //!< New triangle vertex
    );

    //! Get i-th triangle vertex
    vec3 const &
    vertex(
        unsigned i //!< New triangle vertex
    ) const;

    //! Set i-th triangle vertex
    void
    vertex(
        unsigned i,       //!< Triangle i-th vertex index
        vec3 const &input //!< New triangle vertex
    );

    //! Set triangle vertices
    void
    vertices(
        vec3 const &vertex0, //!< Input first triangle vertex
        vec3 const &vertex1, //!< Input second triangle vertex
        vec3 const &vertex2  //!< Input third triangle vertex
    );

    //! Set triangle vertices vertices
    void
    vertices(
        vec3 const vertex[3] //!< New triangle vertices
    );

    //! Get first triangle edge
    segment
    edge_0(void) const;

    //! Get second triangle edge
    segment
    edge_1(void) const;

    //! Get third triangle edge
    segment
    edge_2(void) const;

    //! Get i-th triangle edge
    segment
    edge(
        unsigned i //!< Triangle i-th vertex index
    ) const;

    //! Get triangle edge created by i-th and j-th vertex
    segment
    edge(
        unsigned i, //!< Triangle i-th vertex index
        unsigned j  //!< Triangle j-th vertex index
    ) const;

    //! Get triangle face normal (normalized vector)
    vec3
    normal(void) const;

    //! Translate triangle by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Get translated triangle by vector
    triangle
    translated(
        vec3 const &input //!< Input translation vector
    ) const;

    //! Rotate triangle by matrix
    void
    rotate(
        mat3 const &input //!< Input 3x3 rotation matrix
    );

    //! Get rotated triangle by matrix
    triangle
    rotated(
        mat3 const &input //!< Input 3x3 rotation matrix
    ) const;

    //! Transform triangle from two coordinate frames
    void
    transform(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    );

    //! Get transformed triangle from two coordinate frames
    triangle
    transformed(
        frame const &from_frame, //!< Actual reference coordinate system
        frame const &to_frame    //!< Future reference coordinate system
    ) const;

    //! Swap triangle vertices
    void
    swap(
        unsigned i, //!< Triangle i-th vertex index
        unsigned j  //!< Triangle j-th vertex index
    );

    //! Get minimum box containing the current triangle object
    void
    minimum_box(
        box &input //!< Input box object
    ) const;

    //! Calculate triangle perimeter length
    real_type
    perimeter(void)
        const;

    //! Calculate triangle area
    real_type
    area(void)
        const;

    //! Check if a point lays inside the triangle
    bool
    is_inside(
        vec3 const &point //!< Query point
    ) const;

    //! Compute barycentric coordinates (u,v,w) for point
    void
    barycentric(
        vec3 const &point, //!< Input point
        real_type &u,      //!< Output barycentric coordinate u
        real_type &v,      //!< Output barycentric coordinate v
        real_type &w       //!< Output barycentric coordinate w
    ) const;

    //! Intersect ray with triangle (no precalculated normal) \n
    //! WARNING: This function does not support coplanarity!
    bool
    intersect(
        ray const &ray, //!< Input ray
        vec3 &point     //!< Output point
    ) const;

    //! Intersect line with triangle (no precalculated normal) \n
    //! WARNING: This function does not support coplanarity!
    bool
    intersect(
        line const &line, //!< Input line
        vec3 &point       //!< Output point
    ) const;

    //! Intersect plane with triangle \n
    //! WARNING: This function does not support coplanarity!
    bool
    intersect(
        plane const &plane, //!< Input plane
        segment &segment    //!< Ouput plane
    ) const;

    //! Intersect circle with triangle \n
    //! WARNING: This function only support coplanar objects!
    bool
    intersect(
        circle const &circle, //!< Input circle
        segment &segment      //!< Ouput segment
    ) const;

  }; // class triangle

  static triangle const NaN_triangle = triangle(acme::NaN_vec3, acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number triangle type
  static triangle triangle_goat = triangle(NaN_triangle);                                        //!< Scapegoat triangle type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_triangle.hh
///
