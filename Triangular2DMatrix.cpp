#include <iostream>
#include "Triangular2DMatrix.h"

template<class T>
Triangular2DMatrix<T>::Triangular2DMatrix(size_t size)
{
	this->set_size(size);
}

template<class T>
Triangular2DMatrix<T>::~Triangular2DMatrix() {
	free(this->m_);
}

template<class T>
inline void Triangular2DMatrix<T>::set_size(size_t s) {
	if(s < 1)
		throw -1;

	if(this->osize != -1)
		free(this->m_);

	this->osize = s;
	this->size = (s*s)/2 + s;

	if(this->size % 16 != 0)
		this->size += 16 - this->size % 16;

	this->m_ = static_cast<T*>(aligned_alloc(16, sizeof(T) * this->size));
}

template<class T>
inline size_t Triangular2DMatrix<T>::get_size() {
	return this->osize;
}

template<class T>
inline T& Triangular2DMatrix<T>::operator ()(size_t row, size_t column) {
	if(row >= this->osize || column >= this->osize)
		throw 0;

	size_t i,j;
	i = std::max(row, column)+1;
	j = std::min(row, column);

	return this->m_[((i*i-i)/2)+j];
}

template<class T>
void Triangular2DMatrix<T>::show(std::ostream& os)
{
	os << this->m_[0] << std::endl;

	for(size_t i = 1; i < this->osize; i++)
	{
		for(size_t j = 0; j <= i; j++)
		{
			os << this->m_[((i+1)*(i+1) - i -1)/2 + j] << " ";
		}

		os << std::endl;
	}
}


int main(int argc, char **argv) {
	Triangular2DMatrix<int> a = Triangular2DMatrix<int>((size_t)10);
	int counter = 0;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j <= i; j++)
			a(i,j) = counter++;
	}

	a.show(std::cout);


	return 0;
}
