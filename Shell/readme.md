This shell program operates similarly to a Linux shell and allows for the user to navigate through files. To build this code, enter in 'g++ -g shell.cpp -o  shell.o' into a Linux command prompt window that also contains the shell.cpp file. Then, typing in './shell.o' will begin running the code. 

This function accepts most of the same inputs as a typical linux shell, including:
  - simple command arguments
    - ls (lists files in directory)
    - ls -l  (lists files in directory, sizes, last edits, and file permissions)
    - ls -l /sbin (should list from the /sbin directory that has many files)
    - ls -l -a
    - ls -la
    - ps -aux
    - cd (lists current directory
  - Input/output redirection
    - ps aux > a
    - grep /init < a
    - grep /init < a > b (grep output prints in file b)
  - Background processes
    - sleep 1 &
    - sleep 2 &
    - sleep 20 &
    - sleep 20
