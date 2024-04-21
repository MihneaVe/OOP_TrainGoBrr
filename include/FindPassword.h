//
// Created by Mihnea on 4/21/2024.
//

#ifndef OOP_FINDPASSWORD_H
#define OOP_FINDPASSWORD_H
#include <TakeAnAction.h>

class FindPassword : public TakeAnAction_MainMenu {
public:
    static void showcasepass(int verifypass) {
        if(verifypass==pass){
            std::cout<<"Your password is correct!\n";
        }else{
            std::cout<<"Your password is incorrect!\n";
        }
    }
};

//NOTE:
//THIS WILL BE WHERE ALL PASSWORD RELATED INFORMATION WILL BE REDIRECTED FOR FUTURE IMPLEMENTATIONS. NOW IT JUST VERIFIES PASSWORD BEFORE STARTING UP.
#endif //OOP_FINDPASSWORD_H
