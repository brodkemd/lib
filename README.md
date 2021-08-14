# Library
Functions that accomplish simple yet useful tasks that I use frequently.

See the header file to get more detail on what this code involves.

/*
void search(std::string line, std::string to_find){
    std::string temp;

    if(to_find.length() < line.length()){
        for (int i = 0; i < ((line.length() -1) - to_find.length()); i++){
            if ((i + line.length() - 1) < line.length()){
                temp = line.substr(i, to_find.length());
            }
            else {
                break;

            }

            if(temp == to_find){
                std::cout << "got one" << std::endl;
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
