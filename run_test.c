#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordquiz.h"

void run_test ()
{
	char wordbook[128] ;
	char filepath[256] ;

	printf("Type in the name of the wordbook?\n") ;
	printf(">") ;
	scanf("%s", wordbook) ;

	sprintf(filepath, "wordbooks/%s", wordbook) ;

	FILE * fp = fopen(filepath, "r") ;

	printf("\n-----\n") ;

	int n_questions = 0 ;
	int n_correct = 0 ; 

	char * line ;
	while (line = read_a_line(fp)) {
		char * word = strtok(line, "\"") ;
		strtok(NULL, "\"") ;
		char * meaning = strtok(NULL, "\"") ;

		printf("Q. %s\n", meaning) ;
		printf("?  ") ;

		char answer[128] ;
		scanf("%s", answer) ;

		if (strcmp(answer, word) == 0) {
			printf("- correct\n") ;
			n_correct++ ;
		}
		else {
			printf("- wrong: %s\n", word) ;
		}

		n_questions++ ;
		free(line) ;
	}

	printf("(%d/%d)\n", n_correct, n_questions) ;

	printf("-----\n\n") ;

	fclose(fp) ;
}

