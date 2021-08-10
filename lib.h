#ifndef LIB_H
#define LIB_H

#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 100

class lib {
    private:
        // constants used often
        const double param_pi = 3.14159265358979323846;
        const double param_e = 2.71828182845904523536;
        const std::string param_lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
        const std::string param_upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public:
        // pointer for assignment, usually used for std::system assignments
        char command_input[SIZE];

        // clear the above pointer
        void clear_command_input();

        // returns the private constant pi
        double pi(){
            return param_pi;
        }
        // returns the private constant e
        double e(){
            return param_e;
        }
        // returns the private constant the alaphabet
        std::string lower_alphabet(){
            return param_lower_alphabet;
        }

        std::string upper_alphabet() {
            return param_upper_alphabet;
        }

        // functions in the source file, go there for a description of each
        // prints for types
        void print(std::string line);
        void print(char x);
        void print(int x);
        void print(double x);
        void print(long x);

        // prints elements in 1-d vector
        void print(std::vector<std::string> line);
        void print(std::vector<double> g);
        void print(std::vector<int> g);
        void print(std::vector<char> g);

        // prints elements in a 2-d
        void print(std::vector<std::vector<double>> in);
        void print(std::vector<std::vector<std::string>> in);
        void print(std::vector<std::vector<int>> in);

        // finds first instance of type in vector
        int first(std::string line, char x);
        int first(std::vector<std::string> vars, std::string op);
        int first(std::vector<int> stor, int x);
        int first(std::vector<double> stor, double x);

        // finds last instance of type in vector
        int last(std::string line, char x);

        // converts string to char*
        void string_to_char_pointer(std::string line);

        // converts int to char
        char con(int x);

        // converts char to int
        int con(char x);

        bool within_tol(double num, double tol, double goal);
        void rm_space(std::string& Line);
        void to_upper(std::string& line);

        // file and directory handling
        void opening_error(std::string file_name);
        void copy_lines_of_file_to_vector(std::vector<std::string>& lines, std::string file);
        void write_lines_to_file(std::vector<std::string> lines, std::string file);
        void write_line_to_file(std::string line, std::string file_name_or_path);
            // copies the lines from one file to another file
        void copy_lines_from_one_file_to_another(std::string source_file_name, std::string destination_file_name);
        void copy_contents_from_one_directory_to_another(std::string source_directory_name_or_path, std::string destination_directory_name_or_path);
        void make_these_files(std::vector<std::string> files_to_make);
        void remove_these_files(std::vector<std::string> files_to_remove);
        void make_these_directories(std::vector<std::string> directories_to_make);
        void remove_these_directories(std::vector<std::string> directories_to_remove);

        // searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
        // the string, everything after the string, or replace the string itself
        void search_for_and_replace_string_in_vector_with_options(std::vector<std::string>& lines, 
                                                            std::string to_find, 
                                                            std::string replacement, 
                                                            int option /* options: before = 0, after = 1, on = 2 */ );

        // returns file name
        std::string copy_file_to_cur_dir_to_open (std::string absolute_path);

        // copies file back to the directory it came from
        void copy_file_back_to_original_directory (std::string absolute_path);  

        // turns a vector of strings into one continuous string, can choose to have spaces inbetween the indicies of the vector, true if you want spaces
        std::string vector_to_string(std::vector<std::string> to_convert, bool spaces);  

        // runs the inputted string as a command in terminal
        void run_command(std::string command);

        void printCharArray(char *arr, size_t len);
};

#endif