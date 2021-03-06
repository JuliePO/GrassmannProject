#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Bivector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_bivector::GCA_bivector() : 
		GCA_kBlade(6) {
		(*this).setBases();
	}

	GCA_bivector::GCA_bivector(double a, double b, double c, double d, double e, double f) : 
		GCA_kBlade(6) {

		(*this).setBases();

		(*this).set(e12, a);
		(*this).set(e13, b);
		(*this).set(e14, c);
		(*this).set(e23, d);
		(*this).set(e24, e);
		(*this).set(e34, f);
	}

	// Constructeur par copie
	GCA_bivector::GCA_bivector(const GCA_bivector& other) :
		GCA_kBlade(other) {
	}

	//Initialiser les bases
	void GCA_bivector::setBases() {

		bases.push_back(e12);
		bases.push_back(e13);
		bases.push_back(e14);
		bases.push_back(e23);
		bases.push_back(e24);
		bases.push_back(e34);
	}
	
}
