#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const int MAX_ARGS = 10;
const int MAX_BUFFER_SIZE = 256;

void executeCommand(const std::vector<std::string>& args) {
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Fork failed." << std::endl;
        exit(1);
    } else if (pid == 0) {
        // Child process
        char* argv[MAX_ARGS + 1];
        for (size_t i = 0; i < args.size(); ++i) {
            argv[i] = const_cast<char*>(args[i].c_str());
        }
        argv[args.size()] = nullptr;

        execvp(argv[0], argv);
        std::cerr << "Command execution failed." << std::endl;
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int exitStatus = WEXITSTATUS(status);
            std::cout << "Child process exited with status: " << exitStatus << std::endl;
        }
    }
}

std::vector<std::string> parseArguments(const std::string& command) {
    std::vector<std::string> args;
    std::istringstream iss(command);
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }
    return args;
}

void executeFileManagement(){
    std::cout << "Enter a command ('exit' to quit): " << std::endl;
    std::string command;
    std::string filename;
    std::string content;

    while (true) {
        std::getline(std::cin, command);

        if(command.substr(0,4)=="exit"){
            break;
        }
        
        if (command.substr(0, 4) == "cat ") {
            filename = command.substr(4);
            std::ifstream file(filename);
            std::string line;

            if (file.is_open()) {
                while (getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            }
            else {
                std::cout << "File does not exist" << std::endl;
            }
        }
        else if (command.substr(0, 6) == "gedit ") {
            filename = command.substr(6);
            std::string notepadCommand = "\"C:\\Program Files\\Notepad++\\notepad++.exe\" " + filename;//while doing in linux terminal replace the path with nano.
            std::system(notepadCommand.c_str());
        }


        else if (command.substr(0, 6) == "echo \"") {
            std::size_t pos = command.find("\" > ");
            if (pos != std::string::npos) {
                content = command.substr(6, pos - 6);
                filename = command.substr(pos + 4);
                std::ofstream file(filename, std::ios::app); 
                file << content << std::endl;
                file.close();
            }
            else {
                std::cout << "Invalid command format" << std::endl;
            }
        }// opens a file
        else if(command.substr(0,6)=="touch "){
            filename=command.substr(6);
             std::ofstream file(filename);
            if(file){
                continue;
            }
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

void executeProcessManagement(){

    while (true) {
        std::string command;
        std::cout << "Enter a command ('exit' to quit): ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        std::vector<std::string> args = parseArguments(command);
        if (args.empty()) {
            std::cout << "Invalid command." << std::endl;
            continue;
        }

        executeCommand(args);
    }
    
}

int main() {
    
    while(true){
        std::string command;
        std::cout<<"Enter what system calls you want to execute:\n1)File Management\n2)Process Management\nTo kill the program, press 0.\n";
        std::getline(std::cin, command);


        if(command=="0"){
            break;
        }else{
            if(command=="1"){
                executeFileManagement();
            }else if(command=="2"){
                executeProcessManagement();
            }
        }


    }
    return 0;
}
