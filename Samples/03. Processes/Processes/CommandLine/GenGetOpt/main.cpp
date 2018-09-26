#include <cstdio>
#include <stdlib.h>
#include "cmdline.h"

int main(int argc, char *argv[])
{
	gengetopt_args_info args_info;

	if (cmdline_parser(argc, argv, &args_info) != 0)
		exit(-1);

	if (args_info.count_given)
		printf("Count %d", args_info.count_arg);

	if (args_info.wait_given)
		printf("Wait %d", args_info.wait_flag);

	return 0;
}