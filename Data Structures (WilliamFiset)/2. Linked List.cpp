template <class T>
class Node
{
public:
  T data;
  Node<T>* prev;
  Node<T>* next;
};

// Doubly Linked List
template <class T>
class LinkedList
{
private:
  int _size=0;
  Node<T>* head=NULL;
  Node<T>* tail=NULL;

public:
  void clear()
  {
    while(isEmpty()) pop_front();
  }

  int size()
  {
    return _size;
  }

  bool isEmpty()
  {
    return _size==0;
  }

  void push_back(T x)
  {
    Node<T>* newNode = new Node<T>({x,NULL,NULL});
    if(isEmpty()) head=newNode;
    else
    {
      newNode->prev=tail;
      tail->next=newNode;
    }
    tail=newNode;
    _size++;
  }

  void push_front(T x)
  {
    Node<T>* newNode = new Node<T>({x,NULL,NULL});
    if(isEmpty()) tail=newNode;
    else
    {
      newNode->next=head;
      head->prev=newNode;
    }
    head=newNode;
    _size++;
  }

  void pop_front()
  {
    assert(!isEmpty());
    _size--;
    Node<T>* temp = head;
    head=head->next;
    delete temp;
    if(isEmpty()) tail=NULL;
    else head->prev=NULL;
  }

  void pop_back()
  {
    assert(!isEmpty());
    _size--;
    Node<T>* temp = tail;
    tail=tail->prev;
    delete temp;
    if(isEmpty()) head=NULL;
    else tail->next=NULL;
  }

  T& front()
  {
    assert(!isEmpty());
    return head->data;
  }

  T& back()
  {
    assert(!isEmpty());
    return tail->data;
  }

  Node<T> *getNode(int pos)
  {
    assert(0<=pos && pos<_size);
    Node<T>* ans;
    if(pos==0) return head;
    if(pos==_size-1) return tail;

    if(pos<=_size-pos-1)
    {
      ans=head;
      fr(i,0,pos) ans=ans->next;
    }
    else
    {
      ans=tail;
      fr(i,0,_size-pos-1) ans=ans->prev;
    }
    return ans;
  }

  T& get(int pos)
  {
    return getNode(pos)->data;
  }

  void removeNode(Node<T>* rm)
  {
    if(rm==head) pop_front();
    else if(rm==tail) pop_back();
    else
    {
      Node<T>* p = rm->prev;
      Node<T>* n = rm->next;
      p->next=n;
      n->prev=p;
      --_size;
      delete rm;
    }
  }

  void remove(int pos)
  {
    removeNode(getNode(pos));
  }

  void insertAfter(Node<T>* p, T x)
  {
    if(p==tail) push_back(x);
    else
    {
      Node<T>* newNode = new Node<T>({x,NULL,NULL});
      Node<T>* n = p->next;
      newNode->next = n;
      newNode->prev = p;
      p->next = newNode;
      n->prev = newNode;
      _size++;
    }
  }

  void insertBefore(Node<T>* n, T x)
  {
    if(n==head) push_front(x);
    else
    {
      Node<T>* newNode = new Node<T>({x,NULL,NULL});
      Node<T>* p = n->prev;
      newNode->next = n;
      newNode->prev = p;
      p->next = newNode;
      n->prev = newNode;
      _size++;
    }
  }

  void insert(int pos, T x)
  {
      assert(0<=pos && pos<=_size);
      if(pos==0) push_front(x);
      else if(pos==_size) push_back(x);
      else insertAfter(getNode(pos),x);
  }

  void printList()
  {
    Node<T>* trav = head;
    while(trav!=NULL)
    {
      cnl(trav->data);
      trav=trav->next;
    }
  }



  class Iterator
  {
  public:
      using value_type = T;
      using pointer    = T*;
      using reference  = T&;
      using difference_type = std::ptrdiff_t;
      using iterator_category = std::bidirectional_iterator_tag;

      Iterator(): v(getNode(_size-1)), i(0) {}
      Iterator(Node<T>* v, int i): v(v), i(i) {}
      Iterator(LinkedList<T>* v, int i): v(v->getNode(i)), i(i) {}
      // Default Copy/Move Are Fine.
      // Default Destructor fine.

      reference       operator*()             {return v->data;}
      const reference operator*()       const {return v->data;}
      pointer         operator->()            {return &(v->data);}
      const pointer   operator->()      const {return &(v->data);}

      Iterator& operator++()       {++i; v=v->next; return *this;}
      Iterator& operator--()       {--i; v=v->prev; return *this;}
      Iterator  operator++(int)    {v=v->next; Iterator r(*this);++i;return r;}
      Iterator  operator--(int)    {v=v->prev; Iterator r(*this);--i;return r;}

      difference_type operator-(Iterator const& r) const {return i - r.i;}

      // Note: comparing iterator from different containers
      //       is undefined behavior so we don't need to check
      //       if they are the same container.
      bool operator<(Iterator const& r)  const {return i <  r.i;}
      bool operator<=(Iterator const& r) const {return i <= r.i;}
      bool operator>(Iterator const& r)  const {return i >  r.i;}
      bool operator>=(Iterator const& r) const {return i >= r.i;}
      bool operator!=(const Iterator &r) const {return i != r.i;}
      bool operator==(const Iterator &r) const {return i == r.i;}

  private:
      Node<T>* v;
      int      i;
  };

  Iterator begin()
  {
    Iterator it(this,0);
    return it;
  }

  Iterator end()
  {
    Iterator it(this,_size-1);
    it++;
    return it;
  }
};
