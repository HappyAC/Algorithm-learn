#include<iostream>
#include<vector>

using namespace std;


int main () {
  int
  	 N
  	,templeft
  	,left
  	,right
  	,sum
  	,temp
  	;
  	
  	scanf("%d", &N);
  	
  	vector<int> A(N);
  	
  	right 	= N - 1;
  	left 	= 0;
  	sum 	= -1;
  	temp 	= 0;
  	
  	for (int i = 0; i < N; i++) {
  		scanf("%d", &A[i]);
		
		temp += A[i];
		
		if (temp < 0) {
			temp = 0;
			templeft = i + 1;
		} else if (temp > sum) {
			sum = temp;
			left = templeft;
			right = i;
		}
	}
	
	if (sum < 0) {
		sum = 0;
	}
	
	printf("%d %d %d", sum, A[left], A[right]);
	
  	return 0;
}
