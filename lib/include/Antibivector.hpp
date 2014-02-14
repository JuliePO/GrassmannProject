#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Bivector.hpp"
#include "Trivector.hpp"
#include "Antivector.hpp"

namespace gca {

	class GCA_antibivector : public GCA_bivector {
		
		public :
		
		/*** Constructeur ***/
		GCA_antibivector();//Constructeur par défaut
		GCA_antibivector(double a, double b, double c, double d, double e, double f); //Constructor with a double

		GCA_antibivector(const GCA_antibivector& other); // Constructeur par copie

		/*** Base duale **/
		friend GCA_antibivector operator~(const GCA_bivector& bivector);

		/*** Anti wedge product ***/
		friend GCA_antibivector operator&(const GCA_trivector& trivector, const GCA_trivector& other);

	};

	GCA_antibivector operator~(const GCA_bivector& bivector);
	GCA_antibivector operator&(const GCA_trivector& trivector, const GCA_trivector& other);
}
