/**
    This code will do all the functions necessary to intake a properly formatted file with an instruction to add two
    hexadecimal numbers and perform the operation. This is for the Cs219 class with Mr. Dwight Poplin.
    @file main.cpp
    @author Weslee Bovee
    @version 1.0 1/28/2022
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
    int main(int argc, char const *argv[]) {

    int NUM_ARGS = 2;
    unsigned int op1, op2, r;

        if (argc < NUM_ARGS) {
            std::cout << "Correct usage:" << std::endl;
            std::cout << argv[0] << " filename" << std::endl;
            return 0;
        }
        std::string file = argv[1];
        std::ifstream fin; //file being read
        fin.open(file);

            if (fin.is_open()){
                //insert while loop conditions
//_________________________THIS WHILE LOOP INTAKES INFORMATION LINE BY LINE________________________
                while (!fin.eof()) {

//_________________________READING LINE IN TO INDIVIDUAL STRINGS_______________________________________
                    std::string operation, operand1, operand2;
                    fin >> operation >> operand1 >> operand2;
                    //if "my_stream"  doesnt work, try "fin"

//_________________________CONVERTING HEX STRINGS TO INT______________________________________________
                std::stringstream opOne;
                opOne << std::hex << operand1;
                opOne >> op1;

                std::stringstream opTwo;
                opTwo << std::hex << operand2;
                opTwo >> op2;


//__________________________COMPUTING_______________________________________________________
                    if(operation.compare("ADD")==0) {
                        r = op1 + op2;
//___________________________RETURNING r TO HEX _________________________________________

                        std::stringstream stream;
                        stream << std::hex << r;
                        std::string result( stream.str() );


//________________________PRINTING RESULT_______________________________________________________
                        std::cout << operand1 << " plus " << operand2 << " equals--------- 0x" << result << std::endl;
                    }

                }
            }
            fin.close();

    return 0;
}
