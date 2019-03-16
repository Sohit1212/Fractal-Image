#ifndef ZOOM_H
#define ZOOM_H

namespace fractalProgram {

class Zoom
{
    public:
        int x{0};
        int y{0};
        double scale{0.0};

        Zoom(int x,int y,double scale);

};

}
#endif // ZOOM_H
