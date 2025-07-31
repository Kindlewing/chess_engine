CC := clang
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN := $(BUILD_DIR)/main

# Default flags
CFLAGS := -Wall -Wextra -Werror -pedantic -I$(INC_DIR)
DEBUG_FLAGS := -g
RELEASE_FLAGS := -O2

# Sources and objects
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
.PHONY: all
all: release

# --- Release and Debug builds ---
.PHONY: release debug
release: CFLAGS += $(RELEASE_FLAGS)
release: $(BIN)
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BIN)

# --- Linking ---
$(BIN): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@

# --- Compiling ---
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# --- Dependency files ---
-include $(OBJS:.o=.d)

.PHONY: run
run:
	./$(BIN)

# --- Clean up ---
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
