#include <iostream>

template <typename T>
struct vector{
	int N; //количество строк
	T* vectorElements;
	vector(int N){
		this->N = N;
		this->vectorElements = new T[this->N];
	}
	~vector(){
		delete[] this->vectorElements;	
	}
	T* operator[](int index){
		return &(this->vectorElements[index]);
	}
	void printVector(){
		for(int i = 0;i<this->N;i++){
			std::cout<<this->vectorElements[i]<<"  ";
		}
	}
	T operator*(const vector& multVector){
		T result = 0;
		for(int i = 0;i<this->N;i++){
			result+=this->vectorElements[i]*multVector.vectorElements[i];
		}
		return result;
	}
};




int main()
{
	vector<int> v1(3);
	vector<int> v2(3);
	*v1[0] = 10;
	*v1[2] = 20;
	*v1[1] = 2;
	std::cout<<std::endl<<"Vector 1"<<std::endl;
	v1.printVector();
	*v2[0] = 3;
	*v2[1] = 4;
	*v2[2] = 10;
	std::cout<<std::endl<<"Vector 2"<<std::endl;
	v2.printVector();
	std::cout<<std::endl<<"Result of dot product:"<<std::endl;
	std::cout<<v1*v2;
	return 0;
}
