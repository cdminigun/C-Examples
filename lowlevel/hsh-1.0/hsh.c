/*
### hsh.c written by Christopher Doege. ###
### Shell emulation written in C utilizing dup2, forks aned piping. ###
*/
#include <stdio.h>     // Standard IO for printf and perror
#include <stdlib.h>    // Standard library for base functions.
#include <string.h>    // String library for string manipulation.
#include <unistd.h>    // Low level IO and forking functions.
#include <sys/types.h> // Includes type definitions for extended vocab
#include <sys/stat.h>  // Defines variables for stat, ftstat, lstat and chmod.
#include <sys/fcntl.h> // Includes definitions for file control, read & write permissions and extended definitions
#define BUFSZ 1024

struct cmd
{
    int redirect_in; /* Any stdin redirection? */
    int redirect_out; /* Any stdout redirection? */
    int redirect_append; /* Append stdout redirection? */
    int background; /* Put process in background? */
    int piping; /* Pipe prog1 into prog2? */
    char *infile; /* Name of stdin redirect file */
    char *outfile; /* Name of stdout redirect file */
    char *argv1[10]; /* First program to execute */
    char *argv2[10]; /* Second program in pipe */
}command;

int main(void){
    char buf[BUFSZ];
    int fd[2];
    int fd_file_in;
    int fd_file_out;
    int writePermissions;    // Stores the permissions for file creation
    pid_t pid;               // Stores the pid
    while(fgets(buf, BUFSZ, stdin))
    {
        if(strcmp(buf, "exit\n") == 0) // Base exit case
            exit(0);
        if(cmdscan(buf, &command) == -1)
        {
            printf("Illegal Format: \n");
            continue;
        }
        switch(pid = fork())
        {
            case -1:
                perror("An error occured while forking.");
                exit(-1);
            case 0:
                if(command.background)
                {
                    switch(fork())
                    {
                        case -1:
                            perror("An error occured while forking.");
                            exit(-1);
                        case 0:
                            break;
                        default:
                            exit(0);
                    }
                }
                break;
            default:
                waitpid(pid, NULL, 0);
        }

        // Check for child / grandchild
        if(pid == 0)
        {
            if(command.redirect_in)
            {
                if((fd_file_in = open(command.infile, O_RDONLY, 0600)) == -1)
                {
                    perror("An open error occured.");
                    exit(-1);
                }

                if((dup2(fd_file_in, STDIN_FILENO)) == -1)
                {
                    perror("An error occured with dup2.");
                    exit(-1);
                }
                close(fd_file_in);
            }
            if(command.redirect_out)
            {
                if(command.redirect_append)
                    writePermissions = O_WRONLY | O_CREAT | O_APPEND;
                else
                    writePermissions = O_WRONLY | O_CREAT | O_TRUNC;

                if((fd_file_out = open(command.outfile, writePermissions, 0666)) == -1)
                {
                    perror("An open error occured.");
                    exit(-1);
                }
                dup2(fd_file_out, STDOUT_FILENO);
                close(fd_file_out);
            }
            // If the piping is turned on, we want to pipe, dup the fd
            // for the appropriate redirection, and execute the cmd
            if(command.piping)
            {
                if(pipe(fd) == -1)
                {
                    perror("An error occured while opening the pipe.");
                    exit(-1);
                }

                switch(fork())
                {
                    case -1:
                        perror("An error occured while forking.");
                        exit(-1);
                    case 0: // Child
                        dup2(fd[1], STDOUT_FILENO);
                        close(fd[1]);
                        close(fd[0]);
                        execvp(command.argv1[0], command.argv1);
                        perror("Exec Error");
                        exit(-1);
                    default: // Parent
                        dup2(fd[0], STDIN_FILENO);
                        close(fd[0]);
                        close(fd[1]);
                        execvp(command.argv2[0], command.argv2);
                        perror("An error occured during execution.");
                        exit(-1);
                }
            }
            execvp(command.argv1[0], command.argv1);
            perror("An error occured during execution.");
            exit(-1);
        }
    }
    //Never reached.
}
