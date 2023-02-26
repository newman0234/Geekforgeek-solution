#include <bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int build_query(int index,int low,int high,int l,int r,int segment[]){
        // no overlap  [low high] [l,r] or [l,r] [low,high]
        if(l>high || r<low){
            return 0;
        }
        // complete overlap  [l low high r]
        if(low>=l and high<=r){
            return segment[index];
        }
        int mid=(low+high)>>1;
        int left=build_query((2*index)+1,low,mid,l,r,segment);
        int right=build_query((2*index)+2,mid+1,high,l,r,segment);
        return left^right;
    }
    void build(int index,int low,int high,int a[],int segment[]){
        if(low==high){
            segment[index]=a[low];
            return;
        }
        int mid=(low+high)>>1;
        build((2*index)+1,low,mid,a,segment);
        build((2*index)+2,mid+1,high,a,segment);
        segment[index]=(segment[2*index+1]^segment[2*index+2]);
    }
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        int segment[400000];
        for(int i=0;i<400000;i++){
            segment[i]=0;
        }
        vector<int>ans;
        build(0,0,N-1,a,segment);
        for(int i=0;i<Q;i++){
            int a=query[i][0];
            int b=query[i][1];
            //cout<<a<< " "<<b<<endl;
            int range1=1;
            int range2=a-1;
            int ans1=0;
            int ans2=0;
            //cout<<range1<<" "<<range2<<endl;
            if(range1<=range2){
                range1--;
                range2--;
                ans1=build_query(0,0,N-1,range1,range2,segment);
            }
            
            range1=b+1;
            range2=N;
           // cout<<range1<<" "<<range2<<endl;
             if(range1<=range2){
                range1--;
                range2--;
                ans2=build_query(0,0,N-1,range1,range2,segment);
            }
            int final=ans1^ans2;
            ans.push_back(final);
           
        }
        
        return ans;
        
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends