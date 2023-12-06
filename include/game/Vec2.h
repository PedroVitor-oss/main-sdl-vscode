#ifndef VEC2_H
#define VEC2_H


class Vec2
{
	public:
		float x,y;
		Vec2(float x_, float y_) {x=(x_); y=(y_);}

		// Funções para operações com vetores
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);

    // Função para calcular o comprimento do vetor
    float length() const;

    // Função para normalizar o vetor
    Vec2 normalize() const;

    // Função para calcular o produto escalar entre dois vetores
    float dot(const Vec2& other) const;

    // Funções para comparar vetores
    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;
	protected:

	private:
};

#endif // VEC2_H
