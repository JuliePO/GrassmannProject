#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Bivector.hpp"
#include "Antibivector.hpp"
#include "Trivector.hpp"
#include "Antivector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_antibivector::GCA_antibivector() : 
		GCA_bivector() {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_antibivector::GCA_antibivector(double a, double b, double c, double d, double e, double f) : 
		GCA_bivector(a, b, c, d, e, f) {

		(*this).setBases();

		(*this).set(e12, a);
		(*this).set(e13, b);
		(*this).set(e14, c);
		(*this).set(e23, d);
		(*this).set(e24, c);
		(*this).set(e34, d);
	}

	// Constructeur par copie
	GCA_antibivector::GCA_antibivector(const GCA_antibivector& other) :
		GCA_bivector(other) {
	}

	/*** Base duale **/
	GCA_antibivector operator~(const GCA_bivector& bivector) {
	
		std::cout << "entrer " << std::endl;

                GCA_antibivector antibivector;
		antibivector.setBases();

                antibivector.set(e12, bivector.get(e34));
		antibivector.set(e13, -bivector.get(e24));
		antibivector.set(e14, bivector.get(e23));
		antibivector.set(e23, bivector.get(e14));
		antibivector.set(e24, -bivector.get(e13));
		antibivector.set(e34, bivector.get(e12));

                return antibivector;
        }

	/*** Anti wedge product **/
	// Wedge product 2 antivector = antibivector => ~trivector ^ ~trivector = ~bivector
	GCA_antibivector operator&(const GCA_trivector& trivector, const GCA_trivector& other) {

                GCA_antibivector antibivector;

		antibivector.setBases();

               	antibivector.set(e12, (~trivector).get(e1)*(~other).get(e2) - (~trivector).get(e2)*(~other).get(e1)); 
		antibivector.set(e13, (~trivector).get(e1)*(~other).get(e3) - (~trivector).get(e3)*(~other).get(e1)); 
		antibivector.set(e14, (~trivector).get(e1)*(~other).get(e4) - (~trivector).get(e4)*(~other).get(e1));
		antibivector.set(e23, (~trivector).get(e2)*(~other).get(e3) - (~trivector).get(e3)*(~other).get(e2)); 
		antibivector.set(e24, (~trivector).get(e2)*(~other).get(e4) - (~trivector).get(e4)*(~other).get(e2));
		antibivector.set(e34, (~trivector).get(e3)*(~other).get(e4) - (~trivector).get(e4)*(~other).get(e3)); 

                return antibivector;
        }
	
}
