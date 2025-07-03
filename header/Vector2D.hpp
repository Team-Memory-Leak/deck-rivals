#pragma once
#include <iostream>

class Vector2D{
  private:
		float x;
		float y;

	public:
		Vector2D();
		Vector2D(float x , float y);
		~Vector2D(){};
		Vector2D(Vector2D&) = delete; 
		Vector2D & operator=(Vector2D&) = delete;

		Vector2D & Add(const Vector2D& vec);
		Vector2D & Subtract(const Vector2D& vec);
		Vector2D & Multiply(const Vector2D& vec);
		Vector2D & Divide(const Vector2D& vec);

		friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

		Vector2D& operator+=(const Vector2D& vec);
		Vector2D& operator-=(const Vector2D& vec);
		Vector2D& operator*=(const Vector2D& vec);
		Vector2D& operator/=(const Vector2D& vec);

		Vector2D operator*(float scalar);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);

		float getX(){return x;}
		float getY(){return y;}
		void setX(float newX){x = newX;}
		void setY(float newY){y = newY;}

};