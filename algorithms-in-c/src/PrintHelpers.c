#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/Internal/PrintHelpers.h"

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
	// Remove newline to avoid duplicating newlines
	if (strchr(msg, '\n') != NULL)
	{
		msg[strlen(msg) - 1] = '\0';
	}

	// Get length of both strings
	int newMsgLen = (int)(strlen(msg) + strlen(indicator) + 1);
	char* newMsg = (char*)calloc(newMsgLen, sizeof(char));

	if (newMsg == NULL) { return; }

	strncpy(newMsg, indicator, strlen(indicator));
	strncat(newMsg, msg, strlen(msg));
	printf("%s\n", newMsg);
	
	free(newMsg);
}

void PrintAlgorithmInformation(AlgorithmInformation* info)
{
	char* str = (char*)calloc(CAVEAT_LEN, sizeof(char));
	
	sprintf(str, "Algorithm: %s\n", info->Name);
	PrintInformation(str);

	sprintf(str, "Runtime: %s\n", info->Runtime);
	PrintInformation(str);

	sprintf(str, "Caveats: %s", info->Caveats);
	PrintInformation(str);

	free(str);
}

