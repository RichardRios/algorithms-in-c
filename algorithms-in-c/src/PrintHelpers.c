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
	printf("\n\n\n");
	printf("Algorithm: %s\n", info->Name);
	printf("Runtime: %s\n", info->Runtime);
	printf("Caveats: %s\n", info->Caveats);
}

AlgorithmInformation GetNewAlgorithmInfo()
{
	AlgorithmInformation information =
	{
		.Name = (char*)calloc(NAME_LEN, sizeof(char)),
		.Runtime = (char*)calloc(RUNTIME_LEN, sizeof(char)),
		.Caveats = (char*)calloc(CAVEAT_LEN, sizeof(char))
	};

	return information;
}