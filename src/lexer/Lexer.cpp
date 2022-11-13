#include "Lexer.h"

#include <iostream>

namespace mushroom {

	void Lexer::add_token(const Token& token) {
		available_tokens.push_back(token);
	}

	std::vector<Token> Lexer::lex(std::string to_lex) {
		std::vector<Token> token_list;
		std::string match_buffer;

		while (!to_lex.empty()) {
			while (to_lex.at(0) == ' ')
				to_lex.erase(0, 1);

			pop_char(to_lex, match_buffer);

			while (!to_lex.empty() && isdigit(to_lex.at(0))) {
				pop_char(to_lex, match_buffer);
			}

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

	void Lexer::pop_char(std::string& base, std::string& buffer) {
		buffer.append(base.substr(0, 1));
		base = base.substr(1, base.length() - 1);
	}

}
