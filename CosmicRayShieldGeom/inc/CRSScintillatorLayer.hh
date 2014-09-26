#ifndef CosmicRayShieldGeom_CRSScintillatorLayer_hh
#define CosmicRayShieldGeom_CRSScintillatorLayer_hh
//
// Representation of one Scintillator Layer in  CosmicRayShield
//
// $Id: CRSScintillatorLayer.hh,v 1.10 2014/02/10 14:23:03 ehrlich Exp $
// $Author: ehrlich $
// $Date: 2014/02/10 14:23:03 $
//
// Original author KLG; somewhat based on  Rob Kutschke's Layer
//

#include <vector>
#include <deque>

#include "CosmicRayShieldGeom/inc/CRSScintillatorLayerId.hh"
#include "CosmicRayShieldGeom/inc/CRSScintillatorBar.hh"

#include "CLHEP/Vector/ThreeVector.h"

namespace mu2e 
{

  class CRSScintillatorLayer
  {

    friend class CRSScintillatorModule;
    friend class CRSScintillatorShield;
    friend class CosmicRayShieldMaker;

    CRSScintillatorLayer();

    public:

    CRSScintillatorLayer(CRSScintillatorLayerId const & id);

    // Accept the compiler generated destructor, copy constructor and assignment operators

    CRSScintillatorLayerId const & id() const { return _id;}

    int nBars() const { return _bars.size(); }

    CRSScintillatorBar const & getBar( int n ) const 
    {
      return *_bars.at(n);
    }

    CRSScintillatorBar const & getBar( const CRSScintillatorBarId& id ) const 
    {
      return getBar(id.getBarNumber());
    }

    const std::vector<const CRSScintillatorBar*>& getBars() const { return _bars; }

    const CLHEP::Hep3Vector &getPosition() const {return _position;}
    const std::vector<double> &getHalfLengths() const {return _halfLengths;}

    // Formatted string embedding the id of the layer.
    std::string name( std::string const & base ) const;

    private:

    CRSScintillatorLayerId _id;

    // Pointers to the bars in this layer.
    // These pointers do not own the bars to which they point.
    // These are not persisted and may need to be recomputed after readback.
    // CosmicRayShield "owns" the bars
    mutable std::vector<const CRSScintillatorBar*> _bars;

    CLHEP::Hep3Vector _position;
    std::vector<double> _halfLengths;
  };
}

#endif /* CosmicRayShieldGeom_CRSScintillatorLayer_hh */
