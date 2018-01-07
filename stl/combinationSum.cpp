#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> current;
        
        backtracking(ans, candidates, current, 0, target);
        
        return ans;
    }
    
    void backtracking(vector<vector<int> >& ans, vector<int>& candidates, vector<int> current, int last_use, int rest_target) {
        
        if (rest_target == 0) {
            ans.push_back(current);
        }
        
        for (int i = last_use; i < candidates.size() && candidates[i] <= rest_target; i++) {
            current.push_back(candidates[i]);
            backtracking(ans, candidates, current, i, rest_target - candidates[i]);
            current.pop_back();
            
        }
    }
};

int main(){
    Solution solution;
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);

    
    vector<vector<int> > res = solution.combinationSum(candidates, 7);
    for(int i = 0;i < res.size();i++){
        for(int j = 0; j < res[i].size(); j++)  {
            cout<<res[i][j]<<endl;
        }
        cout<<"\n" ;
    }
    return 0;
}
