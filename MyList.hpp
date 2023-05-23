#include "MyAList.hpp"

class MyList : public MyAList {
private:
    int count;
    Node* buffer;

public:
    class Iterator : public MyAIterator
    {
    private:
        int index;
        int count;
        Node* buf;
        Node* p;
    public:
        Iterator(const MyList& list);
        void start()  override;
        bool finish() const override;
        void next() override;
        Node* get() override;
    };

    MyList();
    MyList(const MyList& list);
    MyList(MyList&& obj);
    ~MyList();

    void addI(MyAIterator* const index, int v) override;
    void deleteI(MyAIterator* const index) override;
    Node* getBuffer() const override;
    MyAIterator* searchFirst(int n) const override;
    int getCount() const override;
    void makeEmpty() override;
    bool isEmpty() const override;
    MyAIterator* first() const override;
    MyList& operator=(const MyList& obj);
    MyList operator =(MyList&& obj);

    MyList(MyList (*param)(void));
};
