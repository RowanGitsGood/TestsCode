#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(string, char);



/*
  Implement the methods for following class as described in problem statement.
 */

class Job{
    public:
        string jobID;
        string jobRole;
        int jobSalary;
        Job(string id, string role, int salary){
            jobID = id;
            jobRole = role;
            jobSalary = salary;
        }
};

class User{
    public:
        string userName;
        string interestedRole;
        User(string name, string interRole){
            userName = name;
            interestedRole = interRole;
        }
};

static vector<Job> jobList;
static vector<User> userList;

class FindJobDB{
public:
    string postJob(string jobID, string jobRole, int jobSalary){
        //find if job exists
        for (unsigned int i = 0; i<jobList.size(); i++){
            if (jobID == jobList[i].jobID){
                return "JobID Already Exists";
            }
        }
        jobList.push_back(Job(jobID, jobRole, jobSalary));
        return "Success";
    }
    
    string createUser(string userName, string interestedRole){
        //find if user exists
        for (unsigned int i = 0; i<userList.size(); i++){
            if (userName == userList[i].userName){
                return "User Already Exists";
            }
        }
        userList.push_back(User(userName, interestedRole));
        return "Success";
    }
    
    vector<string> getJobs(string userName, int k){
        vector<string> result;
        vector<Job> temp;
        User ourGuy("frog", "frog");
        for (unsigned int i = 0; i<userList.size(); i++){
            if (userName == userList[i].userName){
                ourGuy = userList[i];
            }
        }
        if (ourGuy.userName == "frog"){
            result.push_back("User Doesn't Exists");
            return result;
        }        
        for (unsigned int i = 0; i<jobList.size(); i++){
            if (ourGuy.interestedRole == jobList[i].jobRole){
                temp.push_back(jobList[i]);
            }
        }
        /* sort temp
        for (unsigned int i = 0; i<temp.size(); i=+2){
            if (temp[i].jobSalary){
                temp.push_back(jobList[i]);
            }
        }
        */
        return result;
    }
};


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<string> result(arr_count);
    FindJobDB service;
    for (int i = 0; i < arr_count; i++) {
        string arr_item;
        getline(cin, arr_item);
        vector<string> tmp = split(arr_item, ' ');
        if(tmp[0]=="postJob"){
            result[i]=service.postJob(tmp[1], tmp[2], stoi(tmp[3]));
        }
        else if(tmp[0]=="createUser"){
            result[i]=service.createUser(tmp[1], tmp[2]);
        }
        else if(tmp[0]=="getJobs"){
            vector<string> resFromMethod = service.getJobs(tmp[1], stoi(tmp[2]));
            string res = "";
            for(auto itr : resFromMethod){
                res+=itr;
                res+="/";
            }
            if(resFromMethod.size()) res.pop_back();
            result[i]=res;
        }
    }
    for(auto itr : result){
        fout << itr << "\n";
    }
    fout.close();

    return 0;
}

vector<string> split(string s, char ch){
    vector<string> ret;
    string curr = "";
    for(auto itr : s){
        if(itr==ch){
            ret.push_back(curr);
            curr.clear();
        }
        else curr.push_back(itr);
    }
    if(curr.size()) ret.push_back(curr);
    return ret;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}