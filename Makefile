# system configuration

SHELL	:= /bin/sh

AR		:= ar
ARFLAGS	:= rcs

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
CPPFLAGS	:= -I.

MKDIR	:= mkdir -p
RMDIR	:= rm -rf
RM	:= rm -f

# project configuration

NAME	:= libftprintf.a 

SRCDIR	:= srcs
OBJDIR	:= objs
DEPDIR	:= deps

DEPFLAGS	= -MMD -MT $@ -MP -MF $(DEPDIR)/$*.d

SRCBASE	:= ft_printf ft_vprintf
SRCS	:= $(addprefix $(SRCDIR)/, $(addsuffix .c, $(SRCBASE)))
OBJS	:= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCBASE)))
DEPS	:= $(addprefix $(DEPDIR)/, $(addsuffix .d, $(SRCBASE)))

.SUFFIXES:

.PHONY:		all bonus clean fclean re

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(OBJS):	$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(DEPS):	;

$(OBJDIR) $(DEPDIR):	; $(MKDIR) $@

include $(DEPS)

clean:
	$(RMDIR) $(OBJDIR) $(DEPDIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all
