//
//  main.cpp
//  PRG-6-12-Star-Search
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A particular talent competition has five judges, each of whom awards a score between
//  0 and 10 to each performer. Fractional scores, such as 8.3, are allowed. A performer's
//  final score is determined by dropping the highest and lowest score recieved, then averaging
//  the three remaining scores. Write a program that uses this method to calculate a
//  contestant's score. It should include the following functions:
//
//  * void getJudgeData() should ask the user for a judge's score, store it in a reference
//      parameter variable, and validate it. This function should be called by main once for
//      each of the five judges.
//  * void calcScore() should calculate and display the average of the three scores that
//      remain after dropping the highest and lowest scores the performer received. This
//      function should be called just once by main and should be passed the five scores.
//
//  The last two functions, described below, should be called by calcScore, which uses
//  the returned information to determine which of the scores to drop.
//
//  * int findLowest() should find and return the lowest of the five scores passed to it.
//  * int findHighest() should find and return the highest of the five scores passed to it.
//
//  Input Validation: Do not accept judge scores lower than 0 or higher than 10.

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void getJudgeData(float &refVar);
void calcScore(float, float, float, float, float);
float findLowest(float, float, float, float, float);
float findHighest(float, float, float, float, float);

int main()
{
    float fltScore1,
          fltScore2,
          fltScore3,
          fltScore4,
          fltScore5;
    
    getJudgeData(fltScore1);
    getJudgeData(fltScore2);
    getJudgeData(fltScore3);
    getJudgeData(fltScore4);
    getJudgeData(fltScore5);
    
    calcScore(fltScore1, fltScore2, fltScore3,
              fltScore4, fltScore5);
    
    return 0;
}

void getJudgeData(float &refVar)
{
    cout << "Please enter a score:\n";
    cin >> refVar;
    
    while(!cin || refVar < 0.0f || refVar > 10.0f)
    {
        cout << "Please enter a valid score from 0 to 10:\n";
        cin.clear();
        cin.ignore();
        cin >> refVar;
    }
}

void calcScore(float fltScore1, float fltScore2, float fltScore3,
               float fltScore4, float fltScore5)
{
    float fltLowest,
          fltHighest,
          fltScoreAverage;
    
    fltLowest = findLowest(fltScore1, fltScore2, fltScore3,
                           fltScore4, fltScore5);
    fltHighest = findHighest(fltScore1, fltScore2, fltScore3,
                             fltScore4, fltScore5);
    
    // Simply add all 5 scores together and subtract highest and lowest from that total
    fltScoreAverage = (fltScore1 + fltScore2 + fltScore3 + fltScore4 +
                       fltScore5 - fltLowest - fltHighest) / 3.0f;
    
    // Configure decimal output to single point of precision
    cout << setprecision(1) << fixed << showpoint;
    
    cout << "The average score is " << fltScoreAverage << endl;
}

float findLowest(float fltScore1, float fltScore2, float fltScore3,
                 float fltScore4, float fltScore5)
{
    if(min(fltScore1, min(fltScore2, min(fltScore3, min(fltScore4, fltScore5)))) == fltScore1)
    {
        return fltScore1;
    }
    else if(min(fltScore1, min(fltScore2, min(fltScore3, min(fltScore4, fltScore5)))) == fltScore2)
    {
        return fltScore2;
    }
    else if(min(fltScore1, min(fltScore2, min(fltScore3, min(fltScore4, fltScore5)))) == fltScore3)
    {
        return fltScore3;
    }
    else if(min(fltScore1, min(fltScore2, min(fltScore3, min(fltScore4, fltScore5)))) == fltScore4)
    {
        return fltScore4;
    }
    else if(min(fltScore1, min(fltScore2, min(fltScore3, min(fltScore4, fltScore5)))) == fltScore5)
    {
        return fltScore5;
    }
    else
    {
        cout << "ERROR: No min value\n";
    }
    return 0; // Will never be called
}

float findHighest(float fltScore1, float fltScore2, float fltScore3,
                  float fltScore4, float fltScore5)
{
    if(max(fltScore1, max(fltScore2, max(fltScore3, max(fltScore4, fltScore5)))) == fltScore1)
    {
        return fltScore1;
    }
    else if(max(fltScore1, max(fltScore2, max(fltScore3, max(fltScore4, fltScore5)))) == fltScore2)
    {
        return fltScore2;
    }
    else if(max(fltScore1, max(fltScore2, max(fltScore3, max(fltScore4, fltScore5)))) == fltScore3)
    {
        return fltScore3;
    }
    else if(max(fltScore1, max(fltScore2, max(fltScore3, max(fltScore4, fltScore5)))) == fltScore4)
    {
        return fltScore4;
    }
    else if(max(fltScore1, max(fltScore2, max(fltScore3, max(fltScore4, fltScore5)))) == fltScore5)
    {
        return fltScore5;
    }
    else
    {
        cout << "ERROR: No max value\n";
    }
    return 0; // Will never be called
}

