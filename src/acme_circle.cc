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
/// file: acme_circle.cc
///

#include "acme_circle.hh"

namespace acme
{

  /*\
   |        _          _      
   |    ___(_)_ __ ___| | ___ 
   |   / __| | '__/ __| |/ _ \
   |  | (__| | | | (__| |  __/
   |   \___|_|_|  \___|_|\___|
   |                          
  \*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle &
  circle::operator=(
      circle const &input)
  {
    if (this == &input)
    {
      return *this;
    }
    else
    {
      this->_radius = input._radius;
      this->_plane = input._plane;
      return *this;
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::is_equal(
      circle const &input)
      const
  {
    return acme::is_equal(this->_radius, input._radius) &&
           acme::is_equal(this->_plane.origin(), input._plane.origin()) &&
           acme::is_equal(this->_plane.normal(), input._plane.normal());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::is_degenerated(void)
      const
  {
    return acme::is_equal(this->_radius, 0.0) && this->_plane.is_degenerated();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  real_type
  circle::radius(void)
      const
  {
    return this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  circle::center(void)
      const
  {
    return this->_plane.origin();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  vec3 const &
  circle::normal(void)
      const
  {
    return this->_plane.normal();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  plane const &
  circle::laying_plane(void)
      const
  {
    return this->_plane;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::radius(
      real_type input)
  {
    this->_radius = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::center(
      vec3 const &input)
  {
    this->_plane.origin(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::normal(
      vec3 const &input)
  {
    this->_plane.normal(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::normalize_normal(void)
  {
    this->_plane.normalize_normal();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  void
  circle::laying_plane(
      plane const &input)
  {
    this->_plane = input;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::translate(
      vec3 const &input)
  {
    this->_plane.translate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle
  circle::translated(
      vec3 const &input)
      const
  {
    return circle(this->_radius,
                  this->_plane.translated(input));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::rotate(
      mat3 const &input)
  {
    this->_plane.rotate(input);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle
  circle::rotated(
      mat3 const &input)
      const
  {
    return circle(this->_radius,
                  this->_plane.rotated(input));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::transform(
      frame const &from_frame,
      frame const &to_frame)
  {
    this->_plane.transform(from_frame, to_frame);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle
  circle::transformed(
      frame const &from_frame,
      frame const &to_frame)
      const
  {
    return circle(this->_radius,
                  this->_plane.transformed(from_frame, to_frame));
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  void
  circle::reverse(void)
  {
    this->_plane.reverse();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  circle
  circle::reversed(void)
      const
  {
    return circle(this->_radius,
                  this->_plane.reversed());
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::is_inside(
      vec3 const &point)
      const
  {
    return this->_plane.is_inside(point) && (this->_plane.origin() - point).norm() <= this->_radius;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      line const &line,
      vec3 &point)
      const
  {
    return acme::intersect(line, *this, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      ray const &ray,
      vec3 &point)
      const
  {
    return acme::intersect(ray, *this, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      segment const &segment,
      vec3 &point)
      const
  {
    return acme::intersect(segment, *this, point);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      line const &line,
      segment &segment)
      const
  {
    return acme::intersect(line, *this, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      ray const &ray,
      segment &segment)
      const
  {
    return acme::intersect(ray, *this, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  //bool
  //circle::intersect(
  //    plane const &plane,
  //    segment &segment)
  //    const
  //{
  //  return acme::intersect(plane, *this, segment);
  //}

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      segment const &segment_in,
      segment &segment_out)
      const
  {
    return acme::intersect(segment_in, *this, segment_out);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  bool
  circle::intersect(
      triangle const &triangle,
      segment &segment)
      const
  {
    return acme::intersect(*this, triangle, segment);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace acme

///
/// eof: acme_circle.cc
///