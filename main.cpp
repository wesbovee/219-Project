/**
    This code will do all the functions necessary to intake a properly formatted file with an instruction to add two
    hexadecimal numbers and perform the operation. This is for the Cs219 class with Mr. Dwight Poplin.
    @file main.cpp
    @author Weslee Bovee
    @version 1.0 1/28/2022
*/

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>


std::string decToBi(int n){
    int mod;
    int num=n;
    int i=0;
    int biar[32];
    std::string binum ="";
    while (num!=0){

        mod = num%2;
        num=num/2;
        biar[i] = mod;
        i++;
    }
    i--;
    while(i>=0) {
        std::string bit = std::to_string(biar[i]);
        binum += bit;
        i--;
    }
    return binum;
}

int biToDec(std::string bits){
    std::string binum = bits;
    int n = binum.length();

    char cbiar[n+1];
    int biar[n];
    int tot[n];

    std::strcpy(cbiar, binum.c_str());
    int i=0;
    int b=n;

    while(b>0) {
        biar[i] = cbiar[i] - '0';
        //std::cout << biar[i] << std::endl;
        i++;
        b--;
    }
    i=0;
    int compBiar[n];
    int m=n;

    while(n>0) {
        compBiar[i] = pow(2, n-1);
        n--;
        i++;
    }
    int t=m;
    i=0;

    while(m>=0) {
        tot[i]= biar[i] * compBiar[i];
        m--;
        i++;
    }
    i=0;
    int dec=0;
    while(t>0){
        dec +=tot[i];
        i++;
        t--;
    }
    return dec;
}

int add(int first, int second){
    int r = first + second;
    return r;
}

int sand(int first, int second) {

    std::string one = decToBi(first);

    int lengA = one.length();
    std::string binum;

    std::string two = decToBi(second);
    int lengB = two.length();
    std::string r;
    int i=0;
    int n;
    int res;
    if (lengA == lengB){

        n=lengB;


        while(n>0){
            if ((one[i]=='1') && (two[i]=='1')){
                r+='1';
                n--;
                i++;
            }
            else{
                r+='0';
                n--;
                i++;
            }
        }



    }

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else if(lengA<lengB){
        std::string bloop;
        for (int i=0; i<(lengB-lengA);i++){
            bloop+='0';
        }
        bloop+= one;


        n=lengB;


        while(n>0){
            if ((bloop[i]=='1') && (two[i]=='1')){
                r+='1';
                n--;
                i++;
            }
            else{
                r+='0';
                n--;
                i++;
            }
        }
    }
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else {
        std::string bloop;
        for (int i=0; i<(lengA-lengB);i++){
            bloop+='0';
        }
        bloop+= two;


        n=lengA;


        while(n>0){
            if ((one[i]=='1') && (bloop[i]=='1')){
                r+='1';
                n--;
                i++;
            }
            else{
                r+='0';
                n--;
                i++;
            }
        }
    }

    std::string bit(r);


    res = biToDec(bit);

    return res;
}

int asr(int first){
    std::string one = decToBi(first);
    int n = one.length();
    std::string shifted = one;
    shifted.resize (n - (n-1));
    shifted+=one;
    shifted.resize (n -1);

    int res = biToDec(shifted);
    return res;

}
//do a 1 bit arithmetic shift right on first opp

int lsr(int first){
    std::string one = decToBi(first);
    int n = one.length();
    std::string shifted ="0";
    shifted+=one;
    shifted.resize(n-1);

    int res = biToDec(shifted);
    return res;

}
//1 bit logical shift right on first operand

int lsl(int first){
    std::string one = decToBi(first);
    int n = one.length();
    std::string shifted =one;
    shifted.erase(0,1);;
    shifted+='0';


    int res = biToDec(shifted);
    return res;

}
// 1 bit logical shift left on first operand

int snot(int first){
    std::string one = decToBi(first);
    int n = one.length();
    std::string notted="";

    for(int i =0; i<=n; i++){
        if (one[i]=='1'){
            notted += '0';
            i++;
        }
        else{
            notted +='1';
            i++;
        }
    }

    int res = biToDec(notted);
    return res;
}
// bitwise not

int orr(int first, int second) {

    std::string one = decToBi(first);
    int lengA = one.length();
    std::string binum;

    std::string two = decToBi(second);
    int lengB = two.length();
    std::string r="";
    int i=0;
    int n;
    int res;
    if (lengA == lengB){

        n=lengB;


        while(n>0){
            if ((one[i]=='1') || (two[i]=='1')){
                r+='1';
                n--;
                i++;
            }
            else{
                r+='0';
                n--;
                i++;
            }
        }



    }

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else if(lengA<lengB){
        std::string bloop;
        for (int i=0; i<(lengB-lengA);i++){
            bloop+='0';
        }
        bloop+= one;


        n=lengB;


        while(n>0){
            if ((bloop[i]=='1') || (two[i]=='1')){
                r+='1';
                n--;
                i++;
            }
            else{
                r+='0';
                n--;
                i++;
            }
        }
    }
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else {
        std::string bloop;
        for (int i=0; i<(lengA-lengB);i++){
            bloop+='0';
        }
        bloop+= two;

        n=lengA;


        while(n>0){
            if ((one[i]=='1') || (bloop[i]=='1')){
                r+='1';
                n--;
                i++;

            }
            else{
                r+='0';
                n--;
                i++;

            }
        }
    }


    std::string bit(r);

    res = biToDec(bit);

    return res;
}
//bitwise or of operands
int sub(int first, int second) {
    int r = first - second;
    return r;
}
//subtract second opperand from the first
int sxor(int first, int second){

    std::string one = decToBi(first);
    int lengA = one.length();
    std::string binum;
    std::string two = decToBi(second);

    int lengB = two.length();
    std::string r;
    int i=0;
    int n;
    int res;
    if (lengA == lengB){

        n=lengB;



        while(n>0){
            if ((one[i]=='0') && (two[i]=='0')){
                r+='0';
                n--;
                i++;
            }
            else if ((one[i]=='1') && (two[i]=='1')){
                r+='0';
                n--;
                i++;
            }
            else{
                r+='1';
                n--;
                i++;
            }

        }

    }

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else if(lengA<lengB){
        std::string bloop;
        for (int i=0; i<(lengB-lengA);i++){
            bloop+='0';
        }
        bloop+= one;


        n=lengB;


        while(n>0){
            if ((bloop[i]=='0') && (two[i]=='0')){
                r+='0';
                n--;
                i++;
            }
            else if ((bloop[i]=='1') && (two[i]=='1')){
                r+='0';
                n--;
                i++;
            }
            else{
                r+='1';
                n--;
                i++;
            }

        }
    }
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    else {
        std::string bloop;
        for (int i=0; i<(lengA-lengB);i++){
            bloop+='0';
        }
        bloop+= two;


        n=lengA;


        while(n>0){
            if ((one[i]=='0') && (bloop[i]=='0')){
                r+='0';
                n--;
                i++;
            }
            else if ((one[i]=='1') && (bloop[i]=='1')){
                r+='0';
                n--;
                i++;
            }
            else{
                r+='1';
                n--;
                i++;
            }

        }
    }


    std::string bit(r);

    res = biToDec(bit);
    return res;
}

//bitwise xor of opperands


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
            if(operation=="ADD"){
                r = add(op1, op2);  //i need help here**********************
                std::cout << "ADD result: " << std::endl;
            }
            else if (operation=="AND"){
                r = sand(op1, op2);
                std::cout << "AND result: " << std::endl;
            }
            else if (operation=="ASR"){
                r = asr(op1);
                std::cout << "ASR result: " << std::endl;
            }
            else if (operation=="LSR"){
                r = lsr(op1);
                std::cout << "LSR result: " << std::endl;
            }
            else if (operation=="LSL"){
                r = lsl(op1);
                std::cout << "LSL result: " << std::endl;
            }
            else if (operation=="NOT"){
                r = snot(op1);
                std::cout << "NOT result: " << std::endl;
            }
            else if (operation=="ORR"){
                r = orr(op1, op2);
                std::cout << "ORR result: " << std::endl;
            }
            else if (operation=="SUB"){
                r = sub(op1, op2);
                std::cout << "SUB result: " << std::endl;
            }
            else if (operation=="XOR"){
                r = sub(op1, op2);
                std::cout << "XOR result: " << std::endl;
            }
            else {
                return 0;
            }


//___________________________RETURNING r TO HEX _________________________________________

            std::stringstream stream;
            stream << std::hex << r;
            std::string result( stream.str() );


//________________________PRINTING RESULT_______________________________________________________
            std::cout << "0x" << result << std::endl << std::endl;
        }

    }

    //fin.close();

    return 0;
}
