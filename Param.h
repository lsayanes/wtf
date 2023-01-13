

#pragma once

#include <vector>
#include <string>

struct Param
{

	char mode;

	explicit Param(int argc, char** argv):
		mode{ 0 },
		args{ std::vector<std::string>(10) }
	{
		if (argc >= 2)
		{
			if ('-' == argv[1][0])
			{
				if (4 == argc)
				{
					if ('f' == argv[1][1])
					{
						mode = 'f';
						path(argv[3]);
						pattern(argv[2]);
					}
				}
			}
			else
			{
				mode = 'w';
				path(argv[1]);
			}
		}

	}
	
	virtual ~Param()
	{
	}

	inline const char* path()
	{
		return args[0].c_str();
	}

	inline const char* pattern()
	{
		return args[1].c_str();
	}

private:

	std::vector<std::string> args;

	inline void path(const char *szPath)
	{
		args[0] = szPath;
	}

	inline void pattern(const char* szPattern)
	{
		args[1] = szPattern;
	}

};