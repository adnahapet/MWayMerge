//
//  record.cpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "record.h"

record::record(){
    
}

record::record(int primary, float secondary, std::string tertiary, float value ):
    primary(primary),
    secondary(secondary),
    tertiary(tertiary),
    value(value)
{
    
}


int record::getPrimary(void){
    
    return this->primary;
    
}

float record::getSecondary(void){
    
    return this->secondary;
}


std::string record::getTertiary(void){
    
    return this->tertiary;
    
}

float record::getValue(void){
    
    return this->value;
    
}


void record::setPrimary(int key){
    
    this->primary = key;
    
}

void record::setSecondary(float key){
    
    this->secondary = key;
}


void record::setTertiary(std::string key){
    
    this->tertiary = key;
    
}

void record::setValue(float value){
    
    this->value = value;
    
}