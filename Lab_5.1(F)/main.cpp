#include <iostream>
#include <iomanip>

#include "Triangle.h"
#include "Triangle_Public.h"
#include "Triangle_Private.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"

int main(void) {
	using std::cout;

	std::cout << "\n\n////////////////////////////////////////////////////////////11111111\n";

	//визначається власний виняток
	try {	//захищений(контрольований) блок
		Triangle_Public A(4, 2, 3);

		cout << "\n\nDisplay first object --- Triangle_Public: ";
		cout << A;

		cout << "\n\nAdding object numbers is : " << A.Addition();

		cout << "\n\nLetter string conversion method: ";
		cout << A.operator std::string();

		cout << "\n\nThe area of the triangle is: " << A.Calcul_Square();

		angle alpha, beta, sigma;
		cout << "\n\nThe angles of the triangle are: ";

		A.Calcul_Angles(alpha, beta, sigma, A.Calcul_Square());
		cout << "\n\nThe first angle of the triangle is: " << std::setprecision(3) << alpha;
		cout << "\nThe second angle of the triangle is: " << std::setprecision(3) << beta;
		cout << "\nThe third angle of the triangle is: " << std::setprecision(3) << sigma;
	}
	catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
		std::cout << a->What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////2222222\n";

	//використання стандартного винятка
	try { //захищений(контрольований) блок
		Triangle_Public B;
		cout << "\n\nThe first object --- Triangle_Private: ";
		std::cin >> B;

		cout << "\n\nDisplay first object --- Triangle_Private: ";
		cout << B;

		cout << "\n\nAdding object numbers is : " << B.Addition();

		cout << "\n\nLetter string conversion method: ";
		cout << B.operator std::string();

		cout << "\n\nThe area of the triangle is: " << B.Calcul_Square();

		cout << "\n\nThe angles of the triangle are: ";

		angle alpha, beta, sigma;
		B.Calcul_Angles(alpha, beta, sigma, B.Calcul_Square());
		cout << "\n\nThe first angle of the triangle is: " << std::setprecision(3) << alpha;
		cout << "\nThe second angle of the triangle is: " << std::setprecision(3) << beta;
		cout << "\nThe third angle of the triangle is: " << std::setprecision(3) << sigma;
	}
	catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
		std::cout << obj_1.what();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////3333333\n";

	//використання винятків - нащадки від стандартних винятків;
	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nVvedit size masuva: ";  std::cin >> size;

		if ((size < 2) || (size > 80'000'000))
			throw Me_Error_size_memorry("!!!Incorrectly allocated memory!!!");		//генерування об'єкта винятка
		Triangle* masuv = new Triangle[size];
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}