CC = gcc
WARNINGS = -Wall
MAIN_SOURCE = main.c
SHARED_SOURCES = linked_list.h linked_list.c hash_functions.h hash_functions.c hash_table.h hash_table.c
BUILD_DIR = ./build

TEST_SOURCE_FILENAMES = test_linked_list.h test_linked_list.c test_runner.c test_utils/utils.h test_utils/utils.c test_hash_table.h test_hash_table.c
TEST_SOURCES = $(patsubst %,tests/%,$(TEST_SOURCE_FILENAMES))


hash_table: $(MAIN_SOURCE) $(SHARED_SOURCES)
	$(CC) $(WARNINGS) -g -o $(BUILD_DIR)/main $(MAIN_SOURCE) $(SHARED_SOURCES)

test: $(SHARED_SOURCES) $(TEST_SOURCES)
	$(CC) $(WARNINGS) -g -o $(BUILD_DIR)/tests/run_tests $(SHARED_SOURCES) $(TEST_SOURCES)

clean:
	find build/ -type f ! -name ".gitignore" -delete
