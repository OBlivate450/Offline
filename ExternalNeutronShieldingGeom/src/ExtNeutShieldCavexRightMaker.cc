//
// Original author David Norvil Brown

#include <string>

#include "CLHEP/Vector/TwoVector.h"
#include "CLHEP/Units/SystemOfUnits.h"

#include "ExternalNeutronShieldingGeom/inc/ExtNeutShieldCavexRightMaker.hh"
#include "ExternalNeutronShieldingGeom/inc/ExtNeutShieldCavexRight.hh"

#include "ConfigTools/inc/SimpleConfig.hh"

namespace mu2e {

  //  namespace {

  std::unique_ptr<ExtNeutShieldCavexRight>  ExtNeutShieldCavexRightMaker::make(const 
							      SimpleConfig& c)
  {
    // Get the material name
    std::string mat = c.getString("ExtNeutShieldCavexRight.materialName");

    // Get the FULL length in z of the external shield
    double leng = c.getDouble("ExtNeutShieldCavexRight.length")*CLHEP::mm;

    // Now retrieve the vertices and put into a vector
    std::vector<CLHEP::Hep2Vector> shape;
    CLHEP::Hep2Vector v1(c.getDouble("ExtNeutShieldCavexRight.X1")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y1")*CLHEP::mm);
    shape.push_back(v1);

    CLHEP::Hep2Vector v2(c.getDouble("ExtNeutShieldCavexRight.X2")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y2")*CLHEP::mm);
    shape.push_back(v2);

    CLHEP::Hep2Vector v3(c.getDouble("ExtNeutShieldCavexRight.X3")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y3")*CLHEP::mm);
    shape.push_back(v3);

    CLHEP::Hep2Vector v4(c.getDouble("ExtNeutShieldCavexRight.X4")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y4")*CLHEP::mm);
    shape.push_back(v4);

    CLHEP::Hep2Vector v5(c.getDouble("ExtNeutShieldCavexRight.X5")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y5")*CLHEP::mm);
    shape.push_back(v5);

    CLHEP::Hep2Vector v6(c.getDouble("ExtNeutShieldCavexRight.X6")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y6")*CLHEP::mm);
    shape.push_back(v6);

    CLHEP::Hep2Vector v7(c.getDouble("ExtNeutShieldCavexRight.X7")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y7")*CLHEP::mm);
    shape.push_back(v7);

    CLHEP::Hep2Vector v8(c.getDouble("ExtNeutShieldCavexRight.X8")*CLHEP::mm,
		  c.getDouble("ExtNeutShieldCavexRight.Y8")*CLHEP::mm);
    shape.push_back(v8);


    // Location of the center of the shape relative to its parent volume
    // (the detector hall).
    CLHEP::Hep3Vector site(c.getDouble("ExtNeutShieldCavexRight.centerX")
			   *CLHEP::mm,
			   c.getDouble("ExtNeutShieldCavexRight.centerY")
			   *CLHEP::mm,
			   c.getDouble("ExtNeutShieldCavexRight.centerZ")
			   *CLHEP::mm);
			   
    
    double rot( c.getDouble("ExtNeutShieldCavexRight.rotateX")
		*CLHEP::degree);

    std::unique_ptr<ExtNeutShieldCavexRight> res(new ExtNeutShieldCavexRight(
								     shape,
								     leng,
								     mat,
								     site,
								     rot)
					     );

    //----------------------------------------------------------------
    if(c.getInt("ExtNeutShieldCavexRight.verbosityLevel") > 0) {
      std::cout<<*res<<std::endl;
    }

    return res;
  }

} // namespace mu2e