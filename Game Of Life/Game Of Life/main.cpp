//
//  main.cpp
//  Game Of Life
//
//  Created by Michael Liu on 1/26/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


//counts the number of columns
int count_y(const string& s){
    int y = 0;
    for(size_t i = 0; i<s.length();++i){
        if (s[i] == '\n'){
            y++;
        }
    }
    return y;
}

//counts the length of the row
int count_x(const string& s){
    int x = 0;
    for(size_t i = 0; i<s.length(); ++i){
        if(s[i]=='\n'){
            break;
        }
        x++;
    }
    return x;
}

string read_input(const string& filename){
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "failed to open file\n";
        exit(1);
    }
    string s((std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()));
    return s;
}
//creates a 2d vector of ints, 0 is dead/no cell, 1 is alive cell
vector<vector<int>> convert_string_to_matrix(const string& s){
    vector<vector<int>> matrix;
    int column = count_y(s);
    int string_index = 0;
    int column_count = 0;
    int row_count = 0;
    while(column_count<column){
        vector<int> curr_row;
        while(s[string_index]!='\n'){
            if(s[string_index] == '*'){
                curr_row.push_back(1);
                row_count++;
                string_index++;
            }else if(s[string_index] == '-'){
                curr_row.push_back(0);
                row_count++;
                string_index++;
            }
        }
        row_count = 0;
        string_index++;
        matrix.push_back(curr_row);
        column_count++;
    }
    cout<<column_count<<endl;
    return matrix;
}

string print_2d_vector(const vector<vector<int>>& matrix){
    string grid;
    for (size_t i = 0; i < matrix.size(); i++){
        string line;
        for (size_t j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]==1){
                line.push_back('*');
            }else{
                line.push_back(' ');
            }
        }
        
        grid+=line;
        grid+='\n';
    }
    return grid;
}


int num_of_neighbors(const vector<vector<int>>& matrix, int column, int row){
    int num_of_neighbors = 0;
    for(int i = column-1; i<=column+1; i++){
        for(int j = row-1; j<=row+1; j++){
            if(i==column&&j==row){
                continue;
            }
            if (i>-1&&i<matrix.size()&&j>-1&&j<matrix[0].size()){
                if (matrix[i][j]==1){
                    num_of_neighbors++;
                }
            }
        }
    }
    return num_of_neighbors;
}

vector<vector<int>> next_state(const vector<vector<int>>& matrix){
    vector<vector<int>> next = matrix;
    for(int i = 0; i<matrix.size(); i++){
        for (int j = 0; j<matrix[i].size(); j++){
            if(num_of_neighbors(matrix, i, j)<2 ||num_of_neighbors(matrix, i, j)>3){
                next[i][j] = 0;
            }else if(num_of_neighbors(matrix, i, j)==3){
                next[i][j] = 1;
            }else{
                continue;
            }
        }
    }
    
    return next;
}




int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = read_input("life.txt");
    vector<vector<int>> board = convert_string_to_matrix(s);
    cout<<"Initial World"<<endl;
    cout<<print_2d_vector(board)<<endl;
    cout<<"====================="<<endl;
    int generation;
    cout << "Enter generation: ";
    cin >> generation;
    for(int i = 1; i<=generation; i++){
        cout<<"Generation "<<i<<endl;
        board = next_state(board);
        cout<<print_2d_vector(board)<<endl;
        cout<<"====================="<<endl;

    }
    

   
    return 0;
}
