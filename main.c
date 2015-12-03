#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "search_handler.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
	FILE *file;
	char *pattern_to_search;
	SearchCasesStruct *search_cases_struct;
	
	if (argc == 1)
		return 1;

	file=fopen(argv[argc-1],"r");
	if (file ==NULL)
	{
		file = stdin;
		pattern_to_search = argv[argc-1];
	}
	else
	{	
		pattern_to_search = argv[argc-2];
	}
	
	search_cases_struct = InitSearchStruct();
	
	ArgHandler(search_cases_struct,argc,argv);
	
	ReadFile(file,search_cases_struct,pattern_to_search);
	
	fclose(file);
}
