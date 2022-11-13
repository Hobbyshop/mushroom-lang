#include "App.h"

bool mushroom::App::run(char* args[]) {
	Lexer lexer;
	gen_lexer_tokens(lexer);

	std::string sourcecode = "func var const var";    // TODO add read file
	std::vector<Token> tokens = lexer.lex(sourcecode);

	return true;
}

void mushroom::App::gen_lexer_tokens(mushroom::Lexer &lexer) {
	lexer.add_token(Token("FUNCTION", std::regex("func")));
	lexer.add_token(Token("VARIABLE", std::regex("var")));
	lexer.add_token(Token("CONSTANT", std::regex("const")));
}
