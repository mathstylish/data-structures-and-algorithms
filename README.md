[![pt-br](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/mathstylish/data-structures-and-algorithms/blob/main/README.pt-br.md)
# Data Structures and Algorithms

The goal of this repository is to serve as a study reference, providing implementations of the data structures and algorithms that you typically learn in this discipline. The programming language I will use is C, for at least two reasons which **I** think didactically interesting:

- **Simplicity and Clarity**: The syntax of the C language is relatively simple, making it easier to understand. Just by reading the code, you can get an idea of what's being done, allowing you to focus more on the concepts of the discipline rather than the details of the language itself.

- **Memory Management**: The C language requires programmers to explicitly manage memory using functions like `malloc()` and `free()`. This allows you to understand how memory is **allocated** and **released** for different data structures.

**Note**: While the C language has its advantages for learning data structures and algorithms, it's important to note that you can learn these concepts in any programming language. What will change is only the language and how the operations are carried out in it.

## Repository Structure
 - Source code, e.g., `LinkedList/`
 - In the source code directories, there's a `.h` file and a `.c` file, e.g., `LinkedList/Singly/singly.h` and `LinkedList/Singly/singly.c`. `.h` is a header file containing macros, structures, and function declarations that we'll implement in the `.c` file.

## How to Run the Examples?
Firstly, you need the following dependencies: `gcc`, `make`. I explain how to install these tools in the [challenge](#challenge) that I proposed. There, you'll find examples of how to install them.

Then compile the source code with `gcc -o LinkedList/Singly/test LinkedList/Singly/singly.c LinkedList/Singly/main.c` and execute with `./LinkedList/Singly/test`. The -o flag indicates where the executable output of the compilation will be generated, `test` is the name of the executable file. Name it whatever you want.

## How to Install?
If you're here, I'll assume you're studying Computer Science, Computer Engineering, or something related. If not, that's okay. However, it's important that you have the ability to research and learn on your own. Programmers should be able to seek solutions and solve problems autonomously. It's natural to seek occasional help, but don't become the person who asks everything without trying to solve anything on your own. I've seen people asking things that could easily be solved with a simple search.

It's essential that you know how to research and install the specific tools for your area, as mentioned earlier. You can do this easily by opening a new tab in your browser and searching for tutorials and installation guides.

But to help you get started, I'll briefly cover the minimum you need to understand to use your computer more efficiently as a programmer:

- **Environment Variables**: These allow you to "tell" the operating system or programs where tools, configuration files, etc., reside. They also allow these to be accessed throughout the operating system or for a specific user. Some programs need these environment variables configured for them to locate or know what to use in your environment.

- **Terminal Emulators, Shells**: Remember when you were a teenager and you ran the `ipconfig` command in the **Command Prompt/CMD** and felt like a hacker/cracker? If you've done that, you interacted with a **terminal emulator**, and the `ipconfig` command was interpreted (understand as "understood") by a **shell** that executed the command.

  The tasks you perform using mouse clicks, window dragging, and so on, are just facilitators so that you don't have to keep running commands and passing arguments directly in the command line. But as a programmer, you should learn at least a dozen or more commands to solve problems, obtain information like: **"Which program/process is running on port 8080, causing issues with the startup of my web server?"**

- **Shell Command Syntax**: Every shell command has a structure more or less like this: `command [action] [parameters] [arguments]`. Commands can have an **action**, which specifies what that **command** will do. However, there are commands that don't have an **action** because the **command** itself is the **action**. The **parameters** can be **mandatory** or **optional**, assuming **values** or default behaviors if you don't explicitly define them. The number of **arguments** can vary, and some commands don't accept **arguments** explicitly.

  I'll use two examples to illustrate, with an abstract command called `cutfruit`, and I'll also use some real examples of commands you'll probably see and use.

  - `cutfruit --cut=slice --pieces 8 -f apple --peel=true apple anotherapple`: Executes the `cutfruit` command with options: slice cut, into 8 pieces, the fruit to be cut is an

  - `cutfruit --cut=cubes --pieces 12 apple orange`: Executes the same command as above, but specifies only the cut and the number of pieces, and then provides an apple and an orange for the cut. Let's assume that if I don't specify the fruit, it will cut any fruit I provide without peeling it for the cut. These are the default options for the command.

  - `winget search "Visual Studio Code"`: Using the Windows package manager, `winget`, I perform a search action using the keyword "Visual Studio Code". Since the argument contains spaces, I need to enclose it in double quotes.

  - `winget install -e --id Microsoft.VisualStudioCode`: With the same command as the example above, I install the package I possibly found in the search using the install action. I use the parameters `-e` and `--id` to specify that I want to install exactly with the id `Microsoft.VisualStudioCode` to avoid the chance of installing the wrong package, as IDs are typically unique.

  - `scoop install gcc sudo`: With the package manager `scoop`, I install the packages `gcc`, which is the compiler needed to run C code, and `sudo`, which I can use as a prefix for commands requiring elevated permission, so I don't need to open a new elevated shell instance.

  - `sudo rm -Recurse -Force study-directory`: I execute a command to delete a directory using `sudo` because this command requires elevated permissions. I need to include the parameters `-Recurse` and `-Force` because it's a directory and not a file.

    By this, I hope you've understood the basic functioning of shell commands, whether in Command Prompt, PowerShell, Zsh, Bash, and others.

- **Elevated Permissions**: You've probably come across tutorials advising you to "run as administrator" for certain programs. This is a way to protect users from potentially harmful commands for the operating system. When I say "harmful," I don't mean physical damage, but rather potentially damaging your Windows installation or disrupting program functionality.

  In an operating system, there's a regular user with a limited set of functions they can execute, and there's a superuser or administrator who can perform almost any function. It's important to understand this because people often struggle to execute commands beyond their permission level. Don't worry, the command-line output or a popup will indicate the need for elevated permissions to execute a command.

- **Package Managers**: Up to now, everything you've installed, be it Google Chrome, Microsoft Office, or a PDF reader, was done by downloading an executable from a website and following installation steps. However, there are other ways to install programs.

  You can install programs via the command line, and you need to know how to do this because you'll likely encounter it sooner or later, whether for installing a program or a library required by a programming language.

  The tools responsible for this installation process are called **package managers**, where programs, dependency libraries, etc., are referred to as **packages**. Different operating systems have their package managers, like Debian's `apt`, Arch Linux's `pacman`, or Fedora's `yum`. Windows, despite not always having a decent package manager, has seen the development of package managers like Chocolatey (`choco`), `scoop`, and eventually Microsoft's own `winget`.

## Challenge
With that said, I present you with the following challenge (I'll use Windows 10/11 as an example, as many of you might be using it): Set up an environment with the following programs/tools:

- **Winget**: Windows 11 and some Windows 10 builds come with `winget`. To check if it's installed, open **Windows PowerShell** or **Command Prompt** and run the command `winget` without any action, parameters, or arguments. If you see a message other than a red error or an error description, it's likely installed. If not, you can install it from the Microsoft Store by searching for **"App Installer"**.

- **PowerShell 7**: The Command Prompt (CMD) is outdated, and Microsoft offers better alternatives. Windows typically comes with Windows PowerShell 5.1, but I strongly recommend using version 7. You can install it from the Microsoft Store or via `winget`.

- **Windows Terminal**: This terminal emulator allows you to group various shells (CMD, PowerShell, WSL distributions, etc.). You can install it from the Microsoft Store or via `winget`.

- **Scoop**: A package manager that lets you install various tools, like the `gcc` compiler, via the command line. Visit [scoop.sh](https://scoop.sh) and follow the instructions.

- **GCC**: Compiler for the C language. With `scoop`, install the `gcc` package.

- **Visual Studio Code**: Use `winget` to install the Visual Studio Code package.

From this point on, I believe you can explore on your own. Practice operations like creating directories, deleting, renaming, creating files, and installing packages you use. Customize your shell and terminal emulator environment to make it visually appealing. Don't fear errors; take a moment to read error messages, and if needed, copy and paste them into Google to find solutions. Remember, many others have faced the same errors. Embracing errors and successes will lead you to mastering various subjects.

**Final Note**: You have the capability and should exercise the freedom to disagree with what I believe is necessary. What I find necessary might not be the same for you; it's just what I followed. It might seem unnecessary to mention this, but I know people who dismiss learning **x** because they already know **y** and believe it makes **x** redundant. However, understanding **x** often greatly aids in comprehending **y**. That said, learn to judge for yourself what you need to learn; don't outsource your decisions. Good luck!