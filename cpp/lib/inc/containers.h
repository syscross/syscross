#pragma once

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <span>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <tuple>

using std::array;
using std::vector;
using std::deque;
using std::list;
using std::stack;
using std::queue;
using std::span;

using std::set;
using std::map;

using std::pair;
using std::tuple;

template <typename... T>
using vec = std::vector<T...>;

template <typename... T>
using hashset = std::unordered_set<T...>;

template <typename... T>
using hashmap = std::unordered_map<T...>;
