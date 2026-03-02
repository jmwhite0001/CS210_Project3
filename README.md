# CS 210 Project Three Portfolio Submission

Project summary and problem it solved
This project is a C++ program for the Corner Grocer item-tracking scenario. It reads a list of purchased items from an input file (CS210_Project_Three_Input_File.txt), counts how many times each item appears, and allows the user to interact with the results through a menu. The user can search for a specific item’s frequency, print all item frequencies, or print a histogram. The program also writes a backup data file (frequency.dat) that stores each item and its count.

What I did particularly well
I did well creating a clear, user-friendly menu and making the program easy to use. I also separated the logic into an ItemTracker class to keep responsibilities organized instead of putting everything in main(). Another thing I did well was using maps to store and retrieve item counts efficiently, which made searching and printing the results straightforward.

Where I could enhance my code and why that helps
I could enhance the code by improving input validation and error handling. For example, I could add stronger handling for unexpected user input (non-numeric menu entries, blank item searches) and provide clearer messages if the input file cannot be opened. I could also add more comments explaining key logic decisions and consider adding unit-style tests for trimming, normalizing item names, and counting behavior. These improvements would make the program more reliable, easier to maintain, and safer by controlling how input is processed.

Most challenging part and how I overcame it (tools/resources)
The most challenging part was handling file input correctly and making sure item names were processed consistently so counts were accurate. I overcame this by breaking the program into smaller steps: reading the file first, confirming counts were correct, then adding the menu actions and output formatting. I also used incremental testing and debugging to confirm each feature worked before moving on. Resources that helped included course materials, C++ documentation, and the Visual Studio build and debug feedback during development.

Transferable skills
This project strengthened my skills in C++ program design, file input/output, and using data structures to store and retrieve information efficiently. I also gained practice building a menu-driven program, validating user input, and organizing code into multiple files with a header and implementation file. These skills will transfer directly to other courses and projects that require clean structure, reliability, and readable code.

How I made it maintainable, readable, adaptable
I improved maintainability by separating the program into an ItemTracker class and keeping responsibilities organized. I used clear naming for functions and variables and kept the program logic separated from user interaction where possible. This structure makes it easier to update the program later, such as changing the input source, adding new menu options, or adjusting output formatting without rewriting everything.

How to run

Compile the project in Visual Studio.

Make sure CS210_Project_Three_Input_File.txt is in the same folder as the program when you run it.

Run the program and use the menu options to search items, print counts, or print the histogram.

The program will create frequency.dat automatically.

Files included

CS210_ProjectThree.cpp

ItemTracker.cpp

ItemTracker.h

CS210_Project_Three_Input_File.txt
