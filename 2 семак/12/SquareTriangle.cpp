struct Position
{
    double x;
    double y;
};

class SquareTriangle
{

    SquareTriangle()
    {
    }
    SquareTriangle(Position A, Position B, Position C)
    {
        setA(A);
        setB(B);
        setC(C);
    }

private:
    Position __A;
    Position __B;
    Position __C;
    void setA(Position A)
    {
        this->__A = A;
    }
    void setB(Position B)
    {
        this->__B = B;
    }
    void setC(Position C)
    {
        this->__C = C;
    }

public:
    Position getA()
    {
        return this->__A;
    }
    Position getB()
    {
        return this->__B;
    }
    Position getC()
    {
        return this->__C;
    }

    void scale(double s)
    {
    }
    void rotate()
    {
    }
    void miror()
    {
    }
};