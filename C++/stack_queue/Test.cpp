﻿#include"Stack_queue.h"
using namespace std;


int main()
{
	lsl::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}


