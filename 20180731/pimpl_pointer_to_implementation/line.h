///
/// @file    line.h
/// @date    2018-08-01 09:11:08
///

#include <iostream>
using std::cout;
using std::endl;

//PIMPL设计模式:
////1. 实现信息隐藏
////2. 接口与实现进行分离
////3. 减小编译依赖
////4. 能够以最小的代价，实现库的平滑升级

class Line
{
	class LineImpl;
	public:
	Line(int, int, int, int);
	~Line();

	void printLine() const;

	private:
	LineImpl * _pimpl;
};
