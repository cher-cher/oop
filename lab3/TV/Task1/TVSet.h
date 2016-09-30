#pragma once

class CTVSet
{
public:
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	int GetChannel()const;
	bool SetChannelName(size_t channel, std::string const & channelName);
	bool SelectChannel(size_t channel);
	bool SelectPreviousChannel();
	bool SelectChannel(std::string const& channelName);
	bool DeleteChannelName(std::string const& channelName);
	boost::optional <std::string> GetChannelName(size_t channel)const;
	boost::optional <size_t> GetChannelByName(std::string const& channelName)const;

	bool ChannelNumberIsValid(size_t n)const;

private:
	bool m_isOn = false;
	size_t m_selectedChannel = 1;
	size_t m_prevChannel = 0;
public:
	std::map<size_t, std::string> m_tvChannelsNumbers;
	std::map<std::string, size_t> m_tvChannelsName;
};

