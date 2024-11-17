#include <stdio.h>
#include <stdlib.h> //Added required libraries.



int main(int argc, char *argv[]) { //Start of the main function with usual arguments, which were also used in other programs in the project.


    if (2>argc) {

        printf("my-unzip: file1 [file2 ...]\n");
        exit(1); //Exit with code 1 if less than 2 arguments.
    }

    int iter;
    for (iter = 1; argc> iter; iter++) { //Argument iteration loop (index 0 is just the program name).

        FILE *currFilePointer = fopen(argv[iter], "rb"); //Opening the file, although this time in read binary mode.

        if (NULL == currFilePointer) {

            printf("my-unzip: cannot open file\n");
            exit(1); //If unable to open the file, exit with code 1.
        }



        int i;
        char character;
//fread usage, as recommended from project instructions learned here https://www.geeksforgeeks.org/fread-function-in-c/.

        while (fread(&i, sizeof(int), 1, currFilePointer) == 1) { //The first loop that reads the integer values stored as binary in the file.
                                                                  //=1 means that exactly one integer was successfully read.
        
            if (fread(&character, sizeof(char), 1, currFilePointer) != 1) {
                // Read the character value, at the same time handling error if character cannot be read

                printf("Unable to read the character.\n");

                break;
            }


            int j;
            for (j = 0; j < i; j++) { //Loop for printing a character i times, since the consecutive number of the character is specified
                                      // by the number.

                printf("%c", character);//Printing the character i times. Integer is not printed because it just shows the number of consecutive
                                        // characters.
            }
        }



        fclose(currFilePointer);//Closing the file after it was read.
    }

    return 0; //Successful program run, end with code 0.
}
