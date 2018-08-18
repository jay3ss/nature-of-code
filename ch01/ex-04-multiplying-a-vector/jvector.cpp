#ifndef JVECTOR_EX_1_03_H
#define JVECTOR_EX_1_03_H


class JVector{
public:
    double x;
    double y;

    JVector(double x_, double y_):
        x(x_),
        y(y_)
        {}

    void add(JVector);
    void sub(JVector);
};

void JVector::add(JVector v)
{
    x += v.x;
    y += v.y;
}

void JVector::sub(JVector v)
{
    x -= v.x;
    y -= v.y;
}

#endif // JVECTOR_EX_1_03_H
