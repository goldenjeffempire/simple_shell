0x16. C - Simple Shell

# THE GATES OF SHELL - ALX PROJECT

The Gates of Shell is an ALX project that explores advanced concepts in shell programming. It covers processes, system calls, file management, and error handling.

# Unix Shell

A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.[2]

Users typically interact with a Unix shell using a terminal emulator; however, direct operation via serial hardware connections or Secure Shell are common for server systems. All Unix shells provide filename wildcarding, piping, here documents, command substitution, variables and control structures for condition-testing and iteration.

## General Knowledge
Original Unix System Design: The original Unix operating system was meticulously designed and implemented by the legendary duo, Dennis Ritchie and Ken Thompson.

First Version of UNIX Shell: It was none other than Ken Thompson himself who penned the inaugural version of the UNIX shell.

B Programming Language Inventor: Ken Thompson also stands as the mastermind behind the creation of the B programming language, which paved the way for the C programming language we know today.

Ken Thompson - A Pioneer: Ken Thompson, a luminary in the field of computer science, co-crafted the Unix operating system and played a pivotal role in shaping the course of computing history.

Inner Workings of a Shell: At its core, a shell serves as a bridge between users and the operating system. It interprets user commands, communicating with the kernel to execute them.

PID and PPID Demystified: A PID (Process ID) serves as a unique identifier for a process, while PPID (Parent Process ID) indicates the ID of the process that spawned it.

Environment Manipulation: The environment of a process can be modified using environment variables, which wield significant influence over program behavior.

Function vs System Call: A function is a block of code within a program designed to perform a specific task. In contrast, a system call is a request made by a program to the operating system for a specific service or operation.

Process Creation Mastery: Processes can be forged using system calls like fork in C, spawning a child process as a replica of its parent.

The Trio of Main Prototypes: main can manifest in three distinct prototypes, each serving unique purposes:

int main(void)
int main(int argc, char *argv[])
int main(int argc, char *argv[], char *envp[])
The PATH's Role: The shell leverages the PATH environment variable to seek out executable programs, scouring directories in the order they're listed.

Executing Programs via execve: The execve system call orchestrates the execution of another program, seamlessly supplanting the current process.

Suspending Execution with wait: Processes can be held in suspension until one of their offspring completes its journey, thanks to the wait or waitpid system calls.

EOF Unraveled: EOF (end-of-file) surfaces when no more data is available for reading from a file or input stream.

## Features
Interactive Prompt: The shell graciously presents a prompt, patiently awaiting user commands. Every command line culminates in a new line.

Error Handling Excellence: In case an executable remains elusive, the shell promptly emits an error message, restoring the prompt for further input.

Meticulous Error Management: The shell excels at handling a multitude of errors, ensuring graceful navigation through potential pitfalls.

Graceful Handling of EOF: The shell exhibits finesse in addressing the "end of file" scenario, triggered by Ctrl+D.

Mastering Command Lines with Arguments: Armed with the prowess to deftly handle command lines adorned with arguments.

Path Proficiency: Navigating the labyrinth of directories is no challenge for the shell, courtesy of adeptly managing the PATH environment variable.

Exit Strategy: The shell pays heed to the exit command, allowing users to gracefully conclude their session with an optional status code.

Ctrl-C Survival Skills: A judicious handling of Ctrl-C ensures that the shell remains resilient, refusing to yield to premature termination.

Command Separator Sensibility: The semicolon serves as a poised conductor, orchestrating the sequential execution of commands.

Logical Operator Expertise: The shell deftly juggles the logical operators && and ||, facilitating conditional execution of commands.

Variable Replacement Mastery: Special variables $? and $$ undergo seamless replacement, yielding their respective values.

Commentary Brilliance: The shell lends an attentive ear to comments prefaced by the venerable #, filtering them out with finesse.

Historical Insight: Armed with a robust history feature, the shell enables users to traverse through a timeline of past commands.

File Input Finesse: The shell demonstrates remarkable versatility in processing commands from an input file, streamlining the execution process.

## Built-ins
Graceful Exit: exit [STATUS] - Bid adieu to the shell with grace, optionally specifying an exit status.

Navigating Directories: cd [DIRECTORY] | [OPTION] - Seamlessly traverse the directory landscape with ease.

Enviable Environment Display: env - An illuminating display of environment variables, offering insights into the shell's inner workings.

Env Variable Pioneering: setenv [VARIABLE] [VALUE] - Forge new environment variables or refine existing ones with aplomb.

Unsetenv Unraveled: unsetenv [VARIABLE] - With a deft hand, clear the path for environment variables to pave their own way.

Alias Crafting: alias [name [='value'] ...] - Bestow names upon commands, fashioning a bespoke lexicon for the shell.

Helpful Insights: help [BUILTIN] - Seek enlightenment on built-in commands, illuminating their usage and functionality.

Glimpse into History: history - Delve into the annals of command history, uncovering a tapestry of past interactions.

## Authors
[Jeffery Emuodafevware] 
[Ola Olajide]
