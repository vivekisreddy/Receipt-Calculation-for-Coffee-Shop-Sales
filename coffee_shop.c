#include <stdio.h>
#include "coffee_shop.h"

int main()
{
    int task;            // initializes task which is a variable for what program the user would like to run
    char inputFile[50];  // variable used for file input for user
    int itemInput;       // variable used for user input item
    char outputFile[50]; // variable used for output file for user
    char writeOption;    // variable used for checking if the user wants to Append or Over-write
    FILE *file;          // pointer that opens the input file
    FILE *ptrOutputFile; // pointer that opens the output file

    // asks for which program the user would like to run
    printf("Which program would you like to run: (1) Calculate overall revenue, (2) Calculate register balance, or (3) Calculate sales for an item.\n");
    scanf("%d", &task);

    // Checks if the user picked any other task other 1,2 or 3
    if (task < 1 || task > 3)
    {
        printf("This option is not valid.\n"); // prints is not valid because the user did not chose any of the options that could be run
        return 1;
    }

    printf("Please enter an input file:\n"); // asks for the user for an input file they want the program to execute
    scanf("%s", inputFile);

    file = fopen(inputFile, "r"); // opens the example text file which has the data

    switch (task)
    { // switch statement for checking through each case and making sure it runs all the functions

    case 1:
        overall_revenue(file); // goes through the overall_revenue function
        break;

    case 2:
        balance(file); // goes through the calculating balance function
        break;

    case 3:
        printf("Which item to analyze?\n"); // asks the user what item they want
        scanf("%d", &itemInput);
        printf("What is the output file?\n"); // asks the user where they want their item to put into
        scanf("%s", outputFile);
        int program3 = tally(file, itemInput);               // setting the variable to the function so it can be used
        printf("Enter A for Append or O for over-write.\n"); // asks the user if they want to append the input or over-write
        scanf(" %c", &writeOption);

        if (writeOption == 'A' || writeOption == 'a')
        {                                           // if user types 'A' or 'a' which means they clicked append then it will put in the output file
            ptrOutputFile = fopen(outputFile, "a"); // opens the output file
        }
        else
        {
            ptrOutputFile = fopen(outputFile, "w");
        }
        if (file == NULL) // if the input file is NULL, then user's option is invalid

        { // if the file the user uses is NULL, then it won't open that file
            printf("This option is invalid\n");
        }

        fprintf(ptrOutputFile, "  %d   %d\n", itemInput, program3); // prints out the item the user inputted and the tally function

        break;
    }
    return 0; // checks if the program sucessfully
}
