#ifndef RGB_H
#define RGB_H

namespace fractalProgram {

struct RGB
{
    public:
        double r;
        double g;
        double b;

        RGB(double,double,double);

    protected:

    private:
};

RGB operator-(const RGB &first, const RGB &second);
}
#endif // RGB_H
