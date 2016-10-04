//
//  mWayMerge.cpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "mWayMerge.h"


mWayMerge::mWayMerge(std::string auxilaryFile, std::string outputFile, int m, int n){
    
    
    //instance of compareRecords class to pass to findMin
    compareRecords comparer;
    
    
    std::vector <record> mRecords;
    std::string data;
    std::string token;
    
    //input stream from auxfile
    std::ifstream  auxfile;
    
    
    //streams for writing out to outputfile
    std::filebuf oo;
    oo.open(outputFile,std::ios::out);
    std::ostream outfile(&oo);
    
    
    //data structures for tracking the merge
    //blockmax keeps the number of entries written out from each block
    //positions stores the last known position for each block
    long currentPosition;
    std::vector <long> positions;
    std::vector <int> blockMax;

    
    auxfile.open(auxilaryFile);
    
    
    //this fills a vector with the starting position of each block of data
    //the starting positions are based on the number m of blocks and the n number of records in each block
    //the for loop getline() repeatedly discarding the data for now
    currentPosition = auxfile.tellg();
    positions.push_back(currentPosition);
    for(int z= 1; z < m; z++){
        for(int i=0;i < n ;i++){
            getline(auxfile,data);
        }
        currentPosition = auxfile.tellg();
        positions.push_back(currentPosition);
    }
 
    
    //this for loop gets the initial set of records to pass to findmin
    //it uses the original positions and fills a vector with the data
    //each position is updated post getline() to reflect the new position
    for(int i = 0; i < m; i++){
        auxfile.seekg(positions[i]);
        getline(auxfile,data);
        mRecords.push_back(makenewRecord(data));
        currentPosition = auxfile.tellg();
        positions[i]=currentPosition;
        blockMax.push_back(0);
    }
        
   
    //for loop writes merged files
    //calls findmin to return lowest record from vector of records
    //once a blocks maximum number of records is written to the outfile
    //its block is erased from the loop by removing it from the 3 vectors that keep track of the data
    //the data remains in the aux file
    for(int i = 0; i < n * m;){
        
        int min = findMinRecords(&comparer, &compareRecords::compare, mRecords);
        
        if(blockMax[min]< n ){
            outfile<<mRecords[min].getPrimary()<<" "<<mRecords[min].getSecondary()<<" "<<mRecords[min].getTertiary()<<" "<<mRecords[min].getValue()<<std::endl;
            auxfile.seekg(positions[min]);
            getline(auxfile,data);
            if (i < n*m-1)
                mRecords[min] = makenewRecord(data);
            currentPosition = auxfile.tellg();
            positions[min] = currentPosition;
            blockMax[min]++;
            i++;
        }
        else{
            blockMax.erase(blockMax.begin()+min);
            mRecords.erase(mRecords.begin()+min);
            positions.erase(positions.begin()+min);
        }
        
    }
    
    
    //closing outfile stream
    oo.close();
    
}

//parses a vector of records
//compares each index storing the index of the lowest found record in a return variable
//
int mWayMerge::findMinRecords(compareRecords *rec, bool(compareRecords::*functocall)(record,record), std::vector<record> & records){
    
    if(records.size()==1)
        return 0;
    int min = 0;
    for(int i = 1;i<records.size();i++){
        if((rec->*functocall)(records[i],records[min]) ==true )
            min = i;
    }
    
    return min;
}

//a reusable function that takes a string of data
//returns a new record object
record mWayMerge::makenewRecord(std::string data){
    
    std::istringstream ss(data);
    std::string token;
    std::vector<std::string> temp;
    
    for(int i=0 ; i < 4 ; i ++ ){
        getline(ss,token,' ');
        temp.push_back(token);
    }
    
    
    record newRecord = *new record;
    newRecord.setPrimary(std::stoi(temp[0]));
    newRecord.setSecondary(std::stof(temp[1]));
    newRecord.setTertiary(temp[2]);
    newRecord.setValue(stof(temp[3]));
    
    temp.clear();
    
    return newRecord;
}


