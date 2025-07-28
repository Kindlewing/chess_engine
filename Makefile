# Compiler and flags
CC := clang
CFLAGS := -Wall -Werror -Wpedantic -Wextra -Iinclude -Isrc -g

# Source and output definitions
SRCS := $(shell find src -name "*.c")
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

BIN := main

# Default target
all: $(BIN)

debug: $(CFLAGS) += 
debug: $(BIN)

# Link the binary
$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@

# Compile .c to .o with dependency tracking
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS)  -MMD -c $< -o $@

# Include dependency files if they exist
-include $(DEPS)

# Clean build output
clean:
	rm -rf build main



.PHONY: all clean
