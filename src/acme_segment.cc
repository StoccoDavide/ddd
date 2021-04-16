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
/// file: acme_segment.cc
///

#include "acme_segment.hh"

namespace acme
{

  /*\
   |                                       _   
   |   ___  ___  __ _ _ __ ___   ___ _ __ | |_ 
   |  / __|/ _ \/ _` | '_ ` _ \ / _ \ '_ \| __|
   |  \__ \  __/ (_| | | | | | |  __/ | | | |_ 
   |  |___/\___|\__, |_| |_| |_|\___|_| |_|\__|
   |            |___/                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment::segment(
      real_type x0, real_type y0, real_type z0,
      real_type x1, real_type y1, real_type z1)
  {
    this->_point[0] = vec3(x0, y0, z0);
    this->_point[1] = vec3(x1, y1, z1);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment::segment(
      vec3 const &point0,
      vec3 const &point1)
  {
    this->_point[0] = point0;
    this->_point[1] = point1;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment::segment(
      vec3 const point[2])
  {
    this->_point[0] = point[0];
    this->_point[1] = point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment &
  segment::operator=(
      segment const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_point[0] = input._point[0];
      this->_point[1] = input._point[1];
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::is_equal(
      segment const &input)
      const
  {
    return acme::is_equal(this->_point[0], input._point[0]) &&
           acme::is_equal(this->_point[1], input._point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::is_degenerated(void)
      const
  {
    return acme::is_equal((this->_point[0] - this->_point[1]).norm(), real_type(0.0));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  segment::point_0(void)
      const
  {
    return this->_point[0];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void segment::point_0(
      vec3 const &input)
  {
    this->_point[0] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  segment::point_1(void)
      const
  {
    return this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::point_1(
      vec3 const &input)
  {
    this->_point[1] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::midpoint(void)
      const
  {
    return (this->_point[0] + this->_point[1]) / 2.0;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  segment::point(
      unsigned i) const
  {
    return this->_point[i];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::point(
      unsigned i,
      vec3 const &input)
  {
    this->_point[i] = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::points(
      vec3 const &input0,
      vec3 const &input1)
  {
    this->_point[0] = input0;
    this->_point[1] = input1;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::to_vector(void) const
  {
    return vec3(this->_point[1] - this->_point[0]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3
  segment::to_normalized_vector(void) const
  {
    return (this->_point[1] - this->_point[0]).normalized();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::translate(
      vec3 const &input)
  {
    this->_point[0] = input + this->_point[0];
    this->_point[1] = input + this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment
  segment::translated(
      vec3 const &input)
      const
  {
    return segment(input + this->_point[0],
                   input + this->_point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::rotate(
      mat3 const &input)
  {
    this->_point[0] = input * this->_point[0];
    this->_point[1] = input * this->_point[1];
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment
  segment::rotated(
      mat3 const &input)
      const
  {
    return segment(input * this->_point[0],
                   input * this->_point[1]);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::transform(
      frame const &from_frame,
      frame const &to_frame)
  {
    this->_point[0] = acme::transform_point(this->_point[0], from_frame, to_frame);
    this->_point[1] = acme::transform_point(this->_point[1], from_frame, to_frame);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  segment
  segment::transformed(
      frame const &from_frame,
      frame const &to_frame)
      const
  {
    return segment(acme::transform_point(this->_point[0], from_frame, to_frame),
                   acme::transform_point(this->_point[1], from_frame, to_frame));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::swap(void)
  {
    vec3 tmp_point(this->_point[0]);
    this->_point[0] = this->_point[1];
    this->_point[1] = tmp_point;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  segment::minimum_box(
      box &input)
      const
  {
    input.x_min(acme::min(this->_point[0].x(), this->_point[1].x()));
    input.y_min(acme::min(this->_point[0].y(), this->_point[1].y()));
    input.z_min(acme::min(this->_point[0].z(), this->_point[1].z()));
    input.x_max(acme::max(this->_point[0].x(), this->_point[1].x()));
    input.y_max(acme::max(this->_point[0].y(), this->_point[1].y()));
    input.z_max(acme::max(this->_point[0].z(), this->_point[1].z()));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  segment::length(void) const
  {
    return (this->_point[0] - this->_point[1]).norm();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::is_inside(
      vec3 const &point)
      const
  {
    real_type d0 = this->length();
    real_type d1 = (point - this->_point[0]).norm();
    real_type d2 = (point - this->_point[1]).norm();
    return acme::abs(d0 - d1 - d2) <= acme::Epsilon;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      segment const &segment,
      vec3 &point)
      const
  {
    return acme::intersect(segment, *this, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      plane const &plane,
      vec3 &point)
      const
  {
    return acme::intersect(*this, plane, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      circle const &circle,
      vec3 &point)
      const
  {
    return acme::intersect(*this, circle, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      segment const &segment_in,
      segment &segment_out)
      const
  {
    return acme::intersect(segment_in, *this, segment_out);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      line const &line,
      segment &segment)
      const
  {
    return acme::intersect(line, *this, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      ray const &ray,
      segment &segment)
      const
  {
    return acme::intersect(ray, *this, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  segment::intersect(
      circle const &circle,
      segment &segment)
      const
  {
    return acme::intersect(*this, circle, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_segment.cc
///