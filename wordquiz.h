#include <stdio.h>
#ifndef WORDQUIZ_H
#define WORDQUIZ_H

typedef 
	enum {
		C_ZERO,
		C_LIST,
		C_SHOW,
		C_TEST,
		C_EXIT,
	}
	command_t ;

char * read_a_line (FILE * fp);

void print_msdenu();

int get_command();

void list_wordbooks ();

void show_words ();

void run_test ();


#endif