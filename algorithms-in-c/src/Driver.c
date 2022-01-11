#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Headers/Driver.h"
#include "Headers/Internal/AlgorithmOptions.h"
#include "Helpers/Headers/PrintHelpers.h"

Driver Initialize()
{
	Driver driver =
	{
		.Run = Run,
		.PrintHelp = PrintHelp,
		.RunTypeSelection = RunTypeSelection,
		.GetInformation = GetInformation
	};

	return driver;
}

void Run()
{
	char selection = 'q';
	do
	{
		printf(
			"                         *** Algorithm Type Selection ***\n\n" \
			"\t1) Search Algorithms\n" \
			"\t2) Sort Algorithms\n"\
			"\tQ) Quit"
			"\n\n\tEnter Selection > ");
		
		selection = getchar();
		RunTypeSelection(tolower(selection));

	} while (tolower(selection) != 'q');

}

void PrintHelp()
{

}

void RunTypeSelection(char selection)
{
	if (selection != '1' && selection != '2' && selection != 'q')
	{
		PrintError("Invalid selection");
		return false;
	}
}

void GetInformation(Algorithm selection)
{

}