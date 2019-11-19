#include <iostream>

#include "ConsoleInterface.h"

template <typename T>
bool run(){
    std::string str;
    ConsoleInterface<T> interface;

    while(std::getline(std::cin, str)) {
        if(str == "change_type") return true;
        else if(str == "exit") return false;
        else interface.parse(str);
    }
    return false;
}

int main() {
    std::string str;
    bool running = true;
    while(running && std::getline(std::cin, str)){
        switch (hash(str.c_str())) {
            case hash("int"):
                running = run<int>();
                break;
            case hash("double"):
                running = run<double>();
                break;
            case hash("string"):
                running = run<std::string>();
                break;
            case hash("IPv4"):
                running = run<IPv4>();
                break;
            case hash("IPv6"):
                running = run<IPv6>();
                break;
            case hash("MAC"):
                running = run<MAC>();
                break;
            case hash("exit"):
                running = false;
                break;
            default:
                std::cout << "Unknown type.\n";
        }
    }
    return 0;
}




