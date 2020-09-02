//N meetings in 1 room

//Given a list of start times and end times, find the number of meeting that
//can be held in 1 room. No meetings can overlap.

//Greedy approach:
//Create object for each meeting with position number and collect all meetings in a list. Sort meetings by their end times (ascending)
//Take pos of the 1st meeting in result list and take endtime in a variable.
//For each meeting after that, check if meeting start time is later than the last meeting endtime
//If true, place the meeting pos in result list

#include<bits/stdc++.h>
using namespace std;

class Meeting{
    public:
        int start;
        int end;
        int pos;
        Meeting(){
            start = 0;
            end = 0;
            pos = -1;
        }
        Meeting(int start, int end, int pos){
            this->start = start;
            this->end = end;
            this->pos = pos;
        }
};

//comparator function for sorting meetings in asc order of endtime
bool comparator(Meeting m1, Meeting m2){
    return m1.end < m2.end;
}

void maxMeeting(int *s, int *f, int n){
    vector<Meeting> meetingVec(n);
    for(int i=0;i<n;++i){ //store each meeting object into vector
        meetingVec[i].start = s[i];
        meetingVec[i].end = f[i];
        meetingVec[i].pos = i+1;
    }
    sort(meetingVec.begin(), meetingVec.end(), comparator); //sort the meetings in asc order of endtimes
    vector<int> order;
    order.push_back(meetingVec[0].pos); //push 1st meeting (with earliest endtime) in the list
    int time_limit = meetingVec[0].end;
    for(int i=1;i<n;++i){ //for all other meetings, add them to list if their start time is greater than prev meeting endtime
        if(meetingVec[i].start >= time_limit){
            order.push_back(meetingVec[i].pos);
            time_limit = meetingVec[i].end;
        }
    }
    for(int i=0;i<order.size();++i) cout<<order[i]<<" "; //print result
}

int main(){
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9};
    int n = sizeof(s)/sizeof(s[0]);
    maxMeeting(s,f,n);
}