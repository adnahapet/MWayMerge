//
//  main.cpp
//  Assignment_4
//
//  Created by Armen Nahapetian on 4/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>

#include "record.h"
#include "compareRecords.h"
#include "qSortRecords.h"
#include "mWayMerge.h"

int main(int argc, const char * argv[]) {


    //standard string declarations
    //used to store the input from command line etc
    std::string data;
    std::string token;
    std::string inputFile;
    std::string auxiliaryFile;
    std::string outputFile;
    std::string merge;


    inputFile = argv[1];

    auxiliaryFile = argv[2];

    outputFile = argv[3];

    merge = argv[4];



    //vector to store each block of data
    std::vector <record> block = *new std::vector<record>;

    //input stream
    std::ifstream infile;

    //filebuffer for output to auxiliary file
    std::filebuf ao;


   //opening the output stream
    ao.open(auxiliaryFile,std::ios::out);
    std::ostream auxfile(&ao);



    int nc;

    int n;

    int m = std::stoi(merge);


    //opens the inputfile and captures the first line to calculate n and nc
    infile.open(inputFile);
    getline(infile,data);
    std::istringstream ss(data);
    getline(ss,token,' ');
    nc = std::stoi(token);


    n = nc / m;


    while(infile.good())
    {

        std::vector <std::string> temp;

        //for loop to create new records and insert them into a vector for each block
        for(int i =0; i < n; i++){

            getline(infile,data);
            std::istringstream ss(data);

            for(int i=0 ; i < 4 ; i ++ ){
                getline(ss,token,' ');
                temp.push_back(token);
            }

        //record creation parses data from temp as a stream
        //could hypothetically use
        record newRecord = *new record;
        newRecord.setPrimary(std::stoi(temp[0]));
        newRecord.setSecondary(std::stof(temp[1]));
        newRecord.setTertiary(temp[2]);
        newRecord.setValue(stof(temp[3]));

        block.push_back(newRecord);
        temp.clear();

        }

        //takes a block of vector and passes it to quick sort
        //uses an instance of class comparer and a function pointer to one of its class methods
        compareRecords comparer = *new compareRecords;
        qSortRecords(&comparer, &compareRecords::compare, block, 0, n-1);

        //writes data to output file as strings
        for(int i = 0; i < n; i ++){
            auxfile<<block[i].getPrimary()<<" "<<block[i].getSecondary()<<" "<<block[i].getTertiary()<<" "<<block[i].getValue()<<std::endl;
        }
        block.clear();


    }

    //closes the output stream
    ao.close();


    //calls merge sort passing aux and output files along with number of records in each block and number of blocks
    mWayMerge(auxiliaryFile,outputFile,m,n);

}
