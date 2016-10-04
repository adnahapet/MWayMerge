//
//  record.h
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef record_h
#define record_h

#include <stdio.h>
#include <string>

class record{

public:
    
    record(void);
    
    record(int primary, float secondary, std::string tertiary, float value );
    
    int getPrimary(void);
    
    float getSecondary(void);
    
    std::string getTertiary(void);
    
    float getValue(void);
    
    
    void setPrimary(int key);
    
    void setSecondary(float key);
    
    void setTertiary(std::string key);
    
    void setValue(float value);
    
private:
    
    int primary;
    float secondary;
    std::string tertiary;
    float value;
    
};

#endif /* record_h */
