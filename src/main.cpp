#include <iostream>

#include "lexer/Lexer.h"

void gen_tokens(mushroom::Lexer &lexer) {
	using mushroom::Token;

	lexer.add_token(Token("FUNCTION", std::regex("func")));
	lexer.add_token(Token("VARIABLE", std::regex("var")));
	lexer.add_token(Token("CONSTANT", std::regex("const")));
}

int main() {
	std::string code = "var func const const func";

	mushroom::Lexer lexer;
	gen_tokens(lexer);

	auto tokens = lexer.lex(code);
	std::cout << "---------\n" << tokens.size() << "\n---------\n";

	for (mushroom::Token t : tokens) {
		std::cout << t.get_id() << '\n';
	}

	return 0;
}
