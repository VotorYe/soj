#include<iostream>
#include<set>

using namespace std;

void simulate_picking_card(int sum_of_first, int sum_of_second,
						  int left_bound, int right_bound,
						  int* cards,
						  multiset<int>& sub_second_from_first) {
	if (left_bound > right_bound) {
		sub_second_from_first.insert(sum_of_first-sum_of_second);
		return;
	}

	// first player pick left
	if (cards[left_bound+1] >= cards[right_bound]) {
		// second player pick left
		simulate_picking_card(sum_of_first+cards[left_bound],
							  sum_of_second+cards[left_bound+1],
							  left_bound+2,
							  right_bound,
							  cards,
							  sub_second_from_first);
	} else {
		// secound player pick right
		simulate_picking_card(sum_of_first+cards[left_bound],
							  sum_of_second+cards[right_bound],
							  left_bound+1,
							  right_bound-1,
							  cards,
							  sub_second_from_first);
	}

	// first player pick right
	if (cards[left_bound] >= cards[right_bound-1]) {
		// second player pick left
		simulate_picking_card(sum_of_first+cards[right_bound],
							  sum_of_second+cards[left_bound],
							  left_bound+1,
							  right_bound-1,
							  cards,
							  sub_second_from_first);
	} else {
		// secound player pick right
		simulate_picking_card(sum_of_first+cards[right_bound],
							  sum_of_second+cards[right_bound-1],
							  left_bound,
							  right_bound-2,
							  cards,
							  sub_second_from_first);
	}
}

int get_worst_lose_point(int* cards, const int n) {
	int sum_of_first = 0, sum_of_second = 0;
	multiset<int> sub_second_from_first;
	simulate_picking_card(0, 0, 0, n - 1, cards, sub_second_from_first);
	return *sub_second_from_first.rbegin();
}

int main() {
	int n;
	int cards[1000];

	while (cin >> n && n) {
		for (int i = 0; i < n; ++i)
		{
			cin >> cards[i];
		}

		cout << "In game 1, the greedy strategy might lose by as many as "
			 << get_worst_lose_point(cards, n) << " points." << endl;
	}

	return 0;
}
