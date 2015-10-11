#include <stdlib.h>
#include <stdio.h>

const int count = 5;
const int inf = -99999999;
int target;
int ans;

void dfs(int* nums,int n) {
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] <= target && nums[i] > ans) {
			ans = nums[i];
		}
	}
	if (ans == target) return;		// get target
	if (n == 1) return;		// one operand left

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int tem_a = nums[i];
			int tem_b = nums[j];

			nums[j] = nums[n - 1];

			nums[i] = tem_a + tem_b;
			dfs(nums, n - 1);

			nums[i] = tem_a - tem_b;
			dfs(nums, n - 1);

			nums[i] = tem_b - tem_a;
			dfs(nums, n - 1);

			nums[i] = tem_a * tem_b;
			dfs(nums, n - 1);

			if (tem_b != 0 && tem_a % tem_b == 0) {
				nums[i] = tem_a / tem_b;
				dfs(nums, n - 1);
			}
			if (tem_a != 0 && tem_b % tem_a == 0) {
				nums[i] = tem_b / tem_a;
				dfs(nums, n - 1);
			}

			nums[i] = tem_a;
			nums[j] = tem_b;
		}
	}
}

int main() {
	int cases;
	scanf("%d", &cases);
	int nums[count];

	while (cases--) {
		ans = inf;
		for (int i = 0; i < count; ++i)
		{
			scanf("%d", &nums[i]);	
		}
		scanf("%d", &target);

		dfs(nums, count);

		printf("%d\n", ans);
	}
	return 0;
}