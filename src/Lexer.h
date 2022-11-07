#pragma once

#include <vector>
#include <string>
#include <regex>

namespace mushroom {

	struct Token {
		std::string id;
		std::regex pattern;
	};

	class Lexer {
	private:
		std::vector<Token> tokens;

	public:
		void add_token(std::string id, std::regex pattern);
	};

}
