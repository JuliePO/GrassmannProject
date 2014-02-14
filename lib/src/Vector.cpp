#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Quadvector.hpp"
#include "Trivector.hpp"
#include "Bivector.hpp"
#include "Vector.hpp"

namespace gca {

	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_vector::GCA_vector() : 
		GCA_kBlade(4) {
		(*this).setBases();
	}
	//Constructeur à partir de 4 doubles
	GCA_vector::GCA_vector(const double x, const double y, const double z, const double w) : 
		GCA_kBlade(4) {

		(*this).setBases();

		(*this).set(e1, x);
		(*this).set(e2, y);
		(*this).set(e3, z);
		(*this).set(e4, w);
	}
	
	// Constructeur par copie
	GCA_vector::GCA_vector(const GCA_vector& other) :
		GCA_kBlade(other) {
	}

	//Initialiser les bases
	void GCA_vector::setBases() {

		bases.push_back(e1);
		bases.push_back(e2);
		bases.push_back(e3);
		bases.push_back(e4);
	}


	/*** Surcharge d'opérateur ***/
	
	/*** Wedge product ***/

	// Wedge product 2 vectors = bivector
	GCA_bivector operator^(const GCA_vector& vector, const GCA_vector& other) {

                GCA_bivector bivector;

		bivector.setBases();

               	bivector.set(e12, vector.get(e1)*other.get(e2) - vector.get(e2)*other.get(e1)); 
		bivector.set(e13, vector.get(e1)*other.get(e3) - vector.get(e3)*other.get(e1)); 
		bivector.set(e14, vector.get(e1)*other.get(e4) - vector.get(e4)*other.get(e1));
		bivector.set(e23, vector.get(e2)*other.get(e3) - vector.get(e3)*other.get(e2)); 
		bivector.set(e24, vector.get(e2)*other.get(e4) - vector.get(e4)*other.get(e2));
		bivector.set(e34, vector.get(e3)*other.get(e4) - vector.get(e4)*other.get(e3)); 

                return bivector;
        }

	// Webge product vector and bivector = trivector
	 GCA_trivector operator^(const GCA_vector& vector, const GCA_bivector& bivector) { 

	        GCA_trivector trivector;

		trivector.setBases();

		trivector.set(e123, vector.get(e3)*bivector.get(e12) - vector.get(e2)*bivector.get(e13) + vector.get(e1)*bivector.get(e23)); 
		trivector.set(e124, vector.get(e4)*bivector.get(e12) - vector.get(e2)*bivector.get(e14) + vector.get(e1)*bivector.get(e24)); 
		trivector.set(e134, vector.get(e4)*bivector.get(e13) - vector.get(e3)*bivector.get(e14) + vector.get(e1)*bivector.get(e34)); 
		trivector.set(e234, vector.get(e4)*bivector.get(e23) - vector.get(e3)*bivector.get(e24) + vector.get(e2)*bivector.get(e34)); 

	        return trivector;
	}
	
	// Webge product bivector and vector = trivector
	GCA_trivector operator^(const GCA_bivector& bivector, const GCA_vector& vector){ 

	        GCA_trivector trivector;

		trivector.setBases();

		trivector.set(e123, -vector.get(e3)*bivector.get(e12) + vector.get(e2)*bivector.get(e13) - vector.get(e1)*bivector.get(e23)); 
		trivector.set(e124, -vector.get(e4)*bivector.get(e12) + vector.get(e2)*bivector.get(e14) - vector.get(e1)*bivector.get(e24)); 
		trivector.set(e134, -vector.get(e4)*bivector.get(e13) + vector.get(e3)*bivector.get(e14) - vector.get(e1)*bivector.get(e34)); 
		trivector.set(e234, -vector.get(e4)*bivector.get(e23) + vector.get(e3)*bivector.get(e24) - vector.get(e2)*bivector.get(e34)); 
	
	        return trivector;
	}

	// Wedge product vector and trivector = quadvector
	GCA_quadvector operator^(const GCA_vector& vector, const GCA_trivector& trivector) {
		
		GCA_quadvector quadvector;
		quadvector.setBases();

		quadvector.set(e1234, trivector.get(e123)*vector.get(e4) - trivector.get(e124)*vector.get(e3) + trivector.get(e134)*vector.get(e2) - trivector.get(e234)*vector.get(e1));
	      
	        return quadvector;
	}

	// Wedge product trivector and vector = quadvector
	GCA_quadvector operator^(const GCA_trivector& trivector, const GCA_vector& vector) {

		GCA_quadvector quadvector;
		quadvector.setBases();

	       	quadvector.set(e1234, trivector.get(e123)*vector.get(e4) + trivector.get(e124)*vector.get(e3) - trivector.get(e134)*vector.get(e2) + trivector.get(e234)*vector.get(e1));
		
	        return quadvector;
	}

}
