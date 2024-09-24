CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic
OUTPUT_DIR = bin

all: $(OUTPUT_DIR)/average $(OUTPUT_DIR)/pointers $(OUTPUT_DIR)/appendTest $(OUTPUT_DIR)/arrCopy


$(OUTPUT_DIR)/average: average.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/average average.c

$(OUTPUT_DIR)/pointers: pointers.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/pointers pointers.c

$(OUTPUT_DIR)/appendTest: appendTest.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/appendTest appendTest.c

$(OUTPUT_DIR)/arrCopy: arrCopy.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/arrCopy arrCopy.c

.PHONY: clean average pointers appendTest arrCopy

average: $(OUTPUT_DIR)/average
pointers: $(OUTPUT_DIR)/pointers
appendTest: $(OUTPUT_DIR)/appendTest
arrCopy: $(OUTPUT_DIR)/arrCopy

clean:
	@rm -rf $(OUTPUT_DIR)
	@mkdir $(OUTPUT_DIR)
