#include "MyList.cpp"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"

using namespace std;

TEST(MyList, MyListTest){
    MyList list;
    MyAIterator* it =  new MyList::Iterator(list);
    it->start();
    list.addI(it, 1);
    list.addI(it, 2);
    list.addI(it, 3);
    list.addI(it, 4);
    list.addI(it, 5);
    list.addI(it, 6);
    it->start();
    it->next();
    EXPECT_EQ(6,it->get()->data);
    it->next();
    EXPECT_EQ(5,it->get()->data);
    it->next();
    EXPECT_EQ(4,it->get()->data);
    it->next();
    EXPECT_EQ(3,it->get()->data);
    it->next();
    EXPECT_EQ(2,it->get()->data);
    it->next();
    EXPECT_EQ(1,it->get()->data);

    list.makeEmpty();
    EXPECT_TRUE(list.isEmpty());
    it->start();
    cout << it->get()->data;
}

TEST(MyList, MyListTest1){
    MyList list;
    MyAIterator* it = new MyList::Iterator(list);
    it->start();
    list.addI(it, 6);
    it->next();
    list.addI(it, 4);
    it->next();
    list.addI(it, 3);
    it->start();
    it->next();
    EXPECT_EQ(6,it->get()->data);
    it->next();
    EXPECT_EQ(4,it->get()->data);
    it->next();
    EXPECT_EQ(3,it->get()->data);
    it->next();
    EXPECT_EQ(4,list.searchFirst(4)->get()->data);
    EXPECT_EQ(6,list.first()->get()->data);

    it->start();
    it->next();
    list.deleteI(it);
    it->start();
    it->next();
    EXPECT_EQ(4,it->get()->data);
    it->next();
    EXPECT_EQ(3,it->get()->data);
    //check first
    EXPECT_EQ(4,list.first()->get()->data);
    it = new MyList::Iterator(list);
    it->start();
    while(!it->finish()){
        it->next();
        cout << it->get()->data<<endl;
    }

    MyList l1 = list;
    MyList l2(move(list));

    MyAIterator* i = new MyList::Iterator(l1);
    i->start();

    cout << "List l1" << endl;
    while (!i->finish()){
        i->next();
        cout << i->get()->data << endl;
    }
    MyAIterator* iter = new MyList::Iterator(l2);
    iter->start();
    cout << "List l2" << endl;
    while (!iter->finish()){
        iter->next();
        cout << iter->get()->data << endl;
    }

    MyAIterator* it1 = new MyList::Iterator(list);
    it1->start();
    while (!it1->finish()){
        it1->next();
        cout << it1->get()->data << endl;
    }

}