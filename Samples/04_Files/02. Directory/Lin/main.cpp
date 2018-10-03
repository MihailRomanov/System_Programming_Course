#include <dirent.h>
#include <cstdio>


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid argument count\n");
		return 1;
	}

	DIR *dir;
	dirent *entry;

	dir = opendir(argv[1]);

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
	return 0;
}