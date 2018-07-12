# Inventory
Write a complete C++ program called inventory.cpp as described below.  Documentation is required; see next page. 
 
Write an interactive program for processing inventory information for a parts warehouse.   When started, the program should read in from a text file used for storing information between sessions.  It is possible that the text file is empty.  The program user is then given five choices in the main menu: enter a new part to the system, find and print data for a part when given the part ID number, find and modify data for a part when given the part ID number, copy all information to a binary archive file, and quit.   These choices will be explained more fully below. 
 
While the program is running, all parts information should be in the main memory for fast response.  You may assume that there will always be enough space in memory to do this.    
 
# Specifications
 
For each part, you need to store its ID (an integer), a short text description, its price, and a count of how many of that part the warehouse currently has.  You are given two files Part.h and Part.cpp that hold the declarations and definitions for a simple Part class that holds just the ID, and the text description.  You can revise the files as needed for this assignment. 
 
When the program first starts, it reads in the information is stored in a text file called textSave.txt.  You may assume that such a file always exists, but may be empty.   
 
The program should now print a menu and ask the user to enter one of the following letters corresponding to the 4 choices below.  The program will do the appropriate task, and keep repeating (get choice, do task) until the option 4 is chosen, 
 
1:  this stands for a new part.  The program should ask the user to enter the part ID and the rest of the part information.  The program will then enter the new part information into the system. 
 
2: this stands for finding a particular part.  The program will ask for a part ID number, and search the system for a part with that ID. If it is found, the program will display the ID and all other information about the part to the screen.  If it is not found, the program will print a message to the screen, telling the user that it could not be found. 
 
3: This stands for archiving the information.  Everything is output to a binary file called binarySave.dat.  Any previous file of that name will be overwritten. 
 
4: this stands for quit.  The program will write all the current parts information into the text file textSave.txt, overwriting any previous data before quitting. 
 
# Design considerations  
 
You do not need to be concerned with speed when reading from or writing to the files. However, you should try to make the other tasks run quickly.  You may choose any format for the two save files, as long as they contain all the information and can be read and written by your program as text (for textSave.txt) and written as binary (for binarySave.dat). 
