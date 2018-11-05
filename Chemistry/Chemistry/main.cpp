//
//  main.cpp
//  Chemistry
//
//  Created by Michael Liu on 2/2/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//struct hydrocarbon stores the string name, number of carbon molecules and number of hydrogen molecules
struct HydroCarbon{
    vector<string> name;
    int carbonNum;
    int hydrogenNum;
};

//checks if the character is a digit
bool isDigit(char character){
    return '0'<=character && character<='9';
}


//sort the vector of hydrocarbons using carbon number in acending order, modifies original list
void sortHydroCarbon(vector<HydroCarbon>& list){
    for(int i = 0; i<list.size();i++){
        int minCarbonIndex = i;
        int j = i;
        for(;j<list.size(); j++){
            if(list[j].carbonNum < list[minCarbonIndex].carbonNum){
                minCarbonIndex = j;
            }
        }
        HydroCarbon temp = list[i];
        list[i] = list[minCarbonIndex];
        list[minCarbonIndex] = temp;
    }
}

//display hydrocarbon object
void displayHydroCarbon(const HydroCarbon& molecule){
    string string = "C";
    string+=to_string(molecule.carbonNum);
    string+="H";
    string+=to_string(molecule.hydrogenNum);
    for(int i = 0; i<molecule.name.size(); i++){
        string+=" ";
        string += molecule.name[i];
    }
    cout<<string<<endl;
}

//reads the textfile and puts all molecules into the vector of hydrocarbons
vector<HydroCarbon> readHydroCarbonFile(const string& filename){
    ifstream textfile(filename);
    if(!textfile){
        cerr<<"file could not be opened"<<endl;
    }
    string word;
    char C;
    int cNum;
    char H;
    int hNum;
    //list of hydrocarbons
    vector<HydroCarbon> listOfHydroCarbon;
    while(textfile>>word>> C>>cNum>> H>> hNum){
        HydroCarbon molecule;
        molecule.name.push_back(word);
        molecule.carbonNum = cNum;
        molecule.hydrogenNum = hNum;
        bool sameMolecule = false;
        for (int i=0; i<listOfHydroCarbon.size(); i++) {
            if(molecule.hydrogenNum == listOfHydroCarbon[i].hydrogenNum &&
               molecule.carbonNum == listOfHydroCarbon[i].carbonNum){
                listOfHydroCarbon[i].name.push_back(molecule.name[0]);
                sameMolecule = true;
            }
        }
        if(!sameMolecule){
            listOfHydroCarbon.push_back(molecule);
        }
    }
    
    textfile.close();
    return listOfHydroCarbon;
}


//main runs the program
int main() {
    vector<HydroCarbon> listOfHydroCarbon = readHydroCarbonFile("formula.txt");
    sortHydroCarbon(listOfHydroCarbon);
    for(int i = 0; i<listOfHydroCarbon.size(); i++){
        displayHydroCarbon(listOfHydroCarbon[i]);
    }
    

    return 0;
}
