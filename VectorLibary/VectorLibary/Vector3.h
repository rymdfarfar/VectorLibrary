#pragma once

#include <math.h>

template <typename T>
struct  vector3
{
	T x, y, z;

	// constructor
	vector3<T>() {}

	// setting constructor
	vector3<T>(const T x0, const T y0, const T z0) : x(x0), y(y0), z(z0) {}

	// function call operator
	void operator ()(const T x0, const T y0, const T z0)
	{
		x = x0; y = y0; z = z0;
	}

	//Test for equality
	bool operator==(const vector3<T> &v)
	{
		return (x == v.x && y == v.y && z == v.z);
	}


	//test for inequality
	bool operator!=(const vector3<T> &v)
	{
		return (x != v.x || y != v.y || z != v.z);
	}


	// set to value return this vector
	const vector3<T> &operator =(const vector3<T> &v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}
	// negation  return new vector
	const vector3<T> operator -(void) const
	{
		return vector3<T>(-x, -y, -z);
	}


	// addition  return new vector
	const vector3<T> operator +(const vector3<T> &v) const
	{
		return vector3<T>(x + v.x, y + v.y, z+ v.z);
	}

	// subtraction return new vector
	const vector3<T> operator -(const vector3<T> &v) const
	{
		return vector3<T>(x - v.x, y - v.y, z -v.z);
	}

	// uniform scaling return new vector
	const vector3<T> operator *(const T num) const
	{
		vector3<T> temp(*this);
		return temp *= num;
	}

	// uniform scaling
	const vector3<T> operator /(const T num) const
	{
		vector3<T> temp(*this);
		return temp /= num;
	}

	// addition return this vector
	const vector3<T> &operator +=(const vector3<T> &v)
	{
		x += v.x;	y += v.y; z += v.z;
		return *this;
	}

	// subtraction return this vector
	const vector3<T> &operator -=(const vector3<T> &v)
	{
		x -= v.x;	y -= v.y; z -= v.z;
		return *this;
	}
	// subtraction return this vector
	const vector3<T> &operator -=(const vector3<T> &v)
	{
		x -= v.x;	y -= v.y; z -= v.z;
		return *this;
	}

	//uniform scaling
	const vector3<T> &operator *=(const T num)
	{
		x *= num;	y *= num z*=num;
		return *this;
	}

	// uniform scaling return this vector
	const vector3<T> &operator /=(const T num)
	{
		x /= num;	y /= num; z /= num;
		return *this;
	}

	// dot product return this vector
	T operator *(const vector3<T> &v) const
	{
		return x*v.x + y*v.y + z*v.z;
	}

	//cross product return new vector
	const vector3<T> operator %(const vector3<T> &v) const
	{
		vector3<T> temp(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
		return temp;
	}


};

// macro to make creating the constructorst for the different types of vectors 
#define VECTOR3_CTORS(name, type)   \
	/*  constructor */				\
	name() {}						\
	/* down casting constructor */			\
	name(const vector3<type> &v): vector3<type>(v.x, v.y, v.z) {}	\
	/* make x,y,z combination into a vector */					\
	name(type x0, type y0, type z0): vector3<type>(x0, y0, z0) {}


struct vector3i : public vector3<int>
{
	 VECTOR3_CTORS(vector3i, int)


		 // gets the length of this vector squared
		 int length_squared() const
	 {
		 return (int)(*this * *this);
	 }

	 // gets the length of this vector
	 int length() const
	 {
		 return (int)sqrt(*this * *this);
	 }

	 // normalizes this vector
	 void normalize()
	 {
		 *this /= length();
	 }

	 // returns the normalized vector
	 vector3i normalized() const
	 {
		 return  *this / length();
	 }
};


struct vector3f : public vector3<float>
{
	VECTOR3_CTORS(vector3f, float)

		// gets the length of this vector squared
		float length_squared() const
	{
		return (float)(*this * *this);
	}

	// gets the length of this vector
	float length() const
	{
		return (float)sqrt(*this * *this);
	}

	// normalizes this vector
	void normalize()
	{
		*this /= length();
	}

	// returns the normalized vector
	vector3f normalized() const
	{
		return  *this / length();
	}


};






