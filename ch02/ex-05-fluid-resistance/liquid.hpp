#pragma once

class Liquid
{
public:
    Liquid(double x_, double y_, double w_, double h_, double c_):
        x(x_),
        y(y_),
        w(w_),
        h(h_),
        c(c_)
    {}

    double x;
    double y;
    double w;
    double h;
    double c;
};
