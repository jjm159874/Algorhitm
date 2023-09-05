# Split 구현

- split할 초기 문자열:s   
- 자를 경계 문자열(delimeter):d
vector<string> a=split(s,d);

"저는 25살 조재민 입니다."

저는/25살/조재민/입니다. 4개의 문자열을 저장해야 하므로 vector<string> 변수 사용.

```c++
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> split(string _s,string d) {
	vector<string> res;
	string token="";
	long long pos = 0;
	while ((pos= _s.find(d)) != string::npos) {	//pos는 d(split경계)를 찾아서 그 위치 받는다. _s.find(d)!=string::npos는 찾았다는 뜻. 
		token = _s.substr(0, pos);
		res.push_back(token);
		_s.erase(0, pos + d.length());
	}
	res.push_back(_s);

	return res;	
}

int main() {
	string s,d=" ";
	getline(cin, s);
	
	vector<string> a = split(s, d); 
	
	for (string k : a)
		cout << k << "\n";

	return 0;
}
```
