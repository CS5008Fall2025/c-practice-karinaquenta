# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository.


1. What is the difference between a standard numeric type (int, float, double) and a pointer? How I understand it is a regular type like int, float, or double is just used to hold actual numbers, like 5 or 3.14. It’s pretty straightforward becasue you store a value, and that’s it. But a pointer is a little different. Instead of holding the number itself, it holds the address of where that number is saved in your computer’s memory. So it’s like the pointer is saying, “hey, the value is over there!” rather than keeping the value itself. At first it feels kinda confusing, but I understand.
   
2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory? So the reason we only do free(arr) and not free(expected) is because they live in different places in memory. The arr variable was created using malloc, which means we have to clean up ourselves using free. But expected was just made normally inside the function, so it lives on the stack, and the program takes care of cleaning that up automatically when the function ends. So if we tried to free(expected), it would actually be wrong and could crash the program. Basically, heap memory needs our help to clean up, stack memory doesn’t becasue the program handles it for us.

3. What is the difference between the heap and stack when related to memory allocation and management? So the way I understand it, the stack and the heap are two different places where our program stores stuff in memory. The stack is used for things like local variables which is organized & fast, and the computer automatically takes care of cleaning it up when the function is done. We don’t have to do anything. But the heap is different becasue when we use functions like malloc, we’re asking the computer to give us memory from the heap, and now it’s our job to manage it. That means we need to call free when we’re done, or else we’ll have a memory leak. So basically, the stack is automatic, and the heap is manual.

4. Take the following code:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```
   Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times). Yes it does compile, some potential runtime issues is that the function returns a pointer to a local variable that no longer exists once the function ends.Which means it can be buggy, sometimes it’ll print the right values, other times it’ll show random numbers, or it might even crash
   ```c
   x: 10, y: 10
   x: -5373, y: 32767
   ```

   Fix the code in the following block:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point* pt = malloc(sizeof(point));
     pt->x=x;
     pt->y=y;
     return pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);

      free(point);

      return 0;
   }
   ```

5. When you use `malloc`, where are you storing the information? We are storing the information on the heap.

6. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)? So the difference is that malloc just grabs a chunk of memory for you, but it doesn’t clean it up the values. On the other hand, calloc not only gives you the memory, it also sets everything to zero, nice and clean. calloc takes two numbers (how many items and the size of each), while malloc just takes one (the total size). So if I want my memory to start fresh with zeros, I’d go with calloc.

7. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?
   - Example: stdlib.h - provides functions for general-purpose operations including
              memory management and random numbers [1].
     - void * malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
     - void * calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc. 
     - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand. 
   1. stdio.h – This one is for input and output, like printing to the screen or reading from the user [1]
      * printf(const char *format, …) – prints text/variables to the screen
      * scanf(const char *format, ...); – reads input from the user and stores it in variables
      * getchar(void); – reads a single character from the keyboard
   
   2. string.h – This library helps you work with strings (text) and arrays of characters [2]
      * size_t strlen(const char *str); – returns the length of a string
      * *strcpy(char *dest,const char *src); – copies one string into another.
      * strcmp(const char *str1, const char *str2); – comparing two strings and tells you if they’re the same
 
   3. math.h – This one is for doing more advanced math operations (beyond basic ones like +, -, *, /) [3]
      * double sqrt(double x); – returns the square root of a number.
      * double pow(double base, double exponent); – raises a number to a power (like pow(2, 3) = 8).
      * double sin(double x); – returns the sine of an angle (the angle must be in radians).
 

8. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

**Q**Question from C, the Heap, and Executables Technical Interview Question: What is a header (.h) file and how does it differ from a source file? Why do we use header files?
**A**
A header (.h) declares the interface (info like functions, type def,and variants) to let the other files like .c files know what exists in the code. .c files houses the implementation of the functions. We use the headers to separate the interface and implementation.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

Completed and discussed Leetcode problem 905. Sort Array By Parity in Lab.

## Deeper Thinking
In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words. 

Answer here using a paragraph (not just bullet points). 
Yes, both Java and Python put new objects on the heap, but not the stack. The stack is more used for local variables and return addresses, whereas, the heap has objects and arrays that are global variables. In 'The Java Virtual Machine' documentation, explains that objects and arrays are allocated from the heap, while method calls use per-thread stacks for frames and local variables[4]. In Java's documentation "Java Tutorials" states that 'Java is always a pass-by-value', sayin that objects, are references (like an address), so when passing to a method, its passing a copy of a reference. Inside the method you change the local copy via the reference. [5] With working with C, this sounds like passing a pointer by value with a different syntax. Now for Python, Python objects are all in a private heap and the objects stay on the heap. In Python's documentation, "Python Software Foundation," argument passing is described as pass by assignment" so the function gets a reference to the same object , but that reference itself is passed by value.[6] This works becasue mutating an object inside the function is visble for the caller while rebinding the parameter name doesnt affect the caller [7].


## References
Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference. 

1. cppreference.com Contributors. 2025. Standard library header <stdlib.h>. cppreference.com. Retrieved May 1, 2025 from https://en.cppreference.com/w/c/header/stdlib

2. [1] cppreference.com. “C Standard Library: <stdio.h>.” C Reference, 2025. [Online]. Available: https://en.cppreference.com/w/c/header/stdio
3. [2] cppreference.com. “C Standard Library: <string.h>.” C Reference, 2025. [Online]. Available: https://en.cppreference.com/w/c/header/string
4. [3] cppreference.com. “C Standard Library: <math.h>.” C Reference, 2025. [Online]. Available: https://en.cppreference.com/w/c/header/math
5. [4] Oracle. 2014. The Java® Virtual Machine Specification, Java SE 8 Edition — §2.5.2 Stacks; §2.5.3 Heap. Oracle. Available at: https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-2.html
 (accessed 7 Oct 2025).
 6. [5] Oracle. Passing Information to a Method or a Constructor. The Java Tutorials. Oracle. Available at: https://docs.oracle.com/javase/tutorial/java/javaOO/arguments.html
 (accessed 7 Oct 2025).
 7. [6]Python Software Foundation. 2025. Memory Management — Python/C API Reference Manual. PSF. Available at: https://docs.python.org/3/c-api/memory.html(accessed 7 Oct 2025).
 8. Python Software Foundation. 2025. Programming FAQ — “How do I write a function with output parameters (call by reference)?” PSF. Available at: https://docs.python.org/3/faq/programming.html
 9. Python Software Foundation. 2025. Data model — Objects, values and types. PSF. Available at: https://docs.python.org/3/reference/datamodel.html
 (accessed 7 Oct 2025).

## Resource/Help: Linking to images?
To link an image, you use the following code

```markdown
![alt text](path / link to image)
```
for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

