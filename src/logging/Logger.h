#include <string>

namespace mushroom {

	enum LogLevel {
		INFO,
		WARNING,
		ERROR,
	};

	class Logger {
	public:
		static void log(const std::string& message, LogLevel level);
	};

}
