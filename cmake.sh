
if [ $# -ne 0 ]; then
    cd $1

    cmake -S . -B .target -G Ninja &&
    cmake --build .target &&

    if [ $# -eq 1 ]; then
        .target/bin/_
    else
        .target/bin/$2
    fi
fi
