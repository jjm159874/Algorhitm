# 구간합-Prefixsum

```c++
int psum[10],arr[10]={1,2,3,4,5,6,7,8,9,10};

int main() {
	for (int i = 0; i < 10; i++)
	{
		if(i==0)
			psum[i]=arr[i];
		else{
			psum[i]=psum[i-1]+arr[i];
		}
	}

	for (int k : psum)
		cout << k << " ";
	return 0;
}
```

`참고`
예를 들어, 3번째 구간합을 알고싶다면 psum[2]-psum[1]
