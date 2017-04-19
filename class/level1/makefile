EXECUTABLE := main    # binary name
LIBDIR:=              # static library dir
LIBS :=               # static lib name 
INCLUDES:=.    		  # user defined header file dir
SRCDIR:=              # other src dir , beside current dir '.'

CC:=gcc
CFLAGS := -g -Wall -O2
CPPFLAGS := $(CFLAGS)
CPPFLAGS += $(addprefix -I,$(INCLUDES))
CPPFLAGS += -MMD

RM-F := rm -f

SRCS := $(wildcard *.c) $(wildcard $(addsuffix /*.c, $(SRCDIR)))
OBJS := $(patsubst %.c,%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.c,$(MISSING_DEPS)))


.PHONY : all deps objs clean veryclean rebuild info


all: $(EXECUTABLE)

deps: $(DEPS)

objs: $(OBJS)

clean :
	@$(RM-F) *.o
	@$(RM-F) *.d
	@$(RM-F) $(EXECUTABLE)

veryclean : clean
	@$(RM-F) $(EXECUTABLE)

rebuild: verclean all
ifneq ($(MISSING_DEPS),)

$(MISSING_DEPS):
	@$(RM-F) $(patsubst %.d,%.o,$@)
endif
-include $(DEPS)
$(EXECUTABLE) : $(OBJS)
	$(CC) -o $(EXECUTABLE) $(CFLAGS) $(CPPFLAGS) $(OBJS)

info:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(MISSING_DEPS)
	@echo $(MISSING_DEPS_SOURCES)
