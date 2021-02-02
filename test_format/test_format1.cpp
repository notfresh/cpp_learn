//
// Created by zxzx on 2021/1/21.
//

#include <fmt/core.h>

int main() {
	fmt::print("Hello, world!\n");
	std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
	fmt::print(s);
}
