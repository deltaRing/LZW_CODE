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

// ��ȡ�����ַ�
void _read_char_(string & P, char c) {
	P.push_back(c);
}

// ����ֵ�
// ���룺�ַ���P���ֵ�D����һ�μ�����ַ�c
// �Զ����룬�����ֵ�
void _check_dict_(string & P, dict & d, char c, int & code_res, int & output) {
	vector <string>::iterator iter = find(begin(d._dict_), end(d._dict_), P);
	if (iter != std::end(d._dict_)) {
		// �ҵ��˶�Ӧ���ֵ�
		int index = std::distance(d._dict_.begin(), iter);
		// �ҵ���Ӧ��λ��
		code_res = d._code_.at(index);
		output = -1;
	}
	else {
		// û���ҵ��ֵ�
		d._dict_.push_back(P);
		// �����ֵ�
		d._code_.push_back(d.code_iter);
		code_res = d.code_iter;
		d.code_iter++;
		// �������
		string res = P;
		res.pop_back();
		vector <string>::iterator _iter_ = find(begin(d._dict_), end(d._dict_), res);
		int index = std::distance(d._dict_.begin(), _iter_);
		output = d._code_.at(index);
		// ���±���
		P.clear();
		P.push_back(c);
		// ����P
	}
}

// �����㷨
// ���룺�ֵ� ����ķ���
// ����������ķ���
void _decode_(decode & de, vector <int> & pW, int cW, string & output) {
	vector <int>::iterator iter = find(begin(de._code_), end(de._code_), cW);
	if (iter != std::end(de._code_)) {
		// 	�ҵ��˶�Ӧ�ķ���
		int index = std::distance(de._code_.begin(), iter);
		output = de._dict_.at(index);
		// �������
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
			} // �ҵ�pW��Ӧ���ַ�
		}
		// �ҵ�cW��Ӧ���ַ�
		vector <int>::iterator _iter_ = find(begin(de._code_), end(de._code_), cW);
		if (_iter_ != de._code_.end()) {
			int _index_ = std::distance(de._code_.begin(), _iter_);
			_symbol_.append(de._dict_.at(_index_));
		}
		de._dict_.push_back(_symbol_);
		de._code_.push_back(de.code_iter++);
		// ��ӷ���
		pW.clear();
		pW.push_back(cW);
		// ���·���
	}
	else {
		// û���ҵ���Ӧ�ķ���
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
			} // �ҵ�pW��Ӧ���ַ�
		}
		if (_symbol_.size() > 0)
			_symbol_.push_back(_symbol_.at(0));
		output = _symbol_;
		// ��������
		de._dict_.push_back(_symbol_);
		de._code_.push_back(de.code_iter++);
		// ��ӷ���
		pW.clear();
		pW.push_back(cW);
		// ���·���
	}
}
