#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int firstUniqueChar(string s) {
    unordered_map<char, int> mp; // to count freq
    queue<int> q; // to store indices of potential candidates
    for(int i=0; i<s.length(); i++){
        if(mp.find(s[i]) == mp.end()){
            q.push(i); // push index if char is seen for the first time
        }
        mp[s[i]]++; // inc the freq
        while(!q.empty() && mp[s[q.front()]] > 1){ // remove all chars from the front of the queue that are repeating
            q.pop();
        }
    }
    return q.empty() ? -1 : q.front();
}

int main() {
    string str = "dunnyfox";
    int index = firstUniqueChar(str);
    if (index == -1) {
        cout << "No unique character found." << endl;
    } else {
        cout << "First unique character is '" << str[index] << "' at index " << index << "." << endl;
    }
    return 0;
}