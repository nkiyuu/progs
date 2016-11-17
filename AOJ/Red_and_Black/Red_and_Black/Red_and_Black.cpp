// Red_and_Black.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "iostream"
#include "stack"
#include "cstdio"
#include "sstream"
using namespace std;



int main()
{
	int row, col, size, start, now ;
	int num_mass = 0;
	int count = 0;
	stack<int> st;
	string str_col;
	

	string board[400];

	//while (1) {
		cin >> col >> row;
		size = row * col;
		//if (col == 0 && row == 0) break;

		for (int i = 0; i < row; i++) {
			cin >> str_col;
			for (int j = 0; j < (int)str_col.size(); ++i) {
				board[count] = str_col[j];
				if (str_col[j] == '@') {
					start = count;
				}
				count++;
			}
		}

		int start_r, start_c;

		board[start] = '#';
		num_mass++;
		now = start;
		while (1) {

			//左に動く
			if (now - 1 > -1 && board[now - 1] == (string)".") {
				now = now - 1;
				st.push(now);
				continue;
			}

			//右に動く
			if (now % col + 1 < col && board[now + 1] == (string)".") {
				now = now + 1;
				st.push(now);
				continue;
			}
			//下に動く
			if (now % row + col < col && board[now + col] == (string)".") {
				now = now + col;
				st.push(now);
				continue;
			}
			//上に動く
			if (now - col > 0 && board[now - col] == (string)".") {
				now = now - col;
				st.push(now);
				continue;
			}

			if (st.empty()) break;
			board[now] = '#';
			now = st.top();
			num_mass++;

		}
		cout << num_mass;
	//}
	return 0;
}

