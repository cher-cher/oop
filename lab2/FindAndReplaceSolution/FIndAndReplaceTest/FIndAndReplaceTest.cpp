#include "stdafx.h"
#include "../main/FindAndReplace.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(when_one_of_the_argument_is_empty)

BOOST_AUTO_TEST_CASE(if_subject_is_empty_then_function_returns_an_empty_string)
{
	string subject = "";
	string search = "sun";
	string replace = "moon";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str.empty());
}

BOOST_AUTO_TEST_CASE(if_search_is_empty_then_function_returns_subject)
{
	string subject = "morning";
	string search = "";
	string replace = "morning";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str == "morning");
}

BOOST_AUTO_TEST_CASE(if_replace_is_empty_then_function_returns_string_when_search_string_will_be_deleted)
{
	string subject = "Cats ate birds";
	string search = "s";
	string replace = "";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str == "Cat ate bird");
}

BOOST_AUTO_TEST_SUITE(when_there_are_all_arguments)

BOOST_AUTO_TEST_CASE(it_replaces_all_occurrences_of_the_search_string_in_the_replacement_string)
{
	string subject = "This is an apple";
	string search = "is";
	string replace = "IS";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str == "ThIS IS an apple");
}

BOOST_AUTO_TEST_CASE(it_replaces_all_occurrences_of_the_search_string_in_the_replacement_string_test1)
{
	string subject = "All cats like fish";
	string search = "cats";
	string replace = "people";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str == "All people like fish");
}

BOOST_AUTO_TEST_CASE(it_replaces_all_occurrences_of_the_search_string_in_the_replacement_string_test2)
{
	string subject = "Girls like dancing";
	string search = "Girls";
	string replace = "Boys";

	string str = FindAndReplace(subject, search, replace);

	BOOST_CHECK(str == "Boys like dancing");
}

BOOST_AUTO_TEST_SUITE_END()}