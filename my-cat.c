#include <stdio.h>
#include <stdlib.h> //Including required libraries for the program to function, memory management, etc.


int main(int argc, char *argv[]) { //Main function initiated with arguments for "argument count" and "argument vector". 
                                   //Insights into the usage of this learned here: https://www.ibm.com/docs/en/i/7.4?topic=functions-main-function
                                   //Argument count displays the number of arguments passed for the program, to determine
                                   // if no files are specified in the command line. Char argument vector is a set of pointers
                                   // to the strings passed as arguments. Learned here: https://computer.howstuffworks.com/c38.htm#:~:text=The%20char%20*argv%5B%5D%20line,first%20character%20of%20the%20string).

    if (2>argc) return 0; //If number of arguments is <2, program exits and returns 0.


    int arg;
    for (arg = 1; arg < argc; arg++) { //Iterating upon all the arguments in command line (since the requirements ask for the program
                                 // to be called even if multiple files are written in command line). We start with i = 1 because
                                 // the first argument is just the name of our program.


        FILE *ourFile = fopen(argv[arg], "r"); //Opening the file, "r" stands for read mode. Learned on Principles of C-Programming course,
                                               // but revised here: https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm.
        
        
        if (NULL == ourFile) {

            printf("my-cat: cannot open file\n"); //If the file is invalid or cannot be opened, the program exits with code 1.
            exit(1);
        }


        char buff[5000]; //Initialied a buffer of an arbitrary value of 5000 characters.

        char *line = fgets(buff, sizeof(buff), ourFile); //Points to the first character of the read line in the earlier created buffer.
        while (NULL !=line) {

            printf("%s", buff); //Got a hint how to do this in the project instructions.


            line = fgets(buff, sizeof(buff), ourFile); //Line is updated with the next thing.
        }

        fclose(ourFile); //Closing the file. Not a necessary step, but on the Principles of C-Programming course I was taught that it would
                         // help in avoiding memory leaks.
    }

    return 0; //Successful finish of the program with code 0.
}
