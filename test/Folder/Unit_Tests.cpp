#include <gtest/gtest.h>
#include "TakeAnAction.h"


TEST(SuiteName, Initial) {
    EXPECT_EQ(1, 1);
    //Tester initial
}

TEST(SuiteName, Initialization_And_Overloaded_Contructors){
    CreateTickets obj;
    CreateTickets obj2(1);
    EXPECT_EQ(obj.getval(), obj2.getval());
}

TEST(SuiteName, CopyConstructor){
    CreateTickets obj;
    CreateTickets obj2=obj;
    EXPECT_EQ(obj.getval(), obj2.getval());
}

///Other Tests are impossible to run on here, sadly.

//     Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean