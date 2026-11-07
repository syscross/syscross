
if [ $# -ne 0 ]; then
    if [ $# -eq 1 ]; then
        cargo run --manifest-path $1/Cargo.toml
    else
        cargo run --manifest-path $1/Cargo.toml --bin $2
    fi
fi
