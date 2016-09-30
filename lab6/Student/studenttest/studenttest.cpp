#include "stdafx.h"
#include "../student/student.h"
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(StudentTests)

	BOOST_AUTO_TEST_CASE(student_has_name)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_EQUAL(student.GetName(), "Ivan");
	}

	BOOST_AUTO_TEST_CASE(student_has_patronymic)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
	}

	BOOST_AUTO_TEST_CASE(student_has_surname)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_EQUAL(student.GetSurname(), "Ivanov");
	}

	BOOST_AUTO_TEST_CASE(student_has_age)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_EQUAL(student.GetAge(), 25);
	}

	BOOST_AUTO_TEST_CASE(student_can_hasnot_patronymic)
	{
		CStudent student("Ivan", "", "Ivanov", 25);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
	}

	BOOST_AUTO_TEST_CASE(student_must_have_name)
	{
		BOOST_CHECK_THROW(CStudent("", "Ivanovich", "Ivanov", 25), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(student_must_have_surname)
	{
		BOOST_CHECK_THROW(CStudent("Ivan", "Ivanovich", "", 25), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(age_of_student_must_be_greater_than_14)
	{
		BOOST_CHECK_THROW(CStudent("Ivan", "Ivanovich", "Ivanov", 10), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(age_of_student_must_be_less_than_60)
	{
		BOOST_CHECK_THROW(CStudent("Ivan", "Ivanovich", "Ivanov", 70), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(age_of_student_cannot_be_reduce)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_THROW(student.SetAge(24), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(age_of_student_can_ba_change)
	{
		CStudent student("Kolya", "Nikolaevich", "Petrov", 25);
		BOOST_CHECK_NO_THROW(student.SetAge(26));
	}

	BOOST_AUTO_TEST_CASE(new_students_name_cannot_be_empty)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_THROW(student.Rename("", "Alexsandrovich", "Alexsandrov"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(new_students_surname_cannot_be_empty)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_THROW(student.Rename("Alexsandr", "Alexsandrovich", ""), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(new_students_patronymic_can_be_empty)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_NO_THROW(student.Rename("Alexsandr", "", "Alexsandrov"));
	}

	BOOST_AUTO_TEST_CASE(student_can_be_rename)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		BOOST_CHECK_NO_THROW(student.Rename("Alexsandr", "Alexsandrovich", "Alexsandrov"));
	}

	BOOST_AUTO_TEST_CASE(commit_or_rollback_supported)
	{
		CStudent student("Ivan", "Ivanovich", "Ivanov", 25);
		std::string newName(900'000'000, 'l');
		BOOST_CHECK_THROW(student.Rename(newName, "Alexsandrovich", "Alexsandrov"), std::bad_alloc);
		BOOST_CHECK_EQUAL(student.GetName(), "Ivan");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Ivanov");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
	}

BOOST_AUTO_TEST_SUITE_END()
