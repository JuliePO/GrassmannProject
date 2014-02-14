#include <iostream>
#include <Eigen/Dense>

#include "grassmannCayley.hpp"

int main(void) {
	/*gca::GCA_vector vector(-1.0, -3.0, 2.0, 1.0);
	gca::GCA_vector vector2(1.0, 2.0, 3.0, 1.0);
	
	gca::GCA_antiscalar s(2.0);
	gca::GCA_antiscalar s2(s);

	s2.set(e, 3.0);

	gca::GCA_vector vect;
	gca::GCA_vector vect2(vector2);

	vector - vector2;
	std::cout << vector << std::endl; 

	gca::GCA_scalar res;
	res.set(e1, vect.transpose()*vect);

	std::cout << res << std::endl;

	vect.set(e2, 3.0);

	vector2 += vector;

	vect2(2) = 1.0;
	//std::cout << vect.get(e1) << std::endl;

	//vector2(2) = vector(1) * vector2(1);
	

	//gca::GCA_trivector trivector;
	//gca::GCA_trivector trivector3(trivector);

	gca::GCA_bivector l = vector2^vector;
	//gca::GCA_trivector p1 = vector2^vector^vector;
	//gca::GCA_trivector p = l^vector2;
	
	//trivector(2) = 3.0;
	
	//Eigen::Vector4d vect = Eigen::Vector4d::Zero();
	//gca::GCA_vector vector3(vector2);
	
	std::cout << s << std::endl << std::endl;
	//vector2 - vect;
	std::cout << s2 << std::endl;

	gca::GCA_vector a;
	a << 1.0, 2.0, 3.0, 1.0;
	std::cout << a.get(e1) << std::endl << std::endl;

	std::cout << a << std::endl << std::endl;*/


	gca::GCA_vector a(1.0, 2.0, 3.0, 1.0);
	gca::GCA_vector b;
	b << -1.0, -3.0, 2.0, 1.0; 

	gca::GCA_bivector l = a^b;
	std::cout << "l : " << l << std::endl;

	gca::GCA_vector x1(2.0, -1.0, -1.0, 1.0);
	gca::GCA_vector x2(1.0, -1.0, 1.0, 1.0);
	gca::GCA_vector x3(-1.0, -1.0, -2.0, 1.0);
	gca::GCA_trivector d = x1^x2^x3;

	std::cout << "intersection : "  << (~d^~l) << std::endl;
	
}
