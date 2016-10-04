//
//  qSortRecords.hpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef qSortRecords_h
#define qSortRecords_h

#include <stdio.h>
#include <iostream>
#include <ostream>
#include <vector>


#include "record.h"
#include "compareRecords.h"


class qSortRecords{
    
public:
    
    qSortRecords(compareRecords * rec, bool (compareRecords::*functocall)(record,record), std::vector <record> &block, int left,int right);
    
    record selectPivot(compareRecords * rec, bool (compareRecords::*functocall)(record,record), std::vector <record> &block, int left, int right);
    
    void insertionSort(compareRecords * rec, bool (compareRecords::*functocall)(record,record),std::vector <record> &block, int left, int right);
    
};
#endif /* qSortRecords_h */
