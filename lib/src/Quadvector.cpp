#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Quadvector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_quadvector::GCA_quadvector() : 
		GCA_kBlade(1) {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_quadvector::GCA_quadvector(double a) : 
		GCA_kBlade(1) {
		(*this).setBases();
		(*this).set(e1234, a);
	}

	// Constructeur par copie
	GCA_quadvector::GCA_quadvector(const GCA_quadvector& other) :
		GCA_kBlade(other) {
	}

	//Initialiser les bases
	void GCA_quadvector::setBases() {
		bases.push_back(e1234);
	}

}
