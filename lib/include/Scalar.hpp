#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"

namespace gca {

	class GCA_scalar : public GCA_kBlade {
		
		public :
		
		/*** Constructeur ***/
		GCA_scalar();//Constructeur par défaut
		GCA_scalar(double a); //Constructor with a double

		GCA_scalar(const GCA_scalar& other); // Constructeur par copie

		void setBases();

		/*** Surcharge d'opérateur ***/
		//Opérateur *
		GCA_scalar operator*(const GCA_scalar& other) const;
		/*GCA_kblade::GCA_kblade operator*(const GCA_kblade::GCA_kBlade& other) const;
		friend GCA_kblade::GCA_kblade operator*(const GCA_kblade::GCA_kBlade& kblade, const GCA_scalar& scalar) const;
		friend GCA_kblade::GCA_scalar operator*(const GCA_kblade::GCA_kBlade& kblade, const GCA_kblade::GCA_kBlade& other) const;*/

		//Opérateur *=
		GCA_scalar operator*=(const GCA_scalar& other);
		/*GCA_kblade operator*=(GCA_kBlade& other);
		friend GCA_kblade operator*=(GCA_kBlade& kblade, const GCA_scalar& scalar);*/

		//Opérateur /
		GCA_scalar operator/(const GCA_scalar& other) const;
		/*GCA_kblade operator/(const GCA_kBlade& other) const;
		friend GCA_kblade operator/(const GCA_kBlade& kblade, const GCA_scalar& scalar) const;
		friend GCA_scalar operator/(const GCA_kBlade& kblade, const GCA_kBlade& other) const;*/

		//Opérateur /=
		GCA_scalar operator/=(const GCA_scalar& other);
		
		
	};

	//Opérateur *
	/*GCA_kblade operator*(const GCA_kBlade& kblade, const GCA_scalar& scalar) const;
	GCA_scalar operator*(const GCA_kBlade& kblade, const GCA_kBlade& other) const;

	//Opérateur *=
	GCA_kblade operator*=(GCA_kBlade& kblade, const GCA_scalar& scalar);

	//Opérateur /
	GCA_kblade operator/(const GCA_kBlade& kblade, const GCA_scalar& scalar) const;
	GCA_scalar operator/(const GCA_kBlade& kblade, const GCA_kBlade& other) const;

	//Opérateur /=
	GCA_kblade operator/=(GCA_kBlade& kblade, const GCA_scalar& scalar);*/
}
