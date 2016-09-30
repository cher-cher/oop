#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(int x, int y, std::string const & borderColor)
	: m_x(x)
	, m_y(y)
	, m_borderColor(borderColor)
{
}

std::string CPoint::ToString() const
{
	std::stringstream stream;
	stream << "Point (" << m_x << "," << m_y << ")";
	stream << ", P=" << GetPerimeter() << ", S=" << GetArea();
	return stream.str();
}

int CPoint::GetX()const
{
	return m_x;
}

void CPoint::SetX(int val)
{
	m_x = val;
}

int CPoint::GetY()const
{
	return m_y;
}

void CPoint::SetY(int val)
{
	m_y = val;
}

double CPoint::GetArea() const
{
	return 0.0;
}

double CPoint::GetPerimeter() const
{
	return 0.0;
}

std::string CPoint::GetBorderColor() const
{
	return m_borderColor;
}
