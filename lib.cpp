#include "lib.h"

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

// finds the last instance of a char in a string, if no instance then returns the length of
// the string
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

// converting functions
// converts int to char
char lib::con(int x) {
    char y[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int i = 0;
    while (x != i) {
        i++;
    }
    return y[i];
}

// converts char to int
int lib::con(char x) {
    char y[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int i = 0;
    while (x != y[i]) {
        i++;
    }
    return i;
}

bool lib::within_tol(double num, double tol, double goal){
    if(abs(abs(num) - abs(goal)) < tol){
        return true;
    }
    return false;
}

// removes spaces
void lib::rm_space(std::string& Line) {
    std::string temp;

    // scanning through the string
    for (int i = 0; i < Line.size(); i++) {

        // if there is not a space then it adds the character the string declared above
        if (Line[i] != ' ') {
            temp.push_back(Line[i]);
        }
    }

    // assigns the original string to the filtered string, the original string is passed by
    // reference so it is changed
    Line = temp;
}

// converts string to upper case
void lib::to_upper(std::string& line){
    std::string alphabet_upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(char& it : line){
        for(char letter : alphabet_upper_case){
            if(std::tolower(letter) == it){
                it = letter;
            }
        }
    }
}  

// clears the command_input char*
void lib::clear_command_input(){
    // instance of this library
    lib inst;

    //clearing the memory
    memset(inst.command_input, 0, SIZE);
}

// prints whether there was an error opening a file or not
void lib::opening_error(std::string file_name){
    std::cout << "Error opening: " << file_name << std::endl;
}

// copies lines from the input file into the inputted vector, can provide the absolute path of the file
void lib::copy_lines_of_file_to_vector(std::vector<std::string>& lines, std::string file_name_or_path){

    // instance of library
    lib inst;

    // letting use know what is happening
    //inst.print("Copying lines from: " + file_name_or_path);

    
    std::ifstream read;
    
    // opening the inputted file name
    read.open(file_name_or_path);

    // empty variable to copy lines of the file into
    std::string line;

    // checking that the file is open
    if (read.is_open()){

        // while there is a line read it
        while(std::getline(read, line)){
        
            // append the line to the end of the inputted vector
            lines.push_back(line);

        }
    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }
    
    // closing the file
    read.close();
}

// writes each column in the inputted vector to a line in the file with name that is also inputted, can provide the absolute path of the file
void lib::write_lines_to_file(std::vector<std::string> lines, std::string file_name_or_path){

    // instance of library
    lib inst;

    // informing the user what is happening
    inst.print("writing lines to file: " + file_name_or_path);

    std::ofstream write;

    // opening the file
    write.open(file_name_or_path);

    // making sure the file open
    if(write.is_open()){
        // iterates through the elements of the vector and appends a \n to end the line, then writes the line to file
        for(std::string line : lines){
            line += "\n";
            write << line;
        }
    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }

    // closing the file
    write.close();

}

void lib::printCharArray(char *arr, size_t len)
{
    printf("arr: ");
    for (size_t i = 0; i < len; ++i) {
        printf("%c, ", arr[i]);
    }
    printf("\n");
}

// string to char pointer
void lib::string_to_char_pointer(std::string input_string){
    // instance of this library
    lib inst;

    int i = 0;
    // iterates through the string and assigns each element to each element in the global char*
    for(char it : input_string){
        inst.command_input[i] = it;
        inst.print(it);
        i++;
    }
}

// writes the inputted string to the file with name that is also inputted, can provide the absolute path of the file
void lib::write_line_to_file(std::string line, std::string file_name_or_path){

    // instance of library
    lib inst;

    // informing the user what is happening
    inst.print("writing lines to file: " + file_name_or_path);

    std::ofstream write;

    // opening the file
    write.open(file_name_or_path);

    // making sure the file open
    if(write.is_open()){
        // writes the line to file
        write << line;

    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }

    // closing the file
    write.close();
}

// runs the inputted string as a command in terminal
void lib::run_command(std::string command){
    // instance of this library
    lib inst;

    // calling function to convert copy command to a char* for std::system
    inst.string_to_char_pointer(command);
    
    // the copy_command was turned into a char* in the previous command call, command_input is gloabl variable
    std::system(inst.command_input);

    // clearing the global
    inst.clear_command_input();
}

// turns a vector of strings into one continuous string, can choose to have spaces inbetween the indicies of the vector, true if you want spaces
std::string lib::vector_to_string(std::vector<std::string> to_convert, bool spaces){
    // string that is returned
    std::string output;

    // iterates throughthe vector and appends all the members
    for (std::string it : to_convert){
        // appending
        output+=it;

        // adding spaces if specified by the user
        if (spaces){
            output += " ";
        }
    }
    return output;
}

// copies the lines from one file to another file
void lib::copy_lines_from_one_file_to_another(std::string source_file_name, std::string destination_file_name){
    // empty vectors to store the lines from each file
    std::vector<std::string> lines_in_source_file;

    // instance of this library
    lib inst;

    // copies lines of the source file to its corresponding vector
    inst.copy_lines_of_file_to_vector(lines_in_source_file, source_file_name);

    // writes the lines of the source file to the destination file
    inst.write_lines_to_file(lines_in_source_file, destination_file_name);

}

// copies the contents of one directory to another
void lib::copy_contents_from_one_directory_to_another(std::string source_directory_name_or_path, std::string destination_directory_name_or_path){
    // instance of this library
    lib inst;

    //string that holds the commands to be excuted by the kernal
    std::string copy_command;

    // adding command, moves to source directory
    copy_command = "cd " + source_directory_name_or_path;

    // adding command, partial of the copy command
    copy_command += "cp * ";
    
    // determines if a path was provided, if not it adds .. which gives a relative path for the copy command
    // determines this by essentially checking to see if there is a / before directory name
    if ((inst.first(destination_directory_name_or_path, '/') == destination_directory_name_or_path.length() - 1) || (inst.first(destination_directory_name_or_path, '/') == -1)){
        // adding the ../ to the beginning of destination directory variable
        destination_directory_name_or_path.insert(0, "../");
    }

    // adding rest of copy command
    copy_command += destination_directory_name_or_path;

    inst.print("this is the copy command: " + copy_command);

    // running the copy command
    inst.run_command(copy_command);

}

// makes the files listed in the inputted vector
void lib::make_these_files(std::vector<std::string> files_to_make){
    // instance of this library
    lib inst;

    // string that stores the names of the files along with the bash command
    std::string make_command = "touch " + inst.vector_to_string(files_to_make, true);

    // running the make command
    inst.run_command(make_command);
}

// removes the files listed in the inputted vector
void lib::remove_these_files(std::vector<std::string> files_to_remove){
    // instance of this library
    lib inst;

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm " + inst.vector_to_string(files_to_remove, true);

    // running the remove command
    inst.run_command(remove_command);
}

// makes the directories listed in the inputted vector
void lib::make_these_directories(std::vector<std::string> directories_to_make){
    // instance of this library
    lib inst;

    // string that stores the names of the files along with the bash command
    std::string make_command = "mkdir " + inst.vector_to_string(directories_to_make, true);

    // running the make command
    inst.run_command(make_command);
}

// removes the directories listed in the inputted vector
void lib::remove_these_directories(std::vector<std::string> directories_to_remove){
    // instance of this library
    lib inst;

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm -r " + inst.vector_to_string(directories_to_remove, true);

    // running the remove command
    inst.run_command(remove_command);
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

// copies the file from the absolute path to the directory of the executing code, returns the the file name
std::string lib::copy_file_to_cur_dir_to_open (std::string absolute_path) {
    // instance of library
    lib inst;

    // empty string to write the file name to
    std::string file_name;

    // checks to make sure the file does not exist in the current directory by looking for the / in the file name
    if (inst.first(absolute_path, '/') != -1){
        // making a shell script file because it is easier to do it that way
        std::system("touch temp.sh");

        // adding needed items to a string
        std::vector<std::string> input;

        // declaring neccessary string to be added to the vector
        std::string temp = "cp ";
        
        // adding the path of the file to the string
        temp += absolute_path;

        // adding a neccessary item to the string
        temp += " `pwd`";

        // adding string to vector
        input.push_back(temp);

        // running the string the terminal
        inst.write_lines_to_file(input, "temp.sh");

        // running the shell script
        std::system("bash temp.sh");

        // deleting the shell script
        std::system("rm temp.sh");

        // finds last index of / to deternmine the file name
        int pos = inst.last(absolute_path, '/');

        // finding the name of the file from the path
        file_name = absolute_path.substr(pos + 1, absolute_path.length() - (pos + 1));


    }
    // if the file is not in the directory of the executable
    else {
        // do not need to do anything to the provided string
        file_name = absolute_path;

    }

    // returning the file name
    return file_name;
}

// copies the file back to the directory that it came from
void lib::copy_file_back_to_original_directory (std::string absolute_path) {
    // instance of library
    lib inst;
    
    // finds last index of / to deternmine the file name
    int pos = inst.last(absolute_path, '/');

    // finding the name of the file from the path
    std::string file_name = absolute_path.substr(pos + 1, absolute_path.length() - (pos + 1));

    // erasing the path part from the provided path
    absolute_path.erase(absolute_path.begin() + pos, absolute_path.end());

    // adding needed items to a string
    std::vector<std::string> input;

    // declaring neccessary string to be added to the vector
    std::string temp = "cp ";

    // adding the path of the file to the string
    temp += file_name;

    // adding a space
    temp += " ";

    // adding a neccessary item to the string
    temp += absolute_path;

    // adding string to vector
    input.push_back(temp);

    // adds line to the input vector that removes file from the current directory
    temp = "rm " + file_name;

    // adding to input vector
    input.push_back(temp);

    // making a shell script file because it is easier to do it that way
    std::system("touch temp.sh");

    // running the string the terminal
    inst.write_lines_to_file(input, "temp.sh");

    // running the shell script
    std::system("bash temp.sh");

    // deleting the shell script
    std::system("rm temp.sh");
}
