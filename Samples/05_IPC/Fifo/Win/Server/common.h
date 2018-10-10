#pragma once

const char *pipename = "\\\\.\\pipe\\test_pipe";

struct message 
{
	int id;
	SYSTEMTIME starttime;
};