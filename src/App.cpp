#include "App.h"

#include <iostream>

bool mushroom::App::run(char* args[]) {
	Lexer lexer;
	gen_lexer_tokens(lexer);

	std::string sourcecode = "if (true) {}";    // TODO add read file
	std::vector<Token> tokens = lexer.lex(sourcecode);

	for (auto& token : tokens) {
		std::cout << "(" << token.get_id() << ", \"" << token.get_pattern() << "\")\n";
	}

	return true;
}

void mushroom::App::gen_lexer_tokens(mushroom::Lexer &lexer) {
	// KEYWORDS //
	lexer.add_token(Token("FUNCTION", "(func)"));
	lexer.add_token(Token("RETURN", "(return)"));
	lexer.add_token(Token("VARIABLE", "(var)"));
	lexer.add_token(Token("CONSTANT", "(const)"));
	lexer.add_token(Token("IF", "if"));
	lexer.add_token(Token("ELSE", "else"));
	lexer.add_token(Token("SWITCH", "switch"));
	lexer.add_token(Token("CASE", "case"));
	lexer.add_token(Token("BREAK", "break"));
	lexer.add_token(Token("TRUE", "true"));
	lexer.add_token(Token("FALSE", "false"));

	// OPERATORS //
	lexer.add_token(Token("PLUS", "\\+"));
	lexer.add_token(Token("MINUS", "\\-"));
	lexer.add_token(Token("ASTERISK", "\\*"));
	lexer.add_token(Token("SLASH", "\\/"));
	lexer.add_token(Token("EQUALS", "="));
	lexer.add_token(Token("EQUALS_CHECK", "=="));
	lexer.add_token(Token("GREATER", "\\>"));
	lexer.add_token(Token("GREATER_EQUALS", "\\>="));
	lexer.add_token(Token("LESS", "\\<"));
	lexer.add_token(Token("LESS_EQUALS", "\\<="));
	lexer.add_token(Token("AMPERSAND", "\\&"));
	lexer.add_token(Token("PIPE", "\\|"));
	lexer.add_token(Token("EXCLAMATION_MARK", "!"));
	lexer.add_token(Token("INCREMENT", R"(\+\+)"));
	lexer.add_token(Token("DECREMENT", R"(\-\-)"));
	lexer.add_token(Token("ADD_EQUALS", "\\+="));
	lexer.add_token(Token("SUB_EQUALS", "\\-="));
	lexer.add_token(Token("MUL_EQUALS", "\\*="));
	lexer.add_token(Token("DIV_EQUALS", "\\/="));

	// DATA TYPES //
	lexer.add_token(Token("INT_8", "i8"));
	lexer.add_token(Token("INT_16", "i16"));
	lexer.add_token(Token("INT_32", "i32"));
	lexer.add_token(Token("INT_64", "i64"));
	lexer.add_token(Token("FLOAT_16", "f16"));
	lexer.add_token(Token("FLOAT_32", "f32"));
	lexer.add_token(Token("CHAR", "char"));
	lexer.add_token(Token("STRING", "string"));
	lexer.add_token(Token("BOOLEAN", "bool"));

	// MISCELLANEOUS //
	lexer.add_token(Token("PERIOD", "\\."));
	lexer.add_token(Token("COLON", ":"));
	lexer.add_token(Token("COMMA", ","));
	lexer.add_token(Token("SEMICOLON", ";"));
	lexer.add_token(Token("BACKSLASH", R"(\\)"));
	lexer.add_token(Token("DOLLAR_SIGN", "$"));
	lexer.add_token(Token("L_PAREN", "\\("));
	lexer.add_token(Token("R_PAREN", "\\)"));
	lexer.add_token(Token("L_BRACE", "\\{")); 
	lexer.add_token(Token("R_BRACE", "\\}"));
	lexer.add_token(Token("L_BRACKET", "\\["));
	lexer.add_token(Token("R_BRACKET", "\\]"));

	// DATA //
	lexer.add_token(Token("NUMBER", "\\d+"));
	lexer.add_token(Token("NAME", "\\w+"));
	lexer.add_token(Token("STRING_CONTENT", R"((["])(?:(?=(\?))\2.)*?\1)"));
	lexer.add_token(Token("CHARATER", R"((['])(?:(?=(\\?))\2.)*?\1)"));

	// comments: (/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/)|(//.*)
}
