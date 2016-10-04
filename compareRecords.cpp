//
//  compareRecords.cpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "compareRecords.h"


compareRecords::compareRecords()
{
    
    
    
}

//compare records takes two records as parameters
//compares each key returning true if the first parameter is lower than the second
//the compare method is thus always in the form of One < Two
//randomly decides which bool value to return if all 3 keys are equal
bool compareRecords::compare(record One, record Two){
    
    if(One.getPrimary()!=Two.getPrimary()){
        
        if(One.getPrimary()<Two.getPrimary()){
            return true;
        }
        return false;
    }
    
    else if(One.getSecondary()!=Two.getSecondary()){
        
        if(One.getSecondary()<Two.getSecondary()){
            return true;
        }
        return false;
        
    }
    
    else if(One.getTertiary()!=Two.getTertiary()){
        
        if(One.getTertiary()<Two.getTertiary()){
            return true;
        }
        return false;
    }
    
    else{
        srand(time(NULL));
        int randomSort = rand() % 100;
        if (randomSort > 50){
            return false;
        }
        return true;
    }
    
}



