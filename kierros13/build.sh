#!/bin/bash
output_file="main"
source_files=(  *.cpp
                src/*.cpp
                src/shapes/*.cpp)

outside_dependencies="E:/coding/libraries/lodepng/lodepng.cpp"

flags="-Wno-narrowing"

g++ -o "$output_file" "${source_files[@]}" "${flags[@]}"

if [ $? -eq 0 ]; then
    echo "Build successful."
    echo "Running $output_file..."
    (cd "$(dirname "$0")" && ./"$output_file")
else
    echo "Build failed."
fi