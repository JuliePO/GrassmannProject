#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Bivector.hpp"
#include "Trivector.hpp"
#include "Quadvector.hpp"

namespace gca {

	class GCA_vector : public GCA_kBlade {

		public :

		/*** Constructeur ***/
		GCA_vector();//Constructeur par défaut
		GCA_vector(const double x, const double y, const double z, const double w); //Constructeur à partir de 4 doubles

		GCA_vector(const GCA_vector& other); // Constructeur par copie
		
		void setBases(); //Initialiser les bases
 
		/*** Surharge d'opérateur ***/

		/*** Wedge product ***/
		friend GCA_bivector operator^(const GCA_vector& vector, const GCA_vector& other); // Wedge product 2 vectors = bivector
		friend GCA_trivector operator^(const GCA_vector& vector, const GCA_bivector& bivector); // Webge product vector and bivector = trivector
		friend GCA_trivector operator^(const GCA_bivector& bivector, const GCA_vector& vector); // Webge product bivector and vector = trivector
		friend GCA_quadvector operator^(const GCA_vector& vector, const GCA_trivector& trivector); // Wedge product vector and trivector = quadvector
		friend GCA_quadvector operator^(const GCA_trivector& trivector, const GCA_vector& vector);

		

	};
	
	//void operator<<(GCA_vector& vector, double x, double y, double z, double w);

	GCA_bivector operator^(const GCA_vector& vector, const GCA_vector& other); 

	GCA_trivector operator^(const GCA_vector& vector, const GCA_bivector& bivector);
	GCA_trivector operator^(const GCA_bivector& bivector, const GCA_vector& vector);

	GCA_quadvector operator^(const GCA_vector& vector, const GCA_trivector& trivector);
	GCA_quadvector operator^(const GCA_trivector& trivector, const GCA_vector& vector);

}
