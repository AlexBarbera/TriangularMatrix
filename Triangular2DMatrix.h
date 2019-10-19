/*
 * Triangular2DMatrix.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Alex Barbera
 */

#ifndef TRIANGULAR2DMATRIX_H_
#define TRIANGULAR2DMATRIX_H_

#include <cstdlib>
#include <algorithm>

template<class T>
class Triangular2DMatrix {
public:
	Triangular2DMatrix(size_t size);
	virtual ~Triangular2DMatrix();
	T* m_;
	size_t size;
	size_t osize=-1;

	void set_size(size_t s);
	size_t get_size();

	T& operator()(size_t row, size_t column);

	void multiply(long long o);
	void divide(long long o);
	void add(long long o);
	void subtract(long long o);

	void multiply(float o);
	void divide(float o);
	void add(float o);
	void subtract(float o);

	void multiply(Triangular2DMatrix<T> o);
	void divide(Triangular2DMatrix<T> o);
	void add(Triangular2DMatrix<T> o);
	void subtract(Triangular2DMatrix<T> o);


	void show(std::ostream& os);

private:

};

#endif /* TRIANGULAR2DMATRIX_H_ */
