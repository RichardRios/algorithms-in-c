#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/PrintHelpers.h"

void PrintInformation(char* msg)
{
	char* information = "[+] ";
	Print(information, msg);
}

void PrintWarning(char* msg)
{
	char* warning = "[-] ";
	Print(warning, msg);
}

void PrintError(char* msg)
{
	char* error = "[!] ";
	Print(error, msg);
}

void Print(char* indicator, char* msg)
{
	int newMsgLen = strlen(msg) + strlen(indicator) - 1;
	char* newMsg = (char*)malloc(sizeof(char) * newMsgLen);
	if (newMsg == NULL) { return; }

	strncpy(newMsg, indicator, strlen(indicator) - 1);
	strncat(newMsg, msg, strlen(msg) - 1);
	newMsg[newMsgLen - 1] = '\0';

	printf("%s", newMsg);

	if (msg[strlen(msg) - 1] != '\n')
	{
		printf("\n");
	}

	free(newMsg);
}