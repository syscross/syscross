#pragma once

#include <cstdio>
#include <print>
#include <format>
#include <iostream>
#include <string>
#include <utility>

using std::print;
using std::println;

// flush
inline void flush() {
    std::fflush(stdout);
}

// printfl: print + flush
inline void printfl() {
    flush();
}

template <typename... Args>
void printfl(std::format_string<Args...> fmt, Args&&... args) {
    std::print(fmt, std::forward<Args>(args)...);
    flush();
}

// get_line
inline std::string get_line() {
    std::string s;
    std::getline(std::cin, s);
    auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

// msg_line: printfl then get_line
inline std::string msg_line() {
    printfl();
    return get_line();
}

template <typename... Args>
std::string msg_line(std::format_string<Args...> fmt, Args&&... args) {
    printfl(fmt, std::forward<Args>(args)...);
    return get_line();
}
