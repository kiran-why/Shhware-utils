# utilities name (Brand names + standard GNU names)
UTILS		:= peek whisper tap erase where ls mkdir cp mv head
 
# directories
SRC_DIR 	:= src
UTIL_DIR 	:= $(SRC_DIR)/utils
INC_DIR 	:= $(SRC_DIR)/include
BUILD_DIR 	:= .build
TEST_DIR 	:= tests

# Install path (default: ~/.local/bin)
PREFIX		?= $(HOME)/.local
INSTALL_BIN	:= $(PREFIX)/bin

# include files
COMMON_SRCS	:= $(INC_DIR)/errors.c
COMMON_OBJS := $(COMMON_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# source files
UTIL_SRCS 	:= $(addprefix $(UTIL_DIR)/, $(addsuffix .c, $(UTILS)))
UTIL_OBJS	:= $(UTIL_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# path to compiled utils
TARGETS 	:= $(addprefix $(TEST_DIR)/, $(UTILS))

# objects and dependings
OBJS 		:= $(COMMON_OBJS) $(UTIL_OBJS)
DEPS        := $(OBJS:.o=.d)

# compiler and flags
CC 			:= gcc
CFLAGS		:= -Wall -Wextra -g
CPPFLAGS 	:= -I$(INC_DIR) -MMD -MP

# misc
RM 			:= rm -rf
MKDIR 		:= /bin/mkdir  # <--- ЖЕСТКО УКАЗЫВАЕМ СИСТЕМНЫЙ MKDIR
MAKEFLAGS 	+= --no-print-directory


# Recipes
all: $(TARGETS)

# build rule (builds every util separately)
# $@ - target name, $^ - all dependigs
$(TEST_DIR)/%: $(BUILD_DIR)/utils/%.o $(COMMON_OBJS)
	@$(MKDIR) -p $(@D) # <--- ИСПОЛЬЗУЕМ ПЕРЕМЕННУЮ
	$(CC) $(CFLAGS) $^ -o $@

# compiler rule (.c from src/ -> .o in .build/)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) -p $(@D) # <--- ИСПОЛЬЗУЕМ ПЕРЕМЕННУЮ
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Install rule (uses our own whisper instead of echo)
install: all
	@$(MKDIR) -p $(INSTALL_BIN)
	@./$(TEST_DIR)/whisper "Installing Shhware-Utils to $(INSTALL_BIN)..."
	@install -m 755 $(TARGETS) $(INSTALL_BIN)
	@./$(TEST_DIR)/whisper "Done! Make sure $(INSTALL_BIN) is in your PATH."

# Uninstall rule
uninstall:
	@if [ -f "./$(TEST_DIR)/whisper" ]; then \
		./$(TEST_DIR)/whisper "Removing Shhware-Utils from $(INSTALL_BIN)..."; \
	else \
		echo "Removing Shhware-Utils from $(INSTALL_BIN)..."; \
	fi
	@$(RM) $(addprefix $(INSTALL_BIN)/, $(UTILS))

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(TARGETS)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re install uninstall
