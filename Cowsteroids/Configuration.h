#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <map>
#include <vector>

class Configuration
{
public:
	Configuration();
	Configuration(std::vector<std::string> file);
	~Configuration();

	std::map<std::string, std::string> operator[](std::string key);

private:
	std::map<std::string, std::map<std::string, std::string>> config;

	static std::vector<std::string> splitString(std::string s, char c);

};

#endif