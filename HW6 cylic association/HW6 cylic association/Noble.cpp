//
//  Noble.cpp
//  HW6 cylic association
//
//  Created by Michael Liu on 3/22/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Noble.hpp"
#include "Warrior.hpp"

using namespace std;

namespace WarriorCraft{
    class Warrior;
    
    //output operator
    ostream& operator<<(ostream& os, const Noble& noble){
        os<<"Noble: "<<noble.name<<" has an army of "<<noble.employees.size()<<endl;
        for (size_t i = 0; i<noble.employees.size(); i++){
            os<<"   "<<noble.employees[i]->getName()<<" Strenth: "<<noble.employees[i]->getStrength();
        }
        return os;
    }
    
    //battle method outputs the results/conditions of the battle
    void Noble::battle(Noble& noble){
        cout<<name<<" is battles "<<noble.name<<endl;
        if(!alive && !noble.alive){
            cout<<"They are both dead"<<endl;
        }
        else if(!alive){
            cout<<"He's dead, "<<noble.name<<endl;
        }
        else if(!noble.alive){
            cout<<"He's dead, "<<name<<endl;
        }
        else{
            float tempStrength = currStrength();
            decreaseStrength(noble.currStrength());
            noble.decreaseStrength(tempStrength);
            if(currStrength()==0 && noble.currStrength()==0){
                cout<<"Mutual annihiliation"<<endl;
            } else if(currStrength()==0){
                cout<<name<<" dies at the hands of "<<noble.name<<endl;
            } else if(noble.currStrength()==0){
                cout<<noble.name<<" dies at the hands of "<<name<<endl;
            }
        }
    }
    
    

    //decrease strength after battle, noble dies if enemyStrength>self.strength, decrease by ratio
    //rounds to the nearest number
    void Noble::decreaseStrength(float enemyStrength){
        if (enemyStrength>=currStrength()){
            alive = false;
            for(size_t i = 0; i<employees.size(); i++){
                //this would set all warrior strength to 0
                (*employees[i]).decreaseStrength(enemyStrength);
            }
        } else{
            float ratio = enemyStrength/currStrength();
            for(size_t i = 0; i<employees.size(); i++){
                //this decreases all warrior strength according to the ratio
                Warrior& warrior = *employees[i];
                warrior.decreaseStrength(warrior.getStrength()*ratio);
            }
        }
    }
    
    //returns the current total strength of the noble
    float Noble::currStrength() const{
        float strength = 0;
        for(size_t i = 0; i < employees.size(); i++){
            
            strength += (*(employees[i])).getStrength();
            
        }
        return strength;
    }
    
    //return true if hire is successfull, returns false if fails, takes warrior reference
    bool Noble::hire(Warrior& warrior){
        if(alive){
            if(warrior.hire(*this)){
                employees.push_back(&warrior);
                return true;
            }
        }
        return false;
    }
    
    //returns true if firing is successful, returns false otherwise, takes warrior reference
    bool Noble::fire(Warrior& warrior){
        if(alive){
            for(size_t i = 0; i < employees.size(); i++){
                if(&warrior == employees[i]){
                    employees.erase(employees.begin()+i);
                    warrior.fire();
                    cout<<"You don't work for me anymore, "<<warrior.getName()<<" -- "<<getName()<<endl;
                    return true;
                }
            }
        }
        cout<<"Can't fire someone who doesn't work for me"<<endl;
        return false;
    }
    
    //display method for the noble
    void Noble::display() const{
        cout<<"Noble "<<name<<", strength: "<<currStrength()<<" with an army of "<<employees.size()<<endl;
        for(size_t i = 0; i < employees.size(); i++){
            cout<<"     ";
            (*employees[i]).display();
        }
    }
    
    //returns the list of employees
    vector<Warrior*>& Noble::getEmployeeList() {
        return employees;
    }
    
    //get name
    string Noble::getName() const{
        return name;
    }
    

}
    
    
    
