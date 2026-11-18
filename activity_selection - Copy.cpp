#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start;
    int finish;
};

bool cmp(Activity a, Activity b){
    return a.finish < b.finish;
}

int maxActivities(vector<Activity>& activities){
    sort(activities.begin(),activities.end(),cmp);

    int ans = 1;
    cout<<"Selected Activities"<<endl;
    cout<<activities[0].start<<" "<<activities[0].finish<<endl;
    int pr = 0;

    for(int i = 1; i < activities.size();i++){
        if(activities[i].start > activities[pr].finish){
            cout<<activities[i].start<<" "<<activities[i].finish<<endl;
            pr = i;
            ans++;
        }
    }

    return ans;
}

int main(){
    vector<Activity> activities = {
        {1,3}, {2,5}, {4,7}, {1,8},
        {5,9}, {8,10}, {9,11}
    };

    int ans = maxActivities(activities);
    cout<<"Maximum Activities Possible:"<<ans;
    
    return 0;
}