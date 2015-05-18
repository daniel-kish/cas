#include "tree"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	Tree<string> t;
	Iterator<Tree<string>> p = t.root();
	
	*p = "root"s;
	t.append(p, "first"s );
	t.append(p, "second"s);
	t.append(p, "third"s);
	
	auto b = t.begin(p);
	auto e = t.end(p);

	std::for_each( b, e, [](auto& e){ e += "_end"s ;} );

	cout << t;
}
