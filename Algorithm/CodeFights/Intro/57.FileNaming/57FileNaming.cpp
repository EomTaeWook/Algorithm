// 57FileNaming.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <set>
std::vector<std::string> fileNaming(std::vector<std::string> names) {
	std::set<std::string> _list;
	for (int i = 0; i < names.size(); i++)
	{
		if (_list.count(names[i]) > 0)
		{
			int num = 1;
			while (_list.count(names[i] + "(" + std::to_string(num) + ")") > 0)
				num++;
			names[i] += "(" + std::to_string(num) + ")";
		}
		_list.insert(names[i]);
	}
	return names;
}

int main()
{
	std::vector<std::string> v = { "doc","doc","image","doc(1)","doc"};
	fileNaming(v);
    return 0;
}

