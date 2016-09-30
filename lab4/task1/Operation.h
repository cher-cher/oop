#pragma once
#include "Shape.h"
#include "Point.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

typedef std::shared_ptr<IShape> ShapePtr;

class COperations
{
public:
	COperations(std::istream & input, std::ostream & output, std::vector<std::shared_ptr<IShape>> & shapes);
	~COperations() = default;
	
	bool HandleCommand();
	void PrintInformationAboutSort(std::vector<std::shared_ptr<IShape>> & x);
	ShapePtr GetPointPtr(std::istream & strm);
	ShapePtr GetLinePtr(std::istream & strm);
	ShapePtr GetCirclePtr(std::istream & strm);
	ShapePtr GetRectanglePtr(std::istream & strm);
	ShapePtr GetTrianglePtr(std::istream & strm);
	
private:
	std::istream & m_input;
	std::ostream & m_output;
	std::vector<ShapePtr> m_shapes;
	typedef std::map<std::string, std::function<ShapePtr(std::istream & args)>> ShapesMap;
	const ShapesMap m_shapesMap;
};

