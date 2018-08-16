 ///
 /// @file    node.h
 /// @date    2018-08-16 20:13:45
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class CalcNode;

class Node
{
	friend CalcNode;
protected:
	virtual ~Node() = default;
private:
	virtual double calc() const= 0;	
};

class CalcNode
{
	friend CalcNode operator-(const CalcNode &,const CalcNode &);
	friend CalcNode operator+(const CalcNode &,const CalcNode &);
	friend CalcNode operator*(const CalcNode &,const CalcNode &);
	friend CalcNode operator/(const CalcNode &,const CalcNode &);
public:
	CalcNode(double);
	double calc() const
	{
		return _q->calc();
	}
	CalcNode operator-();
private:
	CalcNode(shared_ptr<Node> q)
		:_q(q){}
	shared_ptr<Node> _q;
};

//-------------------------------------------
class NumNode
:public Node
{
	friend class CalcNode;
	friend CalcNode CalcNode::operator-();
	friend CalcNode operator-(const CalcNode &,const CalcNode &);
	friend CalcNode operator+(const CalcNode &,const CalcNode &);
	friend CalcNode operator*(const CalcNode &,const CalcNode &);
	friend CalcNode operator/(const CalcNode &,const CalcNode &);
	NumNode(double d)
		:_d(d){}
	double calc() const
	{
		return _d;
	}
	double _d;
};
//---------------------------------------------
class BinaryNode
:public Node
{
protected:
	BinaryNode(CalcNode l,CalcNode r)
		:_left(l),_right(r){}
	CalcNode _left,_right;
};

class AddNode
:public BinaryNode
{
	friend CalcNode operator+(const CalcNode &,const CalcNode &);
	AddNode(const CalcNode& l ,const CalcNode& r)
		:BinaryNode(l,r){}
	double calc() const
	{
		return _left.calc()+_left.calc();
	}
};

class MultiplyNode
:public BinaryNode
{
	friend CalcNode operator*(const CalcNode &,const CalcNode &);
	MultiplyNode(const CalcNode& l ,const CalcNode& r)
		:BinaryNode(l,r){}
	double calc() const
	{
		return _left.calc()*_left.calc();
	}
};
class SubtractNode
:public BinaryNode
{
	friend CalcNode operator-(const CalcNode &,const CalcNode &);
	SubtractNode(const CalcNode& l ,const CalcNode& r)
		:BinaryNode(l,r){}
	double calc() const
	{
		return _left.calc()-_left.calc();
	}
};
class DivideNode
:public BinaryNode
{
	friend CalcNode operator/(const CalcNode &,const CalcNode &);
	DivideNode(const CalcNode& l ,const CalcNode& r)
		:BinaryNode(l,r){}
	double calc() const
	{
		return _left.calc()-_left.calc();
	}
};
//-------------------------------------------------------------------
class UnaryNode
:public Node
{
protected:
	UnaryNode(CalcNode s)
		:_single(s){}
	CalcNode _single;
};
class UMinusNode
:public UnaryNode
{
	friend CalcNode CalcNode::operator-();
	UMinusNode(const CalcNode & s)
		:UnaryNode(s){}
	double calc() const
	{
		return -_single.calc();
	}
};

inline
CalcNode::CalcNode(double _d)
:_q(new NumNode(_d)){}

inline
CalcNode CalcNode::operator-()
{
	return shared_ptr<Node>(new NumNode(-1*this->_q->calc()));
}
inline
CalcNode operator-(const CalcNode &l,const CalcNode &r)
{
	return shared_ptr<Node>(new NumNode(l.calc()-r.calc()));
}
inline
CalcNode operator+(const CalcNode &l,const CalcNode &r)
{
	return shared_ptr<Node>(new NumNode(l.calc()+r.calc()));
}
inline 
CalcNode operator*(const CalcNode &l,const CalcNode &r)
{
	return shared_ptr<Node>(new NumNode(l.calc()*r.calc()));
}
inline
CalcNode operator/(const CalcNode &l,const CalcNode &r)
{
	return shared_ptr<Node>(new NumNode(l.calc()/r.calc()));
}
