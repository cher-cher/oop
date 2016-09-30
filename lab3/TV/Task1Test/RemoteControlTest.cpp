#include "stdafx.h"
#include "../Task1/RemoteControl.h"
#include "../Task1/TVSet.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// Зависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструирования самого remote-контрола
struct RemoteControlDependencies
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture()
		: remoteControl(tv, input, output)
	{
	}

	void VerifyCommandHandling(const string& command, const optional<int> & expectedChannel, const string& expectedOutput)
	{
		input << command;
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedChannel.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetChannel(), expectedChannel.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
	void VerifyCommandWithNamesHandling(const string& command, const optional<unsigned> & channel, const optional<string> & channelName, const string& expectedOutput)
	{
		input << command;
		BOOST_CHECK(tv.IsTurnedOn());
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.GetChannelName((*channel)), channelName);
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
{
	VerifyCommandHandling("TurnOn", 1, "TV is turned on\n");
}

BOOST_AUTO_TEST_CASE(can_not_select_previous_channel_when_tv_is_off)
{
	VerifyCommandHandling("SelectPreviousChannel", none, "");
}

BOOST_AUTO_TEST_CASE(can_not_select_previous_channel_when_previously_channel_was_not_choose)
{
	VerifyCommandHandling("SelectPreviousChannel", none, "");
}

BOOST_AUTO_TEST_CASE(can_turn_off_tv_which_is_on)
{
	tv.TurnOn();
	VerifyCommandHandling("TurnOff", none, "TV is turned off\n");
}

struct _after_set_names_of_some_channels : RemoteControlFixture
{
	_after_set_names_of_some_channels()
	{
		tv.TurnOn();
		tv.SetChannelName(45, "bbc rus");
		tv.SetChannelName(32, "1_channel");
		tv.SelectChannel(20);
	}
};
BOOST_FIXTURE_TEST_SUITE(_after_set_names_of_some_channels_, _after_set_names_of_some_channels)

BOOST_AUTO_TEST_CASE(can_get_name_of_some_channel_when_tv_is_on)
{
	boost::optional <string> nameChannel = "1_channel";
	VerifyCommandWithNamesHandling("GetChannelName 32", 32, nameChannel, "1_channel");
}
BOOST_AUTO_TEST_CASE(can_delete_name_of_some_channel_when_tv_is_on)
{
	VerifyCommandWithNamesHandling("DeleteChannelName bbc rus", 45, none, "");
}
BOOST_AUTO_TEST_CASE(can_select_channel_by_channel_name)
{
	VerifyCommandHandling("SelectChannel bbc rus", 45, "");
}
BOOST_AUTO_TEST_CASE(can_get_channel_by_channel_name)
{
	boost::optional<string> channelName = "1_channel";
	VerifyCommandWithNamesHandling("GetChannelByName 1_channel", 32, channelName, "32");
}
BOOST_AUTO_TEST_CASE(can_select_previous_channel)
{
	VerifyCommandHandling("SelectPreviousChannel", 1, "");
}

BOOST_AUTO_TEST_SUITE_END()

struct _after_TV_is_off : _after_set_names_of_some_channels
{
	_after_TV_is_off()
	{
		tv.TurnOff();
	}
	void VerifyCommandWithNamesHandlingWhenTurnedOff(const string& command, const optional<unsigned> & channel, const optional<string> & channelName, const string& expectedOutput)
	{
		input << command;
		BOOST_CHECK(tv.IsTurnedOn() == false);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.GetChannelName((*channel)), channelName);
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(_after_TV_is_off_, _after_TV_is_off)
BOOST_AUTO_TEST_CASE(can_not_get_name_of_some_channel)
{
	VerifyCommandWithNamesHandlingWhenTurnedOff("GetChannelName 32", 32, none, "");
}
BOOST_AUTO_TEST_CASE(can_not_delete_name_of_some_channel_when_tv_is_on)
{
	VerifyCommandWithNamesHandlingWhenTurnedOff("DeleteChannelName bbc rus", 45, none, "");
}
BOOST_AUTO_TEST_CASE(can_not_select_channel_by_channel_name)
{
	VerifyCommandHandling("SelectChannel bbc rus", none, "");
}
BOOST_AUTO_TEST_CASE(can_not_select_channel)
{
	VerifyCommandHandling("SelectChannel 45", none, "");
}
BOOST_AUTO_TEST_CASE(can_not_get_channel_by_channel_name)
{
	VerifyCommandWithNamesHandlingWhenTurnedOff("GetChannelByName 1_channel", 32, none, "");
}
BOOST_AUTO_TEST_CASE(can_not_get_channel_name_by_channel_number)
{
	VerifyCommandWithNamesHandlingWhenTurnedOff("GetChannelName 32", 32, none, "");
}
BOOST_AUTO_TEST_CASE(can_not_select_previous_channel)
{
	VerifyCommandHandling("SelectPreviousChannel", none, "");
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()