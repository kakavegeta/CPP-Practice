#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K){
        int left=0, right = points.size()-1;
        while(left<right){
            int p = partition(points, left, right);
            if(p == K-1) break;
            if(p < K-1) left = p+1;
            else right = p-1;
        }
        return vector<vector<int>>(points.begin(), points.begin()+K);


    }

    int partition(vector<vector<int>>& points, int lo, int hi){
        int i=lo, j=hi+1;
        vector<int> pivot = points[lo];
        while(true){
            while(less(points[++i], pivot)){
                if(i==hi) break;
            }
            while(less(pivot, points[--j])){
                if(j==lo) break;
            }
            if(i>=j) break;
            swap(points[i], points[j]);
        }
        swap(points[lo], points[j]);
        return j;
    }

    /*
    //Hoare scheme
    int partition(vector<vector<int>>& points, int left, int right){
        vector<int> pivot = points[(left+right)/2];
        while(true){
            while(less(points[left],pivot)) left++;
            while(less(pivot, points[right])) right--;
            if(left>=right) return right;
            swap(points[left], points[right]);
            left++;
            right--;
        }
    }
    */

    bool less(const vector<int>& A, const vector<int>& B){
        int distA = A[0]*A[0]+A[1]*A[1];
        int distB = B[0]*B[0]+B[1]*B[1];
        if(distA<distB) return true;
        else return false;

    }
};