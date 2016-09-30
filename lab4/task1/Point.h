#pragma once

#include "stdafx.h"
#include "Shape.h"

class CPoint final : public IShape
{
public:
	CPoint(int x, int y, std::string const& borderColor);
	~CPoint() = default;

	int GetX()const;
	void SetX(int val);

	int GetY()const;
	void SetY(int val);

	std::string ToString()const override;
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string GetBorderColor()const override;
private:
	std::string m_borderColor;

	int m_x;
	int m_y;
};