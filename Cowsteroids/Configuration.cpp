#include "Configuration.h"

Configuration::Configuration()
{

}

Configuration::Configuration(std::vector<std::string> file)
{
	std::map<std::string, std::map<std::string, std::string>> map;

	for (std::string line : file)
	{
		std::vector<std::string> pair = splitString(line, ':');
		std::vector<std::string> values = splitString(pair[1], '/');

		std::map<std::string, std::string> map2;

		for (std::string value : values)
		{
			std::vector<std::string> vec = splitString(value, '-');
			map2[vec[0]] = vec[1];
		}

		map[pair[0]] = map2;
	}

	this->config = map;
}

Configuration::~Configuration()
{
}

std::map<std::string, std::string> Configuration::operator[](std::string key)
{
	return this->config[key];
}

std::vector<std::string> Configuration::splitString(std::string s, char c)
{
	std::vector<std::string> vec;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			std::string s1 = s.substr(0, i);
			s = s.erase(0, i + 1);
			i = 0;
			vec.push_back(s1);
		}
	}

	vec.push_back(s);

	return vec;
}
