//This class decrypts text files that uses Caesar Cypher as
//laid out in the instructions for the HW1
//  main.cpp
//  Caesar Cypher
//

//  Created by Michael Liu on 1/28/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/**
 This method takes the parameter of the character to be decrypted and the rotation number
 It returns the character after the rotation
 **/
char decrypt_character(char character,int rotation){
    char decrypted;
    int character_integer = character;
    if(character_integer>='a' && character_integer<='z'){
        if(character_integer-rotation>='a'){
            decrypted = char(character_integer-rotation);
        }
        else{
90        }
    }
    else{
        decrypted = character;
    }
    return decrypted;
}

//this method modifies the string and decrypts by rotating all lower case letters
//takes in the string to be modified and the rotation number, returns void
void decrypt_string(string& str, int rotation){
    for(size_t index = 0; index<str.length(); index++){
        str[index] = decrypt_character(str[index], rotation);
    }
}



//main function used to run the program
int main() {
    //this block of code reads the text file into a input file stream, if no file found outputs ""failed to open file"
    ifstream ifs("encrypted.txt");
    if (!ifs) {
        cerr << "failed to open file\n";
        exit(1);
    }
    //this following block of code reads the first line of the input file stream which is the rotation
    //number
    string line;
    getline(ifs, line);
    int x = line[0] - '0';
    //this vector is used to reverse the lines in the textfiles
    vector<string> reverse_lines;
    //reads the input stream line by line and push them into the vector after decrypting them
    while (getline(ifs, line)) {
        decrypt_string(line, x);
        reverse_lines.push_back(line);
    }
    //prints the lines in the vector in reverse order
    for(size_t index = reverse_lines.size(); index>0; index--){
        cout<<reverse_lines[index-1]<<endl;
    }
    return 0;
}




