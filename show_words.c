#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wordquiz.h"

// Declare the read_a_line function
const int word_size = 32;
const int meaning_size = 64;

void command(char *wordbook){
	printf("1. Add other words in %s\n", wordbook);
	printf("2. Edit words in %s\n", wordbook);
	printf("3. Exit\n");
	printf("\n") ;
	printf(">") ;

}

void add_words(char *filepath, FILE *fp, char *wordbook){
	

	char meaning[meaning_size]; 
	char words[word_size];
	int count = 0;

	fp = freopen(filepath, "r", fp); 
	if (fp == NULL) {
		printf("Failed to open file\n");
		return;
	}

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

void edit_words(const char *filepath, FILE *fp) {
    fp = freopen(filepath, "r+", fp);
	FILE *tempFile = fopen("wordbooks/temp", "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
	char f_word[word_size];
    
	printf("Enter the word to edit : ");
	scanf("%s", f_word);
	
	int find = 0;
	char * line ;
	while (line = read_a_line(fp)) {
		char * word = strtok(line, "\"") ;
		strtok(NULL, "\"") ;
		char * meaning = strtok(NULL, "\"") ;

		
		if(strcmp(word, f_word) == 0){
			
			char new_word[word_size];
			char new_meaning[meaning_size];

			printf("Enter the new word : ");
			scanf("%s", new_word);
			printf("Enter the new meaning : ");
			scanf(" %[^\n]", new_meaning);

			char buffer[256];
			char current_word[128];
			fseek(fp, 0, SEEK_SET);
			while (fgets(buffer, sizeof(buffer), fp)) {
				sscanf(buffer, "\"%127s[^\"]", current_word);
				if(strncmp(current_word,word,sizeof(word)-1) == 0){
					fprintf(tempFile, "\"%s\" \"%s\"\n", new_word, new_meaning);
				}
				else{
					fputs(buffer, tempFile);
				}
			}
			
			find++;
		}
		
		free(line);
	}
    

    if (!find) {
        printf("Word not found.\n");
		fclose(fp);
		fclose(tempFile);
    }
	else{
		fclose(tempFile);
		fclose(fp);
		printf("%s\n", filepath);
		remove(filepath);
		rename("wordbooks/temp", filepath);
		printf("Word edited successfully.\n");

	}  

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
	printf("file : %s\n", filepath);
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
				edit_words(filepath, fp);
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