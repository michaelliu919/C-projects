//
//  Warrior.cpp
//  HW6 cylic association
//
//  Created by Michael Liu on 3/22/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//
#include <iostream>
#include <string>

#include "Warrior.hpp"
#include "Noble.hpp"

using namespace std;


namespace WarriorCraft {
    class Noble;
    
    
        //hire function, returns false if warrior is already hired, returns true if warrior is available for hiring
        bool Warrior::hire(Noble& noble){
            if(employment){
                return false;
            }
            owner = &noble;
            employment = true;
            return true;
        }
    
    //runaway function, returns false when warrior is not hired yet
        bool Warrior::runaway(){
            cout<<name<<" is running away"<<endl;
            if(employment == true){
                int index = -1;
                for(int i = 0; i<owner->getEmployeeList().size(); i++){
                    if(owner->getEmployeeList()[i]==this){
                        index = i;
                        break;
                    }
                }
                for(int i = index; i<owner->getEmployeeList().size()-1; i++){
                    owner->getEmployeeList()[i] = owner->getEmployeeList()[i+1];
                }
                owner->getEmployeeList().pop_back();

                return true;
            }
            return false;
        }
        
        //returns the employment status, whether employed or not
        bool Warrior::getEmploymentStatus() const{
            return employment;
        }
        
        //decrease strength by given amount
        void Warrior::decreaseStrength(float decrease){
            strength-=decrease;
            if (strength<0){
                strength = 0;
            }
        }
        
        //warrior gets fired
        void Warrior::fire(){
            employment = false;
            owner = nullptr;
        }
        
        //returns the strength of the warrior
        float Warrior::getStrength() const{
            return strength;
        }
        
        //displays the warrior
        void Warrior::display() const{
            cout<<"Warrior "<<name<<", strength: "<<strength<<endl;
        }
        
        //get name
        string Warrior::getName() const{
            return name;
        }
        


}

