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
    int k;
    scani(k);
    int v=0, e=0;
    int a=1, b=2;
    int b_=0;
    vector<vector<int>> output;
    while (k>0) {
        int n = (1+pow((1+8*k), 0.5))/2;
        v+=n;
        for (int i=0; i<n-1; i++) {
            vector<int> s = {a, b};
            output.pb(s);
            a++; b++;
        }
        if (b_!=0) {
            vector<int> s = {a, b_};
            output.pb(s);
            b_=0;
        }
        vector<int> s = {1, a};
        output.pb(s);
        b_=b;
        a++; b++;
        k-=n*(n-1)/2;
    }
    printi(v); print(" "); printi(output.size()); print("\n");
    for (vector<int> a : output) {
        printi(a[0]); print(" "); printi(a[1]); print("\n");
    }
}
