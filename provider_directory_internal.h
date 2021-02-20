#ifndef _PROVIDER_DIRECTORY_INTERNAL_H
#define _PROVIDER_DIRECTORY_INTERNAL_H

/* Pair: Forward declaration for template friend functions */
template <class K, class V> class Pair;
template <class K, class V> bool operator== (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator== (const Pair<K,V>& c, const K& key);
template <class K, class V> bool operator!= (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator!= (const Pair<K,V>& c, const K& key);
template <class K, class V> bool operator<= (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator<= (const Pair<K,V>& c, const K& key);
template <class K, class V> bool operator>= (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator>= (const Pair<K,V>& c, const K& key);
template <class K, class V> bool operator< (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator< (const Pair<K,V>& c, const K& key);
template <class K, class V> bool operator> (const K& key, const Pair<K,V>& c);
template <class K, class V> bool operator> (const Pair<K,V>& c, const K& key);


/** This class represents a comparable key-value pair
 *  Essential for mapping
 *
 *  Key must be comparable via relational operators
 *  */
template <class K, class V>
class Pair
{
  private:
    K key;
    V* data;

  public:
    Pair();
    Pair(const Pair<K,V>&);
    Pair(const K& key, const V& value);
    virtual ~Pair();

    int compare(const K& key) const;
    void setKey(const K& key);
    const K& getKey() const;
    const V& value() const;
    V& value();
    void value(const V& data);

    friend bool operator== <>(const K& key, const Pair<K,V>& c);
    friend bool operator== <>(const Pair<K,V>& c, const K& key);
    friend bool operator!= <>(const K& key, const Pair<K,V>& c);
    friend bool operator!= <>(const Pair<K,V>& c, const K& key);
    friend bool operator<= <>(const K& key, const Pair<K,V>& c);
    friend bool operator<= <>(const Pair<K,V>& c, const K& key);
    friend bool operator>= <>(const K& key, const Pair<K,V>& c);
    friend bool operator>= <>(const Pair<K,V>& c, const K& key);
    friend bool operator< <>(const K& key, const Pair<K,V>& c);
    friend bool operator< <>(const Pair<K,V>& c, const K& key);
    friend bool operator> <>(const K& key, const Pair<K,V>& c);
    friend bool operator> <>(const Pair<K,V>& c, const K& key);
};


/** TreeNode describes a tree's internal node
 * */
template <class K, class V>
class TreeNode
{
  public:
    enum Color
    {
      BLACK = 0,
      RED   = 1,
    };

  private:
    Color c;
    Pair<K,V>* p;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

  public:
    TreeNode();
    TreeNode(const TreeNode&);
    TreeNode(const K& key, const V& value);
    ~TreeNode();

    void setLeft(TreeNode<K,V>* left);
    void setRight(TreeNode<K,V>* right);
    void setParent(TreeNode<K,V>* parent);
    TreeNode<K,V>* getLeft();
    TreeNode<K,V>* getRight();
    TreeNode<K,V>* getParent();
    void setKey(const K& key);
    const K& getKey() const;
    const V& value() const;
    void value(const V& data);
    V& value();
    Color color() const;
    void setColor(Color color);
};


/** TreeMap provides fast lookup by sorting the keys in ascending order 
 *  Implements red-black tree
 *  */
template <class K, class V>
class TreeMap
{
  private:
    TreeNode<K,V>* root;
    TreeNode<K,V>* nilNode;
    int count;

    void copyTree(TreeNode<K,V>* dest, TreeNode<K,V>* src, TreeNode<K,V>* nil);
    void freeTree(TreeNode<K,V>*);
    int rotateLeft(TreeNode<K,V>* parent);
    int rotateRight(TreeNode<K,V>* parent);
    int insertFix(TreeNode<K,V>* node);
    int removeFix(TreeNode<K,V>* node);

  public:
    TreeMap();
    TreeMap(const TreeMap&);
    ~TreeMap();

    int size() const;
    void remove(const K& key);
    void set(const K& key, const V& value);
    int get(const K& key, V* value);
    void clear();
};

template class TreeMap<int, int>;

#endif
