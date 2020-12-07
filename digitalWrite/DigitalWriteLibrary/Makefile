SRC_DIR=./src
CODE_DIR=$(SRC_DIR)/code
OUT=main
TEST_DIR=tests
INC=-I/usr/local/Cellar/avr-gcc/9.1.0/avr/include/ -I./src/code/digitalWrite.h
 
test:
	make -C $(TEST_DIR)
 
test_clean:
	make -C $(TEST_DIR) clean
 
digitalWrite.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/digitalWrite.cpp -o $(CODE_DIR)/digitalWrite.o
 
main: digitalWrite.o
	gcc -I$(CODE_DIR) $(CODE_DIR)/digitalWrite.o $(INC) $(SRC_DIR)/main.cpp -o $(OUT)
 
all: test main
 
clean: test_clean
	rm $(SRC_DIR)/*.o $(CODE_DIR)/*.o $(OUT)

flash: 
	avr-gcc -c -Wall -Os -mmcu=atmega328p -DF_CPU=16000000UL $(INC) $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o
	avr-gcc -Wall -Os -mmcu=atmega328p -DF_CPU=16000000UL $(SRC_DIR)/main.o -o $(SRC_DIR)/main.elf
	avr-objcopy -j .text -j .data -O ihex $(SRC_DIR)/main.elf $(SRC_DIR)/main.hex
	avrdude -v -patmega328p -carduino -b115200 -P /dev/tty.usbmodem1431301 -D -Uflash:w:$(SRC_DIR)/main.hex:i