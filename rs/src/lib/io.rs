
use std::io::{stdin, stdout, Write};

// flush
pub fn flush() {
    stdout().flush().unwrap();
}

// printfl: print + flush
#[macro_export]
macro_rules! printfl {
    () => {
        $crate::flush();
    };
    ($($arg:tt)+) => {{
        std::print!($($arg)+);
        $crate::flush();
    }};
}

// get_line
pub fn get_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

// msg_line: printfl then get_line
#[macro_export]
macro_rules! msg_line {
    ($($arg:tt)*) => {{
        $crate::printfl!($($arg)*);
        $crate::get_line()
    }};
}
