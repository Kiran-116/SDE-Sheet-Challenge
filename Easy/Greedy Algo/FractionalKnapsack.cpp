#include <bits/stdc++.h> 
using namespace std;

// Take them in decreasing order of profit or value/weight ratio.

bool comp(pair<int,int>a,pair<int,int>b)
{
    double r1=(double)a.second/a.first;
    double r2=(double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);
    double res=0;
    for (int i=0;i<n;i++)
    {
        if(items[i].first<=w)
        {
            res=res+items[i].second;
            w=w-items[i].first;
        }
        else
        {
            res=res+(items[i].second *((double)w/items[i].first));
            break;
        }
    }
    
    return res;
}
// Time -> O(N logN)
// Space -> O(1)