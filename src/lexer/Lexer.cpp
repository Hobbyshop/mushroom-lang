#include "Lexer.h"

#include <regex>

namespace mushroom {

	void Lexer::add_token(const Token& token) {
		available_tokens.push_back(token);
	}

	std::vector<Token> Lexer::lex(std::string& to_lex) {
		std::vector<Token> token_list;

		to_lex = std::regex_replace(to_lex, std::regex(R"((/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/)|(//.*))"), "");		// remove comments

		while (!to_lex.empty()) {
			to_lex = std::regex_replace(to_lex, std::regex("^\\s+|\\s+$"), "");	// trim string

			for (Token t : available_tokens) {
				std::regex r(t.get_pattern());
				std::smatch m;

				std::regex_search(to_lex, m, r);

				if (!to_lex.empty() && m.position(0) == 0) {
					Token instance = t.copy();
					instance.set_pattern(m.str(0));
					token_list.push_back(instance);

					to_lex = to_lex.erase(0, m.str(0).size());
				}
			}
		}

		return token_list;
	}

}
