CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic
OUTPUT_DIR = bin

all: $(OUTPUT_DIR)/array $(OUTPUT_DIR)/cyclic_ll 

$(OUTPUT_DIR)/array: array.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/array array.c

$(OUTPUT_DIR)/cyclic_ll: cyclic_ll.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/cyclic_ll cyclic_ll.c

$(OUTPUT_DIR)/cyclic_ll: cyclic_ll.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/cyclic_ll cyclic_ll.c

.PHONY: clean array cyclic_ll

array: $(OUTPUT_DIR)/array $(OUTPUT_DIR)/cyclic_ll

clean:
	@rm -rf $(OUTPUT_DIR)
	@mkdir $(OUTPUT_DIR)
