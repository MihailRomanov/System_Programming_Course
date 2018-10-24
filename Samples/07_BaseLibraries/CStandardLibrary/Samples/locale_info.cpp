#include <cstdio>
#include <locale.h>


void locale_info()
{
	printf("locale: %s\n", setlocale(LC_ALL, NULL));
	printf("%f\n", 12.5);

	printf("locale: %s\n", setlocale(LC_ALL, "ru_RU.utf-8"));
	printf("%f\n", 12.5);

	lconv *l = localeconv();
		
	printf("%s %s\n", l->currency_symbol, l->decimal_point);
	
}