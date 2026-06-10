# Compiler and flags
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -pedantic -std=c11 -O2 -Iinclude
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Directory structure
SRCDIR   := src
INCDIR   := include/ds
OBJDIR   := obj
DEPDIR   := $(OBJDIR)/.deps
BINDIR   := bin

# Target executable or library name
TARGET   := $(BINDIR)/libds.a

# Source, object, and dependency files
SRCS     := $(wildcard $(SRCDIR)/*.c)
OBJS     := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS     := $(SRCS:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

# Default rule
all: $(TARGET)

# Rule to link/create the static library
$(TARGET): $(OBJS) | $(BINDIR)
	ar rcs $@ $^

# Rule to compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@

# Create required directories on the fly
$(OBJDIR) $(DEPDIR) $(BINDIR):
	mkdir -p $@

# Clean up build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Include automatically generated dependency files
$(DEPS):
-include $(DEPS)

.PHONY: all clean

