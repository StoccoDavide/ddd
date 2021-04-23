/*
(***********************************************************************)
(*                                                                     *)
(* The ACME project - Release Version 0.0.0                            *)
(*                                                                     *)
(* Copyright (c) 2020 Davide Stocco, All Rights Reserved.              *)
(*                                                                     *)
(* The ACME project and its components are supplied under the terms of *)
(* the open source BSD 2-Clause License. The contents of the ACME      *)
(* project and its components may not be copied or disclosed except in *)
(* accordance with the terms of the BSD 2-Clause License.              *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
(*                                                                     *)
(*    Davide Stocco                                                    *)
(*    University of Trento                                             *)
(*    Department of Industrial Engineering                             *)
(*    davide.stocco@unitn.it                                           *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_ray.hh
///

#ifndef INCLUDE_ACME_RAY
#define INCLUDE_ACME_RAY

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! Ray class container
  /**
   * Infinite ray in 3D space and defined by any point lying on the line and a direction
   * vector.
  */
  class ray
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<ray const> ptr; //!< Shared pointer to ray object
#else
    typedef ray const *ptr; //!< Pointer to ray object
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to ray objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to ray objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to ray objects

  private:
    vec3 _origin;    //!< Ray origin point
    vec3 _direction; //!< Ray direction vector

  public:
    //! Ray class destructor
    ~ray() {}

    //! Ray class constructor
    ray() {}

    //! Ray copy constructor
    ray(ray const &) = default;

    //! Ray class constructor
    ray(
        real_type ox, //<! Input x value of ray origin point
        real_type oy, //<! Input y value of ray origin point
        real_type oz, //<! Input z value of ray origin point
        real_type dx, //<! Input x value of ray direction
        real_type dy, //<! Input y value of ray direction
        real_type dz  //<! Input z value of ray direction
        ) : _origin(vec3(ox, oy, oz)),
            _direction(vec3(dx, dy, dz))
    {
    }

    //! Ray class constructor
    ray(
        vec3 const &origin,   //!< Input ray origin point
        vec3 const &direction //!< Input ray direction vector
        ) : _origin(origin),
            _direction(direction)
    {
    }

    //! Equality operator
    ray &
    operator=(
        ray const &input //!< Input ray object
    );

    //! Check if ray objects are (almost) equal
    bool
    isApprox(
        ray const &input //!< Input ray object
    ) const;

    //! Check if ray is degenerated (null vector)
    bool
    isDegenerated(void) const;

    //! Return ray origin point
    vec3 const &
    origin() const;

    //! Return ray direction vector
    vec3 const &
    direction() const;

    //! Set ray origin point
    void
    origin(
        vec3 const &input //!< input ray object
    );

    //! Set ray direction vector
    void
    direction(
        vec3 const &input //!< input ray object
    );

    //! Normalize ray direction vector
    void
    normalize(void);

    //! Convert ray to vector
    vec3
    toVector(void) const;

    //! Convert ray to normalized vector
    vec3
    toNormalizedVector(void) const;

    //! Translate ray by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform ray with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    //! Reverse ray direction
    void
    reverse(void);

    // Check whether the point is inside the ray
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

  }; // class ray

  static ray const NaN_ray = ray(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number ray type
  static ray ray_goat = ray(NaN_ray);                             //!< Scapegoat ray type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_ray.hh
///