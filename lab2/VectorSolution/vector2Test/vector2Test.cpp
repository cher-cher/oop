#include "stdafx.h"
#include "../vector2/vector2.h"
#include "../../FindAndReplaceSolution/main/FindAndReplace.h"

using namespace std;

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}

BOOST_AUTO_TEST_SUITE(ProcessVector_function)


	BOOST_AUTO_TEST_CASE(should_make_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(should_multiply_each_element_by_the_minimum_element_when_all_items_are_the_same)
	{
		vector<double> checkedVector = { 5, 5, 5, 5 };
		vector<double> rightVector = { 25, 25, 25, 25 };
		ProcessVector(checkedVector);
		BOOST_CHECK(checkedVector == rightVector);
	}

	BOOST_AUTO_TEST_CASE(should_multiply_each_item_by_the_minimal_item_when_minimum_is_in_the_beginning)
	{
		vector<double> checkedVector = { 3, 9, 8, 16 };
		vector<double> rightVector = { 9, 24, 27, 48 };
		ProcessVector(checkedVector);
		BOOST_CHECK(checkedVector == rightVector);
	}

	BOOST_AUTO_TEST_CASE(should_multiply_each_item_by_the_minimal_item_when_minimum_is_in_the_middle)
	{
		vector<double> checkedVector = { 13, 5, 10 };
		vector<double> rightVector = { 25, 50, 65 };
		ProcessVector(checkedVector);
		BOOST_CHECK(checkedVector == rightVector);
	}

	BOOST_AUTO_TEST_CASE(should_multiply_each_item_by_the_minimal_item_when_minimum_is_in_the_end)
	{
		vector<double> checkedVector = { 8, 25, 3, 2 };
		vector<double> rightVector = { 4, 6, 16, 50 };
		ProcessVector(checkedVector);
		BOOST_CHECK(checkedVector == rightVector);
	}

BOOST_AUTO_TEST_SUITE_END()