#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"

namespace gca {

	class GCA_trivector : public GCA_kBlade {
		
		public :
		
		/*** Constructeur ***/
		GCA_trivector();//Constructeur par défaut
		GCA_trivector(double a, double b, double c, double d);  //Constructor with 4 doubles

		GCA_trivector(const GCA_trivector& other); // Constructeur par copie

		void setBases();//Initialiser les bases


	};
}
