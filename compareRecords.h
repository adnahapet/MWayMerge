//
//  compareRecords.h
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef compareRecords_h
#define compareRecords_h

#include <stdio.h>
#include <iostream>
#include "stdlib.h"
#include "time.h"

#include "record.h"

class compareRecords{

public:
    
    compareRecords();
    
    bool compare(record One, record Two);
    
    record One;
    record Two;
};


#endif /* compareRecords_h */
