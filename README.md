# Simple Shell

##Tasks
1. 0. Betty would be proud
Write a beautiful code that passes the Betty checks

2. 1. Simple shell 0.1
Write a UNIX command line interpreter.
* Usage: simple_shell

Your Shell Should
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)

3. 2. Simple shell 0.2
Simple shell 0.1 +
* Handle command lines with arguments

4. 3. Simple shell 0.3
Simple shell 0.2 +
* Handle the PATH
* fork must not be called if the command doesn’t exist

5. 4. Simple shell 0.4
Simple shell 0.3 +
* Implement the exit built-in, that exits the shell
* Usage: exit
* You don’t have to handle any argument to the built-in exit

6. 5. Simple shell 1.0
Simple shell 0.4 +
* Implement the env built-in, that prints the current environment

7. 6. Simple shell 0.1.1
Simple shell 0.1 +
* Write your own getline function
* Use a buffer to read many chars at once and call the least possible the read system call
* You will need to use static variables
* You are not allowed to use getline
You don’t have to:
* be able to move the cursor

8. 7. Simple shell 0.2.1
Simple shell 0.2 +
* You are not allowed to use strtok

9. 8. Simple shell 0.4.1
Simple shell 0.4 +
* handle arguments for the built-in exit
* Usage: exit status, where status is an integer used to exit the shell

10. 9. setenv, unsetenv
Simple shell 1.0 +
Implement the setenv and unsetenv builtin commands
* setenv
** Initialize a new environment variable, or modify an existing one
** Command syntax: setenv VARIABLE VALUE
** Should print something on stderr on failure
* unsetenv
** Remove an environment variable
** Command syntax: unsetenv VARIABLE
** Should print something on stderr on failure

11. 10. cd
Simple shell 1.0 +
Implement the builtin command cd:
* Changes the current directory of the process.
* Command syntax: cd [DIRECTORY]
* If no argument is given to cd the command must be interpreted like cd $HOME
* You have to handle the command cd -
* You have to update the environment variable PWD when you change directory

2list.c
environment_var.c
main.h
path_parser.c
string_handling2.c
atoi.c
handle_error.c
mani_history.c
ptr_memory.c
string_handling.c
builtins_2.c
handle_input1.c
mani_info.c
read_input.c
string_mani.c
builtins.c
handle_input2.c
mani_list.c
token_generator.c
env_func.c
main.c
mem.h
shell_loop.c
variables.c
