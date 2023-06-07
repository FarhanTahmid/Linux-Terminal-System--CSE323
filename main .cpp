#include <iostream>
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

int main() {
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

    return 0;
}
