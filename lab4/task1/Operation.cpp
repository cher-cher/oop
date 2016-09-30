#include "stdafx.h"
#include "Operation.h"
#include <algorithm>
#include <boost/range/algorithm.hpp>

using namespace std;
using namespace std::placeholders;

COperations::COperations(istream & input, ostream & output, std::vector<shared_ptr<IShape>> & shapes)
	: m_input(input)
	, m_output(output)
	, m_shapes(shapes)
	, m_shapesMap({
		{ "point", bind(&COperations::GetPointPtr, this, _1) },
		{ "line", bind(&COperations::GetLinePtr, this, _1) },
		{ "circle", bind(&COperations::GetCirclePtr, this, _1) },
		{ "rectangle", bind(&COperations::GetRectanglePtr, this, _1) },
		{ "triangle", bind(&COperations::GetTrianglePtr, this, _1) },
})
{
}

void COperations::PrintInformationAboutSort(vector<shared_ptr<IShape>> & shapes)
{
	boost::range::sort(m_shapes, [](ShapePtr & first, ShapePtr & second)
	{
		return first->GetPerimeter() < second->GetPerimeter();
	});

	cout << endl << endl << "Sorting by reduce the perimeters:\n" << endl;

	auto printShape = [](ShapePtr const& shape) {
		std::cout << shape->ToString() << std::endl;
	};

	std::for_each(shapes.begin(), shapes.end(), printShape);

	boost::range::sort(m_shapes, [](ShapePtr & first, ShapePtr & second)
	{
		return first->GetArea() < second->GetArea();
	});

	m_output << "Sorting by increasing the areas:\n" << endl;

	std::for_each(shapes.begin(), shapes.end(), printShape);
}

bool COperations::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string shape;
	strm >> shape;
	auto it = m_shapesMap.find(shape);
	if (it != m_shapesMap.end())
	{
		m_shapes.push_back(it->second(strm));
	}
	else if (shape == "end")
	{
		PrintInformationAboutSort(m_shapes);
	}
	else
	{
		return false;
	}
	return true;
}

ShapePtr COperations::GetPointPtr(istream & strm)
{
	int x, y;
	strm >> x >> y;
	string borderColor;
	strm >> borderColor;
	return make_shared<CPoint>(x, y, borderColor);
}

ShapePtr COperations::GetLinePtr(std::istream & strm)
{
	int beginX, beginY, endX, endY;
	strm >> beginX >> beginY >> endX >> endY;
	string borderColor;
	strm >> borderColor;
	return make_shared<CLineSegment>(beginX, beginY, endX, endY, borderColor);
}

ShapePtr COperations::GetCirclePtr(std::istream & strm)
{
	int x, y, radius;
	strm >> x >> y >> radius;
	string borderColor, color;
	strm >> borderColor >> color;
	return make_shared<CCircle>(x, y, radius, borderColor, color);
}

ShapePtr COperations::GetRectanglePtr(std::istream & strm)
{
	int x, y, w, h;
	strm >> x >> y >> w >> h;
	string borderColor, color;
	strm >> borderColor >> color;
	return make_shared<CRectangle>(x, y, w, h, borderColor, color);
}

ShapePtr COperations::GetTrianglePtr(std::istream & strm)
{
	int x1, y1, x2, y2, x3, y3;
	strm >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	string borderColor, color;
	strm >> borderColor >> color;
	return make_shared<CTriangle>(x1, y1, x2, y2, x3, y3, borderColor, color);
}

