//Job Sequencing Problem

//Given a list of jobs and their maximum deadlines as well as
//profits from completed jobs, sequence the jobs in a way such that
//max profit can be obtained.
//NOTE: Each job takes 1 unit of time to complete.
//Deadlines are the maximum time post which the job will expire. It can be done earlier if feasible.


#include<bits/stdc++.h>
using namespace std;


//Brute force approach: O(n^2) time

class Job{
    public:
        string jobId;
        int deadline;
        int profit;
        Job(string jobId, int deadline, int profit):jobId{jobId},deadline{deadline},profit{profit}{}
};

bool comparator(Job a, Job b){ //comparator function to sort jobs by desc order of profit
    return a.profit > b.profit;
}

int getJobSequenceProfit(Job* jobList, int n){
    int total_profit = 0;
    vector<bool> free_slot(n,false); //array of slots (initially set to false i.e. empty)
    vector<string> job_sequence(n); //array to store sequence of jobs
    sort(jobList,jobList+n,comparator); //sort jobs by desc order of profit
    for(int i=0;i<n;++i){ //for all jobs in list
        for(int j=min(n,jobList[i].deadline)-1;j>=0;--j){ //we try to insert the job with the greatest profit from the right, so that the minimum deadlines can be left empty for jobs with lesser deadlines. If job deadline is higher than no. of slots, we place it in the right most slot (n)
            if(free_slot[j] == false){ //if slot is empty
                job_sequence[j] = jobList[i].jobId; //we set the job to that slot
                total_profit+=jobList[i].profit; //we calculate the running profit
                free_slot[j] = true; //we mark the slot as occupied
                break; //we break out of the loop once a job is placed. If not placed, we decrement j by 1 and try to insert job in the prev slot
            }
        }
    }
    cout<<"Sequence of jobs to earn most profit: ";
    for(string s:job_sequence) cout<<s<<" ";
    return total_profit;
}

// int main(){
//     Job jobList[] = {{"a",2,100},{"b",1,19},{"c",2,27},{"d",1,25},{"e",3,15}};
//     int n = sizeof(jobList)/sizeof(jobList[0]);
//     cout<<"Total profit from jobs is: ";
//     cout<<getJobSequenceProfit(jobList,n)<<endl;
// }


//Optimized (Using disjoint sets) - O(n)

class DisjointSet{
    public:
        int* parentArr; //array stores job slot as index and parent as array value
        DisjointSet(int n){
            parentArr = new int[n+1]; //size of disjoint set is equal to the max deadline out of all job deadlines
            for(int i=0;i<=n;i++) parentArr[i] = i; //for each job set, we set its value equal to itself (each is its own parent root) (can also be set to -1 or 0)
        }

        //function to find available slot (find root parent of disjoint set)
        int find(int s){
            if(s==parentArr[s]) return s; //if s is its own parent, it means the slot is empty (since we initialize all elements to its own parent in the constructor)
            return parentArr[s] = find(parentArr[s]); //else we recurse down to find the next available slot (path compression used)
        }

        //function to merge to disjoint sets by setting the parent of the set v as set u
        void merge(int u, int v){ //set u as the greatest available slot now
            parentArr[v] = u;
        }
};

//function to find the maximum deadline (could also be found by taking 1st element in sorted array)
int findMaxDeadline(Job jobArr[], int n){
    int max_deadline = INT_MIN;
    for(int i=0;i<n;i++){
        max_deadline = max(max_deadline, jobArr[i].deadline);
    }
    return max_deadline;
}

int printJobScheduling(Job jobArr[], int n){
    int total_profit = 0;
    sort(jobArr, jobArr+n, comparator); //sort all jobs by desc order of deadline
    int maxDeadline = findMaxDeadline(jobArr, n);
    DisjointSet ds(maxDeadline); //create disjoint set with max deadline (set will have all slot e.g. 0 to 1, 1 to 2, 2 to 3 if max deadline is 3)
    for(int i=0;i<n;i++){ //for each job
        int availableSlot = ds.find(jobArr[i].deadline); //we find the next available slot
        if(availableSlot>0){ //if available slot is valid (gt 0) i.e. free slot is available
            ds.merge(ds.find(availableSlot-1), availableSlot); //we merge the two sets (find available parent slot from availaleslot-1 and merge both sets)
            total_profit+=jobArr[i].profit;
            cout<<jobArr[i].jobId<<" ";
        }
    }
    return total_profit;
}

int main(){
    Job jobList[] = {{"a",2,100},{"b",1,19},{"c",2,27},{"d",1,25},{"e",3,15}};
    int n = sizeof(jobList)/sizeof(jobList[0]);
    cout<<"Total profit from jobs is: ";
    cout<<printJobScheduling(jobList,n)<<endl;
}
