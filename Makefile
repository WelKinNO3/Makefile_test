ARCH ?= x86#预配置编译环境

SCR_DIR=sourceA#确认源文件的文件夹

INC_DIR=includes#确认头文件的文件夹

SCRS=$(foreach var,$(SCR_DIR),$(wildcard $(var)/*.c))

BUILD_DIR=build_$(ARCH)#确认可重定位文件的文件夹（需要自行建立）

OBJS=$(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SCRS))) #确认可重定位文件的名称

TARGET=open_file	#确认目标文件名称

INC=$(foreach var,$(INC_DIR),$(wildcard $(var)/*.h)) #确认头文件名称



#vPATH=$(patsubst %,-I %,$(INC))

ifeq ($(ARCH),x86)
CC=gcc
else
CC=arm-linux-gnueabihf-gcc
endif

$(BUILD_DIR)/$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET) 

$(BUILD_DIR)/%.o:$(SCR_DIR)/%.c | create_build 
	$(CC) -c $< -o $@

.PHONY:prin create_build

prin:
	echo "$(OBJS)"
	echo "$(SCR_DIR)"


create_build:
	mkdir -p $(BUILD_DIR)


