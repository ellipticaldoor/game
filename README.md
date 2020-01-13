# Scripts
```sh
make run
```

# Testing
```sh
# Run all tests
make test

# Filter tests
./scripts/test.sh your_filter_keyword_here
```

# macOS install

```sh
# Dependencies
brew install sdl2 sdl2_image sdl2_ttf
# Tooling
brew install gdb pkg-config llvm
ln -s "$(brew --prefix llvm)/bin/clang-format" "/usr/local/bin/clang-format"
ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
```

# Install catch2 for testing
```
git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
```
