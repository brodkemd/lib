#include "../lib.h"

// prints whether there was an error opening a file or not
void lib::opening_error(std::string file_name){
    std::cout << "Error opening: " << file_name << std::endl;
}

// writes each column in the inputted vector to a line in the file with name that is also inputted, can provide the absolute path of the file
void lib::write_lines_of_vector_to_file(std::vector<std::string> lines, std::string file_name_or_path){

    // instance of library
    lib inst;

    // informing the user what is happening
    //inst.print("writing lines to file: " + file_name_or_path);

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
// searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
// the string, everything after the string, or replace the string itself 
// options: before = 0, after = 1, on = 2
void lib::search_for_and_replace_string_in_file_with_options(std::string file_name_or_path, std::string to_find, std::string replacement, int option){
    
    // instance of this library
    lib inst;
    
    // vector to store contents of file
    std::vector<std::string> lines_in_file;

    inst.print("copying");
    // copies the lines of a file into a vector
    inst.copy_lines_of_file_to_vector(lines_in_file, file_name_or_path);

    inst.print("looking");
    inst.print(lines_in_file);
    // searches for and replaces the to_find string with the replacement string in the vector of the file contents
    inst.search_for_and_replace_string_in_vector_with_options(lines_in_file, "he", "she", false, false, 2);
    
    inst.print("writing");
    // writes the changed lines back to the file
    inst.write_lines_of_vector_to_file(lines_in_file, file_name_or_path);
}

// copies lines from the input file into the inputted vector, can provide the absolute path of the file, will erase vector that is inputted
void lib::copy_lines_of_file_to_vector(std::vector<std::string>& lines, std::string file_name_or_path){

    // clearing the inputted vector
    lines.clear();

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


// copies the lines from one file to another file
void lib::copy_lines_from_one_file_to_another(std::string source_file_name, std::string destination_file_name){
    // empty vectors to store the lines from each file
    std::vector<std::string> lines_in_source_file;

    // instance of this library
    lib inst;

    // copies lines of the source file to its corresponding vector
    inst.copy_lines_of_file_to_vector(lines_in_source_file, source_file_name);

    // writes the lines of the source file to the destination file
    inst.write_lines_of_vector_to_file(lines_in_source_file, destination_file_name);

}

// copies the contents of one directory to another
void lib::copy_contents_from_one_directory_to_another(std::string source_directory_name_or_path, std::string destination_directory_name_or_path){
    // instance of this library
    lib inst;

    //string that holds the commands to be excuted by the kernal
    std::string copy_command;

    // adding command, moves to source directory
    copy_command = "cd " + source_directory_name_or_path + "; ";

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
    std::string make_command = "touch ";
    make_command += inst.vector_to_string(files_to_make, true);

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

// removes the files listed in the inputted vector
void lib::remove_these_files(std::string files_to_remove){
    // instance of this library
    lib inst;

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm " + files_to_remove;

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

// copies the file from the absolute path to the directory of the executing code, returns the the file name
std::string lib::copy_file_to_cur_dir_to_open (std::string absolute_path) {
    // instance of library
    lib inst;

    // empty string to write the file name to
    std::string file_name;

    // checks to make sure the file does not exist in the current directory by looking for the / in the file name
    if (inst.first(absolute_path, '/') != -1){

        // declaring neccessary string to be added to the vector
        std::string command = "cp ";
        
        // adding the path of the file to the string
        command += absolute_path;

        // adding a neccessary item to the string
        command += " `pwd`";

        // running the string in terminal
        inst.run_command(command);

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
    std::string command = "cp ";

    // adding the path of the file to the string
    command += file_name;

    // adding a space
    command += " ";

    // adding a neccessary item to the string
    command += absolute_path;

    // adding ; to seperate commands
    command += "; ";

    // adds line to the input vector that removes file from the current directory
    command += "rm " + file_name;

    // running the command in terminal
    inst.run_command(command);


}
