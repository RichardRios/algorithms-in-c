#ifndef ALGORITHM_INFORMATION_H
#define ALGORITHM_INFORMATION_H

#define		NAME_LEN		250
#define		RUNTIME_LEN		50
#define		CAVEAT_LEN		1000

typedef struct _AlgorithmInformation
{
	char* Name;
	char* Runtime;
	char* Caveats;

} AlgorithmInformation;

AlgorithmInformation GetNewAlgorithmInfo();
void DisposeAlgorithmInformation(AlgorithmInformation*);

#endif
