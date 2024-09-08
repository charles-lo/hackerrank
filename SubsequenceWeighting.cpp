#include <cstdio>
#include <vector>
#include <map>
using namespace std;


/* reference https://willyopel.wordpress.com/2015/12/11/subsequence-weighting/
*/
 
int main() {
    int nt;
    scanf("%d", &nt);
    while (nt--) {
        int n;
        scanf("%d", &n);
        vector<pair<long, long> > seqs(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &seqs[i].first);
        }
        for (int i = 0; i < n; ++i)
            scanf("%d", &seqs[i].second);
 
 
        map<long, long> maxWeight;  // sort is important
 
        vector<pair<long, long> >::iterator curr = seqs.end();
        for (advance(curr, -1); curr >= seqs.begin(); --curr) {
            long key = curr->first;
            long val = curr->second;
             
            map<long, long>::iterator higher = maxWeight.upper_bound(key);
            if (higher != maxWeight.end()) { // check if there is no higher key
                val += higher->second;  //accumulate it
            }
 
            if ((maxWeight.count(key)) and (maxWeight[key] >= val)) {
                continue;
            }
 
            maxWeight[key] = val;
 
            map<long, long>::iterator lower;
            // remove all inappropriate cases
            while ((lower = maxWeight.lower_bound(key)) != maxWeight.begin()) {
                advance(lower, -1);
                if (lower->second < val)
                    maxWeight.erase(lower);
                else
                    break;
            }
        }
        printf("%lld\n", maxWeight.begin()->second);
    }
}