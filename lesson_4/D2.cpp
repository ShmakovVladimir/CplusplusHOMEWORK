#include <iostream>
#include <math.h>

struct ComplexNumber{
	ComplexNumber(float a,float b = 0)
	{
		init_data(a,b);
	}
	void init_data(float a,float b)
	{
		this->a = a;
		this->b = b;
	}
	void printNumber() const
	{
		std::cout<<std::endl<<a<<" + "<<b<<"*i";
	}
	friend ComplexNumber operator+(const ComplexNumber& number1, const ComplexNumber& number2)
	{
		return ComplexNumber{number1.a+number2.a,number1.b+number2.b};
	}
	ComplexNumber operator+(const float numberToAdd) const
	{
		return ComplexNumber{a+numberToAdd,b};
	}
	float getAbsValue() const
	{
		return sqrt(pow(a,2)+pow(b,2));
	}
	ComplexNumber getMirror() const
	{
		return ComplexNumber{a,-b};
	}
	float a;
	float b;
};

int main()
{
	ComplexNumber alpha = {5,2};
	ComplexNumber betta = {3,4};
	int gamma = 5;
	std::cout<<"First complex number(alpha) is:";
	alpha.printNumber();
	std::cout<<std::endl<<"Second complex number(betta) is:";
	betta.printNumber();
	std::cout<<std::endl<<"Result of alpha+betta: ";
	(alpha+betta).printNumber();
	std::cout<<std::endl<<"Non-complex number gamma is: "<<std::endl<<gamma;
	std::cout<<std::endl<<"Result of alpha+gamma: ";
	(alpha+gamma).printNumber();
	std::cout<<std::endl<<"alpha absolute value is: "<<std::endl<<alpha.getAbsValue();
	std::cout<<std::endl<<"betta mirrored complex number is: ";
	betta.getMirror().printNumber();
	return 0;
}
