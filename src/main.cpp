#include"FractalCreator.h"

using namespace std;

using namespace caveOfProgramming;

int main()
{
    int const m_height = 600;

    FractalCreator fractalCreator(800,600);

    fractalCreator.addZoom(Zoom(295,m_height-202,0.1));
    fractalCreator.addZoom(Zoom(312,m_height-304,0.1));
    //fractalCreator.addZoom(Zoom(312,m_height-304,0.1));

    fractalCreator.calculateIterations();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("text.bmp");

    return 0;
}
