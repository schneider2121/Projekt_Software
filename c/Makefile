BUILD_DIR := build

.PHONY: build test clean check

build:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

test: build
	ctest --test-dir $(BUILD_DIR) --output-on-failure

clean:
	rm -rf $(BUILD_DIR)

check:
	cppcheck --enable=all --error-exitcode=1 --suppress=missingIncludeSystem src/