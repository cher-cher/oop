#pragma once
#include "stdafx.h"

class CStudent
{
public:
	CStudent(const std::string& name, const std::string& patronymic, const std::string& surname, unsigned age);
	~CStudent() = default;
	std::string GetName()const;
	std::string GetPatronymic()const;
	std::string GetSurname()const;
	unsigned GetAge()const;
	void Rename(std::string name, std::string patronymic, std::string surname);
	void SetAge(unsigned age);

private:
	std::string m_name, m_patronymic, m_surname;
	unsigned m_age;
};