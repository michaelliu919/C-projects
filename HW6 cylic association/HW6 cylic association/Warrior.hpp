//
//  Warrior.hpp
//  HW6 cylic association
//
//  Created by Michael Liu on 3/22/18.
//  Copyright © 2018 Michael Liu. All rights reserved.
//

#ifndef Warrior_hpp
#define Warrior_hpp

#include <iostream>
#include <string>

#include "Noble.hpp"


namespace WarriorCraft {
    class Noble;
    class Warrior{
    public:
        Warrior(const std::string& name, float strength):name(name), strength(strength), employment(false){}
        bool hire(Noble& noble);
        bool getEmploymentStatus() const;
        void decreaseStrength(float decrease);
        void fire();
        float getStrength() const;
        void display() const;
        std::string getName() const;
        bool runaway();



    private:
        std::string name;
        float strength;
        bool employment;
        Noble* owner = nullptr;
        
    };
    
    
}



#endif /* Warrior_hpp */
