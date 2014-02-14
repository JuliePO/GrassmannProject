#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Trivector.hpp"
#include "Vector.hpp"
#include "Antivector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_antivector::GCA_antivector() : 
		GCA_vector() {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_antivector::GCA_antivector(double x, double y, double z, double w) : 
		GCA_vector(x, y, z, w) {

		(*this).setBases();

		(*this).set(e1, x);
		(*this).set(e2, y);
		(*this).set(e3, z);
		(*this).set(e4, w);
	}

	// Constructeur par copie
	GCA_antivector::GCA_antivector(const GCA_antivector& other) :
		GCA_vector(other) {
	}

	/*** Base duale **/
	GCA_antivector operator~(const GCA_trivector& trivector) {

		std::cout << "entrer " << std::endl;

                GCA_antivector antivector;
		antivector.setBases();

                antivector.set(e1, -trivector.get(e234));
		antivector.set(e2, trivector.get(e134));
		antivector.set(e3, -trivector.get(e124));
		antivector.set(e4, trivector.get(e123));

                return antivector;
        }
	
}
