
#include <memory>
#include <iostream>
#include <vector>

struct Widget{
    Widget() { std::cout << "Widget(" << this << ")" << std::endl; }
    ~Widget() { std::cout << "~Widget(" << this << ")" << std::endl; }
};

void makeLogentry(Widget *pw) {std::cout << "Log entry for " << pw << "." << std::endl;}

auto loggingDel = [](Widget *pw)       
                  {                     
                    makeLogentry(pw);
                    delete pw;
                  };

int main(){

    // customer deleter type is not in shared_prt
    std::shared_ptr<Widget> spw (new Widget, loggingDel);
    std::unique_ptr<Widget, decltype(loggingDel)> upw (new Widget, loggingDel);

    std::cout << "###########" << std::endl;

    // flexibility
    auto customDel1 = [](Widget *pw){
        makeLogentry(pw);
        delete pw;
    };

    auto customDel2 = [](Widget *pw){
        makeLogentry(pw);
        delete pw;
    };

    std::shared_ptr<Widget> pw1 (new Widget, customDel1);
    std::shared_ptr<Widget> pw2 (new Widget, customDel2);

    std::vector<std::shared_ptr<Widget>> pws{pw1, pw2};

    std::cout << "##################" << std::endl;

    // construction error
    std::shared_ptr<Widget> spw1 (new Widget, loggingDel);
    std::shared_ptr<Widget> spw2 {spw1};
    std::cout << "##################" << std::endl;

    std::cout << "before exit" << std::endl;
}
