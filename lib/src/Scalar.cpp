#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "Bases.hpp"
#include "KBlade.hpp"
#include "Scalar.hpp"

namespace gca {
	
	/*** Constructeurs ***/

	//Constructeur par défaut
	GCA_scalar::GCA_scalar() : 
		GCA_kBlade(1) {
		(*this).setBases();
	}
	//Constructor with a double
	GCA_scalar::GCA_scalar(double a) : 
		GCA_kBlade(1) {
		(*this).setBases();
		(*this).set(e, a);
	}

	// Constructeur par copie
	GCA_scalar::GCA_scalar(const GCA_scalar& other) :
		GCA_kBlade(other) {
	}

	void GCA_scalar::setBases() {
		bases.push_back(e);
	}


	/*** Surcharge d'opérateur ***/

	//Opérateur *
	GCA_scalar GCA_scalar::operator*(const GCA_scalar& other) const {
	        GCA_scalar b(*this);

		if(b.bases.size() == other.bases.size()) {
			b.set(e, (b.get(e))*(other.get(e)));                                        
			return b;
		}
		std::cout << "Erreur ce ne sont pas les deux scalaire\n" << std::endl;
		return 0;
	}

	/*GCA_kblade::GCA_kblade GCA_scalar::operator*(const GCA_kblade::GCA_kBlade& other) const {
	        GCA_kBlade b(other);

		for(int i = 0; i < b.bases.size(); ++i) {
		        if(b.bases[i])
				b.set(b.bases[i], ((*this).get(e))*(b.get(b.bases[i])));                                        
		}
		return b;
	}

	GCA_kblade::GCA_kblade operator*(const GCA_kblade::GCA_kBlade& kblade, const GCA_scalar& scalar) const {
	        GCA_kBlade b(kblade);

		for(int i = 0; i < b.bases.size(); ++i) {
		        if(b.bases[i])
				b.set(b.bases[i], (scalar.get(e))*(b.get(b.bases[i])));                                        
		}
		return b;
	}

	GCA_scalar operator*(const GCA_kblade::GCA_kBlade& kblade, const GCA_kblade::GCA_kBlade& other) const {
		GCA_scalar res();
		res.setBases();
		res.set(e, 0.0);

		if(kblade.bases.size() == other.bases.size()) {
			for(int i = 0; i < kblade.bases.size(); ++i) {
			        if(kblade.bases[i] && other.bases[i])
					res.set(e, res.get(e) + (kblade.get(kblade.bases[i]))*(other.get(other.bases[i])));                                        
			}
			return res;
		}
		std::cout << "Erreur ce ne sont pas les deux mêmes K-blade\n" << std::endl;
		return 0;
	}*/

	//Opérateur *=

	GCA_scalar GCA_scalar::operator*=(const GCA_scalar& other) {

		if((*this).bases.size() == other.bases.size()) {
			(*this).set(e, ((*this).get(e))*(other.get(e)));                                        
			return (*this);
		}
		std::cout << "Erreur ce ne sont pas les deux scalaire\n" << std::endl;
		return 0;
	}

	/*GCA_kblade GCA_scalar::operator*=(GCA_kBlade& other) const {

		for(int i = 0; i < other.bases.size(); ++i) {
		        if(other.bases[i])
				other.set(b.bases[i], ((*this).get(e))*(other.get(other.bases[i])));                                        
		}
		return other;
	}

	GCA_kblade operator*=(GCA_kBlade& kblade, const GCA_scalar& scalar) {

		for(int i = 0; i < kblade.bases.size(); ++i) {
		        if(kblade.bases[i])
				kblade.set(kblade.bases[i], (scalar.get(e))*(kblade.get(b.bases[i])));                                        
		}
		return kblade;
	}*/

	//Opérateur /
	GCA_scalar GCA_scalar::operator/(const GCA_scalar& other) const {
	        GCA_scalar b(*this);

		if(b.bases.size() == other.bases.size()) {
			b.set(e, (b.get(e))/(other.get(e)));                                        
			return b;
		}
		std::cout << "Erreur ce ne sont pas les deux scalaire\n" << std::endl;
		return 0;
	}

	/*GCA_kblade GCA_scalar::operator/(const GCA_kBlade& other) const {
	        GCA_kBlade b(other);

		for(int i = 0; i < b.bases.size(); ++i) {
		        if(b.bases[i])
				b.set(b.bases[i], ((*this).get(e))/(b.get(b.bases[i])));                                        
		}
		return b;
	}

	GCA_kblade operator/(const GCA_kBlade& kblade, const GCA_scalar& scalar) const {
	        GCA_kBlade b(kblade);

		for(int i = 0; i < b.bases.size(); ++i) {
		        if(b.bases[i])
				b.set(b.bases[i], (b.get(b.bases[i]))/(scalar.get(e)));                                        
		}
		return b;
	}

	GCA_scalar operator/(const GCA_kBlade& kblade, const GCA_kBlade& other) const {
		GCA_scalar res();
		res.setBases();
		res.set(e, 0.0);

		if(kblade.bases.size() == other.bases.size()) {
			for(int i = 0; i < kblade.bases.size(); ++i) {
			        if(kblade.bases[i] && other.bases[i])
					res.set(e, res.get(e) + (kblade.get(kblade.bases[i]))/(other.get(other.bases[i])));                                        
			}
			return res;
		}
		std::cout << "Erreur ce ne sont pas les deux mêmes K-blade\n" << std::endl;
		return 0;
	}*/

	//Opérateur /=

	GCA_scalar GCA_scalar::operator/=(const GCA_scalar& other) {

		if((*this).bases.size() == other.bases.size()) {
			(*this).set(e, ((*this).get(e))/(other.get(e)));                                        
			return (*this);
		}
		std::cout << "Erreur ce ne sont pas les deux scalaire\n" << std::endl;
		return 0;
	}

	/*GCA_kblade GCA_scalar::operator/=(GCA_kBlade& other) const {

		for(int i = 0; i < other.bases.size(); ++i) {
		        if(other.bases[i])
				other.set(b.bases[i], ((*this).get(e))/(other.get(other.bases[i])));                                        
		}
		return other;
	}

	GCA_kblade operator/=(GCA_kBlade& kblade, const GCA_scalar& scalar) {

		for(int i = 0; i < kblade.bases.size(); ++i) {
		        if(kblade.bases[i])
				kblade.set(kblade.bases[i], (kblade.get(b.bases[i]))/(scalar.get(e)));                                        
		}
		return kblade;
	}*/

	
	
}
