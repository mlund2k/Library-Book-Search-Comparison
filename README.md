# Library-Book-Search-Comparison


This program compares a few popular computational search methods to determine which methods perform best in varying scenarios.


This program was compiled using WSL (Windows Subsystem for Linux) on Windows 10 and 11 and runs perfectly in such environments.


**Steps to run:**
- Copy files into one directory
- Set the location of the files as your directory with your terminal of choice
- Execute ```make``` to compile the project
- Execute ```./create_testdata <num_newbooks> <num_requested>``` to create test data and necessary files for the program to run. Specify a desired number for <num_newbooks> and <num_requested> to determine the number of books that will be searched.
- Execute ```./SearchNewBooks newBooks.dat request.dat result_file.dat``` to run the program. The supplied files will be used to feed the information in and output the results of the program for troubleshooting.
- The program will ask to specify a type of search from the 3 available, ```l``` for linear, ```b``` for binary, and ```r``` for recursive binary.


From the results, it appears that linear search is more useful for smaller input on the order of N<1000, while for larger datasets recursive binary appears to lead typical binary in performance.
