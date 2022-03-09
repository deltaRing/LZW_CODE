// LZW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LZWCoding.h"

int main()
{
	dict d;
	decode de;
	// 建议预先建立一个完备的字典库
	string c = "ababcababac";
	string p;
	vector <int> pW;
	int cW;
	_init_dict_(d);
	_init_decode(de);
	for (int ii = 0; ii < c.size(); ii++) {
		int res = -1;
		int output = -1;
		string out;
		_read_char_(p, c.at(ii));
		cout << "数据：" << p.c_str();
		_check_dict_(p, d, c.at(ii), res, output);
		cout << " 编码结果：" << output;
		cW = output;
		if (cW < 0) {
			cout << endl;
			continue;
		}
		if (pW.size() == 0) {
			pW.push_back(cW); // 赋值
			cout << endl;
			continue;
		}
		_decode_(de, pW, cW, out);
		cout << " 解码结果：" << out.c_str() << endl;

	}

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
