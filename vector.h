class Vectori_de_vectori;

class Vector
{
private:
    int *V;
    int nr;
public:
    friend class Vectori_de_vectori;
    Vector(int x, int n): nr(n)
    {
        V = new int(n+1);
        for(int i=1; i<=n; i++)
            V[i]=x;
    }
    Vector(): nr(0)
    {

    }
    Vector(Vector &ob): nr(ob.nr)
    {
        V = new int(ob.nr + 1);
        for(int i=1; i<=ob.nr; i++)
            V[i] = ob.V[i];
    }
    ~Vector()
    {
        delete[] V;
        nr=0;
    }
    void Reinitializare(int x, int n)
    {
        nr = n;
        delete[] V;
        V=new int[nr+1];
        for(int i=1; i<=n; i++)
            V[i] = x;
    }
    int Return_Suma()
    {
        int suma = 0;
        for(int i=1; i<=nr; i++)
            suma += V[i];
        return suma;
    }
    void Return_Maxim(int &maxim, int &poz)
    {
        for (int i=1; i<=nr; i++)
            if(V[i] > maxim)
            {
                maxim=V[i];
                poz=i;
            }
    }
    void Sortare()
    {
        for(int i=1; i<nr; i++)
            for(int j=i+1; j<=nr; j++)
                if(V[i] > V[j])
                    std::swap(V[i],V[j]);
    }


    friend std::istream& operator>>(std::istream &is, const Vector &ob);
    friend int operator*(const Vector &v1, const Vector &v2);
    Vector& operator= (const Vector &ob);
    friend std::ostream& operator<<(std::ostream &os, const Vector &ob);
};


std::istream& operator>>(std::istream &is, const Vector &ob)
{
    int n = ob.nr;
    std::cout << std::endl;
    for(int i=1; i<=n; i++)
    {
        std::cout << "V[" << i << "]= ";
        is >> ob.V[i];
    }
    return is;
}


std::ostream& operator<<(std::ostream &os, const Vector &ob)
{
    int n = ob.nr;
    os << std::endl << "(";
    for(int i=1; i<=n; i++)
    {
        os << ob.V[i] << ", ";
    }
    os << ")" << std::endl;
    return os;
}


Vector& Vector::operator= (const Vector &ob)
{
    if(this==&ob)
        return *this;

    nr=ob.nr;
    delete[] V;
    V=new int[nr+1];
    for(int i=1; i<=nr; i++)
        V[i] = ob.V[i];
}

int operator*(const Vector &v1, const Vector &v2)
{
    int produs = 0;
    if (v1.nr != v2.nr)
        return 0;
    int n = v2.nr;
    for(int i=1; i<=n; i++)
        produs *= v1.V[i] * v2.V[i];
    return produs;
}





