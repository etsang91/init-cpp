#include <iostream>

#include "projectlib/project.h"

using namespace std;

int f(int a){
    cout << "f" << a << endl;
    return a;
}

int g(int a){
    cout << "g" << a << endl;
    return a;
}

function<int(int)> compose(function<int(int)> af, function<int(int)> ag){
    auto fg = [af,ag](auto a){
        return af(ag(a));
    };
    return fg;
}



int main(void) {
  std::cout << project::api() << std::endl;
  auto newfunc = compose(f,g);
  newfunc(3);
  return 0;
}
