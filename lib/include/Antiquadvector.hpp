#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Scalar.hpp"
#include "Quadvector.hpp"
#include "Vector.hpp"
#include "Trivector.hpp"
#include "Antivector.hpp"
#include "Antitrivector.hpp"

namespace gca {

	class GCA_antiquadvector : public GCA_quadvector {
		
		public :
		
		/*** Constructeur ***/
		GCA_antiquadvector();//Constructeur par défaut
		GCA_antiquadvector(double a); //Constructor with a double

		GCA_antiquadvector(const GCA_antiquadvector& other); // Constructeur par copie

		/*** Base duale **/
		friend GCA_antiquadvector operator~(const GCA_scalar& scalar);

		/*** Anti wedge product ***/
		friend GCA_antiquadvector operator&(const GCA_trivector& trivector, const GCA_vector& vector); // Wedge product vector and trivector = quadvector
		friend GCA_antiquadvector operator&(const GCA_vector& vector, const GCA_trivector& trivector);

	};

	GCA_antiquadvector operator~(const GCA_scalar& scalar);

	GCA_antiquadvector operator&(const GCA_trivector& trivector, const GCA_vector& vector);
	GCA_antiquadvector operator&(const GCA_vector& vector, const GCA_trivector& trivector);

	
}
