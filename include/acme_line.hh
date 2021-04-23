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
/// file: acme_line.hh
///

#ifndef INCLUDE_ACME_LINE
#define INCLUDE_ACME_LINE

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |   _ _            
   |  | (_)_ __   ___ 
   |  | | | '_ \ / _ \
   |  | | | | | |  __/
   |  |_|_|_| |_|\___|
   |                  
  \*/

  //! Line class container
  /**
   * Infinite line in 3D space and defined by any point lying on the line and a direction
   * vector.
   */
  class line
  {
  public:
#ifdef ACME_USE_CXX11
    typedef std::shared_ptr<line const> ptr; //!< Shared pointer to line
#else
    typedef line const *ptr; //!< Pointer to line
#endif

    typedef std::pair<ptr, ptr> pairptr;     //!< Pair of pointers to line objects
    typedef std::vector<ptr> vecptr;         //!< Vector of pointers to line objects
    typedef std::vector<pairptr> vecpairptr; //!< Vector of pairs of pointers to line objects

  private:
    vec3 _origin;    //!< Origin (point)
    vec3 _direction; //!< Direction (vector)

  public:
    //! Line class destructor
    ~line() {}

    //! Line class constructor
    line() {}

    //! Line copy constructor
    line(line const &) = default;

    //! Line class constructor for line
    line(
        real_type ox, //<! Input x value of line origin point
        real_type oy, //<! Input y value of line origin point
        real_type oz, //<! Input z value of line origin point
        real_type dx, //<! Input x value of line direction vector
        real_type dy, //<! Input y value of line direction vector
        real_type dz  //<! Input z value of line direction vector
        ) : _origin(vec3(ox, oy, oz)),
            _direction(vec3(dx, dy, dz))
    {
    }

    //! Line class constructor
    line(
        vec3 const &origin,   //!< Input line origin point
        vec3 const &direction //!< Input line direction vector
        ) : _origin(origin),
            _direction(direction)
    {
    }

    //! Equality operator
    line &
    operator=(
        line const &input //!< Input line object
    );

    //! Check if objects are (almost) equal
    bool
    isApprox(
        line const &input //!< Input line object
    ) const;

    //! Check if line is degenerated (direction vector has zero norm)
    bool
    isDegenerated(void) const;

    //! Return line origin point
    vec3 const &
    origin(void) const;

    //! Return line direction vector
    vec3 const &
    direction(void) const;

    //! Set line origin point
    void
    origin(
        vec3 const &input //!< input line origin point
    );

    //! Set line direction vector
    void
    direction(
        vec3 const &input //!< input line direction vector
    );

    //! Normalize line direction vector
    void
    normalize(void);

    //! Convert line to vector
    vec3
    toVector(void) const;

    //! Convert line to normalized vector
    vec3
    toNormalizedVector(void) const;

    //! Translate line by vector
    void
    translate(
        vec3 const &input //!< Input translation vector
    );

    //! Transform line with affine transformation matrix
    void
    transform(
        affine const &matrix //!< 4x4 affine transformation matrix
    );

    //! Reverse line direction
    void
    reverse(void);

    // Check whether the point is inside the line
    bool
    isInside(
        vec3 const &point //!< Query point
    ) const;

  }; // class line

  static line const NaN_line = line(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number line type
  static line line_goat = line(NaN_line);                            //!< Scapegoat line type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_line.hh
///