#pragma once

#include <vector>

#include "Tokens.h"

namespace mushroom {

	class Lexer {
	private:
		std::vector<Token> available_tokens;

	public:
		void add_token(Token token);
		std::vector<Token> lex(std::string to_lex);
	};

}
