#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Trivector.hpp"
#include "Vector.hpp"
#include "Antitrivector.hpp"
#include "Antivector.hpp"
#include "Antibivector.hpp"
#include "Bivector.hpp"


namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_antitrivector::GCA_antitrivector() : 
		GCA_trivector() {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_antitrivector::GCA_antitrivector(double a, double b, double c, double d) : 
		GCA_trivector(a, b, c, d) {

		(*this).setBases();

		(*this).set(e123, a);
		(*this).set(e124, b);
		(*this).set(e134, c);
		(*this).set(e234, d);
	}

	// Constructeur par copie
	GCA_antitrivector::GCA_antitrivector(const GCA_antitrivector& other) :
		GCA_trivector(other) {
	}

	/*** Base duale **/
	GCA_antitrivector operator~(const GCA_vector& vector) {

                GCA_antitrivector antitrivector;
		antitrivector.setBases();

                antitrivector.set(e123, -vector.get(e4));
		antitrivector.set(e124, vector.get(e3));
		antitrivector.set(e134, -vector.get(e2));
		antitrivector.set(e234, vector.get(e1));

                return antitrivector;
        }

	/*** Anti wedge product ***/
	// Wedge product antivector et antibivector = antitrivector => ~trivector ^ ~bivector = ~vector
	GCA_antitrivector operator&(const GCA_trivector& trivector, const GCA_bivector& bivector) {

                 GCA_antitrivector antitrivector;

		antitrivector.setBases();

		antitrivector.set(e123, (~trivector).get(e3)*(~bivector).get(e12) - (~trivector).get(e2)*(~bivector).get(e13) + (~trivector).get(e1)*(~bivector).get(e23)); 
		antitrivector.set(e124, (~trivector).get(e4)*(~bivector).get(e12) - (~trivector).get(e2)*(~bivector).get(e14) + (~trivector).get(e1)*(~bivector).get(e24)); 
		antitrivector.set(e134, (~trivector).get(e4)*(~bivector).get(e13) - (~trivector).get(e3)*(~bivector).get(e14) + (~trivector).get(e1)*(~bivector).get(e34)); 
		antitrivector.set(e234, (~trivector).get(e4)*(~bivector).get(e23) - (~trivector).get(e3)*(~bivector).get(e24) + (~trivector).get(e2)*(~bivector).get(e34)); 

		return antitrivector;
        }

	// Wedge product antivector et antibivector = antitrivector => ~bivector ^ ~trivector = ~vector
	GCA_antitrivector operator&(const GCA_bivector& bivector, const GCA_trivector& trivector) {

                 GCA_antitrivector antitrivector;

		antitrivector.setBases();

		antitrivector.set(e123, -(~trivector).get(e3)*(~bivector).get(e12) + (~trivector).get(e2)*(~bivector).get(e13) - (~trivector).get(e1)*(~bivector).get(e23)); 
		antitrivector.set(e124, -(~trivector).get(e4)*(~bivector).get(e12) + (~trivector).get(e2)*(~bivector).get(e14) - (~trivector).get(e1)*(~bivector).get(e24)); 
		antitrivector.set(e134, -(~trivector).get(e4)*(~bivector).get(e13) + (~trivector).get(e3)*(~bivector).get(e14) - (~trivector).get(e1)*(~bivector).get(e34)); 
		antitrivector.set(e234, -(~trivector).get(e4)*(~bivector).get(e23) + (~trivector).get(e3)*(~bivector).get(e24) - (~trivector).get(e2)*(~bivector).get(e34)); 

		return antitrivector;
        }
	
}
