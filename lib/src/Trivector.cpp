#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Trivector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_trivector::GCA_trivector() : 
		GCA_kBlade(4) {
		(*this).setBases();
	}

	//Constructor with 4 doubles
	GCA_trivector::GCA_trivector(double a, double b, double c, double d) : 
		GCA_kBlade(6) {

		(*this).setBases();

		(*this).set(e123, a);
		(*this).set(e124, b);
		(*this).set(e134, c);
		(*this).set(e234, d);
	}

	// Constructeur par copie
	GCA_trivector::GCA_trivector(const GCA_trivector& other) :
		GCA_kBlade(other) {
	}

	//Initialiser les bases
	void GCA_trivector::setBases() {

		bases.push_back(e123);
		bases.push_back(e124);
		bases.push_back(e134);
		bases.push_back(e234);
	}


}
