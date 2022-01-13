#ifndef SIEVE_H
#define SIEVE_H

#include <stdbool.h>
#include "Internal/AlgorithmInformation.h"

typedef struct _Sieve
{
	bool(*Run)(int);
	void(*PrintInformation)(AlgorithmInformation*);
	AlgorithmInformation Information;
} Sieve;

Sieve InitSieve();
bool RunSieve(int);
void PrintSieveInformation(AlgorithmInformation*);
void DisposeSieve(Sieve*);

#endif