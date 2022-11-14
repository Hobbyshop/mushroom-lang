#include "Tokens.h"

namespace mushroom {

	Token::Token(const std::string& id, const std::string& pattern) {
		this->id = id;
		this->pattern = pattern;
	}

	Token Token::copy() {
		return { id, pattern };
	}

	std::string Token::get_id() {
		return id;
	}
	std::string Token::get_pattern() {
		return pattern;
	}

	void Token::set_pattern(const std::string& new_pattern) {
		this->pattern = new_pattern;
	}

}
