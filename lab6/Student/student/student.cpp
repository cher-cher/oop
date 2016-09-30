#include "stdafx.h"
#include "student.h"

using namespace std;

CStudent::CStudent(const string& name, const string& patronymic, const string& surname, unsigned age)
{
	if (name == "" || surname == "")
	{
		throw invalid_argument("Name (surname) can not be empty");
	}
	if (age < 14 || age > 60)
	{
		throw out_of_range("14 <= age <= 60");
	}
	m_name = name;
	m_surname = surname;
	m_patronymic = patronymic;
	m_age = age;
}

string CStudent::GetName()const
{
	return m_name;
}

string CStudent::GetSurname()const
{
	return m_surname;
}

string CStudent::GetPatronymic()const
{
	return m_patronymic;
}

unsigned CStudent::GetAge()const
{
	return m_age;
}

void CStudent::Rename(string name, string patronymic, string surname)
{
	if (name == "" || surname == "")
	{
		throw invalid_argument("Name (surname) can not be empty");
	}
	m_name = move(name);
	m_patronymic = move(patronymic);
	m_surname = move(surname);
}

void CStudent::SetAge(unsigned age)
{
	if (age < m_age)
	{
		throw domain_error("Age must be greater than the current");
	}
	if (age < 14 || age > 60)
	{
		throw out_of_range("14 <= age <= 60");
	}
	m_age = age;
}

