//
//  Noble.hpp
//  HW6 cylic association
//
//  Created by Michael Liu on 3/22/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Warrior.hpp"

namespace WarriorCraft {
    class Warrior;
    
    class Noble{
    public:
        friend std::ostream& operator<<(std::ostream& os, const Noble& r);

        //constructor
        Noble(const std::string& name):name(name),alive(true){}
        
        void battle(Noble& noble);
        void decreaseStrength(float enemyStrength);
        float currStrength() const;
        bool hire(Warrior& warrior);
        bool fire(Warrior& warrior);
        void display() const;
        std::vector<Warrior*>& getEmployeeList();
        std::string getName() const;

        
        
    private:
        std::string name;
        std::vector<Warrior*> employees;
        bool alive;



    };
    
    
    
}



#endif /* Noble_hpp */
