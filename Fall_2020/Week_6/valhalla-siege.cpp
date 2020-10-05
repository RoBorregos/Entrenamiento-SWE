/*
Problem: https://codeforces.com/contest/975/problem/C

Approach: Use an array to accumulate the warriors' strength and upper bound to 
      find how many are left after t minutes.
			
Time complexity: O(n*m*log(n))

Space complexity: O(n)
*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int warriorsStanding(int warriors, int battle_time, int arr[], int arrArrow[]){
    long long int warrior_strength[200003], sum=0, arrtime=0, result;
	warrior_strength[0] = arr[0];
	
	for(int i=1;i<warriors;i++){
		warrior_strength[i] = arr[i];
		warrior_strength[i]+=warrior_strength[i-1];
	}
	
	for(int j=0;j<battle_time;j++){
		arrtime = arrArrow[j];
		sum+=arrtime;
 
		if(sum>=warrior_strength[warriors-1]){
			sum=0;
			cout<<warriors<<endl;
		}
		else{
			result = warriors - (upper_bound(warrior_strength,warrior_strength+
			warriors,sum) - warrior_strength);
			cout<<result<<endl;
		}
	}
	return 0;
}

int main() {
	int warriors_test = 5;
	int battle_time_test = 5;
	int testWarriors[warriors_test] = {1, 2, 1, 2, 1};
	int testArrow[battle_time_test] = {3, 10, 1, 1, 1};
	warriorsStanding(warriors_test, battle_time_test, testWarriors, testArrow);
	cout << endl;
	return 0;
}
