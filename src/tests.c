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
 * ADDED SWAP TEST - swap a negative with a positive
*/

int test_swap_two(void){
    printf("2.test_swap_two()\n");
    int a= -3;
    int b= 9;
    swap(&a, &b);
    if (a == 5 && b== -5){
        return 1;
    }
    return 0;
}

/**
 * ADDED SWAP TEST - swapping equal numbers should keep them equal
*/

int test_swap_three(void){
    printf("3.test_swap_three()\n");
    int a = 7;
    int b = 7;
    swap(&a, &b);
    if (a == 7 && b == 7){
        return 1;
    }
    return 0;
}

/**
 * ADDED - Tests the create_array_of_ints_fib function (size 5)
*/
int test_create_array_of_ints_fib(void) {
    printf("4. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    if (arr == NULL) {
        return 0;
    }
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note: expected is on the stack; do not free it
    return 1;
}

/**
 * ADDED FIB TEST - size 0 should return NULL
*/
int test_create_array_of_ints_fib_two(void) {
    printf("5. test_create_array_of_ints_fib_two()\n");
    int* arr = create_array_of_ints_fib(0);
    if (arr != NULL) {
        free(arr);
        return 0; // failed
    }
    return 1; // passed
}
/**
 * ADDED ANOTHER FIB TEST - Tests if the size of 1 works, Outputshould be [1] for passing test
*/
int test_create_array_of_ints_fib_three(void) {
    printf("6. test_create_array_of_ints_fib_three()\n");
    int* arr = create_array_of_ints_fib(1);
    if (arr == NULL) {
        return 0;
    }
    if (arr[0] != 1) {
        free(arr);
        return 0;
    }
    free(arr);
    return 1;
}
//Added CREATE CREATE POINT TESTS-this tests if the x and y values are getting correctly assigned , making sure create_point returns a non-NULL ptr or

int create_point_test_one(){
    printf("running test_create_point_one\n");
    //defining inputs
    int x=5;
    int y=10;
    //callling the function
    Point* p=create_point(x,y);

    if(p == NULL){
        printf("create_ppoint failed, return null\n");
        return 0;
    }

    if (p->x != x || p->y != y){
        printf("create_point failed,expected (%d, %d), but got (%d, %d)\n");
        free(p);
        return 0;
    }

    printf("create_point passed, point has been created corrected, as expected: (%d, %d)\n");

    free(p);
    //passed the test
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
        create_point_test_one,

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
            printf("Test %d failed\n");
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
