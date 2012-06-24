#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "libircclient.h"
#include <unistd.h>
#include <stdbool.h>
#include "bot.h"

struct sqlite3* Database;
char* Server;
char* UserName;
char* Channel;
char* Passwort;

bool Daemon, Help;

int main(int argc, char** argv)
{
	ParseOptions(argc, argv);
	printf("%s, %s, %s, %s, %i", Server, UserName, Channel, Passwort, Daemon);
	if(Help)
		return 0;
}

void ParseOptions(int argc, char** argv)
{
	int opt = 0;

	while((opt = getopt(argc, argv, "C:D::H::P:S:U:c:d::h::p:s:u:")) != -1)
	{
		switch(opt)
		{
			case 'C': Channel = optarg; break;
			case 'D': Daemon = true; break;
			case 'H': Hilfe(); break;
			case 'P': Passwort = optarg; break;
			case 'S': Server = optarg; break;
			case 'U': UserName = optarg; break;

			case 'c': Channel = optarg; break;
			case 'd': Daemon = true; break;
			case 'h': Hilfe(); break;
			case 'p': Passwort = optarg; break;
			case 's': Server = optarg; break;
			case 'u': UserName = optarg; break;
		}
	}
}

void Hilfe()
{
	Help = true;
	printf("Hilfe fuer benoetigte Felder.\n");
	printf("\t-c irc Channel	Beispiel: -c 'MeinChannel'\n");
	printf("\t-s irc Server		Beispiel: -s irc.MeinServer.net\n");
	printf("\t-u irc UserName	Beispiel: -u Chu\n\n");
	printf("\t-d Den irc nicht als Daemon starten!\n");
	printf("\t-h Diese Nachricht erneut anzeigen.\n");
}

void Mondae()
{
	pid_t pid, sid;
	if(getppid() == 1) 
		return;

	pid = fork();
	if(pid < 0)
		exit (1);

	if(pid > 0)
		exit (0);

	umask(0);

	sid = setsid();
	if(sid < 0)
		exit(1);

	if((chdir("/") < 0))
		exit(1);

	freopen("/dev/null", "r", stdin);
	freopen("/dev/null", "w", stdout);
	freopen("/dev/null", "w", stderr);
}
