#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Scalar.hpp"
#include "Quadvector.hpp"

namespace gca {

	class GCA_antiscalar : public GCA_scalar {
		
		public :
		
		/*** Constructeur ***/
		GCA_antiscalar();//Constructeur par défaut
		GCA_antiscalar(double a); //Constructor with a double

		GCA_antiscalar(const GCA_antiscalar& other); // Constructeur par copie

		/*** Base duale **/
		friend GCA_antiscalar operator~(const GCA_quadvector& quadvector);

	};

	GCA_antiscalar operator~(const GCA_quadvector& quadvector);
}
