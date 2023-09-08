# 구간합-Prefixsum

```c++
int psum[10],arr[10]={1,2,3,4,5,6,7,8,9,10};

int main() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++) {
			psum[i] += arr[j];
		}
	}

	for (int k : psum)
		cout << k << " ";
	return 0;
}
```

`참고`
예를 들어, 3번째 구간합을 알고싶다면 psum[2]-psum[1]
