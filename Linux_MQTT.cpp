to create symbolic link - soft link can be created for files and directories
ln -s filepath/filename /whre to create symbolic link

to see symbolic links
ls -l /ifconfig

- hard links point directly to the physical file on disk, and not to path name. even if you move or rename original file this link is not broken
It is only for files.

how to create folder and files using terminal ?

mkdir - to create folder
to create file
vi
vim
gedit
nano


to view content of files
cat
vi
vim
gedit


environment variables
global variables which controls the behavior of Shell
the path where all the softwares are installed, will be stored as environment variables.
to pass the information into processes that are spawned from the shell.

Redirection in Linux
output of one operation is passed as input to another operation > cat fle1 > file2.txt

grep is used for searching in a file. 
pattern base searching is done by including option and parameters in command.

grep -n sd testing - line number
grep -c sd testing - count

find / -name *.txt | xargs grep -i suraj

ps aux to see status of process

su - password

nohup

find / -name *.sh
find / -name -size 10M

tar -cvf new.tar new
gzip -v new.tar

tar -xvf new.tar
gunzip -v new.tar.gz

to set priority - nice command is used

cd, ls, mv, cp, rm

==================================================================================================
GDB debugger // yoo can use until to break the loop 
to use gdb you have to compile your program using g flag
gcc -Wall -g program.c

1. start gdb
gdb a.out
// break filename/linenumber
2. run 
3. next - to go line by line
4. print variable name
5. step to go into function
6. info breakpoint
7. enable/disable breakpoint
8. clear breakpoint
9. str.assign("Hello")=

===================================================
by installing mosquito in your PC you can create mosquito server
Publish/subscribe  - your device published message or subscribe to topic to receive those messages
message 
topics 
broker - MQTT server  // Raspberry pi // computer on chip
