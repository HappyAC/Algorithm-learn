/*
stack最大值为m 

*/ 
bool check (vector<int> seq) {
	while(!ss.empty()) ss.pop();

	int i = 1, index = 0;
	//printf("->");
	while(ss.size() < m && index < seq.size()) {
		ss.push(i++);
		while(!ss.empty() && seq[index] == ss.top()) {
			index++;
			//printf("%d ", ss.top());
			ss.pop();
		}
	}
	//printf("\n");

	if (index != seq.size() || !ss.empty()) return false;

	return true;
}
