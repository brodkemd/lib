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
#include <chrono>

class lib {
    private:
        // constants used often
        const double pi = 3.14159265358979323846;
        const double e = 2.71828182845904523536;
        const std::string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
        const std::string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public:
        // Source file: prints.cpp
            /*
            ** inputs: a string
            ** outputs: NONE
            ** Decription: Prints the inputted string to the terminal
            */
            void print(std::string line);
            
            /*
            ** inputs: a char
            ** outputs: NONE
            ** Decription: Prints the inputted char to the terminal
            */
            void print(char x);
            
            /*
            ** inputs: an int
            ** outputs: NONE
            ** Decription: Prints the inputted string to the terminal
            */            
            void print(int x);
            
            /*
            ** inputs: a double
            ** outputs: NONE
            ** Decription: Prints the inputted double to the terminal
            */            
            void print(double x);
            
            /*
            ** inputs: a long int
            ** outputs: NONE
            ** Decription: Prints the inputted long int to the terminal
            */
            void print(long x);

            /*
            ** inputs: a vector of strings
            ** outputs: NONE
            ** Decription: Prints each element of the vector to the terminal
            */
            void print(std::vector<std::string> line);
            
            /*
            ** inputs: a vector of doubles
            ** outputs: NONE
            ** Decription: Prints each element of the vector to the terminal
            */
            void print(std::vector<double> g);
            
            /*
            ** inputs: a vector of ints
            ** outputs: NONE
            ** Decription: Prints each element of the vector to the terminal
            */
            void print(std::vector<int> g);
            
            /*
            ** inputs: a vector of chars
            ** outputs: NONE
            ** Decription: Prints each element of the vector to the terminal
            */
            void print(std::vector<char> g);

            /*
            ** inputs: a 2-D vector of doubles
            ** outputs: NONE
            ** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
            ** i.e. Row 0: contents of row
            */
            void print(std::vector<std::vector<double>> in);
            
            /*
            ** inputs: a 2-D vector of strings
            ** outputs: NONE
            ** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
            ** i.e. Row 0: contents of row
            */
            void print(std::vector<std::vector<std::string>> in);
            
            /*
            ** inputs: a 2-D vector of ints
            ** outputs: NONE
            ** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
            ** i.e. Row 0: contents of row
            */
            void print(std::vector<std::vector<int>> in);
        
        // Source file: seraching.cpp
            /*
            ** inputs: a string and a char
            ** outputs: an int that represents an index in the string
            ** Decription: searches through a string and returns the index of the first occurence of a char in a string
            */
            int first(std::string line, char x);
            
            /*
            ** inputs: a vector of strings and a string
            ** outputs: an int that represents an index in the vector of strings
            ** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted string
            */
            int first(std::vector<std::string> vars, std::string op);

            /*
            ** inputs: a vector of ints and an int
            ** outputs: an int that represents an index in the vector of ints
            ** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted int
            */            
            int first(std::vector<int> stor, int x);
            
            /*
            ** inputs: a vector of doubles and a double
            ** outputs: an int that represents an index in the vector of doubles
            ** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted double
            */ 
            int first(std::vector<double> stor, double x);

            /*
            ** inputs: a string and a string
            ** outputs: an int that represents an index in the string named line
            ** Decription: searches through a string and returns the index of the beginning of the first string that equals the inputted string named x
            */             
            int first(std::string line, std::string x);

            /*
            ** inputs: a string and a string
            ** outputs: an int that represents an index in the string named line
            ** Decription: searches through a string and returns the index of the beginning of the last string that equals the inputted string named x
            */       
            int last(std::string line, std::string x);
            
            /*
            ** inputs: a string and a char
            ** outputs: an int that represents an index in the string named line
            ** Decription: searches through a string and returns the index of the last char that equals the inputted char named x
            */  
            int last(std::string line, char x);

            /*
            ** inputs: a string and a string
            ** outputs: NONE
            ** Decription: the inputted string named to_match_case contains the desired cases for its chars and the string named to_change_case has
            ** the cases of its chars changed to match that of the string name to_match_case 
            ** Note: This function will only capitalize all of the chars or the first one currently
            */  
            void match_case_of_strings(std::string to_match_case, std::string& to_change_case);

            /*
            ** inputs: a string
            ** outputs: an int 
            ** Decription: returns an int that represents index of the first letter in a string
            */              
            int find_first_letter_in_string (std::string line);

            /*
            ** inputs in order: a vector of strings, a string that is what you want to find in the vector, a string that you will replace what you find with,
            ** a bool that indicates if case matter matters or not (true if it does matter), a bool that indicates if you want the replacement string
            ** to match the case of the string that it found, and an int that indicates what you the replacement string to replace (0 if you want the replacement string
            ** to replace beginning of element in the vector up to the found string, 1 if you want to replace everything after the found string in the element of the vector,
            ** 2 if you want to replace the found string in the element of the vector)
            ** outputs: NONE
            ** Decription: replaces the instance of the string named to_find in every string in the vector with the string named replacement in the previously lsited
            ** ways, case can be ignored or matched be the string being replaced and the string that is the replacement
            */  
            void search_for_and_replace_string_in_vector_with_options(std::vector<std::string>& lines, std::string to_find, std::string replacement, 
                                                                        bool ignore_case, bool match_case, int how_to_replace);

            // searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
            // the string, everything after the string, or replace the string itself 
            // options: before = 0, after = 1, on = 2
            // void search_for_and_replace_string_in_file_with_options(std::string file_name_or_path, std::string to_find, std::string replacement, int option);

        // Source file: lib.cpp
            /*
            ** inputs: a string
            ** outputs: NONE
            ** Decription: runs the inputted string in the terminal
            */  
            void run_command(std::string command);
            
            /*
            ** inputs: vector of strings, a bool (indicates whether you want a space after each element in a vector, true if so)
            ** outputs: a string
            ** Decription: turns a vector of strings into one continuous string and returns the continuous string, can choose to 
            ** have spaces inbetween the indicies of the vector
            */
            std::string vector_to_string(std::vector<std::string> to_convert, bool spaces);  

            /*
            ** inputs: a char
            ** outputs: an int that represents the case of a char, if 0 is returned if it is not a char that has case, 1 if it is lower case, 
            ** and 2 if it is upper case
            ** Decription: Determines case of char
            */  
            int determine_case_of_char(char x);

            /*
            ** inputs: an int (0 to 9)
            ** outputs: a char
            ** Decription: turns the inputted int (0 to 9) to a char representation (0 to 9)
            */  
            char con(int x);

            /*
            ** inputs: a char (charaters 0 to 9 only)
            ** outputs: an int
            ** Decription: turns the int in character form back into integer form
            */  
            int con(char x);

            /*
            ** inputs: a double (the number), a double the tolerance on that number, the number that the first double must be less than the tolerance
            ** away from
            ** outputs: a bool (whether the number was within the tolerance of the goal double, true if it was within the tolerance)
            ** Decription: determines whether a number is within a tolerance of another number
            */  
            bool within_tol(double num, double tol, double goal);

            /*
            ** inputs: a string passed by reference
            ** outputs: NONE
            ** Decription: removes all the spaces in the inputted string
            */  
            void rm_space(std::string& Line);

            /*
            ** inputs: a string 
            ** outputs: NONE
            ** Decription: converts all of the characters in the string to upper case
            */  
            void to_upper(std::string& line);

            /*
            ** inputs: a char 
            ** outputs: NONE
            ** Decription: converts the inputted char to upper case
            */  
            void to_upper(char& x);

            /*
            ** inputs: a string 
            ** outputs: NONE
            ** Decription: converts all of the characters in the string to lower case
            */  
            void to_lower(std::string& line);
            
            /*
            ** inputs: a char 
            ** outputs: NONE
            ** Decription: converts the inputted char to lower case
            */  
            void to_lower(char& x);

        // Source file: file_handling.cpp
            // file and directory handling
            
            void opening_error(std::string file_name);
            
            void copy_lines_of_file_to_vector(std::vector<std::string>& lines, std::string file_name_or_path);
            
            void write_lines_of_vector_to_file(std::vector<std::string> lines, std::string file);
            
            void write_line_to_file(std::string line, std::string file_name_or_path);
                // copies the lines from one file to another file
            
            void copy_lines_from_one_file_to_another(std::string source_file_name, std::string destination_file_name);
            
            void copy_contents_from_one_directory_to_another(std::string source_directory_name_or_path, std::string destination_directory_name_or_path);
            
            void make_these_files(std::vector<std::string> files_to_make);
            
            void make_these_files(std::string files_to_make);
            
            void remove_these_files(std::vector<std::string> files_to_remove);
            
            void remove_these_files(std::string files_to_remove);
            
            void make_these_directories(std::vector<std::string> directories_to_make);
            
            void make_these_directories(std::string directories_to_make);
            
            void remove_these_directories(std::vector<std::string> directories_to_remove);
            
            void remove_these_directories(std::string directories_to_remove);

            // returns file name
            std::string copy_file_to_cur_dir_to_open (std::string absolute_path);

            // copies file back to the directory it came from
            void copy_file_back_to_original_directory (std::string absolute_path);  


};

#endif