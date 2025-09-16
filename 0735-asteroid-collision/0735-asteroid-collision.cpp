#include<stack>
#include<cmath>
#include<vector>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        stack<int>s;

        for(int i=0;i<n;i++){
            int curr=asteroids[i];
            bool destroyed=false;

            while(!s.empty() && curr<0 && s.top()>0){
                int top=s.top();
                if(abs(curr)>abs(top)){
                    s.pop();
                }
                else if(abs(curr)==abs(top)){
                    s.pop();
                    destroyed=true;
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                s.push(curr);
            }
        }
        vector<int>result(s.size());
        for(int i=s.size()-1;i>=0;i--){
            result[i]=s.top();
            s.pop();
        }
        return result;


        
    }
};