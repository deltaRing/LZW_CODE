#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct dict {
	vector <string> _dict_;	
	vector <int> _code_;
	int code_iter = 0;
};

struct decode {
	vector <string> _dict_;
	vector <int> _code_;
	int code_iter = 0;
};

void _init_decode(decode & d) {
	d._dict_.push_back(string("a"));
	d._dict_.push_back(string("b"));
	d._dict_.push_back(string("c"));
	d._code_.push_back(d.code_iter++);
	d._code_.push_back(d.code_iter++);
	d._code_.push_back(d.code_iter++);
}

void _init_dict_(dict & d) {
	d._dict_.push_back(string("a"));
	d._dict_.push_back(string("b"));
	d._dict_.push_back(string("c"));
	d._code_.push_back(d.code_iter++);
	d._code_.push_back(d.code_iter++);
	d._code_.push_back(d.code_iter++);
}

// 读取单个字符
void _read_char_(string & P, char c) {
	P.push_back(c);
}

// 检查字典
// 输入：字符串P、字典D、上一次加入的字符c
// 自动编码，更新字典
void _check_dict_(string & P, dict & d, char c, int & code_res, int & output) {
	vector <string>::iterator iter = find(begin(d._dict_), end(d._dict_), P);
	if (iter != std::end(d._dict_)) {
		// 找到了对应的字典
		int index = std::distance(d._dict_.begin(), iter);
		// 找到对应的位置
		code_res = d._code_.at(index);
		output = -1;
	}
	else {
		// 没有找到字典
		d._dict_.push_back(P);
		// 更新字典
		d._code_.push_back(d.code_iter);
		code_res = d.code_iter;
		d.code_iter++;
		// 更新输出
		string res = P;
		res.pop_back();
		vector <string>::iterator _iter_ = find(begin(d._dict_), end(d._dict_), res);
		int index = std::distance(d._dict_.begin(), _iter_);
		output = d._code_.at(index);
		// 更新编码
		P.clear();
		P.push_back(c);
		// 更新P
	}
}

// 解码算法
// 输入：字典 输入的符号
// 输出：解码后的符号
void _decode_(decode & de, vector <int> & pW, int cW, string & output) {
	vector <int>::iterator iter = find(begin(de._code_), end(de._code_), cW);
	if (iter != std::end(de._code_)) {
		// 	找到了对应的符号
		int index = std::distance(de._code_.begin(), iter);
		output = de._dict_.at(index);
		// 输出符号
		string _symbol_;
		if (pW.size() > 0) {
			for (int ii = 0; ii < pW.size(); ii++) {
				vector <int>::iterator _iter_ = find(begin(de._code_), end(de._code_),pW.at(ii));
				if (_iter_ != de._code_.end()) {
					int _index_ = std::distance(de._code_.begin(), _iter_);
					_symbol_.append(de._dict_.at(_index_));
				}
				else {
					continue;
				}
			} // 找到pW对应的字符
		}
		// 找到cW对应的字符
		vector <int>::iterator _iter_ = find(begin(de._code_), end(de._code_), cW);
		if (_iter_ != de._code_.end()) {
			int _index_ = std::distance(de._code_.begin(), _iter_);
			_symbol_.append(de._dict_.at(_index_));
		}
		de._dict_.push_back(_symbol_);
		de._code_.push_back(de.code_iter++);
		// 添加符号
		pW.clear();
		pW.push_back(cW);
		// 更新符号
	}
	else {
		// 没有找到对应的符号
		string _symbol_;
		if (pW.size() > 0) {
			for (int ii = 0; ii < pW.size(); ii++) {
				vector <int>::iterator _iter_ = find(begin(de._code_), end(de._code_), pW.at(ii));
				if (_iter_ != de._code_.end()) {
					int _index_ = std::distance(de._code_.begin(), _iter_);
					_symbol_.append(de._dict_.at(_index_));
				}
				else {
					continue;
				}
			} // 找到pW对应的字符
		}
		if (_symbol_.size() > 0)
			_symbol_.push_back(_symbol_.at(0));
		output = _symbol_;
		// 构建符号
		de._dict_.push_back(_symbol_);
		de._code_.push_back(de.code_iter++);
		// 添加符号
		pW.clear();
		pW.push_back(cW);
		// 更新符号
	}
}
