
struct Node{
    Node* prev;
    Node* next;
    int data;
};

class MyAIterator {
public:
    virtual void start() = 0;
    virtual Node* get() = 0;
    virtual void next() = 0;
    virtual bool finish() const = 0;
};


class MyAList {
private:
    int count;
    Node* buffer;
public:
    virtual Node* getBuffer() const = 0;
    virtual void addI(MyAIterator* index, int v) = 0;
    virtual void deleteI(MyAIterator* index) = 0;
    virtual MyAIterator* searchFirst(int n) const = 0;
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() const = 0;
    virtual int getCount() const = 0;
    virtual const MyAIterator* first() const = 0;
};
