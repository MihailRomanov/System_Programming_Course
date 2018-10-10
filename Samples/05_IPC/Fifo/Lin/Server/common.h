#pragma once
#include <time.h>

const char * fifoname = "/tmp/samle_fifo";

struct message
{
	int server_id;
	tm server_start;
};