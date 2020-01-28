#include "pch.h"
#include "../Design/0707_DesignLinkedList.h"

class MyLinkedListTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        myLinkedList_ = new MyLinkedList();
        myLinkedList_->addAtHead(7);
        myLinkedList_->addAtHead(2);
        myLinkedList_->addAtHead(1);
        //myLinkedList_->addAtTail(3);
    }

    virtual void TearDown()
    {
        delete myLinkedList_;
    }

protected:
    MyLinkedList* myLinkedList_;
};

TEST_F(MyLinkedListTest, checkAddAtHead)
{
    myLinkedList_->addAtHead(0);
    EXPECT_EQ(myLinkedList_->get(0), 0);
}

TEST_F(MyLinkedListTest, checkAddAtTail)
{
    myLinkedList_->addAtTail(4);
    EXPECT_EQ(myLinkedList_->get(3), 4);
}

TEST_F(MyLinkedListTest, checkAddAtIndex)
{
    myLinkedList_->addAtIndex(1, 2);
    EXPECT_EQ(myLinkedList_->get(1), 2);
}

TEST_F(MyLinkedListTest, checkDeleteAtIndex)
{
    myLinkedList_->addAtIndex(3, 0);
    myLinkedList_->deleteAtIndex(3);
    EXPECT_EQ(myLinkedList_->get(3), -1);
}