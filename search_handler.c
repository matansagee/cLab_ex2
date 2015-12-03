#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "search_handler.h"
#include <getopt.h>
#include <unistd.h>


void CpyExpWithOutBackslash(char* dest, char* src);
LineAndExpStruct* CheckCaseRoundParentheses(char* line, char* exp_to_search);
LineAndExpStruct* CheckCaseSquareParentheses(char* line, char* exp_to_search);

SearchCasesStruct* InitSearchStruct()
{
	SearchCasesStruct *new_search;
	new_search = (SearchCasesStruct*)malloc(sizeof(SearchCasesStruct));

	if (new_search ==NULL)
		return NULL;

	new_search->case_a = INACTIVE;
	new_search->case_a_number = INACTIVE; 
	new_search->case_b = INACTIVE; 
	new_search->case_c = INACTIVE; 
	new_search->case_e = INACTIVE; 
	new_search->case_i = INACTIVE; 
	new_search->case_n = INACTIVE; 
	new_search->case_x = INACTIVE;  
	new_search->case_v = INACTIVE;
	return new_search;  
}

void ArgHandler(SearchCasesStruct* search,int argc, char* argv[])
{
	int c;
	while ( (c = getopt(argc, argv, "A:abcinvxE")) != -1) 
	{
		switch (c) {
			case 'A':
				search->case_a = ACTIVE;
				search->case_a_number = atoi(optarg);
				break;
			case 'b': search->case_b = ACTIVE;break;
			case 'c': search->case_c = ACTIVE;break;
			case 'i': search->case_i = ACTIVE;break;
			case 'n': search->case_n = ACTIVE;break;
			case 'v': search->case_v = ACTIVE;break;
			case 'x': search->case_x = ACTIVE;break;
			case 'E': search->case_e = ACTIVE;break;
			default:exit(0);
		}
	}
}

char* GetLine(FILE *file)
{
	char *string=NULL; 
	size_t zero=0;
	if(-1 != getline (&string,&zero, file) )
	{
		return string;
	}
	return NULL;
}

void StringToLower(char *str)
{
	int i;
	if (str == NULL)
		return;
	for (i = 0;str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}

int ReturnSizeOfExp(char* exp_to_search, char stop_sign)
{
	int exp_counter = 0;
	for (exp_to_search; *exp_to_search != stop_sign ; exp_to_search++)
		exp_counter++;
	return exp_counter;
}

void CpyExp(char* exp_dest, char* exp_src, int with_backslash)
{
	if (with_backslash)
	{
		strcpy(exp_dest, exp_src);		
	}
	else
		CpyExpWithOutBackslash(exp_dest, exp_src);		
}

char* CpyExpBySign(char* exp_dest, char* exp_src, char stop_sign)
{
	int size_of_first_exp = 0;
	size_of_first_exp = ReturnSizeOfExp(exp_src, stop_sign);
	strncpy(exp_dest, exp_src, size_of_first_exp);
	exp_dest[size_of_first_exp] = '\0';
	exp_src += (size_of_first_exp + 1);
	return exp_src;
}

void CpyExpWithOutBackslash(char* dest, char* src)
{
	for (src; *src != '\0' ;src++)
	{
		if (*src == '\\')
			src++;
		*dest = *src;
		dest++;
	}
	*dest = '\0';
}

void PrintLine (char* line,SearchCasesStruct *search_cases_struct,LineProperties *line_properties)
{
	if(!search_cases_struct->case_c)
	{
		if(line_properties->case_a_print == FALSE )
		{
			if(CheckIfLastLineCase_aPrinted(search_cases_struct, line_properties))
				printf("--\n");
			if(search_cases_struct->case_n)
				printf("%d:",line_properties->line_number);
			if (search_cases_struct->case_b)
				printf("%d:",line_properties->count_bytes);
			printf("%s",line);
		}
		else
		{
			if(search_cases_struct->case_n)
				printf("%d-",line_properties->line_number);
			if (search_cases_struct->case_b)
				printf("%d-",line_properties->count_bytes);
			printf("%s",line);
		}
	}
}

int CheckIfLastLineCase_aPrinted(SearchCasesStruct* search_cases_struct, LineProperties* line_properties)
{
	int line_num = 0;
	line_num = search_cases_struct->case_a_number + line_properties->last_match_line+1;
	if(search_cases_struct->case_a && 
	  (line_properties->case_a_num == 0) && 
	  (line_properties->not_first_match==TRUE) && 
	  (line_properties->line_number != line_num))
		return TRUE;
	else
		return FALSE;	
}

LineProperties* CreateNewLineStruct()
{
	LineProperties *new_line;
	new_line = (LineProperties*)malloc(sizeof(LineProperties));

	if (new_line ==NULL)
		exit(0);

	new_line->line_number=0;
	new_line->count_bytes=0; 
	new_line->case_a_print=FALSE; 
	new_line->not_first_match=FALSE; 
	new_line->case_a_num=0;
	new_line->last_match_line=0; 
	return new_line; 
}

void ReadFile(FILE *file,SearchCasesStruct *search_cases_struct,char* pattern_to_search)
{
	char *line = GetLine(file);
	int count_matches_in_file = 0;
	LineProperties *line_properties;
	line_properties = CreateNewLineStruct();
	
	while(line != NULL)
	{
		line_properties->line_number++;	
		if (IsMatchInLine(line,search_cases_struct,pattern_to_search))
		{
			line_properties->case_a_print=FALSE;		
			PrintLine(line,search_cases_struct,line_properties);	
			count_matches_in_file++;
			line_properties->case_a_num = search_cases_struct->case_a_number;
			line_properties->not_first_match=TRUE;
			line_properties->last_match_line=line_properties->line_number; 
		}
		else if (line_properties->case_a_num != 0)
		{
			line_properties->case_a_print=TRUE;
			PrintLine(line,search_cases_struct,line_properties);
			line_properties->case_a_num--;
		}
		line_properties->count_bytes += strlen(line);
		line=GetLine(file);
	}
	if(search_cases_struct->case_c)
		printf("%d\n",count_matches_in_file);		
}

int IsMatchInLine(char* line,SearchCasesStruct *search_cases_struct,char *pattern_to_search)
{
	char *temp_line= (char*) malloc(strlen(line)*sizeof(char));
	char *pattern_to_compare=(char*) malloc(strlen(pattern_to_search)*sizeof(char));
	char *line_to_compare;
	int found_pattern_inline = FALSE;
	CpyExp(pattern_to_compare,pattern_to_search, search_cases_struct->case_e);
	CpyExp(temp_line, line, 0);
	line_to_compare = strtok(temp_line,"\n");
	if(search_cases_struct->case_i)
	{
		StringToLower(line_to_compare);
		StringToLower(pattern_to_compare);
	}
	if(line_to_compare == NULL)
		found_pattern_inline = FALSE;
	else
		found_pattern_inline = SearchInLine(line_to_compare,pattern_to_compare, search_cases_struct->case_e);
	if (search_cases_struct->case_x && found_pattern_inline != 0 && !search_cases_struct->case_e)
	{
		found_pattern_inline = strcmp(line_to_compare,pattern_to_compare) ? FALSE : TRUE;
	}
	if (search_cases_struct->case_v)
		return (found_pattern_inline == TRUE)? FALSE : TRUE;
	return found_pattern_inline;
}

int SearchInLine(char* line, char* pattern_to_search, int case_e)
{
	if(case_e)
	{
		return SearchInLineCaseE(line, pattern_to_search) ;
	}
	return (strstr(line,pattern_to_search) != NULL);
}

int SearchInLineCaseE(char* line, char* exp_to_search)
{
	int counter = 1;
	int stop_loop = strlen(line);
	for(counter; counter <= stop_loop; counter++)
	{		
		if(SearchAtStartLineCaseE(line, exp_to_search))
			return TRUE;
		line++;
	}
	return FALSE;
}

int SearchAtStartLineCaseE(char *line, char *exp_to_search)
{
	LineAndExpStruct *line_exp_struct;
	
	if (*exp_to_search == '.'){	
		exp_to_search++; line++;
	}
		
	if (*exp_to_search == '\0')
		return TRUE;
	else if (*exp_to_search == '(')
	{	
		line_exp_struct = CheckCaseRoundParentheses(line, exp_to_search);
		if (line_exp_struct != NULL)	{
			line = line_exp_struct->line;
			exp_to_search = line_exp_struct->exp_to_search;
			return SearchAtStartLineCaseE(line,exp_to_search);
		}
		else
			return FALSE;
	}
	else if (*exp_to_search == '[')
	{
		line_exp_struct = CheckCaseSquareParentheses(line, exp_to_search);
		if (line_exp_struct != NULL)	{
			line = line_exp_struct->line;
			exp_to_search = line_exp_struct->exp_to_search;
			return SearchAtStartLineCaseE(line,exp_to_search);
		}
		else
			return FALSE;
	}
	else
	{
		if (*exp_to_search == '\\')
			exp_to_search++;
		if (*line == *exp_to_search){
			line++; exp_to_search++;
			return SearchAtStartLineCaseE(line,exp_to_search);
		}
		else
			return FALSE;
	}
}

LineAndExpStruct* CheckCaseRoundParentheses(char* line, char* exp_to_search)
{
	LineAndExpStruct *line_exp_struct = (LineAndExpStruct*)malloc(sizeof(LineAndExpStruct));
	char* exp_first = (char*)malloc(sizeof(char));
	char* exp_second = (char*)malloc(sizeof(char));
	if (exp_first == NULL || exp_second == NULL || line_exp_struct == NULL)
		return NULL;

	exp_to_search++;
	exp_to_search = CpyExpBySign(exp_first, exp_to_search, '|');
	exp_to_search = CpyExpBySign(exp_second, exp_to_search, ')');

	if (SearchAtStartLineCaseE(line,exp_first))
	{	
		line += strlen(exp_first);
		line_exp_struct->line = line;
		line_exp_struct->exp_to_search = exp_to_search;
		return line_exp_struct;
	}
	else if(SearchAtStartLineCaseE(line,exp_second))
	{
		line += strlen(exp_second);	
		line_exp_struct->line = line;
		line_exp_struct->exp_to_search = exp_to_search;
		return line_exp_struct;
	}
	else 
		return NULL;
}

LineAndExpStruct* CheckCaseSquareParentheses(char* line, char* exp_to_search)
{
	char min_range, max_range;
	LineAndExpStruct* line_exp_struct = (LineAndExpStruct*)malloc(sizeof(LineAndExpStruct));
	if(line_exp_struct == NULL)
		return NULL;

	exp_to_search++;
	min_range = *exp_to_search; 	exp_to_search += 2;
	max_range = *exp_to_search;	exp_to_search += 2;
		
	if(*line >= min_range && *line <= max_range)
	{
		line++;
		line_exp_struct->line = line;
		line_exp_struct->exp_to_search = exp_to_search;
		return line_exp_struct;
	}
	else
		return NULL;
}



