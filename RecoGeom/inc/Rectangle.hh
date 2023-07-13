//
//  Description of a rectangular planar section
//  original author: David Brown (LBN) 2023
//
#ifndef RecoGeom_Rectangle_hh
#define RecoGeom_Rectangle_hh
#include "Offline/RecoGeom/inc/Plane.hh"
#include <exception>
namespace mu2e {
  namespace RecoGeom {
    class Rectangle : public Plane {
      public:
        // construct from necessary parameters
        Rectangle(XYZVectorD const& norm, XYZVectorD const& center, XYZVectorD const& uaxis, double uhalflen, double vhalflen);
        // surface interface
        bool inBounds(XYZVectorD const& point, double tol=1e-8) const override;
        // rectangle-specific interface
        bool onRectangle(double udist, double vdist) const { return fabs(udist) < uhalflen_ && fabs(vdist) < vhalflen_; }
        auto const& uDirection() const { return udir_; }
        auto const& vDirection() const { return vdir_; }
        double uHalfLength() const { return uhalflen_; }
        double vHalfLength() const { return vhalflen_; }
      private:
        double uhalflen_, vhalflen_; // u and v half-lengths
        XYZVectorD udir_; // U direction: perpendicular to the normal
        XYZVectorD vdir_; // UV direction: perpendicular to the normal:w
    };
  }
}
std::ostream& operator <<(std::ostream& ost, mu2e::RecoGeom::Rectangle const& rect);
#endif
