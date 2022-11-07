#include "Lexer.h"

#include <utility>

namespace mushroom {

	void Lexer::add_token(std::string id, std::regex pattern) {
		tokens.push_back(Token {
			std::move(id),
			std::move(pattern)
		});
	}

}
