Project 1: Tokenizer
====================
# Objective:

The purpose of this lab is to create a tokenizer builder that not only creates
a history but can be accessible to the user from various inputs. This is done
by using two additional files called tokenizer and history that will help
implement this functions. Main acts as a menu for the user and is the basis
for all of the commands.

# Files:

The following are the list of files included in this lab, as well as the
overall purpose for their inclusion:
- main.c: Main file and the UI that interacts with the user. Will give the
user various prompts depending on the task at hand.
- tokenizer.c: Will create the actual functions to create a tokenizer from a
user's sentence.
- tokenizer.h: draw.h: Header file containing all the declarations of the
relevant methods used in tokenizer.c.
- history.c: Will store the tokens created in the toekinzer and place them in
assigned slots for the user to recall their previous tokens.
-history.h: draw.h: Header file containing all the declarations of the
relevant methods used in history.c.

# How to Compile and Run:

Follow these steps to make sure you can compile and run the program:

1.Inside the src section, type 'make' to compile all of the necessary
files. Afterwards an executable named "compiler" will be
created.

2.Type './compiler' on the src to run the program.

3.Follow the on screen commands to create and alter your tokens. Enjoy!
