GrassmannProject
================
/************ LIBRAIRIE ALGEBRE DE GRASSMANN CAYLEY *****************/

Bonjour, nous vous remercions d'utiliser la librairie grasmmann.

/--------- Préinstallation ---------/

1 - Créer un répertoire qui accueillera le programme

	exemple vous pouvez taper dans votre terminal :

		$ mkdir Grassmann
		(pour créer un dossier "Grassmann")

2 - Déplacer le .tgz ou .zip dans le dossier

		$ mv GuerreroPo.tgz ~/projetC

3 - Placer vous dans le dossier et décompresser l'archive

		$ cd ~/Grassmann
		$ tar -xzvf GuerreroPo.tgz

/--------- Les consignes avant utilisation ---------/

Pour utiliser ce programme vous aurez besoin d'intaller le package GLUT / OpenGL

1 - Pour installer le package GLUT, si vous vous trouvez sur Ubuntu, allez sur votre terminal et taper :

		$ sudo apt-get install freeglut3 freeglut3-dev

	Si vous possedez une version d'Ubuntu inférieur à la version 11.10 alors taper également la ligne ci-dessous :

		$ sudo apt-get install binutils-gold

	Si vous êtes sur Fedora, allez sur votre terminal est taper :

		sudo yum install freeglut-devel

/--------- Installation du programme ---------/
Pour installer la libraire suivez les consignes suivantes :

1 - Allez dans le dossier build du dossier où se trouve le programme :

		$ cd GrassmannProject/build

2 - Ecrivez la ligne suivante dans votre terminal 

		$ cmake ..

2 - Ecrivez la ligne suivante dans votre terminal pour compiler le programme

		$ make

3 - Lancer le programme :

		$ ./Grassmann/Grassmann
		

/--------- Utilisation ---------/

Pour récupérer la composante d'un k-blade en fonction d'une base :

	Par exemple pour récupérer la composante associé à la base e1 d'un vecteur 

		vector.get(e1);

Pour modifier la composante d'un k-blade en fonction d'une base :

	Par exemple pour modifier la composante associé à la base e1 d'un vecteur

		vector.set(e1, 2);

Pour faire un wedge product utiliser l'opérateur ^ :
	
	Par exemple pour le wedge product de deux vecteur qu'on stock dans un bivecteur :

		gca::GCA_bivector b = vector1 ^ vector2;

Pour afficher un wedge product sans l'avoir stocker dans un k-blade :

		std::cout << (vector1 ^ vector2) << std::endl; 

	car l'opérateur "<<" est prioritaire sur l'opérateur ^.

De même pour la base duale avec l'opérateur "~", et l'antiwedge product "&".


/********************************************************************************/
*      Projet réaliser par Gaétan GUERRERO et Julie PO				*
*				IMAC 2 - 2013/2014				*
/********************************************************************************/


