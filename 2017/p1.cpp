// code by savir singh
// 15/15 on DMOJ & CCC Grader
// added comments to whole code

#include <bits/stdc++.h>
using namespace std;
// macros
#define int long long
#define double long double
#define bit32 int32_t
#define del erase
#define pb push_back
#define str string
#define scani(x) scanf("%lld", &x)
#define scan(x) scanf("%s", &x)
#define scanc(x) scanf("%c", &x)
#define printi(x) printf("%lld", x);
#define print(x) printf("%s", x);
#define printc(x) printf("%c", x);

// driver code
bit32 main()
{
    // initializing everything and reading k
    int k;
    scani(k);
    int v=0;
    int a=1, b=2;
    int b_=0;
    vector<vector<int>> output;
    while (k>0) {
        int n = (1+pow((1+8*k), 0.5))/2; // quadratic formula
        v+=n; // increase vertices/nodes counter
        for (int i=0; i<n-1; i++) {
            // iterate n-1 times and add a, b to output
            vector<int> s = {a, b};
            output.pb(s);
            a++; b++; // add 1 to a, b
        }
        if (b_!=0) {
            // if there's a b_ value, add it to the output
            vector<int> s = {a, b_};
            output.pb(s);
            b_=0;
        }
        vector<int> s = {1, a}; // attach node 1 to node a
        output.pb(s); // add 1, a to output
        b_=b; // store that last value of b in b_
        a++; b++; // add 1 to a, b
        k-=n*(n-1)/2; // break down k
    }
    // output v, e
    printi(v); print(" "); printi(output.size()); print("\n");
    for (vector<int> a : output) {
        // output the entire output at once
        printi(a[0]); print(" "); printi(a[1]); print("\n");
    }
}
