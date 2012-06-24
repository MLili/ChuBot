#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "libircclient.h"
#include <unistd.h>

struct sqlite3* Database;
char* Server;
char* UserName;
char* Channel;

int main(int argc, char** argv)
{
	ParseOptions(argc, argv);
	printf("%s, %s, %s", Server, UserName, Channel);
}

void ParseOptions(int argc, char** argv)
{
	int opt = 0;

	while((opt = getopt(argc, argv, "C:D::H::S:U:c:d::h::s:u:")) != -1)
	{
		switch(opt)
		{
			case 'C': Channel = optarg; break;
			case 'D': break;
			case 'H': break;
			case 'S': Server = optarg; break;
			case 'U': UserName = optarg; break;

			case 'c': Channel = optarg; break;
			case 'd': break;
			case 'h': break;
			case 's': Server = optarg; break;
			case 'u': UserName = optarg; break;
		}
	}
}
