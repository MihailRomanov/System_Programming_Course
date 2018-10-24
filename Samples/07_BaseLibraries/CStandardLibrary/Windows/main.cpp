#include <cstdio>
#include "samples.h"
#include <Windows.h>

int main()
{
	UINT console_cp = GetConsoleCP();
	UINT console_out_cp = GetConsoleOutputCP();

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
		
	//string_declaration();
	//win_wide_to_mb();
	//string_operations();
	//string_conversions();

	//time_operations();
	//
	locale_info();

	SetConsoleCP(console_cp);
	SetConsoleOutputCP(console_out_cp);

	return 0;
}