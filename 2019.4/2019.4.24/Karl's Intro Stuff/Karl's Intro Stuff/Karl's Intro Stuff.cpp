// Karl's Intro Stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>

struct Vector {
	float m_x;
	float m_y;
	float m_z;

	Vector(float x, float y, float z) {
		this->m_x = x;
		this->m_y = y;
		this->m_z = z;
	}

	Vector() { //properly initialized the class
		this->m_x = 0;
		this->m_y = 0;
		this->m_z = 0;
	}

	Vector operator + (Vector r) {
		return Vector(m_x + r.m_x, m_y + r.m_y, m_x + r.m_z);
	}
	Vector operator * (float r) {
		return Vector(m_x * r, m_y * r, m_z * r);
	}

	float operator % (Vector r) {
		return m_x * r.m_x + m_y * r.m_y + m_z * r.m_z; //dot product of a vector
	}

	Vector operator ^ (Vector r) {
		return Vector(m_y * r.m_z - m_z * r.m_y, m_z * r.m_x - m_x * r.m_z, m_x * r.m_y - m_y * r.m_x); //exponent of operator
	}

	Vector operator ! () {
		return *this*(1 / sqrt(*this%*this));
	}
};

int Spheres[] = { 24750, 280596, 280600, 249748, 18578, 231184, 16, 16 };
float Random() {
	return (float)rand() / RAND_MAX; //between 0.0 and 1.0
}

int Tracer(Vector o, Vector d, float& t, Vector& n) {
	t = 1e9;
	int m = 0;
	float p = -o.m_z / d.m_z;
	if (.01 < p) {
		t = p; 
		n = Vector(0, 0, 1);
		m = 1;
	}

	for (int k = 19; k--;) {
		for (int j = 9; j--;) {
			if (Spheres[j] & 1 << k) {
				Vector p = o + Vector(-k, 0, -j - 4);
				float b = p % d;
				float c = p % p;
				float q = b * b - c;
				if (q > 0) {
					float s = -b - sqrt(q);

					if (s< t && s > 0.01) {
						t = s;
						n = !(p + d * t);
						m = 2;
					}
				}
			}
		}
	}
	return m;
}


Vector Sampler(Vector o, Vector d) {
	float t;
	Vector n;

	int m = Tracer(o, d, t, n);

	if (!m) {
		return Vector(.7, .6, .1) * pow(1 - d.m_z, 4);
	}

	Vector h = o + d * t;
	Vector l = !(Vector(9 + Random(), 9 + Random(), 16) + h * -1);
	Vector r = d + n * (n % d * -2);

	
	float b = l%n;

	if (b < 0 || Tracer(h, l, t, n)) {
		b = 0;
	}

	float p = pow(l%r * (b > 0), 99);

	if (m & 1) { //bitwise and not a logical and
		h = h * .2;
		return((int)(ceil(h.m_x) + ceil(h.m_y)) & 1 ? Vector(3, 1, 1) : Vector(3, 3, 3))*(b*.2 + .1);
	}
	return Vector(p, p, p) + Sampler(h, r) * 0.5;
}


int main()
{
	printf("P6 512 512 255 ");
	Vector camera_direction = !Vector(-6, -16, 0);
	Vector camera_up_vector = !(Vector(0, 0, 1) ^ camera_direction) * 0.002;
	Vector right_vector = (camera_direction ^ camera_up_vector) * 0.002;
	Vector c = (camera_up_vector + right_vector) * -256 + camera_direction;



	for (int y = 512; y--;) {
		for (int x = 512; x--;) {
			Vector pixel(13, 13, 13);

			for (int r = 64; r--;) {
				Vector delta = camera_up_vector * (Random() - .5) * 99 + right_vector * (Random() - 0.5) * 99;
				pixel = Sampler(Vector(17, 16, 8) + delta,
					!(delta * -1 + (camera_up_vector * (Random() + x) + right_vector * (y + Random()) + c) * 16) * 3.5 + pixel);
			}
			printf("%c%c%c", (int)pixel.m_x, (int)pixel.m_y, (int)pixel.m_z);
		}
	}
	return 0;
}

//needs to compile via command line then pipe the exe to an output file to a ppm format. BUT IT TOTALLY WORKS!


// DIRTY LIFE HACKS float one = (float)1;