#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wordquiz.h"

// Declare the read_a_line function


void command(char *wordbook){
	printf("1. Add other words in %s\n", wordbook);
	printf("2. Edit words in %s\n", wordbook);
	printf("3. Exit\n");
	printf("\n") ;
	printf(">") ;

}

void add_words(char *filepath, FILE *fp, char *wordbook){
	

	char meaning[40]; 
	char words[20];
	int count = 0;
	fp = freopen(filepath, "r", fp); 
	do{	
		printf("Input words : ");
		scanf("%s", words);
		printf("Input its meaning : ");
		scanf(" %[^\n]", meaning);

		count = 0;
		char * line ;
		while (line = read_a_line(fp)) {
			printf("count : %d\n", count);
			char * f_word = strtok(line, "\"") ;
			strtok(NULL, "\"") ;
			strtok(NULL, "\"") ;
			printf("%s", f_word);
			if(strcmp(f_word, words) == 0){
				count++;
				printf("There is a same word\n\n");
			}

			free(line);
		}
		
	}while(count != 0);


	fp = freopen(filepath, "a+", fp);
	if (fp == NULL) {
		printf("Failed to open file\n");
		return;
	}
	
	fprintf(fp, "\"%s\" \"%s\"\n", words, meaning);
}

void edit_words(FILE *fp, char *wordbook){
	printf("this is edit words\n");
}

void show_words ()
{
	char wordbook[128] ;
	char filepath[256] ;

	list_wordbooks() ;

	printf("Type in the name of the wordbook?\n") ;
	printf(">") ;
	scanf("%s", wordbook) ;

	sprintf(filepath, "wordbooks/%s", wordbook) ;

	FILE * fp = fopen(filepath, "r") ;

	printf("\n  -----\n") ;
	char * line ;
	while (line = read_a_line(fp)) {
		char * word = strtok(line, "\"") ;
		strtok(NULL, "\"") ;
		char * meaning = strtok(NULL, "\"") ;

		printf("  %s : %s\n", word, meaning);

		free(line);
	}
	printf("  -----\n\n") ;

	int cmd;
	do{
		command(wordbook);
		scanf("%d", &cmd);
		switch (cmd){
			case 1: {
				add_words(filepath,fp, wordbook);
				break;
			}
			case 2:{
				edit_words(fp, wordbook);
				break;
			}
			case 3: {
				break;
			}
			default:{
				printf("It is an incorrect input\n");
				break;
			}
		}

	}while(cmd != 3);

	fclose(fp) ;
}