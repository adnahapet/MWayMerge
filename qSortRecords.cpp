//
//  qSortRecords.cpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "qSortRecords.h"

//qsortrecords method is the main quicksort method
//it takes an instance of class compareRecords and a point to a comparison method
//in this case it is a pointer to compareRecords::compare
//but i've abstracted it a bit so hypothetically compareRecords could have other methods
//if the user wanted to sort in descending instead of ascending order
qSortRecords::qSortRecords(compareRecords * rec, bool (compareRecords::*functocall)(record,record), std::vector <record> &block, int left, int right){
    
    //cutoff
    if( left + 10 <= right ){
        
        //call to selectpivot method using pointer to compare method
        const record & pivot = selectPivot(rec,& compareRecords::compare,  block , left, right);
    
        int i = left, j = right - 1;
    
        for( ; ; ) {
            while( (rec->*functocall)(block[++i],pivot) == true ) { }
            while( (rec->*functocall)(pivot,block[--j]) == true ) { }
            if( i < j )
                std::swap( block[ i ], block[ j ] );
            else
                break;
        }

        std::swap(block[i],block[right-1]);
        
        //recursive calls to qsortrecords on left and right subarrays
        qSortRecords(rec, & compareRecords::compare, block, left ,i-1);
        qSortRecords(rec, & compareRecords::compare, block, i+1, right);
        
        
    }
    else
        insertionSort(rec, &compareRecords::compare,block,left,right);
}

//arbitrary pivot selection using median of 3
//considered using a randomly generated index
//this seemed easier since it removes some unecessary comparisons
//reuses compareRecords method
record qSortRecords::selectPivot(compareRecords * rec, bool (compareRecords::*functocall)(record,record),std::vector <record> &block,int left, int right){
    
    int center = ( left + right ) / 2;
    
    if((rec->*functocall)(block[center],block[left])==true)
        std::swap( block[ left ], block[ center ] );
    if( (rec->*functocall)(block[right],block[left])==true )
        std::swap( block[ left ], block[ right ] );
    if( (rec->*functocall)(block[right],block[center]) ==true )
        std::swap( block[ center ], block[ right ] );
    
    // Place pivot at position right - 1
    std::swap( block[ center ], block[ right-1] );
    
    //return pivot
    return block[ right-1 ];
    
}


//insertion sort is the base case for when subarrays become too small for quicksort to remain practical
void qSortRecords::insertionSort(compareRecords * rec, bool (compareRecords::*functocall)(record,record),std::vector <record> &block, int left, int right){
    
    for (int p = left; p < right+1; ++p) {
        
        record tmp = block[p];
        
        int j;
        
        for (j = p; j > 0 && ((rec->*functocall)(tmp,block[j-1]))==true; --j)
            block[j] = block[j-1];
        block[j] = tmp;
        
    }

}