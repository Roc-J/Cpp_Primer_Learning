class Nodefault 
{
public:
    Nodefault(int i) {}
};

class C
{
public:
    C():ndf(0) {}
private:
    Nodefault ndf;
};