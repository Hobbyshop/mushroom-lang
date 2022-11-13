#pragma once

#include <vector>

#include "Tokens.h"

namespace mushroom {

	class Lexer {
	private:
		std::vector<Token> available_tokens;

		static void pop_char(std::string& base, std::string& buffer);

	public:
		void add_token(const Token& token);
		std::vector<Token> lex(std::string to_lex);
	};

}
