
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <string_view>

inline constexpr auto null = nullptr;

using i8       = std::int8_t;
using i16      = std::int16_t;
using i32      = std::int32_t;
using i64      = std::int64_t;
using isize    = std::ptrdiff_t;

using u8       = std::uint8_t;
using u16      = std::uint16_t;
using u32      = std::uint32_t;
using u64      = std::uint64_t;
using usize    = std::size_t;

using f32      = float;
using f64      = double;

using char8    = char8_t;
using char16   = char16_t;
using char32   = char32_t;
using wchar    = wchar_t;

using string   = std::string;
using string8  = std::u8string;
using string16 = std::u16string;
using string32 = std::u32string;
using wstring  = std::wstring;

using str      = std::string_view;
using str8     = std::u8string_view;
using str16    = std::u16string_view;
using str32    = std::u32string_view;
using wstr     = std::wstring_view;
