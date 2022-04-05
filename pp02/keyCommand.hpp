#pragma once
#include "Mcommand.hpp"


class JumpCommand : public Musoeun :: MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î Á¡ÇÁ!!\n";
	}
};
class RunCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ´Þ¸®±â!!\n";
	}
};
class LeftCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ¿ÞÂÊ!!\n";
	}
};
class RightCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "¸¾¸¶¹Ì¾ß ¿À¸¥ÂÊ!!\n";
	}
};
class DownCommand : public Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "¾Ñ½Î ¾¥±¸¸®\n";
	}
};
