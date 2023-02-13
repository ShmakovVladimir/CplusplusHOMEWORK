#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Vector
{
	public:
		Vector() noexcept;
		Vector(std::size_t len) noexcept(false);
		Vector(std::size_t len, T* el) noexcept(false);
		void push(const T elementToBePushed) noexcept;
		std::size_t getLength() const noexcept;
		friend std::ostream& operator<<(std::ostream& outObj,const Vector<int>& vectorToPrint) noexcept;

		~Vector() noexcept;
	private:
		T* elements;
		std::size_t capasity;
		std::size_t length;
		const int capasityPerLength = 2;
		const int startCapasity = 10;

};
