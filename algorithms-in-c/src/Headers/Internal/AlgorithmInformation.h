#ifndef ALGORITHM_INFORMATION_H
#define ALGORITHM_INFORMATION_H

#define		NAME_LEN		20
#define		RUNTIME_LEN		10
#define		CAVEAT_LEN		250

typedef struct _AlgorithmInformation
{
	char* Name;
	char* Runtime;
	char* Caveats;

} AlgorithmInformation;

#endif
