TARGET_EXEC := chess

BUILD_DIR := ./build
SRC_DIRS := ./src
INC_DIRS := ./include
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CC=gcc
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CFLAGS=$(INC_FLAGS) -Wall -Wextra -std=c99 -MMD

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)

