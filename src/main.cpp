#include <iostream>

#include "Lexer.h"

void gen_tokens(mushroom::Lexer lexer) {
	lexer.add_token("FUNCTION", std::regex("func"));

	lexer.add_token("IF", std::regex("if"));
	lexer.add_token("ELSE", std::regex("else"));

	lexer.add_token("INT", std::regex("int"));
	lexer.add_token("STRING", std::regex("string"));
}

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
