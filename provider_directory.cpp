// ProviderDirectory Implementation
// Original author: Billy Zou

#include <fstream>
#include <cstring>
#include <stdexcept>
#include "provider_directory.h"
#include "provider_directory_internal.h"


/** Callback functions */
void freeService(Service*& s);
void writeServiceEntry(Service*& s, void* outStream);

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
  this->value(value);
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
  : c(another.c)
  , p(NULL)
  , left(NULL)
  , right(NULL)
  , parent(NULL)
{
  if (another.p != NULL)
    value(another.p->value());
}


template <class K, class V>
TreeNode<K,V>::TreeNode(const K& key, const V& value)
  : c(TreeNode::BLACK)
  , p(NULL)
  , left(NULL)
  , right(NULL)
  , parent(NULL)
{
  p = new Pair<K,V>(key, value);
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
TreeNode<K,V>* TreeNode<K,V>::getLeft()
{
  return left;
}


template <class K, class V>
TreeNode<K,V>* TreeNode<K,V>::getRight()
{
  return right;
}


template <class K, class V>
TreeNode<K,V>* TreeNode<K,V>::getParent()
{
  return parent;
}


/**
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
// */


template <class K, class V>
void TreeNode<K,V>::setKey(const K& key)
{
  this->p->setKey(key);
}


template <class K, class V>
const K& TreeNode<K,V>::getKey() const
{
  return this->p->getKey();
}


template <class K, class V>
V& TreeNode<K,V>::value()
{
  return this->p->value();
}


template <class K, class V>
const V& TreeNode<K,V>::value() const
{
  return this->p->value();
}


template <class K, class V>
void TreeNode<K,V>::value(const V& data)
{
  this->p->value(data);
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
  copyTree(root, another.root, another.nilNode);
}


template <class K, class V>
TreeMap<K,V>::~TreeMap()
{
  freeTree(root);
  if (nilNode != NULL)
    delete nilNode;
  nilNode = NULL;
}


template <class K, class V>
void TreeMap<K,V>::copyTree(TreeNode<K,V>* dest, TreeNode<K,V>* src, TreeNode<K,V>* nil)
{
  TreeNode<K,V> *newNode, *newLeftNode, *newRightNode;

  if (!src)
    return;

  if (dest == NULL)
  {
    if (src == nil)
    {
      newNode = this->nilNode;
    }
    else
    {
      newNode = new TreeNode<K,V>(*src);
      newNode->setLeft(this->nilNode);
      newNode->setRight(this->nilNode);
      newNode->setParent(this->nilNode);
      ++count;
    }
    root = newNode;
  }

  if (src->getLeft() != nil)
  {
    newLeftNode = new TreeNode<K,V>(*src->getLeft());
    newLeftNode->setLeft(this->nilNode);
    newLeftNode->setRight(this->nilNode);
    newLeftNode->setParent(dest);
  }
  else
    newLeftNode = this->nilNode;

  dest->setLeft(newLeftNode);
  ++count;

  if (src->getRight() != nil)
  {
    newRightNode = new TreeNode<K,V>(*src->getRight());
    newRightNode->setLeft(this->nilNode);
    newRightNode->setRight(this->nilNode);
    newRightNode->setParent(dest);
  }
  else
    newRightNode = this->nilNode;

  dest->setRight(newRightNode);
  ++count;

  copyTree(newLeftNode, src->getLeft(), nil);
  copyTree(newRightNode, src->getRight(), nil);
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
    parentParent->setRight(child);

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
int TreeMap<K,V>::set(const K& key, const V& value, V* oldValue)
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
      if (oldValue != NULL)
        *oldValue = current->value();
      current->value(value);
      return 1;
    }
  }

  newNode = new TreeNode<K,V>(key, value);
  newNode->setParent(parent);
  newNode->setLeft(nil);
  newNode->setRight(nil);
  newNode->setColor(TreeNode<K,V>::RED);

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
      return 1;
    }
  }
  ++count;

  insertFix(newNode);
  return 0;
}


template <class K, class V>
int TreeMap<K,V>::insertFix(TreeNode<K,V>* child)
{
  TreeNode<K,V> *parent, *uncle;
  int status = 0;
  typename TreeNode<K,V>::Color RED = TreeNode<K,V>::RED;
  typename TreeNode<K,V>::Color BLACK = TreeNode<K,V>::BLACK;

  while (child->getParent()->color() == RED)
  {
    parent = child->getParent();
    if (parent == parent->getParent()->getLeft())
    {
      uncle = parent->getParent()->getRight();
      if (uncle->color() == RED)
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
      if (uncle->color() == RED)
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
  TreeNode<K,V> *target = nil, *current, *successor, *successorChild;
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

  if (successor->color() == BLACK)
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

  while (node != this->root && node->color() == RED)
  {
    parent = node->getParent();
    if (node == parent->getLeft())
    {
      sibling = parent->getRight();
      if (sibling->color() == RED)
      {
        sibling->setColor(BLACK);
        parent->setColor(RED);
        status = rotateLeft(parent);
        sibling = parent->getRight();
      }
      if (sibling->getLeft()->color() == BLACK &&
          sibling->getRight()->color() == BLACK)
      {
        sibling->setColor(RED);
        node = parent;
      }
      else
      {
        if (sibling->getRight()->color() == BLACK)
        {
          sibling->getLeft()->setColor(BLACK);
          sibling->setColor(RED);
          status = rotateRight(sibling);
          sibling = parent->getRight();
        }
        sibling->setColor(parent->color());
        parent->setColor(BLACK);
        sibling->getRight()->setColor(BLACK);
        status = rotateLeft(parent);
        node = this->root;
      }
    }
    else
    {
      sibling = parent->getLeft();
      if (sibling->color() == RED)
      {
        sibling->setColor(BLACK);
        parent->setColor(RED);
        status = rotateRight(parent);
        sibling = parent->getLeft();
      }
      if (sibling->getLeft()->color() == BLACK &&
          sibling->getRight()->color() == BLACK)
      {
        sibling->setColor(RED);
        node = parent;
      }
      else
      {
        if (sibling->getLeft()->color() == BLACK)
        {
          sibling->getRight()->setColor(BLACK);
          sibling->setColor(RED);
          status = rotateLeft(sibling);
          sibling = parent->getLeft();
        }
        sibling->setColor(parent->color());
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
int TreeMap<K,V>::get(const K& key, V* value) const
{
  TreeNode<K,V>* nil = this->nilNode;
  TreeNode<K,V>* current;

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
      if (value)
        *value = current->value();
      return 0;
    }
  }

  return -1;
}


template <class K, class V>
void TreeMap<K,V>::traverse(void (*callback)(V& value)) const
{
  traverse(root, callback);
}


template <class K, class V>
void TreeMap<K,V>::traverse(TreeNode<K,V>* node, void (*callback)(V& value)) const
{
  TreeNode<K,V>* nil = this->nilNode;
  if (node != NULL && node != nil)
  {
    traverse(node->getLeft(), callback);
    callback(node->value());
    traverse(node->getRight(), callback);
  }
}


template <class K, class V>
void TreeMap<K,V>::traverse(void (*callback)(V& value, void* any), void* any) const
{
  traverse(root, callback, any);
}


template <class K, class V>
void TreeMap<K,V>::traverse(TreeNode<K,V>* node, void (*callback)(V& value, void* any), void* any) const
{
  TreeNode<K,V>* nil = this->nilNode;
  if (node != NULL && node != nil)
  {
    traverse(node->getLeft(), callback, any);
    callback(node->value(), any);
    traverse(node->getRight(), callback, any);
  }
}


template <class K, class V>
void TreeMap<K,V>::clear()
{
  freeTree(root);
}


template <class K, class V>
void TreeMap<K,V>::freeTree(TreeNode<K,V>* node)
{
  TreeNode<K,V>* nil = this->nilNode;
  if (node == nil)
    return;

  freeTree(node->getLeft());
  freeTree(node->getRight());
  delete node;
  --count;
}


/** # Service */
Service::Service()
  : code(0)
  , fees(0.0)
  , name()
  , description()
{
}


Service::Service(int code, double fees, const std::string& name, const std::string& desc)
  : code(code)
  , fees(fees)
  , name(name)
  , description(desc)
{
}


Service::Service(const Service& another)
  : code(another.code)
  , fees(another.fees)
  , name(another.name)
  , description(another.description)
{
}


Service::~Service()
{
  code = 0;
  fees = 0.0;
}


int Service::getCode() const
{
  return code;
}


double Service::getFees() const
{
  return fees;
}


const std::string& Service::getName() const
{
  return name;
}


const std::string& Service::getDescription() const
{
  return description;
}


void Service::setCode(int code)
{
  this->code = code;
}


void Service::setFees(double fees)
{
  this->fees = fees;
}


void Service::setName(const std::string& name)
{
  this->name = name;
}


void Service::setDescription(const std::string& desc)
{
  this->description = desc;
}


void freeService(Service*& s)
{
  delete s;
  s = NULL;
}



/** # ProviderDirectory */
ProviderDirectory::ProviderDirectory()
  : serviceByCode()
{
}


ProviderDirectory::ProviderDirectory(const ProviderDirectory& another)
  : serviceByCode(another.serviceByCode)
{
}


ProviderDirectory::~ProviderDirectory()
{
  serviceByCode.traverse(freeService);
}


bool ProviderDirectory::load(std::istream& inFile)
{
  Service* s = NULL;
  Service* old = NULL;
  int status = 0;


  while (!inFile.eof())
  {
    s = new Service;
    status = readEntry(inFile, s);

    if (0 != status)
    {
      delete s;
      return false;
    }

    status = serviceByCode.set(s->getCode(), s, &old);
    if (1 == status)
    {
      delete old;
    }
  }

  return true;
}


bool ProviderDirectory::loadFromFile(const std::string& filename)
{
  std::ifstream inFile;

  inFile.open(filename.c_str());
  if (!inFile.is_open())
    return false;

  return load(inFile);
}


int ProviderDirectory::readEntry(std::istream& inFile, Service *s)
{
  if (s == NULL)
    return -1;

  const char* const fields[] = 
    { "ServiceCode"
    , "ServiceName"
    , "Fees"
    , "Description"
    };
  int status = 0;
  char buffer[1024];
  char delimiter = ':';
  char entryDelimiter[] = "----";
  char whiteSpace = ':';


  for (int i = 0; i < int(sizeof(fields)/sizeof(fields[0])); ++i)
  {
    inFile.getline(buffer, sizeof(buffer), delimiter);

    // I/O error
    if (!inFile.good())
      return -1;

    // Invalid format
    if (0 != strcmp(buffer, fields[i]))
      return -1;

    whiteSpace = ':';
    while (whiteSpace == ' ' || whiteSpace == '\t')
    {
        inFile.get();
        whiteSpace = inFile.peek();
    }

    inFile.getline(buffer, sizeof(buffer));

    // I/O error
    if (!inFile.good())
      return -1;

    switch (i)
    {
    case 0: // ServiceCode
      try
      {
        s->setCode(std::stoi(buffer));
      }
      catch (std::invalid_argument& err)
      {
        return -1;
      }
      catch (std::out_of_range& err)
      {
        return -1;
      }
      break;
    case 1: // ServiceName
      s->setName(buffer);
      break;
    case 2: // Fees
      try
      {
        s->setFees(std::stod(buffer));
      }
      catch (std::invalid_argument& err)
      {
        return -1;
      }
      catch (std::out_of_range& err)
      {
        return -1;
      }
      break;
    case 3: // Description
      s->setDescription(buffer);
      break;
    default:
      return -1;
    }
  }

  inFile.getline(buffer, sizeof(buffer));

  // Invalid format
  if (0 != strcmp(buffer, entryDelimiter))
    return -1;

  inFile.peek();

  return status;
}


bool ProviderDirectory::sendTo(const std::string& email) const
{
  std::ofstream outS(email.c_str(), std::ofstream::out);
  if (!outS.is_open())
  {
    // Failed to open file
    return false;
  }

  return sendTo(outS);
}


bool ProviderDirectory::sendTo(std::ostream& outStream) const
{
  serviceByCode.traverse(writeServiceEntry, (void*)&outStream);
  return true;
}


void writeServiceEntry(Service*& s, void* outStream)
{
  std::ostream& outS = *(std::ostream*) outStream;
  outS << "Service Code: " << s->getName() << '\n'
       << "Service Name: " << s->getCode() << '\n'
       << "Service Fees: " << s->getFees() << '\n'
       << "Service Description: " << s->getDescription() << '\n'
       << '\n';
  outS.flush();
}


bool ProviderDirectory::validateServiceCode(int serviceCode) const
{
  bool found = false;
  Service* s = NULL;
  int ok = 0;

  ok = serviceByCode.get(serviceCode, &s);
  if (0 == ok)
    found = true;

  return found;
}


int ProviderDirectory::size() const
{
  return serviceByCode.size();
}
