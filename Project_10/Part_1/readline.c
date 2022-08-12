/*
Hanz Chua
U26738740
Source file for read_line function
*/
#include <stdio.h>
#include <ctype.h>

#include "readline.h"		//includes readline header file

int read_line(char str[], int n) {		//readline function
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;    
	}
	str[i] = '\0';
	return i;
}
