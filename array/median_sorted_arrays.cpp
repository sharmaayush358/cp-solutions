class Solution {
public:

    bool isLTE(int a, int b) {
        return a<=b;
    }

    void initializeVars(vector<int>& nums1,vector<int>& nums2,int mid, int& x1, int& x2, int& y1, int& y2) {
        int m = nums1.size(), n = nums2.size();
        int leftPartitionSize = (m+n+1)/2;

        int negInf = -1e9, posInf = 1e9;
        x1 = negInf, x2 = posInf, y1 = negInf, y2 = posInf;

        int i1 = mid-1, i2 = mid;
        int j1 = leftPartitionSize - mid -1;
        int j2 = j1+1;

        if(i1>=0) {
            x1 = nums1[i1];
        }
        if(i2<m) {
            x2 = nums1[i2];
        }
        if(j1>=0) {
            y1 = nums2[j1];
        }
        if(j2<n) {
            y2 = nums2[j2];
        }

        return;
    }

    double calcMedian(bool isMergedArrayOdd,
    int x1, int x2, int y1, int y2) {
        if(isMergedArrayOdd) {
            return max(x1, y1);
        }
        else {
            double leftMax = max(x1, y1), rightMin = min(x2, y2);
            return (leftMax + rightMin)/2.0;
        }
    }

    double findMedianSortedArraysImpl(
    vector<int>& nums1, int m,
    vector<int>& nums2, int n) {
        bool isMergedArrayOdd = (m+n)%2;

        int start = 0, end = m;
        double median;
        while(start<=end) {
            int mid = (start+end)/2;
            int x1, x2, y1, y2;
            initializeVars(nums1, nums2, mid, x1, x2, y1, y2);

            bool v1 = isLTE(x1, y2), v2 = isLTE(y1, x2);
            if(v1 && v2) {
                median = calcMedian(isMergedArrayOdd, x1, x2, y1, y2);
                break;
            }
            else if(!v1) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }

        return median;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double ans;
        if (m<n) {
            ans = findMedianSortedArraysImpl(nums1, m, nums2, n);
        }
        else {
            ans = findMedianSortedArraysImpl(nums2, n, nums1, m);
        }

        return ans;
    }
};
