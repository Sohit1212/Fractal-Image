#include <iostream>

#include"FractalCreator.h"

using namespace std;

using namespace fractalProgram;

int main()
{
    FractalCreator fractalCreator(800,600);

    fractalCreator.addRange(0.0,RGB(0,0,0));
    fractalCreator.addRange(0.2,RGB(0,250,250));
    fractalCreator.addRange(0.8,RGB(0,0,250));
    fractalCreator.addRange(1.0,RGB(0,0,255));

    fractalCreator.addZoom(Zoom(400,300,0.09));
    //fractalCreator.addZoom(Zoom(312,100,0.1));
    fractalCreator.run("test1.bmp");
    return 0;
}
