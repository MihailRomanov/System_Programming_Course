#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <uchar.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <errno.h>

void print_hex(void* buf, int size)
{
	char *cbuf = (char *)buf;
	while (size-- > 0)
	{
		int digit = (int)*cbuf;
		printf("%02X ", digit);
		cbuf++;
	}
}

void string_declaration()
{
	char ch = 'a';
	wchar_t wch = L'a';
	char16_t ch16 = u'a';
	char32_t ch32 = U'a';

	printf("char (%zd): ", sizeof(ch));
	print_hex(&ch, sizeof(ch));
	printf("\n");

	printf("wchar_t (%zd): ", sizeof(wch));
	print_hex(&wch, sizeof(wch));
	printf("\n");

	printf("char16_t (%zd): ", sizeof(ch16));
	print_hex(&ch16, sizeof(ch16));
	printf("\n");

	printf("char32_t (%zd): ", sizeof(ch32));
	print_hex(&ch32, sizeof(ch32));
	printf("\n");

	char str[] = "abc";
	wchar_t wstr[] = L"abc";
	char16_t str16[] = u"abc";
	char32_t str32[] = U"abc";

	printf("char str (%zd): ", sizeof(str));
	print_hex(&str, sizeof(str));
	printf("\n");

	printf("wchar_t str (%zd): ", sizeof(wstr));
	print_hex(&wstr, sizeof(wstr));
	printf("\n");

	printf("char16_t str (%zd): ", sizeof(str16));
	print_hex(&str16, sizeof(str16));
	printf("\n");

	printf("char32_t str (%zd): ", sizeof(str32));
	print_hex(&str32, sizeof(str32));
	printf("\n");


	char ch2 = '\x31';
	wchar_t wch2 = L'\u02A3';
	char16_t ch162 = u'\u02A3';
	char32_t ch322 = U'\U0001F600';

	printf("char: %c\n", ch2);
	printf("wchar: %lc\n", wch2);
	printf("\n");

	mbstate_t state;
	char buff[20];
	memset(&state, 0, sizeof(state));
	memset(&buff, 0, sizeof(buff));


	setlocale(LC_CTYPE, "ru_RU.utf-8");
	wcrtomb(buff, wch2, &state);
	printf("wcr to mb: %s \n", buff);

	memset(&state, 0, sizeof(state));
	c16rtomb(buff, ch162, &state);
	printf("c16 to mb: %s \n", buff);

	memset(&state, 0, sizeof(state));
	c32rtomb(buff, ch322, &state);
	printf("c32 to mb: %s \n", buff);

}


#ifdef _MSC_BUILD

#include <windows.h>
void win_wide_to_mb()
{
	wchar_t wch[] = L"\u02A3 | \U0001F600";
	char ch[100];


	WideCharToMultiByte(CP_UTF8, 0, wch, -1, ch, 100, NULL, NULL);

	printf("%s\n", ch);
}

#endif
