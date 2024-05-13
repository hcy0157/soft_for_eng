#include <stdio.h>
#include <stdlib.h>
#include "wordquiz.h"


int get_command() {
	int cmd ;

	printf(">") ;
	scanf("%d", &cmd) ;
	return cmd ;
}

int main ()
{
	
	printf(" *** Word Quiz *** \n\n") ;

	int cmd ;
	do {
		print_msdenu() ;

		cmd = get_command() ;
		switch (cmd) {
			case C_LIST : {
				list_wordbooks() ;
				break ;
			}

			case C_SHOW: {
				show_words() ;
				break ;
			}

			case C_TEST: {
				run_test() ;
				break ;
			}

			case C_EXIT: {
				return EXIT_SUCCESS ;
			}
		}
	}
	while (cmd != C_EXIT) ;


	return EXIT_SUCCESS ;
}
