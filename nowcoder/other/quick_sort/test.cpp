#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数，放在x右边
                i++;
            if(i < j)
                s[j--] = s[i];
        }
		//最后i的值一定是在中间位置（左边小于x，右边大于或等于x）
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}

void show(int s[], int size)
{
	for (int i = 0; i< size; i++) {
		cout << s[i] << " ";
	}
	std::cout << std::endl;
}

void quick_sort_mid(int s[], int l, int r)
{
    if (l < r)
    {
		int m = s[(l + r)/2]; //以中间元素作为关键数据
		cout << "m=" << m <<endl;
		int i = l,j = r;
		while(i < j){ //直到i>j
			while(s[i] <= m) i++; //从i开始向前搜索(i++)，找到第一个大于m的值//准备放到右边
			while(s[j] > m) j--; //从j开始向前搜索(j--)，找到第一个小于m的值，准备放到左边
			cout << "i=" << i <<endl;
			cout << "j=" << j <<endl;
			if (i < j) {
				cout << "swap i=" << i <<endl;
				cout << "swap j=" << j <<endl;
				swap(s[i], s[j]);//交换a[i]和a[j]的值
				show(s, 10);
			}
		}

		quick_sort_mid(s, l, i - 1); // 递归调用
		quick_sort_mid(s, i + 1, r);
	}
}

void quick_sort_mid_ok(int s[], int l, int r)
{
    if (l < r)
    {
		cout << "quick_sort_mid_ok start" <<endl;
		int m = s[(l + r)/2]; //以中间元素作为关键数据
		cout << "m=" << m <<endl;
		int i = l,j = r;
		while(i < j){ //直到i>j
			while(s[i] < m) i++; //从i开始向前搜索(i++)，找到第一个大于m的值//准备放到右边
			while(s[j] > m) j--; //从j开始向前搜索(j--)，找到第一个小于m的值，准备放到左边
			cout << "i=" << i <<endl;
			cout << "j=" << j <<endl;
			if (i <= j) {
				cout << "swap i=" << i <<endl;
				cout << "swap j=" << j <<endl;
				swap(s[i], s[j]);//交换a[i]和a[j]的值
				show(s, 10);
				i++;//继续检查下一组元素
				j--;
			}
		}
		cout << "quick_sort_mid_ok end" << endl;

		quick_sort_mid_ok(s, l, j); // 递归调用
		quick_sort_mid_ok(s, i, r);
	}
}

int main()
{
    int n;
	int input;
	while( cin >> n) {
		int a[n];
        for ( int i = 0; i < n; i++)
        {
			cin >> a[i];
        }

		int b[n];
		memcpy(b,a,sizeof(a));

		// quick_sort_mid(a, 0, n-1);
		show(a, 10);
		cout << "b:" << endl;
		quick_sort_mid_ok(b, 0, n-1);
		show(b, 10);
		cout << endl;
    }
}
