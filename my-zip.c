#include <stdio.h>
#include <stdlib.h>  //Required libraries.



int main(int argc, char *argv[]) { //Start of the main function with usual arguments, which were also used in other programs in the project.
    
    #define TRUE 1
    #define FALSE 0
    #define fileEnd -1      //Constannts for later use in the program.
    char chNow, chBefore;
    int counter, iter;         //Varable initialization for later use in the program.
    
    if (2>argc) {

        printf("my-zip: file1 [file2 ...]\n");
        exit(1); //Exit with code 1 if less than 2 arguments.
    }


    for (iter = 1; iter < argc; iter++) { //Iterating arguments, starting from 1, since index 0 is the program name.

        FILE *fileLoc = fopen(argv[iter], "r"); //Opening file of the iteration index in read mode.

        if (NULL == fileLoc) {

            printf("my-zip: cannot open file\n");
            exit(1); //If unable to open the file, exit with code 1.
        }                      //Checked that the program has the right conditions to initiate zipping. Code after this line 
                               //starts the zipping process.




        counter = 0;

        chBefore = fgetc(fileLoc); //First file character reading. Made sure of correct usage here: https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
        
        switch (chBefore) { //If the file is empty, we go to the next file.
            case fileEnd: {
                fclose(fileLoc);
                continue;
            }
            default:
                break;        //Since handling multiple files is possible in this program, if the file is empty, we go to the next file.
        }

        counter = 1;


        while ((chNow = fgetc(fileLoc)) != fileEnd) { //Loop start to read characters from a file until the file ends.
            
            switch ((int)(chNow == chBefore)) {

                case TRUE: {//KEY PROGRAM PART: If the character is the same as the last one, counter increases, to later produce
                           // the zipped values.
                    counter++;
                    break;

                }
                case FALSE: { //Character is different compared to the last one.

                    int numSize = sizeof(int);
                    int charSize = sizeof(char);
                    fwrite(&counter, numSize, 1, stdout); //INDEX0: pointer to data to be written, I1:size in bytes, 
                                                          // I2: number of elements to write, I3: destination pointer.
                    fwrite(&chBefore, charSize, 1, stdout); //Writing the zipped values to the standard output, as explicitly specified in
                                                            // the instructions.

                    chBefore = chNow;
                    counter = 1; //Next character reached, counter reset.

                    break;
                }
            }
        }

        int numSize2 = sizeof(int);   //Handling the last character.
        int charSize2 = sizeof(char);

        fwrite(&counter, numSize2, 1, stdout);
        fwrite(&chBefore, charSize2, 1, stdout); //With fwrite() we write the integer value as a binary value and the character as ASCII in the
                                                 // standard output.

        fclose(fileLoc); // Closing the file.
    }

    return 0; // Exit successfully, program ends with code 0.
}