#ifndef __SEARCH_HANDLER_H
#define __SEARCH_HANDLER_H

#define TRUE 1
#define FALSE 0
#define ACTIVE 1
#define INACTIVE 0

typedef struct SearchCasesStruct
{
	int case_a;
	int case_a_number;
	int case_b;
	int case_c;
	int case_e;
	int case_i;
	int case_n;
	int case_x;
	int case_v;
} SearchCasesStruct;

typedef struct LineProperties
{
	int line_number;
	int count_bytes;
	int case_a_print;
	int not_first_match;
	int case_a_num;
	int last_match_line;
	
}LineProperties;

typedef struct LineAndExpStruct
{
	char* line;
	char* exp_to_search;

}LineAndExpStruct;

SearchCasesStruct* InitSearchStruct();
void ArgHandler(SearchCasesStruct* search,int argc, char* argv[]);
void ReadFile(FILE *file,SearchCasesStruct *search_cases_struct,char* pattern_to_search);



#endif

