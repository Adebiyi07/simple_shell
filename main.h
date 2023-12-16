#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>

extern char **environ;

#define BUFFER_SIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */

/**
 * struct my_c_shell -  structure for global shell
 * @args: argument parameters
 * @error_msg: for the global path
 * @cmd: the parsed command line
 * @index:  command index
 * @line: inputed line
 * @oldpwd: old path
 * @env: the environnment
 *
 * Description: variables used to manage the program
 */

typedef struct my_c_shell
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;

/**
 * struct builtin -  handles and manages builtins
 * @cmd: the command line
 * @f:  associated functions
 *
 * Description: struct for builtin command line
 */

typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *myshell);
} blt_t;


int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int process_cmd(sh_t *);

void shell_exit(char **args);
void myprompt(void);
char *path_g(void);

int terminate_program(sh_t *myshell);
int help_display(sh_t *myshell);
int builtin_handler(sh_t *myshell);
int check_builtin(sh_t *myshell);

int setenv_s(char **args);
int unsetenv_s(char **args);
char *get_input(void);
void input_f(void);
void *gets_line(void);
void shell_exit(char **args);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int free_data(sh_t *);
int print_error(sh_t *);
int _atoi(char *c);
int write_history(sh_t *myshell);
char *get_env(char *path_name);

void error_f(char **argv, char *arg);
void tokens_f(char **ptr);
void paths_f(void);
int is_path_form(sh_t *myshell);
int is_builtin(sh_t *myshell);


int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_memset(char *s, char byt, unsigned int n);
void is_short_form(sh_t *myshell);
void index_cmd(sh_t *myshell);
void signal_handler(int signo);
char *_strdup(char *str);

#endif
