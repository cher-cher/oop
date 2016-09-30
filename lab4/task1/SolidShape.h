#pragma once
#include "Shape.h"

class ISolidShape : public IShape
{
public:
	virtual std::string GetColor()const = 0;
};

