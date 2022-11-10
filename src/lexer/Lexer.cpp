#include "Lexer.h"

#include <iostream>

namespace mushroom {

	void Lexer::add_token(Token token) {
		available_tokens.push_back(token);
	}

	std::vector<Token> Lexer::lex(std::string to_lex) {
		std::vector<Token> token_list;
		std::string match_buffer;

		while (!to_lex.empty()) {
			match_buffer.append(to_lex.substr(0, 1));
			to_lex = to_lex.substr(1, to_lex.size() - 1);

			while (to_lex.rfind(' ', 0) == 0)
				to_lex.erase(0, 1);

			for (Token t : available_tokens) {
				if (std::regex_match(match_buffer, t.get_pattern())) {
					token_list.push_back(t.copy());
					match_buffer = "";
					break;
				}
			}

		}

		return token_list;
	}

	Token Token::copy() {
		return { id, pattern };
	}

	std::string Token::get_id() {
		return id;
	}
	std::regex Token::get_pattern() {
		return pattern;
	}

}
