///////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
// Used by permission, CS 354 Spring 2022, Deb Deppeler
////////////////////////////////////////////////////////////////////////////////
   
// add your own File Header information here
////////////////////////////////////////////////////////////////////////////////
// Main File:        myMagicSquare.c
// This File:        myMagicSquare.c
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Lecture 001 Fall 2022
// Instructor:       deppeler
//
// Author:           Wenpei Shao
// Email:            wshao33@wisc.edu
// CS Login:         wenpei
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure that represents a magic square
typedef struct {
    int size;           // dimension of the square
    int **magic_square; // pointer to heap allocated magic square
} MagicSquare;

/*
 * Prompts the user for the magic square's size, reads it,
 * checks if it's an odd number >= 3 (if not display the required
 * error message and exit), and returns the valid number.
 */
int getSize( ) {
    char input[10];
    int size = 0;

    // Prompt the user for the magic square's size.
    printf("Enter magic square's size (odd integer >=3)\n");
    fgets(input, 10, stdin);
    size = atoi(input);

    // Check if the number is valid.
    if (size < 3){
        if (size % 2 == 0){
            
            printf("Magic square size must be odd.\n");
            exit(1);

        } else {
            
        printf("Magic square size must be >= 3.\n");
        exit(1);

        }
    }
    if (size > 3 && size % 2 == 0){
        
        printf("Magic square size must be odd.\n");
        exit(1);

    }

    return size;
}
   
/*
 * Makes a magic square of size n using the alternate
 * Siamese magic square algorithm from assignment and
 * returns a pointer to the completed MagicSquare struct.
 *
 * n the number of rows and columns
 */
MagicSquare *generateMagicSquare(int n) {
    MagicSquare *ms = malloc(sizeof(MagicSquare));
    ms -> size = n;
    
    // Create a dynamicially allocated 2D array for size n*n asthe board.
    int **board= malloc(sizeof(int*) * n);
    

    int i=0;
    int j=0;
    while (i < n){
        *(board + i) = malloc(sizeof(int) * n);
        i++;
    }


    i=0;
    j=0;
    // Initialize the board with 0.
    while (i < n){
        while (j < n){
            *(*(board + i)+j) = 0;
            j++;
        }
        i++;
    }

    // Create the number which will be putted in the board.

     i = n / 2;
     j = n - 1;

    // Put numbers on the board.
    for (int number =1; number <= n*n; number++){
        *(*(board + i)+j) = number;
        i = i - 1;
        j = j + 1;

        if (i == -1 && j == n){
            
            i = 0;
            j = n - 2;
            
        } else if (i == -1 || j == n){
            
            if (i == -1){
                
                i = n-1;
                
            }
            if (j == n){
                
                j = 0;
                
            }
        } else if (*(*(board + i)+j) != 0){
            
            i = i + 1;
            j = j - 2;
            
        }

    }
    ms -> magic_square = board;

    return ms;
    
}

/*
 * Opens a new file (or overwrites the existing file)
 * and writes the square in the specified format.
 *
 * magic_square the magic square to write to a file
 * filename the name of the output file
 */
void fileOutputMagicSquare(MagicSquare *magic_square, char *filename) {
    // Open the file
    FILE *ofp = fopen(filename, "w");

    // Check if error exits in opening file.
    if (ofp == NULL) {
        
        printf("Cannot open file for reading\n");
        fclose(ofp);
        exit(1);
        
    }
    fprintf(ofp, "%i\n", magic_square->size);
    
    // Write the ouput into the file.
    int i=0;
    int j=0;
    while (i < magic_square->size){
        while (j < magic_square->size){
            if (j == 0){
                
                fprintf(ofp, "%i", *(*(magic_square->magic_square + i)+j));
                
            } else {
                
                fprintf(ofp, ",%i", *(*(magic_square->magic_square + i)+j));
                
            }
            j++;
        }
        fprintf(ofp, "\n");
        i++;
    }
    
    
    //Close the input file
    fclose(ofp);
    if (fclose(ofp) != 0) {
        
        printf("Error while closing the input file\n");
        exit(1);
        
    }
}

/* TODO:
 * Generates a magic square of the user specified size and
 * output the quare to the output filename
 *
 * Add description of required CLAs here
 */
int main(int argc, char **argv) {
    // Check input arguments to get output filename
    if (argc != 2){
        
        printf("Usage: ./myMagicSquare <output_filename>\n");
        exit(1);
        
    }

    // Get magic square's size from user
    int size = getSize();
    // Generate the magic square
    MagicSquare *msp  = generateMagicSquare(size);
    // Output the magic square
    fileOutputMagicSquare(msp, *(argv+1));
    // Free memory.
    int i=0;
    while(i < size){
        free( *(msp -> magic_square + i));
        i++;
    }

    free(msp -> magic_square);
    free(msp);
    return 0;
}


//     F22 deppeler myMagicSquare.c
