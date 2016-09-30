#pragma once
#include "stdafx.h"
#include "Shape.h"
#include "Point.h"


class CLineSegment final : public IShape
{
public:
	CLineSegment(int x1, int y1, int x2, int y2, std::string const& borderColor);
	~CLineSegment() = default;

	std::string ToString()const override;
	double GetArea()const override;
	double GetPerimeter()const override;
	std::string GetBorderColor()const override;

private:
	CPoint m_beginPoint;
	CPoint m_endPoint;
	double m_length;
	std::string m_borderColor;
};