#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "wordquiz.h"

void list_wordbooks ()
{

	DIR * d = opendir("wordbooks") ;
	
	printf("\n  ----\n") ;

	struct dirent * wb ;
	while ((wb = readdir(d)) != NULL) {
		if (strcmp(wb->d_name, ".") != 0 && strcmp(wb->d_name, "..") !=0) {
			printf("  %s\n", wb->d_name) ;
		}
	}
	closedir(d) ;

	printf("  ----\n") ;
}