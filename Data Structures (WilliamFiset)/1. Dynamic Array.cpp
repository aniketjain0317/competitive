template <class T>
class DynamicArray
{
private:
  const int INITIAL_CAPACITY = 16;
  const int GROWTH_FACTOR = 2;


public:
  T* array;
  int capacity;
  int size;

  DynamicArray()
  {
    capacity=INITIAL_CAPACITY;
    array = new T[capacity];
    size=0;
  }

  DynamicArray(int sz)
  {
    int bits = (int)log2(sz)+1;
    capacity=1<<bits;
    array = new T[capacity];
    size=sz;
  }

  DynamicArray(int sz, T x)
  {
    int bits = (int)log2(sz)+1;
    capacity=1<<bits;
    array = new T[capacity];
    size=sz;
    fr(i,0,sz) array[i]=x;
  }

  ~DynamicArray()
  {
    delete[] array;
  }

  T& get(int pos)
  {
    assert(0 <= pos && pos < size);
    return array[pos];
  }

  void resize()
  {
    assert(size==capacity);
    capacity *= GROWTH_FACTOR;
    T* temp = new T[capacity];
    // fr(i,0,size) temp[i]=array[i];
    copy(array,array+size,temp);
    delete[] array;
    array = temp;
  }

  void insert(int pos, T x)
  {
    assert(0 <= pos && pos <= size);
    if(size==capacity) resize();
    frr(i,pos,size) swap(x,array[i]);
    size++;
  }

  void append(T x)
  {
    insert(size, x);
  }

  void remove(int pos)
  {
    assert(0 <= size && pos < size);
    size--;
    frr(i,pos,size) array[i]=array[i+1];
  }

  int length()
  {
    return size;
  }
};
