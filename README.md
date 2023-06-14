# Linux-Terminal-System

## Introduction: 
Linux is one of the most popular open-source operating systems. It is widely used worldwide. Linux has numerous distributions, including Kali Linux, Ubuntu, and Fedora, which are particularly popular. Linux is a powerful operating system renowned for its command-line interface. Therefore, we have decided to create a Linux terminal that can execute specific commands using the C++ programming language.
Objectives: The main objective of this project is to create a terminal that can execute commands based on user input. The operations related to file management include opening, closing, creating, and updating files. For process management, the terminal should be able to retrieve static processes, terminate a process, create a new process, execute processes, display the top system processes, and provide graphical representations of system resources. In terms of information management, the terminal should be capable of retrieving process IDs by program, putting programs to sleep, obtaining netstat information, and displaying process trees, among other functionalities.

## Project Details:
As mentioned earlier, we are using the C++ programming language for this project, and the operating system of choice is Ubuntu 64-bit. We will be utilizing the Ubuntu Terminal and the Nano text editor, which are built-in tools in Ubuntu, for running and executing the project.
![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/d4b401f1-188d-4c05-8725-5a9faa13530f)

The system calls that this project will implement for file management are:
  -	open()
  -	read()
  -	write()
  -	close()

The corresponding functionalities (commands) for these system calls in file management are as follows:
  -	Touch: Creates and edits a file.
  -	Cat: Reads the contents of a file.
  -	Gedit: Writes a file using the nano text editor.
  -	Echo: Writes content to a file from the command line.

  ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/77a6ae5a-e9ed-4b2d-bf10-7a4f1effae0b)


The system calls implemented for process management are:
  -	fork()
  -	exit()
  -	exec()

The functionalities (commands) associated with these system calls in process management are as follows:
  -	W: Displays who is logged in and what they are doing.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/8e51908a-345a-4349-9eb7-9186405803b3)
  -	Tload: Provides a graphical representation of the system's load average.
  -	Ps: Lists static processes.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/a5989578-1c00-4094-90b8-34da709bcd8c)
  -	Top: Lists dynamic processes.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/ddd7e6ea-8d16-4087-8596-e28d8d96ea20)
  -	Kill: Terminates a process.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/463ce5d2-ff44-4453-8dcb-c91f18d90ad4)

The system calls implemented for information management are:
  -	getpid()
  -	sleep()

The functionalities (commands) corresponding to these system calls in information management are as follows:
  -	Pidof: Displays the process ID of a program.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/f308fdbd-4bf5-4f85-99b7-5a2ee87b9dbf)
  -	Pgrep: Locates the process ID.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/56ebb38a-e9da-477a-813c-32f9bf1b26cd)
  -	Pstree: Shows the process tree of the system.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/db54c28e-ac6b-4834-859f-195d7293b333)
  -	Netstat: Displays the network state of the system.
  -	Ss: Shows socket statistics.
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/0a616ff8-0a0c-43b5-91d6-68dababe22b9)
  - Sleep: Makes a process sleep
    
    ![image](https://github.com/FarhanTahmid/Linux-Terminal-System--CSE323/assets/62169118/5cf28b42-55a9-4084-b378-298a6beb21bb)
## Summary: 
The project involved creating a Linux terminal using C++ language on the Ubuntu 64-bit operating system. The objective was to develop a terminal that could execute commands based on user input, focusing on file management, process management, and information management. Overall, the project successfully created a Linux terminal with specific commands for file management, process management, and information management, providing users with a powerful tool to interact with the operating system.


