#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/Sieve.h"
#include "Headers/Internal/AlgorithmInformation.h"
#include "Headers/Internal/PrintHelpers.h"


Sieve InitSieve()
{
	Sieve sieve =
	{
		.Run = RunSieve,
		.PrintInformation = PrintSieveInformation
	};

	sieve.Information = GetNewAlgorithmInfo();
	strcpy(sieve.Information.Name, "Sieve of Eratosthenes");
	strcpy(sieve.Information.Runtime, "O(N Log(N))");
	strcpy(sieve.Information.Caveats, "Find all primes from [2, N].");

	return sieve;
}

bool RunSieve(int upperLimit)
{
	if (upperLimit <= 1)
	{
		char* msg = (char*)calloc(250, sizeof(char));
		sprintf(msg, "Invalid upper limit: %i", upperLimit);
		PrintError(msg);
		free(msg);
		return false;
	}

	int* primes = (int*)calloc(upperLimit, sizeof(int));
	for (int i = 2; i < upperLimit; i++)
	{
		primes[i] = 1;
	}

	for (int i = 2; i < upperLimit; i++)
	{
		if (primes[i])
		{
			for (int j = i; i * j < upperLimit; j++)
			{
				primes[i * j] = 0;
			}
		}
	}

	for (int i = 2; i < upperLimit; i++)
	{
		if (primes[i])
		{
			printf("%4d ", i);
		}
	}

	printf("\n");
	free(primes);

	return true;
}

void PrintSieveInformation(AlgorithmInformation* info)
{
	PrintAlgorithmInformation(info);
}

void DisposeSieve(Sieve* sieve)
{
	DisposeAlgorithmInformation(&sieve->Information);
}