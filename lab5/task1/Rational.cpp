#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. ����������� ����� d() �������� �������
//////////////////////////////////////////////////////////////////////////

double CRational::ToDouble()const
{
	return m_numerator / static_cast<double>(m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 2. ����������� ������� + � ������� -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator-()const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator +()const
{
	return CRational(m_numerator, m_denominator);
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. ����������� �������� +
//////////////////////////////////////////////////////////////////////////

CRational const operator +(const CRational & rational1, const CRational & rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetDenominator()) + (rational2.GetNumerator() * rational1.GetDenominator()),
		rational1.GetDenominator() * rational2.GetDenominator());
}



//////////////////////////////////////////////////////////////////////////
// TODO: 4. ����������� �������� -
//////////////////////////////////////////////////////////////////////////

CRational const operator -(const CRational & rational1, const CRational & rational2)
{
	return (rational1 + -rational2);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. ����������� �������� +=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator +=(const CRational & rational)
{
	m_numerator = (m_numerator * rational.GetDenominator() + m_denominator * rational.GetNumerator());
	m_denominator *= rational.GetDenominator();
	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. ����������� �������� -=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator -=(const CRational & rational)
{
	return *this += -rational;

	/*m_numerator = (m_numerator * rational.GetDenominator() - m_denominator * rational.GetNumerator());
	m_denominator *= rational.GetDenominator();
	Normalize();
	return *this;*/
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. ����������� �������� *
//////////////////////////////////////////////////////////////////////////

CRational const operator *(const CRational & rational1, const CRational & rational2)
{
	return CRational(rational1.GetNumerator() * rational2.GetNumerator(), rational1.GetDenominator() * rational2.GetDenominator());
}



//////////////////////////////////////////////////////////////////////////
// TODO: 8. ����������� �������� /
//////////////////////////////////////////////////////////////////////////

CRational const operator /(const CRational & rational1, const CRational & rational2)
{
	return rational1 * CRational(rational2.GetDenominator(), rational2.GetNumerator());

	//return CRational(rational1.GetNumerator() * rational2.GetDenominator(), rational1.GdetDenominator() * rational2.GetNumerator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. ����������� �������� *=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator *=(const CRational & rational)
{
	m_numerator *= rational.GetNumerator();
	m_denominator *= rational.GetDenominator();
	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 10. ����������� �������� /=
//////////////////////////////////////////////////////////////////////////

CRational & CRational::operator /=(const CRational & rational)
{
	return *this *= CRational(rational.GetDenominator(), rational.GetNumerator());

	/*m_numerator *= rational.GetDenominator();
	m_denominator *= rational.GetNumerator();
	Normalize();
	return *this;*/
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. ����������� ��������� == � !=
//////////////////////////////////////////////////////////////////////////

bool const operator ==(const CRational & rational1, const CRational & rational2)
{
	return ((rational1.GetNumerator() == rational2.GetNumerator()) && (rational1.GetDenominator() == rational2.GetDenominator()));
}

bool const operator !=(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 == rational2);

	//return ((rational1.GetNumerator() != rational2.GetNumerator()) && (rational1.GetDenominator() != rational2.GetDenominator()));
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. ����������� ��������� <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const operator <(const CRational & rational1, const CRational & rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() < rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator <=(const CRational & rational1, const CRational & rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() <= rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator >(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 <= rational2);

	//return (rational1.GetNumerator() * rational2.GetDenominator() > rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator >=(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 < rational2);
	
	//return (rational1.GetNumerator() * rational2.GetDenominator() >= rational2.GetNumerator() * rational1.GetDenominator());
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. ����������� �������� ������ ������������� ����� � �������� ����� 
//////////////////////////////////////////////////////////////////////////

std::ostream & operator <<(std::ostream & stream, CRational const& value)
{
	stream << value.GetNumerator() << '/' << value.GetDenominator();
	return stream;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 14. ����������� �������� ����� ������������� ����� �� �������� ������ 
//////////////////////////////////////////////////////////////////////////


