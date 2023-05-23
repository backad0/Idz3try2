#include <cstddef>
#include "MyList.hpp"

MyList::MyList() : count(0)
{
    buffer = new Node;
    buffer->next = buffer;
    buffer->prev = buffer;
    buffer->data = -1;
}

MyList::MyList(const MyList& list) : buffer(new Node), count(list.count)
{
    buffer = new Node;
    const Node* tmp = list.buffer->next;
    Node* p = buffer;
    Node* n = NULL;
    while (tmp != list.buffer)
    {
        n = new Node;
        p->next = n;
        n->prev = p;
        n->data = tmp->data;
        p = p->next;
        tmp = tmp->next;
    }
    buffer->prev = p;
    p->next = buffer;
}
MyList::MyList(MyList&& obj) :buffer(obj.buffer), count(obj.count)
{
    obj.buffer = nullptr;
    obj.count = 0;
}

MyList::~MyList()
{
    if (!isEmpty())
    {
        makeEmpty();
    }
    delete buffer;
    buffer = nullptr;
}

MyList::Iterator::Iterator(const MyList& list) { buf = list.getBuffer(); count = list.getCount(); }

//начать работу
void MyList::Iterator::start()
{
    p = buf;
    index = -1;
}
//проверка, все ли проитерировано
bool MyList::Iterator::finish() const
{
    return index >= count - 1;
}
//сдвинуть итератор на следующий элемент
void MyList::Iterator::next()
{
    p = p->next;
    index++;
}

//получить очередной элемент
Node* MyList::Iterator::get()
{
    return p;
}

//вставить элемент в позицию, отмеченную итератором
void MyList::addI(MyAIterator* index, int v)
{
    Node* tmp = new Node;
    if (count == 0) {
        tmp->next = buffer;
        tmp->prev = buffer;
        tmp->data = v;
        buffer->next = tmp;
        buffer->prev = tmp;
        count++;
    }
    else
    {
        Node* k = index->get();
        k->next->prev = tmp;
        tmp->next = k->next;
        tmp->prev = k;
        tmp->data = v;
        k->next = tmp;
        count++;
    }
}

//удалить элемент, отмеченный итератором
void MyList::deleteI(MyAIterator* index)
{
    Node* p = index->get();
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
    count--;
}

Node* MyList::getBuffer() const
{
    return buffer;
}

//найти первое вхожжение элемента в список, результат - итератор на найденный элемент
MyAIterator* MyList::searchFirst(int n)  const
{

    MyAIterator* it = new Iterator(*this);
    it->start();
    for (int i = 0; i < count; i++)
    {
        if (it->get()->data == n)
            break;
        it->next();
    }
    return it;
}

//количество элементов в списке
int MyList::getCount() const
{
    return count;
}

//сделать список пустым
void MyList::makeEmpty()
{
    Node* tmp = buffer;
    Node* n = nullptr;
    while (tmp->next != buffer)
    {
        tmp = tmp->next;
        delete n;
        n = tmp;
        count--;
    }
    delete n;
}

//проверка на пустоту
bool MyList::isEmpty() const
{
    return count == 0;
}

//получить итератор на первый элемент списка
MyAIterator* MyList::first() const
{
    MyAIterator* it = new Iterator(*this);
    it->start();
    it->next();
    return it;
}

//итератор копирования
MyList& MyList::operator=(const MyList& obj)
{
    if (this != &obj)
    {
        buffer = new Node;
        const Node* tmp = obj.buffer->next;
        Node* p = buffer;
        Node* n;
        while (tmp != obj.buffer)
        {
            n = new Node;
            p->next = n;
            n->prev = p;
            n->data = tmp->data;
            p = p->next;
            tmp = tmp->next;
        }
        buffer->prev = p;
        p->next = buffer;
    }
    return *this;
}

//итератор перемещения
MyList MyList::operator=(MyList&& obj)
{
    if (this != &obj)
    {
        makeEmpty();
        buffer = obj.buffer;
        count = obj.count;
        obj.buffer = nullptr;
        obj.count = 0;
    }
    return *this;
}

