#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std::placeholders;
using namespace std;

CRemoteControl::CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", bind(&CRemoteControl::TurnOn, this, _1) },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		{ "SelectChannel", bind(&CRemoteControl::SelectedChannel, this, _1) },
		{ "SelectPreviousChannel", bind(&CRemoteControl::SelectedPreviousChannel, this, _1) },
		{ "Info", bind(&CRemoteControl::GetInfo, this, _1) },
		{ "SetChannelName", bind(&CRemoteControl::SetChannelName, this, _1) },
		{ "DeleteChannelName", bind(&CRemoteControl::DeletedChannelName, this, _1) },
})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

bool CRemoteControl::SelectedPreviousChannel(std::istream & /*args*/)
{
	return ((m_tv.SelectPreviousChannel() ? true : false));
}

bool CRemoteControl::TurnOn(std::istream & /*args*/)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream & /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

string GetFullString(istream & strm)
{
	string buf, channelName;
	while (strm >> buf)
	{
		if (channelName.size() == 0)
		{
			channelName += buf;
		}
		else
		{
			channelName += ' ' + buf;
		}
	}
	return channelName;
}

bool CRemoteControl::SetChannelName(istream & strm)
{
	size_t channel;
	strm >> channel;
	return m_tv.SetChannelName(channel, GetFullString(strm));
}

bool CRemoteControl::SelectedChannel(istream & strm)
{
	string value;
	strm >> value;
	size_t channel = atoi(value.c_str());
	if (m_tv.ChannelNumberIsValid(channel))
	{
		return m_tv.SelectChannel(channel);
	}
	return m_tv.SelectChannel(channel);
}

bool CRemoteControl::GetInfo(istream & /*args*/)const
{
	if (m_tv.IsTurnedOn())
	{
		for (auto it : m_tv.m_tvChannelsNumbers)
		{
			cout << it.first << " - " << it.second << endl;
		}
	}
	m_tv.GetChannel() == 0 ? (m_output << "TV is OFF" << endl) : (m_output << "Selected channel : " << m_tv.GetChannel() << endl);
	return true;
}

bool CRemoteControl::DeletedChannelName(istream & strm)
{
	return m_tv.DeleteChannelName(GetFullString(strm));
}

bool CRemoteControl::GetChannelName(istream & strm)const
{
	size_t channel;
	strm >> channel;
	if (m_tv.IsTurnedOn())
	{
		boost::optional <string> channelName = m_tv.GetChannelName(channel);
		if (channelName)
		{
			m_output << (*channelName);
		}
		else
		{
			m_output << "Channel name doesn't set!";
		}
		return true;
	}
	return false;
}

bool CRemoteControl::GetChannelByName(istream & strm)const
{
	auto channel = m_tv.GetChannelByName(GetFullString(strm));
	if (m_tv.IsTurnedOn())
	{
		if (channel)
		{
			m_output << (*channel);
		}
		else
		{
			m_output << "No channel with the same name!";
		}
		return true;
	}
	return false;
}