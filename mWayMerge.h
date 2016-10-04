//
//  mWayMerge.h
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef mWayMerge_h
#define mWayMerge_h

#include <stdio.h>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>

#include "record.h"
#include "compareRecords.h"

class mWayMerge{
    
public:
    
    mWayMerge(std::string aux, std::string out, int m, int n);
    
    int findMinRecords(compareRecords * rec, bool (compareRecords::*functocall)(record, record),  std::vector <record> & records);
    
    record makenewRecord(std::string data);
    
};

#endif /* mWayMerge_h */
