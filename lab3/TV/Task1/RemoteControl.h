#pragma once
#include <boost/noncopyable.hpp>
#include "TVSet.h"

// Наследование от boost::noncopyable - явный способ запретить копирование и присваивание экземпляров класса
class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;
	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;
	const ActionMap m_actionMap;

private:
	bool TurnOn(std::istream & args);
	bool TurnOff(std::istream & args);
	bool GetInfo(std::istream & args)const;
	bool SetChannelName(std::istream & strm);
	bool SelectedChannel(std::istream & strm);
	bool SelectedPreviousChannel(std::istream & args);
	bool DeletedChannelName(std::istream & strm);
	bool GetChannelName(std::istream & strm)const;
	bool GetChannelByName(std::istream & strm)const;
};

