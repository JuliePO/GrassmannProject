#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Scalar.hpp"
#include "Antiquadvector.hpp"
#include "Quadvector.hpp"
#include "Vector.hpp"
#include "Trivector.hpp"
#include "Antivector.hpp"
#include "Antitrivector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_antiquadvector::GCA_antiquadvector() : 
		GCA_quadvector() {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_antiquadvector::GCA_antiquadvector(double a) : 
		GCA_quadvector(a) {
		(*this).setBases();
		(*this).set(e1234, a);
	}

	// Constructeur par copie
	GCA_antiquadvector::GCA_antiquadvector(const GCA_antiquadvector& other) :
		GCA_quadvector(other) {
	}

	/*** Base duale **/
	GCA_antiquadvector operator~(const GCA_scalar& scalar) {

                GCA_antiquadvector antiquadvector;
		antiquadvector.setBases();

                antiquadvector.set(e1234, scalar.get(e));

                return antiquadvector;
        }

	/*** Anti wedge product ***/
	// Wedge product antivector et antitrivector = antiquadvector => ~trivector ^ ~vector = ~scalar
	GCA_antiquadvector operator&(const GCA_trivector& trivector, const GCA_vector& vector) {

		GCA_antiquadvector antiquadvector;
		antiquadvector.setBases();

		antiquadvector.set(e1234, (~trivector).get(e123)*(~vector).get(e4) - (~trivector).get(e124)*(~vector).get(e3) + (~trivector).get(e134)*(~vector).get(e2) - (~trivector).get(e234)*(~vector).get(e1));
	      
	        return antiquadvector;

	}
	

	// Wedge product antivector et antitrivector = antiquadvector => ~vector ^ ~trivector = ~scalar
	GCA_antiquadvector operator&(const GCA_vector& vector, const GCA_trivector& trivector) {
		
		GCA_antiquadvector antiquadvector;
		antiquadvector.setBases();

		antiquadvector.set(e1234, -(~trivector).get(e123)*(~vector).get(e4) + (~trivector).get(e124)*(~vector).get(e3) - (~trivector).get(e134)*(~vector).get(e2) + (~trivector).get(e234)*(~vector).get(e1));
	      
	        return antiquadvector;
	}
}
