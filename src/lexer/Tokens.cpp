#include "Tokens.h"

namespace mushroom {

	Token::Token(std::string id, std::regex pattern) {
		this->id = id;
		this->pattern = pattern;
	}

}
