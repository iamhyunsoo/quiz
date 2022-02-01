class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int keep {0};
	int wap{1};
	for (int i = 1; i < nums1.size(); i++)
	{
		if (nums1[i-1] >= nums2[i] || nums2[i-1] >= nums1[i])
		{
			wap++;
		}
		else if (nums1[i-1] >= nums1[i] || nums2[i-1] >= nums2[i])
		{
			int tmp = keep;
			keep = wap;
			wap = tmp+1;
		}
		else
		{
			int minNum = std::min(keep, wap);
			wap = minNum + 1;
			keep = minNum;
		}
	}
	return std::min(keep, wap);    
    }
};
