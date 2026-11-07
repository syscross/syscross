
module;

#include <print>

export module _;

constexpr auto HELLO_MSG = "Hello, World!";

export void hello() {
    std::println("{}", HELLO_MSG);
}
