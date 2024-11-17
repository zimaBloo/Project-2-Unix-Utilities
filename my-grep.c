#include <stdio.h>
#include <stdlib.h> //Including required libraries. 

#include <string.h> //Found this library to search for substrings in a string (strstr). Found here: https://www.geeksforgeeks.org/c-library-string-h/.


void grepAlgorithm(char *searchVar2, FILE *userInp2) { //The actual algorithm for my-grep. Takes the search variable, and user input in case if no file specified,
                                                       // or the specified file name.

    char *singLine = NULL;                             //Pointer of the arbitraly long line.
    size_t singLineLen = 0;                            //After trying to find how to implement the functionality of analysing arbitrary long
                                                       // lines, it was understood that its possible to use size_t data type to achieve the
                                                       // result. This website helped: https://pvs-studio.com/en/blog/terms/0044/#:~:text=size_t-,Feb%2006%202023,possible%20array%20or%20an%20object. 
 

    while (-1 != getline(&singLine, &singLineLen, userInp2)) { //Reads stdin or file line by line in a loop.
                                                               //THe -1 loop exit condition was learned here: https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-getline-read-entire-line-from-stream.

        if (NULL != strstr(singLine, searchVar2)) { //Returns pointer to first occurence of searched string, or NULL if absent. Got the ide of this
                                                    // kind of implementation here: https://www.ibm.com/docs/en/i/7.4?topic=functions-strstr-locate-substring.

            printf("%s", singLine); //Printing out the buffer with the same way that was recommended in the instructions for my-cat.c.
        }
    }
}



int main(int argc, char *argv[]) { //Similarly to my-cat.c, main function has arguments for argument number and vector. 
                                   //(https://www.ibm.com/docs/en/i/7.4?topic=functions-main-function)



    if (2>argc) {
        printf("my-grep: searchterm [file ...]\n");
    
        exit(1);                 //If there are less than 2 arguments, exits with code 1 and shows user how the program should be used.
    }



    char *searchVariable = argv[1];


    if (2 == argc) {              //Check whether there are precisely 2 arguments.
        printf("Type your text. Press enter to search for the keyword in the input. (Ctrl+C to finish):\n");

        FILE *userInput = stdin; //If 2 argumentss, read from stdin.
        grepAlgorithm(searchVariable, userInput); //Call grep search algorithm with search term and user input as arguments.


    } else { //If there are more than 2 arguments, read from given files.

        int iter;
        int ArgcNum = argc; //Initializing iteration variable and number of arguments.
        
        for (iter = 2; iter < ArgcNum; iter++) { //Iterating through arguments, starting from 2 because argument 0 is program name, argument 1
                                                 // is search term, and starting from argument 2 are file names.

            FILE *currFile = fopen(argv[iter], "r"); //Opening file in read mode, as in my-cat.


            if (NULL == currFile) {

                printf("my-grep: cannot open file\n");

                exit(1);                             //If a file cannot be opened, informing the user and exiting with code 1.
            }

            grepAlgorithm(searchVariable, currFile); //Calling grep algorithm with search term and file name arguments. Since it is in a for- loop,
                                                     // it will iterate through all given file names and print resutls.



            fclose(currFile);                        //Closing the file.
        }

    }

    return 0;                                        //In all successful cases, program exits with code 0, as said in the instructions.
}
