#include "lib.h"

int main(){
  std::vector<std::string> files = {"h", "l"};
  lib lib;
  lib.run_command(files);
}
