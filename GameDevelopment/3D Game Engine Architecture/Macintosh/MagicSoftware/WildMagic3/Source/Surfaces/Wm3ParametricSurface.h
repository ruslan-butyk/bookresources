// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3PARAMETRICSURFACE_H
#define WM3PARAMETRICSURFACE_H

#include "Wm3Surface.h"
#include "Wm3Vector3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM ParametricSurface : public Surface<Real>
{
public:
    // abstract base class
    virtual ~ParametricSurface ();

    // The parametric domain is either rectangular or triangular.  Valid (u,v)
    // values for a rectangular domain satisfy
    //   umin <= u <= umax,  vmin <= v <= vmax
    // Valid (u,v) values for a triangular domain satisfy
    //   umin <= u <= umax,  vmin <= v <= vmax,
    //   (vmax-vmin)*(u-umin)+(umax-umin)*(v-vmax) <= 0
    Real GetUMin () const;
    Real GetUMax () const;
    Real GetVMin () const;
    Real GetVMax () const;
    bool IsRectangular () const;

    // position and derivatives up to second order
    virtual Vector3<Real> P (Real fU, Real fV) const = 0;
    virtual Vector3<Real> PU (Real fU, Real fV) const = 0;
    virtual Vector3<Real> PV (Real fU, Real fV) const = 0;
    virtual Vector3<Real> PUU (Real fU, Real fV) const = 0;
    virtual Vector3<Real> PUV (Real fU, Real fV) const = 0;
    virtual Vector3<Real> PVV (Real fU, Real fV) const = 0;

    // Compute a coordinate frame.  The set {T0,T1,N} is a right-handed
    // orthonormal set.
    void GetFrame (Real fU, Real fV, Vector3<Real>& rkPosition,
        Vector3<Real>& rkTangent0, Vector3<Real>& rkTangent1,
        Vector3<Real>& rkNormal) const;

    // Differential geometric quantities.  The returned scalars are the
    // principal curvatures and the returned vectors are the corresponding
    // principal directions.
    void ComputePrincipalCurvatureInfo (Real fU, Real fV, Real& rfCurv0,
        Real& rfCurv1, Vector3<Real>& rkDir0, Vector3<Real>& rkDir1);

protected:
    ParametricSurface (Real fUMin, Real fUMax, Real fVMin, Real fVMax,
        bool bRectangular);

    Real m_fUMin, m_fUMax, m_fVMin, m_fVMax;
    bool m_bRectangular;
};

typedef ParametricSurface<float> ParametricSurfacef;
typedef ParametricSurface<double> ParametricSurfaced;

}

#endif
