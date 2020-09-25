# directory-maintenance

Problem Description
The goal of this assignment is to write a C++ program that will simulate directory tree maintenance and process basic UNIX/Linux operating system commands.

Suppose we wanted a directory tree that would allow us to represent the following directory structure:

picture goes here


We could use a binary tree structure where one branch is essentially a linked list of sibling nodes at a given level, and the other branch is a pointer to the contents of the given directory. Pictorially, the data structure would look like this:

picture goes here


For simplicity, we will use the same type of node for a file or a directory. You should define a C++ class Node to provide this capability.

Requirements for this assignment:

We will simulate several of the UNIX command-line operating system commands for a directory system in order to add directories, add files, list directory contents, etc.

We will implement the following commands:
ls              // lists all files and directories in the current directory, indicating which (file or directory) it is
mkdir <dirname> // creates a new directory if it does not already exist
cd <dirname>    // changes into specified directory if it exists
cd ..           // changes to the parent directory
pwd             // specifies the current directory as: <yourname>/root/nextdir/etc/
addf <filename> // adds a file to the current directory

mv <fname1> <fname2> // change the name of the file or directory to the new name

cp <fname1> <fname2> // copy file or folder to the new name

rm <filename>   // locate and remove the file or directory

whereis <filename>   // show the path to the various occurrences of a file or directory if it exists
bye             // ends the session


A technical note:
Think of your structure for a Node in this system. The cd .. command suggests that it will be really critical to be able to navigate from a given node to that node's parent. Does it appear that the second picture above would make such a process efficient? One other thought. You will REALLY want to practice drawing how your pointers get set as you develop this program!!

Program execution:
This assignment will simulate an interactive program by reading the commands from a file. Commands will be in a file entitled commands.txt, one per line. You will NOT have to construct commands from multiple lines and SHOULD NOT code your progam to work that way. We will adopt the approach of running an interactive program non-interactively for two reasons:

It will illustrate that you can test interactive programs without having to do all the typing (most important)
It will simplify life for the person grading the assignment
Error Checking:
This assignment will require quite a bit of error checking. For instance, you should not be able to make a file or directory in a directory that already has a file or directory by that name. You obviously cannot switch into a directory that is not there, and you cannot switch to the parent directory of your root directory (although UNIX might permit you to do this if the System Administrator is not too picky). The data structure will be available in the background and will grow as we add subdirectories and files, or shrink as we remove them. Note the use of the $ as the command prompt - just like a typical command-line system!!

Here is a typical output of a program run:
$ ls
$ pwd
coffey/root/
$ mkdir adir
adir
$ ls
  D adir
$ cd adir
coffey/root/adir/
$ addf f1
f1
$ addf f3
f3
$ addf f4
f4
$ addf f2
f2
$ ls
  F f1
  F f2
  F f3
  F f4
$ mkdir d1
d1
$ cd d1
coffey/root/adir/d1/
$ addf f3
f3
$ addf f2
f2
$ mv f3 f2
f2 already exists in d1
$ mv f3 f4
$ ls a
Illegal command: ls a
$ ls
  F f2
  F f4
$ whereis f2
coffey/root/adir/d1/
coffey/root/adir/
$ whereis querty
querty not found
$ whereis f3
coffey/root/adir/
$ addf f6
f6
$ pwd
coffey/root/adir/d1/
$ ls
  F f2
  F f4
  F f6
$ cd ..
coffey/root/adir/
$ pwd
coffey/root/adir/
$ ls
  D d1
  F f1
  F f2
  F f3
  F f4
$ rm d1
$ ls
  F f1
  F f2
  F f3
  F f4
$ rm f5
f5 was not found
$ rm f4
$ ls
  F f1
  F f2
  F f3
$ bye

Deliverables

1. C++ Source code
2. User's manual
3. UML document showing the final organization of your program

4. Your file commands.txt that issues the commands seen above. You may add cases, but add them to the end of the file.
Submission

Your project must be submitted using the instructions below to be graded.

1. Compile and run your program one last time before submitting it. Your program must run in Linux in the multiplatform lab. 

2. Place all deliverables in a single folder that is named with your last name and first name initial. Packaging your submission this way is critical when we unpack the projects after download. For example, if your name is John Coffey, the folder should be coffeyj. If you are a MacOS user, delete the _MacOS_ folder before zipping up your submission.
3. Create a "zip"  file (using WinZip or similar program) to hold your project files.

The name of your zip file should be named exactly like the single folder inside it but with the .zip extension. For instance:  coffeyj.zip.

3. Login to Canvas and select our course from the dashboard.

4. Go to the Assignments page and choose the assignment for which you are submitting a project.

5. Click the "Submit Assignment" button.
6. Use the "Choose File" capability to select and upload your .zip file.
