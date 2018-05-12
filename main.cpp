#include "graphics.hpp"
#include "Widget.h"
#include "SimpleText.h"
#include "InputField.h"
#include "CheckBox.h"
#include "Spinner.h"
#include "ListBox.h"
#include "Tank.h"
#include "Projectile.h"
#include "GameMaster.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using namespace genv;







int main()
{


    GameMaster * g = new GameMaster();
    g->run();
    delete g;
    return 0;
}
