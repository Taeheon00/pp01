#pragma once
#include "Mcommand.hpp"


class JumpCommand : public Musoeun :: MCommand
{
public:
	void Execute()
	{
		std::cout << "?ѽ? ????!!\n";
	}
};
class RunCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "?ѽ? ?޸???!!\n";
	}
};
class LeftCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "?ѽ? ????!!\n";
	}
};
class RightCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "?????̾? ??????!!\n";
	}
};
class DownCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "?ѽ? ??????\n";
	}
};
