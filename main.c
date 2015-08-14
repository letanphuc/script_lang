/*
 * main.c
 *
 *  Created on: Aug 14, 2015
 *      Author: root
 */

#include "stdio.h"
#include "stdlib.h"
#include "process_cmd.h"

int get_line(char * line){
	int tmp = 0;
	int count = 0;
	printf("> ");
	while (1){
		tmp = getchar();
		if (tmp == '\n' || tmp == '\r')
			break;
		line[count]  = (char) tmp;
		count ++;
	}
	line[count] = '\0';
	return count;
}

int parse_line(char * line, int * argc, char ** argv)
{
#define skipspace(x) while ((*x == ' ' || *x == '\t') && (*x != '\0')) x++
#define skipchar(x) while (*x != ' ' && *x != '\t' && *x != '\0') x++

	*argc = 0;
	while (1)
	{
		skipspace(line);
		argv[*argc] = line;
		(*argc)++ ;
		skipchar(line);
		if (*line == '\0')
			break;
		*line = '\0';
		line ++;
	}
	return *argc;
}


int main(int argc, char **argv) {
	char line [128];
	int c = 0;
	int i = 5;
	char * v[32];

	while (i -- )
	{
		get_line(line);
		parse_line(line, &c, v);
		process_cmd(c, v);
	}


	return 0;
}

