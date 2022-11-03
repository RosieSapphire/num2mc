#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"

int32_t main(int32_t argc, char **argv) {
	uint64_t input_a;
	uint64_t input_b = 0;

	if(!argc) {
		fprintf(stderr, "%sSomething seriously wrong has occured for this "
				"to be showing up...\n%s", COLOR_RED, COLOR_DEFAULT);
		return 1;
	}

	if(argc < 2) {
		fprintf(stderr, "%sPlease specify number of blocks or number of "
				"stacks and remainder.%s\n", COLOR_RED, COLOR_DEFAULT);
		return 1;
	}

	input_a = atoi(argv[1]);
	if(argc > 3) {
		fprintf(stderr, "%sToo many arguments", COLOR_RED);
		if(!input_a || !input_b) {
			fprintf(stderr, ", and invalid input. Please try again");
		}
		fprintf(stderr, ".%s\n", COLOR_DEFAULT);
		return 1;
	}

	switch(argc) {
		case 2:
			if(!input_a) {
				fprintf(stderr, "%sInvalid input. Please try again.%s\n",
						COLOR_RED, COLOR_DEFAULT);
				return 1;
			}

			printf("%sFor %s%lu%s, you need %s%lu%s stacks, "
					"with %s%lu%s left over.\n%s",
					COLOR_YELLOW, COLOR_GREEN, input_a, COLOR_YELLOW,
					COLOR_GREEN, input_a / 64, COLOR_YELLOW, COLOR_GREEN,
					input_a % 64, COLOR_YELLOW, COLOR_DEFAULT);
			break;

		case 3:
			input_b = atoi(argv[2]);
			if(!input_a) {
				fprintf(stderr, "%sInvalid input (1). Please try again.%s\n",
						COLOR_RED, COLOR_DEFAULT);
				return 1;
			}

			if(!input_b && *argv[2] - '0') {
				fprintf(stderr, "%sInvalid input (2). Please try again.%s\n",
						COLOR_RED, COLOR_DEFAULT);
				return 1;
			}

			printf("%sFor %s%lu%s stacks and %s%lu%s remaining, you need "
					"%s%lu%s blocks.%s\n",
					COLOR_YELLOW, COLOR_GREEN, input_a, COLOR_YELLOW,
					COLOR_GREEN, input_b, COLOR_YELLOW, COLOR_GREEN,
					input_a * 64 + input_b, COLOR_YELLOW, COLOR_DEFAULT);
			break;

		default:
			fprintf(stderr, "%sIllegal state achieved. WTF did you do?\n%s",
					COLOR_RED, COLOR_DEFAULT);
			return 1;
	}

	return 0;
}
