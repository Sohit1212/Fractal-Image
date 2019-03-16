#include"FractalCreator.h"

using namespace std;

using namespace fractalProgram;

int main()
{
    int const m_height = 600;

    FractalCreator fractalCreator(800,600);

    //fractalCreator.addZoom(Zoom(295,m_height-202,0.1));
    //fractalCreator.addZoom(Zoom(312,m_height-304,0.1));
    //fractalCreator.addZoom(Zoom(312,m_height-304,0.1));

    fractalCreator.calculateIterations();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");

    FractalCreator fractalCreator2(800,600);
    fractalCreator2.addZoom(Zoom(295,m_height-202,0.5));
    fractalCreator2.addZoom(Zoom(312,m_height-304,0.1));
    fractalCreator2.addZoom(Zoom(312,m_height-304,0.1));

    fractalCreator2.calculateIterations();
    fractalCreator2.calculateTotalIterations();
    fractalCreator2.drawFractal();
    fractalCreator2.writeBitmap("zoom.bmp");


    return 0;
}
