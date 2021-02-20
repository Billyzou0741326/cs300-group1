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


template <class K, class V>
void Pair<K,V>::setKey(const K& key)
{
  this->key = key;
}


template <class K, class V>
const K& Pair<K,V>::getKey() const
{
  return key;
}


template <class K, class V>
const V& Pair<K,V>::value() const
{
  return *data;
}


template <class K, class V>
V& Pair<K,V>::value()
{
  return *data;
}


template <class K, class V>
void Pair<K,V>::value(const V& data)
{
  if (this->data != NULL)
    delete this->data;
  this->data = new V(data);
}


template <class K, class V>
int Pair<K,V>::compare(const K& key) const
{
  if (this->key > key)
    return 1;
  else if (this->key < key)
    return -1;
  return 0;
}


template <class K, class V>
bool operator== (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) == 0;
}


template <class K, class V> 
bool operator== (const Pair<K,V>& pair, const K& key)
{
  return key == pair;
}


template <class K, class V> 
bool operator!= (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) != 0;
}


template <class K, class V> 
bool operator!= (const Pair<K,V>& pair, const K& key)
{
  return key != pair;
}


template <class K, class V> 
bool operator<= (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) >= 0;
}


template <class K, class V> 
bool operator<= (const Pair<K,V>& pair, const K& key)
{
  return pair.compare(key) <= 0;
}


template <class K, class V> 
bool operator>= (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) <= 0;
}


template <class K, class V> 
bool operator>= (const Pair<K,V>& pair, const K& key)
{
  return pair.compare(key) >= 0;
}


template <class K, class V> 
bool operator< (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) > 0;
}


template <class K, class V> 
bool operator< (const Pair<K,V>& pair, const K& key)
{
  return pair.compare(key) < 0;
}


template <class K, class V> 
bool operator> (const K& key, const Pair<K,V>& pair)
{
  return pair.compare(key) < 0;
}


template <class K, class V> 
bool operator> (const Pair<K,V>& pair, const K& key)
{
  return pair.compare(key) > 0;
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


template <class K, class V>
void TreeNode<K,V>::setLeft(TreeNode<K,V>* left)
{
  this->left = left;
}


template <class K, class V>
void TreeNode<K,V>::setRight(TreeNode<K,V>* right)
{
  this->right = right;
}


template <class K, class V>
void TreeNode<K,V>::setParent(TreeNode<K,V>* parent)
{
  this->parent = parent;
}


template <class K, class V>
TreeNode<K,V>*& TreeNode<K,V>::getLeft()
{
  return left;
}


template <class K, class V>
TreeNode<K,V>*& TreeNode<K,V>::getRight()
{
  return right;
}


template <class K, class V>
TreeNode<K,V>*& TreeNode<K,V>::getParent()
{
  return parent;
}


template <class K, class V>
void TreeNode<K,V>::pair(const Pair<K,V>& pair)
{
  if (this->p != NULL)
    delete this->p;
  this->p = new Pair<K,V>(pair);
}


template <class K, class V>
void TreeNode<K,V>::pair(Pair<K,V>* pair)
{
  this->p = pair;
}


template <class K, class V>
Pair<K,V>*& TreeNode<K,V>::pair()
{
  return this->p;
}


template <class K, class V>
typename TreeNode<K,V>::Color TreeNode<K,V>::color() const
{
  return c;
}


template <class K, class V>
void TreeNode<K,V>::setColor(typename TreeNode<K,V>::Color color)
{
  c = color;
}



/** # TreeMap */
template <class K, class V>
TreeMap<K,V>::TreeMap()
  : root(NULL)
  , nilNode(new TreeNode<K,V>)
  , count(0)
{
  root = nilNode;
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


template <class K, class V>
int TreeMap<K,V>::size() const
{
  return count;
}


template <class K, class V>
int TreeMap<K,V>::rotateLeft(TreeNode<K,V>* parent)
{
  TreeNode<K,V> *child, *childLeftChild, *parentParent;
  TreeNode<K,V> *nil = this->nilNode;

  if (parent == NULL || parent->getRight() == nil)
    return -1;

  child = parent->getRight();
  childLeftChild = child->getLeft();
  parentParent = parent->getParent();

  if (parentParent->getLeft() == parent)
    parentParent->setLeft(child);
  else
    parentParent->setRight(parentParent);

  child->setParent(parentParent);
  child->setLeft(parent);
  child->getLeft()->setParent(child);
  parent->setRight(childLeftChild);
  parent->getRight()->setParent(parent);

  if (root == parent)
    root = child;

  return 0;
}


template <class K, class V>
int TreeMap<K,V>::rotateRight(TreeNode<K,V>* parent)
{
  TreeNode<K,V> *child, *childRightChild, *parentParent;
  TreeNode<K,V> *nil = this->nilNode;

  if (parent == NULL || parent == nil || parent->getLeft() == nil)
    return -1;

  child = parent->getLeft();
  childRightChild = child->getRight();
  parentParent = parent->getParent();

  if (parentParent->getLeft() == parent)
    parentParent->setLeft(child);
  else
    parentParent->setRight(child);

  child->setParent(parentParent);
  child->setRight(parent);
  child->getRight()->setParent(child);
  parent->setLeft(childRightChild);
  parent->getLeft()->setParent(parent);

  if (root == parent)
    root = child;

  return 0;
}


template <class K, class V>
void TreeMap<K,V>::set(const K& key, const V& value)
{
  TreeNode<K,V> *nil = this->nilNode;
  TreeNode<K,V> *root, *current, *newNode, *parent = nil;

  current = root = this->root;
  while (current != nil)
  {
    parent = current;
    if (key < current->getKey())
    {
      current = current->getLeft();
    }
    else if (key > current->getKey())
    {
      current = current->getRight();
    }
    else
    {
      current->value(value);
      return;
    }
  }

  newNode = new TreeNode<K,V>(key, value);
  newNode->setParent(parent);
  if (root == nil)
  {
    this->root = newNode;
  }
  else
  {
    if (newNode->getKey() < parent->getKey())
    {
      parent->setLeft(newNode);
    }
    else if (newNode->getKey() > parent->getKey())
    {
      parent->setRight(newNode);
    }
    else
    {
      delete newNode;
      return;
    }
  }
  ++count;

  newNode->setColor(TreeNode<K,V>::RED);
  newNode->setLeft(nil);
  newNode->setRight(nil);
  insertFix(newNode);
}


template <class K, class V>
int TreeMap<K,V>::insertFix(TreeNode<K,V>* child)
{
  TreeNode<K,V> *parent, *uncle;
  int status = 0;
  typename TreeNode<K,V>::Color RED = TreeNode<K,V>::RED;
  typename TreeNode<K,V>::Color BLACK = TreeNode<K,V>::BLACK;

  while (child->getParent()->getColor() == RED)
  {
    parent = child->getParent();
    if (parent == parent->getParent()->getLeft())
    {
      uncle = parent->getParent()->getRight();
      if (uncle->getColor() == RED)
      {
        uncle->setColor(BLACK);
        parent->setColor(BLACK);
        parent->getParent()->setColor(RED);
        child = parent->getParent();
      }
      else
      {
        if (child == parent->getRight())
        {
          child = parent;
          status = rotateLeft(child);
          parent = child->getParent();
        }
        parent->setColor(BLACK);
        parent->getParent()->setColor(RED);
        status = rotateRight(parent->getParent());
      }
    }
    else
    {
      uncle = parent->getParent()->getLeft();
      if (uncle->getColor() == RED)
      {
        uncle->setColor(BLACK);
        parent->setColor(BLACK);
        parent->getParent()->setColor(RED);
        child = parent->getParent();
      }
      else
      {
        if (child == parent->getLeft())
        {
          child = parent;
          status = rotateRight(child);
          parent = child->getParent();
        }
        parent->setColor(BLACK);
        parent->getParent()->setColor(RED);
        status = rotateLeft(parent->getParent());
      }
    }
  }
  this->root->setColor(BLACK);

  return status;
}


template <class K, class V>
void TreeMap<K,V>::remove(const K& key)
{
  TreeNode<K,V> *nil = this->nilNode;
  TreeNode<K,V> *target = nil, current, successor, successorChild;
  typename TreeNode<K,V>::Color RED = TreeNode<K,V>::RED;
  typename TreeNode<K,V>::Color BLACK = TreeNode<K,V>::BLACK;

  current = this->root;
  while (current != nil)
  {
    if (key < current->getKey())
    {
      current = current->getLeft();
    }
    else if (key > current->getKey())
    {
      current = current->getRight();
    }
    else
    {
      target = current;
      --this->count;
      break;
    }
  }

  if (target == nil)
    return;

  if (target->getLeft() == nil || target->getRight() == nil)
  {
    successor = target;
  }
  else
  {
    for (TreeNode<K,V> *s = target->getRight(); s != nil; s = s->getLeft())
    {
      successor = s;
    }
  }

  if (successor->getLeft() != nil)
    successorChild = successor->getLeft();
  else
    successorChild = successor->getRight();

  successorChild->setParent(successor->getParent());

  if (successor->getParent() == nil)
  {
    this->root = successorChild;
  }
  else
  {
    if (successor == successor->getParent()->getLeft())
      successor->getParent()->setLeft(successorChild);
    else
      successor->getParent()->setRight(successorChild);
  }

  if (target != successor)
  {
    target->setKey(successor->getKey());
    target->value(successor->value());
  }

  if (successor->getColor() == BLACK)
  {
    delete successor;
    removeFix(successorChild);
    return;
  }

  delete successor;
}


template <class K, class V>
int TreeMap<K,V>::removeFix(TreeNode<K,V>* node)
{
  TreeNode<K,V> *parent, *sibling;
  typename TreeNode<K,V>::Color RED = TreeNode<K,V>::RED;
  typename TreeNode<K,V>::Color BLACK = TreeNode<K,V>::BLACK;
  int status = 0;

  if (node == NULL)
    return -1;

  while (node != this->root && node->getColor() == RED)
  {
    parent = node->getParent();
    if (node == parent->getLeft())
    {
      sibling = parent->getRight();
      if (sibling->getColor() == RED)
      {
        sibling->setColor(BLACK);
        parent->setColor(RED);
        status = rotateLeft(parent);
        sibling = parent->getRight();
      }
      if (sibling->getLeft()->getColor() == BLACK &&
          sibling->getRight()->getColor() == BLACK)
      {
        sibling->setColor(RED);
        node = parent;
      }
      else
      {
        if (sibling->getRight()->getColor() == BLACK)
        {
          sibling->getLeft()->setColor(BLACK);
          sibling->setColor(RED);
          status = rotateRight(sibling);
          sibling = parent->getRight();
        }
        sibling->setColor(parent->getColor());
        parent->setColor(BLACK);
        sibling->getRight()->setColor(BLACK);
        status = rotateLeft(parent);
        node = this->root;
      }
    }
    else
    {
      sibling = parent->getLeft();
      if (sibling->getColor() == RED)
      {
        sibling->setColor(BLACK);
        parent->setColor(RED);
        status = rotateRight(parent);
        sibling = parent->getLeft();
      }
      if (sibling->getLeft()->getColor() == BLACK &&
          sibling->getRight()->getColor() == BLACK)
      {
        sibling->setColor(RED);
        node = parent;
      }
      else
      {
        if (sibling->getLeft()->getColor() == BLACK)
        {
          sibling->getRight()->setColor(BLACK);
          sibling->setColor(RED);
          status = rotateLeft(sibling);
          sibling = parent->getLeft();
        }
        sibling->setColor(parent->getColor());
        parent->setColor(BLACK);
        sibling->getLeft()->setColor(BLACK);
        status = rotateRight(parent);
        node = this->root;
      }
    }
  }
  node->setColor(BLACK);

  return status;
}


template <class K, class V>
void TreeMap<K,V>::get(const K& key, V* value)
{
  Pair<K,V>* target = NULL;
  TreeNode<K,V>* nil = this->nilNode;
  TreeNode<K,V>* current;

  if (!value)
    return;

  current = this->root;
  while (current != nil)
  {
    if (key < current->getKey())
    {
      current = current->getLeft();
    }
    else if (key > current->getKey())
    {
      current = current->getRight();
    }
    else
    {
      target = current->pair();
      *value = target->value();
      break;
    }
  }
}


template <class K, class V>
void TreeMap<K,V>::clear()
{
  freeTree(root);
}


template <class K, class V>
void TreeMap<K,V>::freeTree(TreeNode<K,V>*& root)
{
  // TODO: implement freeTree
}
