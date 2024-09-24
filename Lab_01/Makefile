CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic
OUTPUT_DIR = bin

all: $(OUTPUT_DIR)/punishment $(OUTPUT_DIR)/averages

$(OUTPUT_DIR)/punishment: punishment.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/punishment punishment.c


$(OUTPUT_DIR)/averages: averages.c
	@mkdir -p $(OUTPUT_DIR)
	@$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/averages averages.c


.PHONY: punishment averages clean

punishment: $(OUTPUT_DIR)/punishment

averages: $(OUTPUT_DIR)/averages

clean:
	@rm -f $(OUTPUT_DIR)/punishment $(OUTPUT_DIR)/averages