#include "provider_directory.h"
#include "provider_directory_internal.h"


/** # Pair */
template <class K, class V>
Pair<K,V>::Pair()
  : key()
  , data(NULL)
{
}


template <class K, class V>
Pair<K,V>::Pair(const Pair<K,V>& another)
  : key(another.key)
  , data(NULL)
{
  if (another.data != NULL)
    data = new V(*another.data);
  else
    data = new V;
}


template <class K, class V>
Pair<K,V>::Pair(const K& key, const V& value)
  : key(key)
  , data(NULL)
{
  value(data);
}


template <class K, class V>
Pair<K,V>::~Pair()
{
  if (data != NULL)
    delete data;
  data = NULL;
}



/** # TreeNoe */
template <class K, class V>
TreeNode<K,V>::TreeNode()
  : c(TreeNode::BLACK)
  , p(NULL)
  , left(NULL)
  , right(NULL)
  , parent(NULL)
{
}


template <class K, class V>
TreeNode<K,V>::TreeNode(const TreeNode<K,V>& another)
  : c(another.color)
  , p(NULL)
  , left(another.left)
  , right(another.right)
  , parent(another.parent)
{
  if (another.p != NULL)
    value(*another.p);
}


template <class K, class V>
TreeNode<K,V>::TreeNode(const K& key, const V& value)
  : c(TreeNode::BLACK)
  , p(NULL)
  , left(NULL)
  , right(NULL)
  , parent(NULL)
{
  Pair<K,V> d(key, value);
  pair(d);
}


template <class K, class V>
TreeNode<K,V>::~TreeNode()
{
  if (p != NULL)
    delete p;
  p = NULL;
  c = TreeNode::BLACK;
  left = NULL;
  right = NULL;
  parent = NULL;
}



/** # TreeMap */
template <class K, class V>
TreeMap<K,V>::TreeMap()
  : root(NULL)
  , nilNode(new TreeNode<K,V>)
  , count(0)
{
}


template <class K, class V>
TreeMap<K,V>::TreeMap(const TreeMap& another)
  : root(NULL)
  , nilNode(new TreeNode<K,V>)
  , count(0)
{
  // TODO: copy the entire tree
}


template <class K, class V>
TreeMap<K,V>::~TreeMap()
{
  // TODO: remove the entire tree
  if (nilNode != NULL)
    delete nilNode;
  nilNode = NULL;
}
