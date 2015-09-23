#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	const float p = 3.1415927;
	const float mile_to_inch = 63360;
	const float hour_to_second = 3600;
	float diameter, seconds;
	float girth;
	float distance;		// in miles
	float MPH;			// miles per hour
	int revolution;
	int cases = 0;
	while (cin >> diameter >> revolution >> seconds && revolution) {
		cases++;
		girth = diameter*p;
		distance = girth * revolution;
		MPH = distance/seconds/mile_to_inch * hour_to_second;
		cout << "Trip #" << cases << ": ";
		cout << setiosflags(ios::fixed) << setprecision(2)
			 << distance/mile_to_inch << " "
			 << MPH << endl;
	}

	return 0;
}