CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic
OUTPUT_DIR = bin

all: $(OUTPUT_DIR)/array $(OUTPUT_DIR)/cyclic_ll $(OUTPUT_DIR)/mem $(OUTPUT_DIR)/NodeStruct

$(OUTPUT_DIR)/array: array.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/array array.c

$(OUTPUT_DIR)/cyclic_ll: cyclic_ll.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/cyclic_ll cyclic_ll.c

$(OUTPUT_DIR)/mem: mem.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/mem mem.c

$(OUTPUT_DIR)/NodeStruct: NodeStruct.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/NodeStruct NodeStruct.c

.PHONY: clean array mem NodeStruct

array: $(OUTPUT_DIR)/array
cyclic_ll: $(OUTPUT_DIR)/cyclic_ll
mem: $(OUTPUT_DIR)/mem
NodeStruct: $(OUTPUT_DIR)/NodeStruct

clean:
	@rm -rf $(OUTPUT_DIR)
	@mkdir $(OUTPUT_DIR)
