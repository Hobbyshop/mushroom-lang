#pragma once

#include <string>
#include <regex>

namespace mushroom {

	class Token {
	private:
		std::string id;
		std::regex pattern;

	public:
		Token(std::string id, std::regex pattern);
		Token copy();

		std::string get_id();
		std::regex get_pattern();
	};

}
