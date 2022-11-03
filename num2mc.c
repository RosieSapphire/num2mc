#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"

int32_t main(int32_t argc, char **argv) {
	uint64_t blocks_input;

	if(!argc) {
		fprintf(stderr, "%sSomething seriously wrong has occured for this "
				"to be showing up...\n%s", COLOR_RED, COLOR_DEFAULT);
		return 1;
	}

	if(argc < 2) {
		fprintf(stderr, "%sPlease specify number of blocks.%s\n",
				COLOR_RED, COLOR_DEFAULT);
		return 1;
	}

	blocks_input = atoi(argv[1]);
	if(argc > 2) {
		fprintf(stderr, "%sToo many arguments", COLOR_RED);
		if(!blocks_input) {
			fprintf(stderr, ", and invalid input. Please try again");
		}
		fprintf(stderr, ".%s\n", COLOR_DEFAULT);
		return 1;
	}

	if(!blocks_input) {
		fprintf(stderr, "%sInvalid input. Please try again.%s\n",
				COLOR_RED, COLOR_DEFAULT);
		return 1;
	}
	printf("%sFor %s%lu%s, you need %s%lu%s stacks, "
			"with %s%lu%s left over.\n%s",
			COLOR_YELLOW, COLOR_GREEN, blocks_input, COLOR_YELLOW, COLOR_GREEN,
			blocks_input / 64, COLOR_YELLOW, COLOR_GREEN, blocks_input % 64,
			COLOR_YELLOW, COLOR_DEFAULT);

	return 0;
}
