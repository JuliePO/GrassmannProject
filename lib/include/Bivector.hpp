#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"

namespace gca {

	class GCA_bivector : public GCA_kBlade { 
	
		public :
		
		/*** Constructeur ***/
		GCA_bivector();//Constructeur par défaut
		GCA_bivector(double a, double b, double c, double d, double e, double f); //constructeur à partir de 6 doubles

		GCA_bivector(const GCA_bivector& other); // Constructeur par copie

		void setBases(); //Initialiser les bases

	};
}
