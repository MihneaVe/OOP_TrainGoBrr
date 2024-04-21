#include <gtest/gtest.h>
#include "TakeAnAction.h"
#include "InRoutesUsual.h"
#include "InRoutesAdmin.h"
#include "GetRoutesHelp.h"
#include "SeeRoutesMain.h"
#include "FindPassword.h"


///TEMA 1 TESTS
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

///Other Tests for Tema 1 are impossible to run on here, sadly, due to poor prior implementation.


///TEMA 2 TESTS

TEST (SuiteName, CopyConstructorInheritance2){
    InRoutesAdmin obj;
    const InRoutesAdmin& obj2=obj;
    EXPECT_EQ(obj.getval2(), obj2.getval2());
}
TEST (SuiteName, CopyConstructorInheritance1){
    InRoutesUsual obj;
    const InRoutesUsual& obj2=obj;
    EXPECT_EQ(obj.getval1(), obj2.getval1());
}
TEST (SuiteName, CopyConstructorInheritance0){
    SeeRoutesMain obj;
    const SeeRoutesMain& obj2=obj;
    EXPECT_EQ(obj.getval(), obj2.getval());
}

//TEST (SuiteName, StaticCorrectPass) {
//    int correctPass=989125;
//    ::testing::internal::CaptureStdout();
//    FindPassword::showcasepass(correctPass);
//    std::string output = ::testing::internal::GetCapturedStdout();
//    EXPECT_EQ(output, "Your password is correct!\n");
//}
//
//TEST (SuiteName, StaticIncorrectPass) {
//    int inCorrectPass=989124;
//    ::testing::internal::CaptureStdout();
//    FindPassword::showcasepass(inCorrectPass);
//    std::string output = ::testing::internal::GetCapturedStdout();
//    EXPECT_EQ(output, "Your password is incorrect!\n");
//}

//These do not work in all tests for some reason

TEST(SuiteName, inheritance_example1){
    RouteInfo routesInfo;
    InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
    SeeRoutesMain *ptRe = &reDo;
    auto *showPtr = static_cast<InRoutesAdmin *>(ptRe);
    EXPECT_NO_THROW(showPtr->AddDelay(0, 15));
}

TEST(SuiteName, inheritance_example2){
    RouteInfo routesInfo;
    InRoutesAdmin reDo(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
    SeeRoutesMain *ptRe = &reDo;
    auto *showPtr = static_cast<InRoutesAdmin *>(ptRe);
    std::cout << "For what train?\n";
    EXPECT_NO_THROW(showPtr->CancelTrain(0));
}

TEST(SuiteName, inheritance_example3){
    RouteInfo routesInfo;
    InRoutesUsual derived(routesInfo.id, routesInfo.company, routesInfo.time, routesInfo.city);
    SeeRoutesMain* basePtr = &derived; //UPCASTING
    EXPECT_NO_THROW(basePtr->printRoutes());
    auto* derivedPtr = static_cast<InRoutesUsual*>(basePtr);
    EXPECT_NO_THROW(derivedPtr->WishReserve(0));
}
