#include "../lib.h"

// finds the position of the first instance of a char in a string, if no instance then returns the length of
// the string
int lib::first(std::string line, char x) {
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == x) {
            return i;
        }
    }
    return -1;
}


// finds the position of the last instance of a smaller string in a string, if no instance then returns -1
int lib::first(std::string line, std::string x) {
    if (x.length() <= line.length()){
        for (int i = 0; i < line.length() - x.length(); i++) {
            if (line.substr(i, x.length()) == x) {
                return i;
            }
        }
    }
    return -1;
}

// finds the last instance of a string in a string, if no instance then returns -1
int lib::last(std::string line, std::string x) {
    int pos = -1;
    if (x.length() <= line.length()){
        for (int i = 0; i < line.length(); i++) {
            if (line.substr(i, x.length()) == x) {
                pos = i;
            }
        }
    }
    return pos;
}

// finds the last instance of a char in a string, if no instance then returns -1
int lib::last(std::string line, char x) {
    int pos = -1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == x) {
            pos = i;
        }
    }
    return pos;
}

// finds first instance of a string in a vector of strings, if no instance then returns the number
// of elements in the vector
int lib::first(std::vector<std::string> vars, std::string op) {
    for (int j = 0; j < vars.size(); j++) {
        if (vars[j] == op) {
            return j;
        }
    }
    return -1;
}

// returns if there is an int with the same value in the vector
int lib::first(std::vector<int> stor, int x) {
    for (int y = 0; y < stor.size(); y ++) {
        if (stor[y] == x) {
            return y;
        }
    }
    return -1;
}

// returns if there is an int with the same value in the vector
int lib::first(std::vector<double> stor, double x) {
    for (int y = 0; y < stor.size(); y ++) {
        if (stor[y] == x) {
            return y;
        }
    }
    return -1;
}


// searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
// the string, everything after the string, or replace the string itself
void lib::search_for_and_replace_string_in_vector_with_options(std::vector<std::string>& lines, 
                                                            std::string to_find, 
                                                            std::string replacement, 
                                                            int option /* options: before = 0, after = 1, on = 2 */ ){
    // instance of library
    lib inst;
    
    // informing the user what is happening
    //inst.print("searching for replacement");
    
    // temporary variable to store substrings of an element of the inputted vector
    std::string temp;

    // boolean that allows the nested loops to all be exited
    //bool exit = false;

    // iterates through all the elements of the vector
    for (std::string& line : lines){

        //inst.print("Line in vector: " + line);

        // checking to make sure the element is large than what is needs to be found
        if(line.length() >= to_find.length()){
            
            // iterating through the element
            for (int i = 0; i < (line.length() - to_find.length()); i++){
                
                // assigning substring of the line that is the same length as the string that needs to be found
                temp = line.substr(i, to_find.length());

                //inst.print("Temp: " + temp);

                // if the substring is what needs to be found
                if(temp == to_find){

                    // informing the use
                    //inst.print("found the string to replace: " + to_find);
                    
                    // setting bool so after this iteration all loops will be exited
                    //exit = true;

                    // determining where to put the replacement string depending where the user specified
                    switch (option)
                    {
                    // if the replacement string needs to placed after the string that was found
                    case 1:
                       // adding neccessary string// inserting the replacement string directly after the string that was found
                        for (int j = 0; j < replacement.length(); j++){
                            line.push_back(replacement[j]);
                        }
                        
                        break;

                    // if the replacement string needs to be replaced before the string that was found
                    case 0:
                        // informing the use
                        //inst.print("inserting at the beginning");

                        // erasing all characters that come before the string that was found
                        line.erase(line.begin(), line.begin() + i);

                        // inserting the replacement string directly in front of the string that was found
                        for (int j = 0; j < replacement.length(); j++){
                            line.insert(line.begin(), replacement[j]);
                        }
                        
                        break;

                    // if the replacement string needs to replace the string that was found
                    case 2:
                        // informing the user
                        //inst.print("inserting by replacing");

                        // erasing the string that was found
                        line.erase(line.begin() + i, line.begin() + i + to_find.length());

                        // inserting the replacement string in the found string's place
                        for (int j = 0; j < replacement.length(); j++){
                            line.insert(line.begin() + i + j, replacement[j]);
                        }

                        break;
                    }
                    
                }

                // if this for loop should be exited
                //if (exit) break;
            }
        }
        // if the element of the vector was not longer than the string that needs to be found, the for loop just increments
        else{
            continue;

        }

        // if this for loop should be exited
        //if(exit) break;
    }
}