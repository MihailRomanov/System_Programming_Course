#include <stdio.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Not valid argument count");
		return 1;
	}

	WIN32_FIND_DATAA fileData;

	HANDLE search = FindFirstFileA(argv[1], &fileData);

	if (search != INVALID_HANDLE_VALUE)
	{
		do
		{
			printf("%s %u\n", fileData.cFileName, fileData.nFileSizeLow);

		} while (FindNextFileA(search, &fileData));

		FindClose(search);
	}
}