#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <sys/type.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **evniron;

/**
 * struct liststr - singly linked list
 * @num: num field
 * @str: string
 * @next: pointer to the next node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo- arguments
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path to the current command
 * @argc: argv count
 * @line_count: the error count
 * @err_num: the error code for exit()
 * @linecount_flag: l
 * @fname: the program file_name
 * @env: local copy of environ
 * @environ: modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ changed
 * @status: the return status of the last command
 * @cmd_buf: address of pointer to cmd_buf on if chaining
 * @cmd_buf_type: cmd_type &&, ||, ;
 * @readfd: fd to read input line from
 * @histcount: the history line number count
*/
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *
