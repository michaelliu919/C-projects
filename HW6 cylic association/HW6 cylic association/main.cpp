//
//  hw6
//
//
//  Copyright © 2018 Michael Liu. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Warrior.hpp"
#include "Noble.hpp"

using namespace std;
using namespace WarriorCraft;





//main
int main(int argc, const char * argv[]) {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;

    cheetah.runaway();
    cout << art << endl;
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    
    
    return 0;
}



////prints out the status takes in a vector of noble pointers and a vector of warrior pointers
//void status(const vector<Noble*>& nobleList, const vector<Warrior*>& warriorList){
//    cout<<"STATUS:"<<endl;
//    cout<<"============="<<endl;
//    cout<<"Noble list: "<<endl;
//    bool noNoble = true;
//    for(size_t i = 0; i<nobleList.size(); i++){
//        nobleList[i]->display();
//        noNoble = false;
//    }
//    if(noNoble){
//        cout<<"None"<<endl;
//    }
//    cout<<"Unemployeed warriors:"<<endl;
//    bool none = true;
//    for(size_t i = 0; i<warriorList.size(); i++){
//        warriorList[i]->display();
//        none = false;
//    }
//    if(none){
//        cout<<"None"<<endl;
//    }
//}
//
////clears the vector and everything on the heap
//void clear(vector<Noble*>& nobleList, vector<Warrior*>& warriorList){
//    for(int i = 0; i<nobleList.size(); i++){
//        delete(nobleList[i]);
//    }
//    nobleList.clear();
//    for(int i = 0; i<warriorList.size(); i++){
//        delete(warriorList[i]);
//    }
//    warriorList.clear();
//}
//
////finds warrior in the list and returns the index, if does not exist return -1
//int findWarrior(vector<Warrior*> listOfWarriors, string name){
//    int index = -1;
//    for(size_t i = 0; i<listOfWarriors.size(); i++){
//        if(listOfWarriors[i]->getName()==name){
//            index = int(i);
//            break;
//        }
//    }
//    return index;
//}
//
////finds noble in the list and returns the index, if does not exist return -1
//int findNoble(vector<Noble*> listOfNobles, string name){
//    int index = -1;
//    for(size_t i = 0; i<listOfNobles.size(); i++){
//        if(listOfNobles[i]->getName()==name){
//            index = int(i);
//            break;
//        }
//    }
//    return index;
//}
//
//
//
////reads in the text files and executes the commands
//void executeCommands(const string& filename){
//    ifstream commands(filename);
//    if (!commands) {
//        cerr << "failed to open file\n";
//        exit(1);
//    }
//    string word;
//    vector<Noble*> listOfNobles;
//
//    vector<Warrior*> listOfWarriors;
//    while ( commands >> word ) {
//        if(word=="Noble"){
//            commands>>word;
//            bool nameUsed = false;
//            if(findWarrior(listOfWarriors, word)==-1||findNoble(listOfNobles, word)==-1){
//                nameUsed = true;
//            }
//            if(!nameUsed){
//                Noble* noble = new Noble(word);
//                listOfNobles.push_back(noble);
//            }
//        }
//        if(word=="Warrior"){
//            commands>>word;
//            float strength;
//            commands>>strength;
//            bool nameUsed = false;
//            if(findWarrior(listOfWarriors, word)==-1||findNoble(listOfNobles, word)==-1){
//                nameUsed = true;
//            }
//            if(!nameUsed){
//                Warrior* warrior = new Warrior(word, strength);
//                listOfWarriors.push_back(warrior);
//            }
//        }
//        if(word == "Hire"){
//            commands>>word;
//            bool nobleExist = false;
//            int nobleIndex = findNoble(listOfNobles, word);
//            if(nobleIndex != -1){
//                nobleExist = true;
//            }
//            if(nobleExist){
//                commands>>word;
//                bool warriorExist = false;
//                int warriorIndex = findWarrior(listOfWarriors, word);
//                if(warriorIndex != -1){
//                    warriorExist = true;
//                }
//                if(warriorExist){
//                    listOfNobles[nobleIndex]->hire(*listOfWarriors[warriorIndex]);
//                    listOfWarriors.erase(listOfWarriors.begin()+warriorIndex);
//                }else{
//                    cout<<"Warrior does not exist"<<endl;
//                }
//            }else{
//                commands>>word;
//                cout<<"Noble does not exist"<<endl;
//            }
//        }
//        if(word=="Fire"){
//            commands>>word;
//            bool nobleExist = false;
//            int nobleIndex = findNoble(listOfNobles, word);
//            if(nobleIndex != -1){
//                nobleExist = true;
//            }
//            if(nobleExist){
//                Noble& noble = *listOfNobles[nobleIndex];
//                commands>>word;
//                bool warriorExist = false;
//                int warriorIndex = findWarrior(listOfWarriors, word);
//                if(warriorIndex != -1){
//                    warriorExist = true;
//                }
//                if(warriorExist){
//                    Warrior* warrior = noble.getEmployeeList()[warriorIndex];
//                    noble.fire(*warrior);
//                    listOfWarriors.push_back(warrior);
//                }else{
//                    cout<<"Warrior does not exist"<<endl;
//                }
//            }else{
//                commands>>word;
//                cout<<"Noble does not exist"<<endl;
//            }
//        }
//        if(word=="Battle"){
//            commands>>word;
//            bool noble1Exist = false;
//            int noble1Index = findNoble(listOfNobles, word);
//            if(noble1Index != -1){
//                noble1Exist = true;
//            }
//            if(noble1Exist){
//                commands>>word;
//                bool noble2Exist = false;
//                int noble2Index = findNoble(listOfNobles, word);
//                if(noble2Index != -1){
//                    noble2Exist = true;
//                }
//                if(noble2Exist){
//                    listOfNobles[noble1Index]->battle(*listOfNobles[noble2Index]);
//                }else{
//                    cout<<"Noble does not exist"<<endl;
//                }
//            }else{
//                commands>>word;
//                cout<<"Noble does not exist"<<endl;
//            }
//        }
//        if(word=="Status"){
//            status(listOfNobles, listOfWarriors);
//        }
//        if(word=="Clear"){
//            cout<<"Clearing"<<endl;
//            clear(listOfNobles, listOfWarriors);
//        }
//
//    }
//    commands.close();
//
//}

