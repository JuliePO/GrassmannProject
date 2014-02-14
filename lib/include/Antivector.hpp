#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Trivector.hpp"
#include "Vector.hpp"

namespace gca {

	class GCA_antivector : public GCA_vector {
		
		public :
		
		/*** Constructeur ***/
		GCA_antivector();//Constructeur par défaut
		GCA_antivector(double x, double y, double z, double w); //Constructor with a double

		GCA_antivector(const GCA_antivector& other); // Constructeur par copie

		/*** Base duale **/
		friend GCA_antivector operator~(const GCA_trivector& trivector);

	};

	GCA_antivector operator~(const GCA_trivector& trivector);
}
