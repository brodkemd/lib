#include "../lib.h"

// prints, these are pretty straight forward
void lib::print(std::string line) {
    std::cout << line << std::endl;
}

void lib::print(char x) {
    std::cout << x << std::endl;
}

void lib::print(int x) {
    std::cout << x << std::endl;
}

//prints each element of the vector
void lib::print(std::vector<std::string> line) {
    for (std::string it : line) {
        std::cout << "\t" << it << std::endl;
    }
}

void lib::print(std::vector<std::vector<std::string>> in){
    for(std::vector<std::string> i : in){
        for(std::string j : i){
            std::cout << "\t" << j << std::endl;
        }
        std::cout << std::endl;
    }
}

void lib::print(std::vector<std::vector<double>> in){
    for(std::vector<double> i : in){
        for(double j : i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

void lib::print(std::vector<std::vector<int>> in){
    for(std::vector<int> i : in){
        for(double j : i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

//prints each element of the vector
void lib::print(std::vector<double> g) {
    for (double it : g) {
        std::cout << it << std::endl;
    }
}

//prints each element of the vector
void lib::print(std::vector<int> g) {
    for (int it : g) {
        std::cout << it << std::endl;
    }
}

//prints each element of the vector
void lib::print(std::vector<char> g) {
    for (char it : g) {
        std::cout << it << std::endl;
    }
}

void lib::print(double x) {
    std::cout << x << std::endl;
}

void lib::print(long x) {
    std::cout << x << std::endl;
}