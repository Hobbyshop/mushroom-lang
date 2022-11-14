#include "lexer/Lexer.h"

#include <iostream>

namespace mushroom {

	class App {
	private:
		static void gen_lexer_tokens(Lexer& lexer);
		static std::string read_file(const std::string& path);

	public:
		bool run(char **args);
	};

}
