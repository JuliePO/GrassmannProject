#pragma once
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"

namespace gca {

	class GCA_kBlade : public Eigen::VectorXd {

		public :

		/*** Values of the class kBlade ***/
		std::vector<BaseE> bases; // array of bases

		/*** Constructeur ***/
		GCA_kBlade(void):Eigen::VectorXd() {} //Constructeur par défaut

		typedef Eigen::VectorXd Base;

		GCA_kBlade(const int nb); //Constructeur à partir d'une taille

		
		GCA_kBlade(const GCA_kBlade& other);//Constructeur par copie

		/*** Surcharge d'opérateur **/
		

		/*** Getter & setter ***/

		double get(BaseE e) const; //Get a value of the vector when we know the base
		void set(BaseE e, double value); //Set a value of the vector when we know the base

		/*** Eigen inheritance ***/

		// This constructor allows you to construct MyVectorType from Eigen expressions
		template<typename OtherDerived>
		GCA_kBlade(const Eigen::MatrixBase<OtherDerived>& other)
			: Eigen::VectorXd(other)
		{ }

		// This method allows you to assign Eigen expressions to MyVectorType
		template<typename OtherDerived>
		GCA_kBlade & operator= (const Eigen::MatrixBase <OtherDerived>& other) {
			this->Base::operator=(other);
			return *this;
		}

	};
}


