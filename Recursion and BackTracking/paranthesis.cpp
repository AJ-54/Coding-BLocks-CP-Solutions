#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> answers(11);

vector<string> compute(int n){
    vector<string> vec;
    //Base Case 
    if (n==1) {
        string s= "{}";
        vec.push_back(s);
        answers[1] = vec;
        return vec;
    }

    //Recursive Case
    vector<string> shvec = compute(n-1);
    answers[n-1] = shvec;

    for (int k=0;k<shvec.size();k++){
        string temp (shvec[k]);      
        for (int i=0;i<temp.length();i++){
            string ans (temp);
            ans.insert(i,"{");
            int len = ans.length();
            for (int j=i+2;j<len;j++){
                string nans (ans);
                nans.insert(j,"}");
                if (find(vec.begin(),vec.end(),nans) == vec.end()) vec.push_back(nans);
            }
        }
    }
    if (!(n&1)){
        int nn = n/2;
        vector<string> sans = answers[nn];
        for (int i=0;i<sans.size();i++){
            string temp (sans[i]);
            temp.append(temp);
            if (find(vec.begin(),vec.end(),temp) == vec.end()) vec.push_back(temp);
        }
    }
    else {
        string temp1 = "{}";
        string temp;
        for(int i=1;i<=n;i++) temp.append(temp1);
        if (find(vec.begin(),vec.end(),temp) == vec.end()) vec.push_back(temp);

    }

    return vec;

}

int main(){
    int n;
    cin >> n;
    vector<string> vec = compute(n);
    sort(vec.begin(),vec.end(),greater<string>());
    for (auto v: vec) cout << v << endl;
}