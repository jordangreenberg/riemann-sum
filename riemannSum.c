#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Program estimates the integral of 2x^2 - 7x - 2 over range [a,b] with n rectangles

//Declare global variables that will be used by entire program
double startOfRange = 0, endOfRange = 0;
int numRectangles = 0;

//Function receives user input and determines if input is valid
bool GetInputs(void) {
    
    //Receive and store inputs
    scanf("%lf %lf %d", &startOfRange, &endOfRange, &numRectangles);
    
    //Determine if inputs are valid. Return false if inputs are invalid
    //The range must be between -10.0 and 10.0
    //The end must be greater than the start
    //The number of rectangles must be greater than 0
    if (startOfRange < -10.0 || endOfRange > 10.0 || endOfRange <= startOfRange || numRectangles <= 0) {
        
        //Output error message
        printf("Invalid inputs...\n\n");
        
        return false;
    }//end of if
    
    //If inputs are valid, return true
    return true;
    
}//end of GetInputs

//Function evaluates the function f(x) at a given value of x
double EvalFunc(double x) {
    return (2 * pow(x, 2) - 7 * x - 2);
}//end of EvalFunc

int main(int argc, char **argv)
{
    //Declare variables
    bool validInput = false;
    double rectangleWidth = 0;
    double leftArea = 0, rightArea = 0, midArea = 0;
    
    //Prompt input from user
    while (validInput == false) {
        printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
        printf("To exit enter 0 0 0\n");
        
        //Get inputs from user using GetInputs function
        validInput = GetInputs();
        
        //Check to see if user would like to terminate program
        if (startOfRange == 0 && endOfRange == 0 && numRectangles == 0) {
            printf("Terminating main!\n");
            return 0;
        }//end of if
        
    }//end of while loop
    
    //At this point in the program, the inputs are valid
    
    //Calculate the width of each rectangle
    rectangleWidth = (endOfRange - startOfRange) / numRectangles;
    
    //Calculate the-left point integral
    for (int i = 0; i < numRectangles; i++) {
        
        //Determine the left-point value where the height of the rectangle will be evaluated
        double x = startOfRange + (i * rectangleWidth);
        
        //Evaluate the function at that left-point value, multiply by rectangle width, and add to area total
        leftArea += EvalFunc(x) * rectangleWidth;
    }//end of for loop
    
    //Calculate the right-point integral
    for (int i = 0; i < numRectangles; i++) {
        
        //Determine the right-point value where the height of the rectangle will be evaluated
        double x = startOfRange + ( (i + 1) * rectangleWidth);
        
        //Evaluate the function at the right-point value, multiply by rectangle width, and add to area total
        rightArea += EvalFunc(x) * rectangleWidth;
    }//end of for loop
    
    //Calculate the mid-point integral
    for (int i = 0; i < numRectangles; i++) {
        
        //Determine the mid-point value where the height of the rectangle will be evaluated
        double x = (startOfRange + (rectangleWidth / 2)) + (i * rectangleWidth);
        
        //Evaluate the function at the mid-point value, mulitply by rectangle width, and add to area total
        midArea += EvalFunc(x) * rectangleWidth;
    }//end of for loop
    
    //Output results
    printf("With Step Size: %.4lf\n", rectangleWidth);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %.2lf and %.2lf, using %d rectangles is as follows\n\n", startOfRange, endOfRange, numRectangles);
    printf("Mid point evaluation approximate: %.4lf\n", midArea);
    printf("Left point evaluation approximate: %.4lf\n", leftArea);
    printf("Right point evaluation approximate: %.4lf\n", rightArea);
    
	return 0;
}//end of main
