#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <memory>

template <class T>
class Tree
{
public:
	struct Node;
	struct Iterator;
	Node head;
	
	Tree() : head{}
	{}
	
	// copy semantics
	Tree(const Tree&) = default;
	Tree& operator=(const Tree&) = default;
	
	// move semantics
	Tree(Tree&&) = default;
	Tree& operator=(Tree&&) = default;
	
	Iterator root()
	{
		return Iterator(&head);
	}
	
	Iterator begin(Iterator& par) const
	{
		return Iterator{ &par.n->leaves[0] };
	}
	
	Iterator end(Iterator& par) const
	{
		return Iterator{ &par.n->leaves[ par.n->leaves.size() ] };
	}
	
	void append(Iterator& i, T v)
	{
		i.n->leaves.emplace_back( v, i.n );
	}
	
	friend std::ostream& operator<<(std::ostream& s, const Tree& t)
	{
		t.head.printNode(s,0);
		return s;
	}
};

template <class T>
struct Tree<T>::Node {
	T data;
	std::vector<Node> leaves;
	Node* parent;

	Node() : data{}, leaves{}, parent{ nullptr }
	{	}
	Node(const T& d) : data{ d }, leaves{}
	{	}
	Node(T&& d) : data( std::move(d) ), leaves{}
	{	}
	Node(Node* par) : data{}, leaves{}, parent{par}
	{	}
	Node(T v, Node* par) : data{v}, leaves{}, parent{par}
	{	}

	// copy semantics
	Node(const Node&) = default;
	Node& operator=(const Node&) = default;
	// move semantics
	Node(Node&&) = default;
	Node& operator=(Node&&) = default;
	// destruction
	~Node() = default;

	void printNode(std::ostream& s, int offset) const
	{
		std::vector<char> v(2*offset, ' ');
		for(char c : v)
			s << c;

		s << data << '\n';
		
		for (const auto& leaf : leaves)
		{
			leaf.printNode(s,offset+1);
		}
	}
};



#endif // TREE_H
