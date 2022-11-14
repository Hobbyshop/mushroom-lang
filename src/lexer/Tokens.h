#pragma once

#include <string>

namespace mushroom {

	class Token {
	private:
		std::string id;
		std::string pattern;

	public:
		Token(const std::string& id, const std::string& pattern);
		Token copy();

		std::string get_id();
		std::string get_pattern();

		void set_pattern(const std::string& new_pattern);
	};

}
