#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Scalar.hpp"
#include "Antiscalar.hpp"
#include "Quadvector.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_antiscalar::GCA_antiscalar() : 
		GCA_scalar() {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_antiscalar::GCA_antiscalar(double a) : 
		GCA_scalar(a) {
		(*this).setBases();
		(*this).set(e, a);
	}

	// Constructeur par copie
	GCA_antiscalar::GCA_antiscalar(const GCA_antiscalar& other) :
		GCA_scalar(other) {
	}

	/*** Base duale **/
	GCA_antiscalar operator~(const GCA_quadvector& quadvector) {

                GCA_antiscalar antiscalar;
		antiscalar.setBases();

                antiscalar.set(e, quadvector.get(e1234));

                return antiscalar;
        }
	
}
