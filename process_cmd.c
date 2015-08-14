/*
 * process_cmd.c
 *
 *  Created on: Aug 14, 2015
 *      Author: root
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "process_cmd.h"

int cmd_print(int argc, char ** argv);
int cmd_var(int argc, char ** argv);

static const cmd_t cmd_data[] =
{
	{"print", cmd_print},
	{"var", cmd_var},
};

static var_t var_list[16];
static int var_count = 0;
int cmd_var(int argc, char ** argv)
{
	var_t * x = &(var_list[var_count]);
	char * eq;
	int i = 0;
	var_count ++ ;
	eq = strstr(argv[0], "=");
	if (eq)
	{
		*eq = '\0';
		strcpy(x->name, argv[0]);
		strcpy(x->value.s, eq + 1);
	}
	else
	{
		strcpy(x->name, argv[0]);
		strcpy(x->value.s, argv[2]);
	}
	return 1;
}

var_t * is_var(char * name)
{
	int i =0;
	for (i =0; i < var_count; i ++)
	{
		if (!strcmp(var_list[i].name, name))
			return &var_list[i];
	}
	return 0;
}
int cmd_print(int argc, char ** argv)
{
	int i = 0;
	var_t* x = is_var(argv[0]);
	if (x)
	{
		printf("%s = %s\r\n", x->name, x->value.s);
	}
	else
	{
		for (i = 0; i < argc; i++)
		{
			printf("[%d] %s ", i, argv[i]);
		}
	}
	printf("\r\n");

	return i;
}
int process_cmd(int argc, char** argv)
{
	int i = 0;
	for (i = 0; i < sizeof(cmd_data) / sizeof (cmd_t); i++)
	{
		if (!strcmp(cmd_data[i].cmd, argv[0]))
			return cmd_data[i].handler(argc - 1, argv + 1);
	}
	return 0;
}
