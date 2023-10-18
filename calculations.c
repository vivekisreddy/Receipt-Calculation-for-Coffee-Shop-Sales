#include <stdio.h>


// Function for calculating overall revenue for the day 
float overall_revenue(FILE *file) {
    float revenue; // variable for storing the calculated revenue 
    int itemCode; // variable for the data stored in the text file 
    float value; // variable for the price of the item 

    while ((fscanf(file, "%d %f", &itemCode, &value)) > 0) { // reads after the 0 itemCode in the file 
        if(itemCode != 0) // if the itemCode does not equal to 0 
        {
            revenue += value; // all the price to the revenue variable 
        }
    }

    printf("%.2f\n", revenue); // prints the revenue before it returns the revenue 
    return revenue; // returns the revenue 
}



// Function for calculating the balance 
float balance(FILE *file) { 
    float balance; // variable for storing the balance calculated 
    int itemCode; // variable for the data stored in the text file 
    float value; // variable for storing the price of an item 

    while ((fscanf(file, "%d %f", &itemCode, &value)) > 0) // while loop for checking if the itemCode and price is greater than 0 
    {
        balance += value; // adds price to the balance variable 
    }

    printf("%.2f\n", balance); // prints the balance 
    return balance; // returns the balance 
}



// Function for calculating the item sales 
int tally(FILE *file, int item) {
    int itemCount = 0; // counter of checking the number of times a particular item was sold 
    int itemCode;
    float value = 0; // setting the price to 0 

    while ((fscanf(file, "%d %f", &itemCode, &value)) > 0) { // while loop for checking if the itemCode and price is grater than 0 
        if (itemCode == item) // if the itemCode equals to the item inputted by the user 
        { 
            itemCount++; // increments the number of times a particular item was sold
        }
    }
return itemCount; // returns the itemCount which has the number of times the item was sold 
    
}