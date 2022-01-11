#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Headers/Driver.h"
#include "Headers/Internal/AlgorithmOptions.h"
#include "Headers/Internal/PrintHelpers.h"

Driver Initialize()
{
	Driver driver =
	{
		.Run = _Run,
		.PrintHelp = _PrintHelp,
		.RunTypeSelection = _RunTypeSelection,
		.GetInformation = _GetInformation
	};

	return driver;
}

void _Run()
{
	char selection = 'q';
	do
	{
		printf(
			"                         *** Algorithm Type Selection ***\n\n" \
			"\t1) Search Algorithms\n" \
			"\t2) Sort Algorithms\n" \
			"\tH) Help"
			"\tQ) Quit"
			"\n\n"\
			"\tEnter Selection > ");
		
		selection = getchar();
		_RunTypeSelection(tolower(selection));

	} while (tolower(selection) != 'q');

}

void _PrintHelp()
{

}

void _RunTypeSelection(char selection)
{
	switch (selection)
	{
		case '1':
			break;
		case '2':
			break;
		case 'h':
			break;
		case 'q':
			break;
	}
	if (selection != '1' && selection != '2' && selection != 'q')
	{
		PrintError("Invalid selection");
	}
}

void _GetInformation(Algorithm selection)
{

}