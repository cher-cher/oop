#include "stdafx.h"
#include "TVSet.h"

using namespace std;

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetChannel()const
{
	return m_isOn ? m_selectedChannel : 0;
}

bool CTVSet::ChannelNumberIsValid(size_t n) const
{
	return (n >= 1) && (n <= 99);
}

bool CTVSet::SetChannelName(size_t channel, string const & channelName)
{
	if (m_isOn && ChannelNumberIsValid(channel) && channelName.size())
	{
		if (m_tvChannelsNumbers.find(channel) != m_tvChannelsNumbers.end())
		{
			m_tvChannelsNumbers[channel] = channelName;
			m_tvChannelsName[channelName] = channel;
			return true;
		}
		m_tvChannelsNumbers.insert(pair<size_t, string>(channel, channelName));
		m_tvChannelsName.insert(pair<string, size_t>(channelName, channel));
		return true;
	}
	return false;
}

bool CTVSet::SelectChannel(size_t channel)
{
	if (ChannelNumberIsValid(channel) && m_isOn)
	{
		m_prevChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}
	return false;
}

bool CTVSet::SelectChannel(string const& channelName)
{
	if (channelName.size() && m_isOn)
	{
		auto channel = GetChannelByName(channelName);
		if (channel)
		{
			m_prevChannel = m_selectedChannel;
			m_selectedChannel = *channel;
			return true;
		}
	}
	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn && (m_prevChannel != 0))
	{
		std::swap(m_prevChannel, m_selectedChannel);
		return true;
	}
	if (!m_isOn || m_prevChannel == 0)
	{
		cout << "Can't select previously channel" << endl;
		return false;
	}
	return false;
}

bool CTVSet::DeleteChannelName(string const& channelName)
{
	if (m_isOn)
	{
		auto it = m_tvChannelsName.find(channelName);
		if (it != m_tvChannelsName.end())
		{
			size_t channel = it->second;
			m_tvChannelsName.erase(it++);
			m_tvChannelsNumbers.erase(m_tvChannelsNumbers.find(channel));
			return true;
		}
	}
	return false;
}

boost::optional <string> CTVSet::GetChannelName(size_t channel)const
{
	boost::optional<string> channelName;
	if (m_isOn)
	{
		auto it = m_tvChannelsNumbers.find(channel);
		if (it != m_tvChannelsNumbers.end())
		{
			channelName = it->second;
		}
	}
	return channelName;
}

boost::optional <size_t> CTVSet::GetChannelByName(string const& channelName)const
{
	boost::optional <size_t> channel;
	if (m_isOn)
	{
		auto it = m_tvChannelsName.find(channelName);
		if (it != m_tvChannelsName.end())
		{
			channel = it->second;
		}
	}
	return channel;
}