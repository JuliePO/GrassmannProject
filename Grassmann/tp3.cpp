#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <ctime>
#include <cstdlib>

Eigen::VectorXf pivotGauss ( Eigen::MatrixXf A, Eigen::VectorXf b) {
	
	/*if(A.rows() != b.size()) {
		std::cout << "Les deux matrice n'ont pas la même taille \n" << std::endl;
		exit(0);
	}

	Eigen::VectorXf result = Eigen::VectorXf::Zero(A.rows());

	int taille = b.size();
	int k = 1;
	float lambda = 0.0;

	for(int i=0; i < (taille-1); ++i) {
		
		for(int j=0; j < k; ++j) {

			lambda = -(A(k, j)) / A(i,j);		
			A.row(k) -= lambda*A.row(i);
			b(k) -= - lambda*b(i);
		}
		++k;
	}

	return 0;*/

	assert(b.size() == A.rows() && "Erreur, les deux n'ont pas la même taille\n");	

	float coef = 0.0;
		
	for(int pivot = 0; pivot < A.rows()-1; ++pivot) {

		//assert(

		for(int i = pivot + 1; i < A.rows(); ++i) {

			coef = A(i, pivot) / A(pivot, pivot);
			A.row(i) -= coef*A.row(pivot);
			b(i) -= coef*b(pivot);
	
		}

	}

	//std::cout << A << std::endl;

	Eigen::VectorXf x = Eigen::VectorXf::Zero(A.cols());
	
	for(int i = A.rows()-1; i >= 0; --i) {
		
		float sum = 0.0;

		for(int j=i+1; j < A.rows(); ++j) {

			sum += A(i,j)*x(j);
			
			
		}

		x(i) = (b(i) - sum)/A(i,i);

	}

	return x;
}

Eigen::VectorXf pivotGaussPartiel ( Eigen::MatrixXf A, Eigen::VectorXf b) {
	

	assert(b.size() == A.rows() && "Erreur, les deux n'ont pas la même taille\n");	

	float coef = 0.0;
	for(int pivot = 0; pivot < A.rows()-1; ++pivot) {


		//recherche meilleur pivot

		for(int j = pivot + 1; j < A.rows(); ++j) {	

			if(fabs(A(j, pivot)) > fabs(A(pivot, pivot))) {

				A.row(j).swap(A.row(pivot));
				std::swap(b(pivot), b(j));
	
			}

		}	

		for(int i = pivot + 1; i < A.rows(); ++i) {

			coef = A(i, pivot) / A(pivot, pivot);
			A.row(i) -= coef*A.row(pivot);
			b(i) -= coef*b(pivot);
		}

		

	}

	//std::cout << A << std::endl;

	Eigen::VectorXf x = Eigen::VectorXf::Zero(A.cols());
	
	for(int i = A.rows()-1; i >= 0; --i) {
		
		float sum = 0.0;

		for(int j=i+1; j < A.rows(); ++j) {

			sum += A(i,j)*x(j);
			
			
		}

		x(i) = (b(i) - sum)/A(i,i);

	}	


	return x;
}


int main() {

	srand(time(0));

	//Eigen::Matrix3f A;
	//A << 2, 5, 1, 2, 9, 3, 6, 23, 5;

	//Eigen::MatrixXf A = Eigen::MatrixXf::Random(50, 50);
	//Eigen::VectorXf b = Eigen::VectorXf::Random(50);

	//Eigen::Vector3f b(7, -1, 17);

	//Eigen::Matrix2f A;
	//A << 1.0e-8, 1, 1, 1;

	//Eigen::Vector2f b(1, 2);

	Eigen::Matrix4f A;
	A << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;


	Eigen::Matrix4f P;
	P << 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1;

	std::cout << A << std::endl << std::endl;
	std::cout << A*P << std::endl << std::endl;
	
	//std::cout << "A\n" << A << std::endl;
	/*std::cout << "b : " << b.transpose() << std::endl;
	std::cout << "x : " << (A.partialPivLu().solve(b)).transpose() << std::endl;*/

	//std::cout << A(1, 2) << std::endl;

	/*Eigen::VectorXf res = pivotGauss(A, b);
	std::cout << "\nPivot de Gauss : " << (A*res-b).norm() << std::endl;
	std::cout << "resultat :\n" << res << std::endl << std::endl;

	res = pivotGaussPartiel(A, b);
	std::cout << "Pivot de Gauss partiel : " << (A*res-b).norm() << std::endl << std::endl;
	std::cout << "resultat :\n" << res << std::endl << std::endl;*/


}
