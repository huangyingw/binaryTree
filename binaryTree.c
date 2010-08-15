#include <stdio.h>
#include <conio.h>
#include <alloc.h>

#include <string.h>

#define MAXCOUNT 32

#define LEFT  0

#define RIGHT 1

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
class SongKe_BinaryTree
{
public:
　　SongKe_BinaryTree() : _i_generate(0) {}
　　~SongKe_BinaryTree() {}
　　void pre_insert(const string& s) { _pre.push_back(s); }
　　void in_insert(const string& s)　　 { _in.push_back(s); }
　　
　　void pre_out()　　{ _out("PREORDER : ", _pre); }
　　void in_out()　　{ _out("INORDER : ", _in); }
　　
　　void post_out();
　　// generate the binary tree
　　void generate();
private:
　　// get left or right subtree for iteration
　　void _get_subtree(int iNode, vector< pair<string, int> >& v);
　　void _get_subtree(bool bLeft, int iNode, vector< pair<string, int> >& v);
　　void _postorder_iterate(const vector< pair<string, int> >& v);// postorder iterate
　　void _inorder_iterate(const vector< pair<string, int> >& v);　　// using postorder iterate
　　void _preorder_iterate(const vector< pair<string, int> >& v);// using postorder iterate
　　int _i_generate; // point to current element of preorder
　　// mark the elements in inorders, and recurse the func in.
　　// bLeft == true or false is right
　　void _kesongemini(bool bLeft, int iNode, const vector<string>& v);
　　void _kesongemini(const string& node, int jj, bool bLeft, int iNode, const vector<string>& v);
　　// print out
　　void _out(const string& explain, const vector<string>& vec);
　　vector<string> _pre; // preorder sequence as known
　　vector<string> _in; // inorder sequence as known
　　vector<string> _post; // postorder sequence as request
　　
　　vector< pair<string, int> > _s; // string, position as ordinal saving
　　map<int, string> _sm; // assistant for making subtree when postorder iterate
　　vector<int> _si; 　　// assistant for making subtree when postorder iterate
};
void SongKe_BinaryTree::_out(const string& explain, const vector<string>& vec)
{
　　cout << explain << "　　";
　　for(vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
　　{
　　　　cout << *i << " ";
　　}
　　cout << endl;
}
void SongKe_BinaryTree::generate()
{
　　cout << "THE BTREE IS " << endl;
　　string node( _pre[_i_generate++] ); // get the first elem of preorder
　　int jj = 1;
　　_kesongemini(node, jj, true, 0, _in);　　
}
void SongKe_BinaryTree::_kesongemini(bool bLeft, int iNode, const vector<string>& v)
{
　　string node( _pre[_i_generate++] ); // get a elem of preorder in turn
　　int jj = bLeft ? 2*iNode /* left */ : 2*iNode+1 /* right */;
　　_kesongemini(node, jj, bLeft, iNode, v);
}
void SongKe_BinaryTree::_kesongemini(const string& node, int jj, bool bLeft, int iNode, const vector<string>& v)
{
　　_s.push_back( make_pair(node, jj) ); // get a node of the betree in turn
　　_sm[ jj ] = node;　　// assistant for postorder iterate later :)
　　_si.push_back( jj ); // assistant for postorder iterate later :)
　　cout << "　　　　" << (*(_s.end()-1)).first << " " << (*(_s.end()-1)).second << endl;　　
　　vector<string> l, r;
　　bool b = false;
　　// to find the node in the inorder sequence
　　for ( vector<string>::const_iterator i = v.begin(); i<v.end(); ++i )
　　{
　　　　if ( !b && *i != node )　　// left subtree
　　　　{
　　　　　　l.push_back(*i);
　　　　}
　　　　else if ( !b && *i == node ) // backbone found here
　　　　{
　　　　　　b = true;
　　　　}
　　　　else if ( b && *i != node ) // right subtree
　　　　{
　　　　　　r.push_back(*i);
　　　　}
　　}
　　if ( !l.empty() )　　_kesongemini(true, jj, l); // left subtree
　　if ( !r.empty() )　　_kesongemini(false, jj, r); // right subtree
}
void SongKe_BinaryTree::_get_subtree(int iNode, vector> pair<string, int> >& v)
{
　　vector<int>::iterator iter;
　　
　　iter = find( _si.begin(), _si.end(), iNode); // the header node self
　　if ( iter != _si.end() )
　　{
　　　　v.push_back( make_pair( _sm[ iNode ], iNode ) );
　　}
　　int jj = iNode*2;　　　　// left subtree
　　iter = find( _si.begin(), _si.end(), jj);　　
　　if ( iter != _si.end() )
　　{　　　　　　　　　　　　　　
　　　　v.push_back( make_pair( _sm[ jj ], jj ) );
　　　　_get_subtree( jj, v );
　　}
　　
　　++jj;　　　　// e.q. iNode*2+1　　　　　　　　
　　　　　　　　// right subtree
　　iter = find( _si.begin(), _si.end(), jj);
　　if ( iter != _si.end() )
　　{
　　　　v.push_back( make_pair( _sm[ jj ], jj ) );
　　　　_get_subtree( jj, v );
　　}
}
void SongKe_BinaryTree::_get_subtree(bool bLeft, int iNode, vector< pair<string, int> >& v)
{
　　_get_subtree(bLeft ? iNode*2 : iNode*2+1, v);
}
void SongKe_BinaryTree::_postorder_iterate(const vector< pair<string, int> >& v)
{
		vector<pair<string,int>> l,r;
　　pair<string, int> f = *v.begin();
　　// generate the new subtree l and r
　　_get_subtree(true, f.second, l);
　　_get_subtree(false, f.second, r);
　　// postorder algorithm
　　if ( !l.empty() )　　_postorder_iterate(l);
		if(!r.empty()) _postorder_iterate(r);
		_post.push_back(f.first);
}
void SongKe_BinaryTree::post_out()　　
{
　　_postorder_iterate( _s );
　　_out("POSTORDER : ", _post);
}


int main(int argc, char* argv[])
{
　　SongKe_BinaryTree tree;　　
		tree.pre_insert("A");
　　tree.pre_insert( "B" );
　　tree.pre_insert( "D" );
　　tree.pre_insert( "C" );
		tree.pre_insert("E");
		tree.pre_insert("G");
		tree.pre_insert("F");
		tree.pre_out();
		tree.in_insert("D");
　　tree.in_insert( "B" );
　　tree.in_insert( "A" );　　
		tree.in_insert("E");　　
		tree.in_insert("G");　　
		tree.in_insert("C");
		tree.in_insert("F");
		tree.in_out();
		tree.generate();
		tree.post_out();
		return 0;
}
