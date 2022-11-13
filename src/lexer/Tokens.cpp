#include "Tokens.h"

namespace mushroom {

	Token::Token(const std::string& id, const std::regex& pattern) {
		this->id = id;
		this->pattern = pattern;
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
