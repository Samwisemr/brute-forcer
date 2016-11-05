#include <cstdlib>
#include <iostream>
#include <string>

/* Description:
 *  prints every combination of a desired amount of characters possible(ascii decimals 32-126)
 *
 * pass in a string of the combo so far
 * if the string is the desired length:
 *      print the string
 * else:
 *      for each character possible:
 *          append that character to the string and recurse
*/

void usage(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
    std::cout << "Usage: wififuck GENERATED-STRING-LENGTH" << std::endl;
    exit(1);
}

void gen_pwd(std::string input, int finalLen) {
    if (input == "s7=") {
        std::cout << "Success! " << input << " is the password!" << std::endl;
        exit(0);
    } else if (input.length() == finalLen) {
        std::cout << input << std::endl;
    } else {
        std::string new_str;
        for (int possibleChar = 32; possibleChar <= 126; possibleChar++) {
            new_str = input;
            new_str += (char)possibleChar;
            gen_pwd(new_str, finalLen);
        } // for
    } // if
}


int main(int argc, char *argv[]) {
    switch(argc) {
        case 2:
            gen_pwd("", atoi(argv[1]));
            break;
        default:
            usage("invalid number of arguments");
    } // switch
    exit(0);
} // main
