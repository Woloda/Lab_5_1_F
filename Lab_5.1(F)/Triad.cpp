#include <stdexcept>
#include <iostream>
#include <string>

#include "My_Error_Range.h"
#include "Triad.h"


Triad::Triad() { x = 3; y = 4; z = 5; }   //конструктор за умовчанням(без параметрів)

Triad::Triad(const number v_x, const number v_y, const number v_z) throw(My_Error_Range) {  //конструктор ініціалізації
	if ((v_z > (v_x + v_y)) || (v_x > (v_z + v_y)) || (v_y > (v_x + v_z)))
		throw new My_Error_Range("\n\n!!!Incorrectly entered data!!!");		//генерування об'єкта винятка

	x = v_x;
	y = v_y;
	z = v_z;
}

Triad::Triad(const Triad& obj) {   //конструктор копіювання
	x = obj.x;
	y = obj.y;
	z = obj.z;
}

std::ostream& operator << (std::ostream& out, Triad& obj) {   //операції виводу
	out << "\n\nEnter the number x: " << obj.x;
	out << "\nEnter the number y: " << obj.y;
	out << "\nEnter the number z: " << obj.z;

	return out;
}

std::istream& operator >> (std::istream& in, Triad& obj) throw(std::out_of_range) {    //операції вводу
	number a, b, c;

	std::cout << "\n\nEnter the side: ";
	std::cout << "\n\nEnter the number x: "; in >> a;
	std::cout << "Enter the number y: ";     in >> b;
	std::cout << "Enter the number z: ";     in >> c;

	/*Використання стандартного винятка
	Успадкований від std :: logic_error.
	Визначає виняток, яке повинно бути кинуто в тому випадку,
	коли відбувається вихід за межі допустимого діапазону значень об'єкта*/
	if ((c > (a + b)) || (a > (c + b)) || (b > (a + c)))
		throw std::out_of_range{ "\n\n!!!Data entered incorrectly!!!" };	//генерування об'єкта винятка

	obj.Set_x(a);
	obj.Set_y(b);	
	obj.Set_z(c);
	return in;
}

Triad& Triad::operator =(const Triad& obj) {   //перевантаження операції "присвоєння"
	x = obj.x;
	y = obj.y;
	z = obj.z;

	return *this;
}

Triad::operator std::string() const {   //перетворення до літерного рядку --- "операції приведення типу"
	std::string str;
	std::stringstream sout;

	sout << "\n\ncoordinate x: " << x;
	sout << "\ncoordinate y: " << y;
	sout << "\ncoordinate z: " << z;

	return sout.str();
}

number Triad::Addition() {   //обчислення суми чисел
	return x + y + z;
}