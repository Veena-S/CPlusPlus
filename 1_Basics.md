# Basics of C++
---------------

## COMPILERS
----------

A compiler turns the program that you write into an executable that your computer can actually understand and run.

Computer language is called machine language

## Introduction to C++
-------------------

A C++ program is a collection of commands, which tell the computer to do ""something"". 
This collection of commands is usually called C++ source code, source code or just code. Commands are either ""functions"" or ""keywords"". 

How does a program actually start? Every program in C++ has one function, always named main, that is always called when your program first executes. 
From main, you can also call other functions whether they are written by us or, as mentioned earlier, provided by the compiler. 

So how do you get access to those prewritten functions?
To access those standard functions that comes with the compiler, you include a header with the #include directive.
What this does is effectively take everything in the header and paste it into your program.

*Sample Program*:-
----------------
```C++
#include <iostream>		// Preprocessor
using namespace std:
int main()
{
	cout << "Hello World\n";
	cin.get();
}
```


The #include is a "preprocessor" directive that tells the compiler to put code from the header called iostream into our program before actually creating the executable. By including header files, you gain access to many different functions. For example, the cout function requires iostream.
Preprocessor directives are interpreted before the compilation of the program itself begins.
 Preprocessor directives (those that begin by #) are lines read and processed by the preprocessor before proper compilation begins. Preprocessor directives must be specified in their own line and, because they are not statements, do not have to end with a semicolon (;).

Following the include is the statement, "using namespace std;". This line tells the compiler to use a group of functions that are part of the standard library (std). By including this line at the top of a file, you allow the program to use functions such as cout. The semicolon is part of the syntax of C++. It tells the compiler that you're at the end of a command.

The next important line is int main(). This line tells the compiler that there is a function named main, and that the function returns an integer, hence int. The "curly braces" ({ and }) signal the beginning and end of functions and other code blocks.

In C++, however, the cout object is used to display text. It uses the << symbols, known as "insertion operators", to indicate what to output.
cout<< results in a function call with the ensuing text as an argument to the function. The quotes tell the compiler that you want to output the literal string as-is. The '\n' sequence is actually treated as a single character that stands for a newline. It moves the cursor on your screen to the next line. Again, notice the semicolon: it is added onto the end of most lines, such as function calls, in C++. 

The next command is cin.get(). This is another function call: it reads in input and expects the user to hit the return key. Many compiler environments will open a new console window, run the program, and then close the window. This command keeps that window from closing because the program is not done yet because it waits for you to hit enter. Including that line gives you time to see the program run. 


## Comments
--------

Two slash signs indicate that the rest of the line is a comment inserted by the programmer but which has no effect on the behavior of the program. Programmers use them to include short explanations or observations concerning the code or program. 
C++ supports two ways of commenting code:

```C++
// line comment
/* block comment */ 
```

The first of them, known as line comment, discards everything from where the pair of slash signs (//) are found up to the end of that same line. The second one, known as block comment, discards everything between the /* characters and the first appearance of the */ characters, with the possibility of including multiple line

