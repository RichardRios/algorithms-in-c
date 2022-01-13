#include <stdlib.h>
#include "Headers/Internal/AlgorithmInformation.h"

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

void DisposeAlgorithmInformation(AlgorithmInformation* info)
{
	free(info->Name);
	free(info->Runtime);
	free(info->Caveats);
}