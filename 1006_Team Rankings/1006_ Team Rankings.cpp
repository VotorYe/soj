#include<stdlib.h>
#include<stdio.h>
#include<string.h>

const int col = 5;
int min_value;
bool on = false;
int count = 0;

int calcu_value(const char ranks[], int rankMakrsA[]) {
	int rankMakrsB[col];
	int value = 0;
	for (int i = 0; i < col; ++i)
	{
		rankMakrsB[ranks[i] - 'A'] = i;
	}

	for (int i = 0; i < col; ++i)
	{
		for (int k = i+1; k < col; ++k)
		{
			int a = rankMakrsA[i] - rankMakrsA[k];
			int b = rankMakrsB[i] - rankMakrsB[k];
			if (a*b < 0) {
				value++;
			}
		}
	}
	return value;
}

int sum_up_value(const char ranks[][col+1],int rows, const char* temp) {
	int i;
	int rankMakrs[col];
	int sum = 0;
	for (int i = 0; i < col; ++i)
	{
		rankMakrs[temp[i] - 'A'] = i;
	}

	for (i = 0; i < rows; i++) {
		sum += calcu_value(ranks[i], rankMakrs);
	}
	return sum;
}

void dfs(const int upperbound, char* output,
		 char* temp, int index, char ranks[][col+1],
		 const char* letters, int* marks, int n) {
	int i;
	if (index == upperbound) {
		count++;
		int sum = sum_up_value(ranks, n, temp);
		if (on == false
			|| min_value > sum)  {
			strcpy(output, temp);
			min_value = sum;
			on = true;
		}
	} else {
		for (i = 0; i < upperbound; i++) {
			if (marks[i] == 0) {
				marks[i] = 1;
				temp[index] = letters[i];
				dfs(upperbound, output, temp, index+1, ranks, letters, marks, n);
				marks[i] = 0;
				temp[index] = '\0';
			}
		}
	}
}

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		char ranks[n+1][col+1];
		char output[col+1] = {'\0'};
		char temp[col+1] = {'\0'};
		char letters[col+1] = {'A', 'B', 'C', 'D', 'E'};
		int marks[col+1] = {0, 0, 0, 0, 0};
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", ranks[i]);	
		}

		dfs(col, output, temp, 0, ranks, letters, marks, n);
		printf("%s is the median ranking with value %d.\n", output, min_value);
		//printf("%d\n", count);
		on = false;
		count = 0;
	}
	return 0;
}
