EXECUTABLE := main    # 可执行文件名
LIBDIR:=              # 静态库目录
LIBS :=               # 静态库文件名
INCLUDES:=./ojlib/    # 头文件目录
SRCDIR:=              # 除了当前目录外，其他的源代码文件目录

### Now alter any implicit rules' variables if you like, e.g.:

CC:=g++
CFLAGS := -g -Wall -O3 -std=c++11
CPPFLAGS := $(CFLAGS)
CPPFLAGS += $(addprefix -I,$(INCLUDES))
CPPFLAGS += -MMD

RM-F := rm -f

SRCS := $(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.cpp,$(MISSING_DEPS)))

.PHONY : all deps objs clean veryclean rebuild info

all: $(EXECUTABLE)

deps: $(DEPS)

objs: $(OBJS)

clean :
	@$(RM-F) *.o
	@$(RM-F) *.d
	@$(RM-F) $(EXECUTABLE)

veryclean : clean
	@$(RM_F) $(EXECUTABLE)

rebuild: verclean all
ifneq ($(MISSION_DEPS),)

$(MISSING_DEPS):
	@$(RM-F) $(patsubst %.d,%.o,$@)
endif
-include $(DEPS)
$(EXECUTABLE) : main.o
	$(CC) -o $(EXECUTABLE) $(CFLAGS) $(CPPFLAGS) main.cpp

info:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
	@echo $(MISSING_DEPS)
	@echo $(MISSING_DEPS_SOURCES)
