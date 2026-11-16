# utilities name
UTILS		:= peek whisper

# directories
SRC_DIR 	:= src
UTIL_DIR 	:= $(SRC_DIR)/utils
INC_DIR 	:= $(SRC_DIR)/include
BUILD_DIR 	:= .build

# include files
COMMON_SRCS	:= $(INC_DIR)/errors.c
COMMON_OBJS := $(COMMON_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# source files
UTIL_SRCS 	:= $(addprefix $(UTIL_DIR)/, $(addsuffix .c, $(UTILS)))
UTIL_OBJS	:= $(UTIL_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# objects and dependings
OBJS 		:= $(COMMON_OBJS) $(UTIL_OBJS)
DEPS        := $(OBJS:.o=.d)

# compiler and flags
CC 			:= gcc
CFLAGS		:= -Wall -Wextra -g
CPPFLAGS 	:= -I$(INC_DIR) -MMD -MP

# misc
RM 			:= rm -rf
MAKEFLAGS 	+= --no-print-directory


# Recipes
all: $(UTILS)

# build rule (builds every util separately)
# $@ - target name, $^ - all dependigs
$(UTILS): %: $(BUILD_DIR)/utils/%.o $(COMMON_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# compiler rule (.c from src/ -> .o in .build/)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # create .build/utils 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(UTILS)

re: fclean all

-include $(DEPS) # include generated dependings files

.PHONY: all clean fclean re
