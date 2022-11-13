#include "lexer/Lexer.h"

namespace mushroom {

	class App {
	private:
		static void gen_lexer_tokens(Lexer& lexer);

	public:
		bool run(char **args);
	};

}
