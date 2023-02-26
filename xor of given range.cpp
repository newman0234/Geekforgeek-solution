#include <bits/stdc++.h>
using namespace std;
  int query(int index,int low,int high,int a,int b,int segment[]){
        //no overlap [low,high] [a,b] or [a,b] [low,high];
        if(a>high || low>b){
            return 0;
        }
        // fully overlap [a low high b];
        if(low>=a and b>=high){
            return segment[index];
        }
        int mid=(low+high)>>1;
        int left=query((2*index)+1,low,mid,a,b,segment);
        int right=query((2*index)+2,mid+1,high,a,b,segment);
        return left^right;
    }
    void build(int index,int low ,int high,vector<int>nums,int segment[]){
        if(low==high){
            segment[index]=nums[low];
            return;
        }
        int mid=(low+high)>>1;
        build((2*index)+1,low,mid,nums,segment);
        build((2*index)+2,mid+1,high,nums,segment);
        segment[index]=segment[2*index+1]^segment[2*index+2];
    }
    int getXor(vector<int>&nums, int a, int b){
        int len=nums.size();
        int segment[4*len];
        build(0,0,len-1,nums,segment);
        int ans=query(0,0,len-1,a,b,segment);
        return ans;
    }
int main() {
    cout<<"Hello World!";
}
