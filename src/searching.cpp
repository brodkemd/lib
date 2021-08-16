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
        for (int i = 0; i < (line.length() - x.length()); i++) {
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


// returns 0 if it is not a char that has case, 1 if it is lower case, and 2 if it is upper case
int lib::determine_case_of_char(char x){
    lib inst;
    // if the char is lower case, returns a 1
    if (inst.first(inst.lower_alphabet(), x) != -1) {
        return 1;
    }
    // if the char is uppercase, returns a 2
    else if (inst.first(inst.upper_alphabet(), x) != -1) {
        return 2;
    }
    // if the char is not a letter it returns 0
    else {
        return 0;
    }
}

// finds the first letter in a string
int lib::find_first_letter_in_string (std::string line){
    lib inst;
    int i = 0;
    // while the char in the string is not a member of the upper or lower case alphabet the int is incremented
    while (inst.first(inst.param_upper_alphabet, line[i]) == -1 && inst.first(inst.param_lower_alphabet, line[i]) == -1){
        i++;
    }

    return i;
}

// currently only supports if the beginning of a string is capitalized or the while thing
void lib::match_case_of_strings(std::string to_match_case, std::string& to_change_case){
    // instance of this library
    lib inst;

    // finds the index of the first letter in to_match_case
    int position_of_first_letter_in_to_match_case = inst.find_first_letter_in_string(to_match_case);
    
    // finds the index of the first letter in to_change_case
    int position_of_first_letter_in_to_change_case = inst.find_first_letter_in_string(to_change_case);
    
    // varible that holds how many uppercase letters there are in the to_match_case string
    int count = 0;

    // iterates through the to_match_case string starting at the position of the first letter
    for (int i = position_of_first_letter_in_to_match_case; i < to_match_case.length(); i++){
        // if the char in the string it upper case
        if (inst.determine_case_of_char(to_match_case[i]) == 2) {
            count++;
        }

        // if there are two upper case letters in the string then the for loop is exiteds
        if (count == 2){
            break;
        }
    }
    switch (count)
    {
    case 0:
        // if there were no upper case letters in the to_match_case string, then the to_change_case string
        // is converted to all lower case
        inst.to_lower(to_change_case);
        break;
    
    case 1:
        // if there was one upper case letters in the to_match_case string, then the first letter in the 
        // to_change_case to converted to upper case
        inst.to_upper(to_change_case[position_of_first_letter_in_to_change_case]);
        break;
    
    case 2:
        // if there was more than one upper case letter in the to_match_case string, all of the letters in
        // to_change_case are converted to upper case
        inst.to_upper(to_change_case);
        break;

    }
}


// searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
// the string, everything after the string, or replace the string itself 
// options: before = 0, after = 1, on = 2
void lib::search_for_and_replace_string_in_vector_with_options(std::vector<std::string>& lines, 
                                                            std::string to_find, 
                                                            std::string replacement,
                                                            bool ignore_case,
                                                            bool match_case, 
                                                            int how_to_replace){
    // instance of library
    lib inst;

    std::string line_before_change;

    if (match_case){
        ignore_case = true;
    }
    
    if (ignore_case){
        inst.to_upper(to_find);
    }
    
    // informing the user what is happening
    //inst.print("searching for replacement");
    
    // temporary variable to store substrings of an element of the inputted vector
    std::string temp;

    // iterates through all the elements of the vector
    for (std::string& line : lines){

        //inst.print("Line in vector: " + line);
        if (ignore_case){
            line_before_change = line;
            inst.to_upper(line);
        }

        // checking to make sure the element is large than what is needs to be found
        if(line.length() >= to_find.length()){
            
            // iterating through the element
            for (int i = 0; i < ((line.length() -1) - to_find.length()); i++){
                
                if ((i + line.length() - 1) < line.length()){
                    // assigning substring of the line that is the same length as the string that needs to be found
                    temp = line.substr(i, to_find.length());
                }
                else {
                    break;

                }

                //inst.print("Temp: " + temp);

                // if the substring is what needs to be found
                if(temp == to_find){
                    
                    // if case does not matter
                    if (ignore_case){
                        
                        // reseting the line back to its original state
                        line = line_before_change;

                        // if the user wants the strings to have matching case
                        if (match_case){
                            // calling a function that matches the case of the two strings
                            inst.match_case_of_strings(line.substr(i, to_find.length()), replacement);
                            
                            //inst.print("replacement: " + replacement);

                        }
                    }
                    
                    
                    // informing the use
                    //inst.print("found the string to replace: " + to_find);

                    // determining where to put the replacement string depending where the user specified
                    switch (how_to_replace)
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
            }
        }
        // if the element of the vector was not longer than the string that needs to be found, the for loop just increments
        else{
            continue;

        }
    }
}

// do not use this unless neccessary, it is 75 times slower than the one above you
/*
void search(std::string line, std::string to_find){
  if (to_find.length() < line.length()){    
    int middle_r;
    int middle_l;

    if (line.length() % 2 == 0){
      middle_l = line.length() / 2;
      middle_r = (line.length() / 2 - 1);
    }
    else { 
      middle_l = floor(line.length() / 2);
      middle_r = middle_l;
    }

    for (int i = 0; i < ceil(line.length() / 4); i++){
      if (to_find[0] == line[i]) {
        if (line.substr(i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;;
        }
      }

      if (to_find[0] == line[middle_l - i]){
        if(line.substr(middle_l - i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }

      if (to_find[0] == line[middle_r + i]){
        if(line.substr(middle_r + i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }
      if (to_find[to_find.length() - 1] == line[line.length() - 1 - i]){
        if(line.substr(line.length() - 1 - i - (to_find.length() - 1), to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }
    }
  }
  else if (to_find.length() == line.length()){
    if (to_find == line){
        std::cout << "got one" << std::endl;
    }
  }

}
*/