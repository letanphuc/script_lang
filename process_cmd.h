/*
 * process_cmd.h
 *
 *  Created on: Aug 14, 2015
 *      Author: root
 */

#ifndef PROCESS_CMD_H_
#define PROCESS_CMD_H_

typedef struct
{
	char * cmd;
	int (*handler)(int, char**);
} cmd_t;

enum
{
	VAR_TYPE_INT,
	VAR_TYPE_STR,
};

typedef struct
{
	char name[16];
	int type;
	union
	{
		int i;
		char s[64];
	} value;
} var_t;

int process_cmd(int argc, char**argv);

#endif /* PROCESS_CMD_H_ */
