#include <cstdio>
#include <stdlib.h>

void string_conversions()
{
	const char *int_str = "23 56 78     ";
	char *current, *end;

	long v1 = atol(int_str);
	printf("%d\n", v1);

	end = (char *)int_str;
	do {
		current = end;
		end = NULL;

		long value = strtol(current, &end, 10);
		if (current != end)
		{
			printf("%d\n", value);
		}
	} while (current != end);

}