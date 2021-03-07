ARCH ?= x86#预配置编译环境

SCR_DIR=sourceA sourceB #确认源文件的文件夹

INC_DIR=includes#确认头文件的文件夹

SCRS=$(foreach var,$(SCR_DIR),$(wildcard $(var)/*.c))

BUILD_DIR=build_$(ARCH)#确认可重定位文件的文件夹（需要自行建立）

OBJS=$(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SCRS))) #确认可重定位文件的名称

TARGET=mp3	#确认目标文件名称

INC=$(foreach var,$(INC_DIR),$(wildcard $(var)/*.h)) #确认头文件名称

vPATH=$(patsubst %,-I %,$(INC))

ifeq ($(ARCH),x86)
CC=gcc
else
CC=arm-linux-gnueabihf-gcc
endif

$(BUILD_DIR)/$(TARGET):$(OBJS)# | $(INC)
#	$(CC) $(OBJS) -o $(TARGET)   # $(vPATH)

#$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c | create_build
$(BUILD_DIR)/%.o:
#	TEMP=%
#	TEM=$(foreach var,$(SRC_DIR),$(wildcard $(var)/$(TEMP).c))
#echo "$(TEMP)"
#	$(CC) -c $(TEM) -o $@

.PHONY:prin create_build

prin:
#	echo "$(BUILD_DIR)"
#	echo "$(OBJS)"


create_build:
	mkdir -p $(BUILD_DIR)



