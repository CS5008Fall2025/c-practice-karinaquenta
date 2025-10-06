/**
 * Student Name:Karina Quenta
 * Semester:Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * ADDED SWAP TEST - Tests if the function swaps a negative number with a positive number
*/

int test_swap_two(){
    printf("2.test_swap_two()\n");
    int a= -3;
    int b= 9;
    swap(&a, &b);
    if (a == 5 && b==5){
        return 1;
    }
    return 0;
}

/**
 * ADDED SWAP TEST - Tests if both numbers are the same and still works
*/

int test_swap_three(){
    printf("3.test_swap_three()\n");
    int a = 7;
    int b = 7;
    swap(&a, &b);
    if (a==5 && b==5){
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

/**
 * ADDED CREAT ARRAY OF INTS FIB TEST - Tests if the size is 0, NULL should be Output
*/
int test_create_array_of_ints_fib_two() {
    printf("2. test_create_array_of_ints_fib_two()\n");
    int* arr = create_array_of_ints_fib_two(0);

    if (arr!= NULL){
        free(arr);
        return 0; //means failed
    }
    return 1; //means passed
}
/**
 * ADDED CREAT ARRAY OF INTS FIB TEST - Tests if the size of 1 works, Outputshould be [1] for passing test
*/
int test_create_array_of_ints_fib_three() {
    printf("3. test_create_array_of_ints_fib_three()\n");
    int* arr = creaate_array_of_ints_fib_three(1);
    int expectedOutput[] = {1};

    if (arr == NULL || arr[0] != expectedOutput[0]){
        free(arr);
        return 0;
    }

    free(arr);
    return 1;
} 


// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_swap_two,
        test_swap_three,
        test_create_array_of_ints_fib,
        test_create_array_of_ints_fib_two,
        test_create_array_of_ints_fib_three,

        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
