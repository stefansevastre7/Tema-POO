class Vectori_de_vectori
{
private:
    int dim;
    Vector *vV;
public:

    Vectori_de_vectori(int x, int d): dim(d)
    {
        vV=new Vector[dim+1];
        for(int i=1; i<=dim; i++)
            for(int j=1; j<=vV[i].nr; j++)
                vV[i].V[j]=x;
    }
    Vectori_de_vectori(): dim(0)
    {

    }
    Vectori_de_vectori(const Vectori_de_vectori &ob)
    {
        dim = ob.dim;
        delete[] vV;
        vV=new Vector[dim+1];
        for(int i=1; i<=dim; i++)
            vV[i] = ob.vV[i];
    }
    ~Vectori_de_vectori()
    {
        delete[] vV;
        dim = 0;
    }
    int get_max_dim()
    {
        int max_dim = 0;
        for(int i=1; i<=dim; i++)
            if(vV[i].nr > max_dim)
                max_dim = vV[i].nr;
        return max_dim;
    }
    int** Creeaza_Matrice()
    {
        int **matrice;
        matrice = new int*[dim+1];
        int max_dim = get_max_dim();
        for(int i=1; i<=dim; i++)
            matrice[i] = new int[max_dim];

        for(int i=1; i<=dim; i++)
            for(int j=1; j<=max_dim; j++)
            {
                if(j>vV[i].nr)
                    matrice[i][j] = 0;
                else
                    matrice[i][j] = vV[i].V[j];
            }
        return matrice;
    }

    friend std::istream& operator>>(std::istream &is, const Vectori_de_vectori &ob);
    friend std::ostream& operator<<(std::ostream &os, const Vectori_de_vectori &ob);
    friend int** operator+(const Vectori_de_vectori &m1, const Vectori_de_vectori &m2);




};

int** Vectori_de_vectori::operator+
{
    int **matrice_1 = m1.Creeaza_Matrice();
    int **matrice_2 = m2.Creeaza_Matrice();
    max_dim1 = m1.get_max_dim();
    max_dim2 = m2.get_max_dim();
    int d = 0, max_d = 0;
    if(m1.dim > m2.dim)
        d = m1.dim;
    else
        d = m2.dim;
    if(m1.get_max_dim() > m2.get_max_dim())
        max_d = m1.get_max_dim();
    else
        max_d = m2.get_max_dim();
    Vectori_de_vectori rez;
    rez.Creeaza_Matrice();

    int **rez;
    rez = new int*(d);
    for(int i=1; i<=d; i++)
        rez = new int(max_d);
    for(int i=1; i<=d; i++)
        for(int j=1; j<=max_d; j++)
            rez[i][j] = matrice_1[i][j] + matrice_2[i][j];
    return rez;
}

std::ostream& operator<<(std::ostream &os, const Vectori_de_vectori &ob)
{
    int d = ob.dim;
    os << std::endl;
    os << "( ";
    for (int i=1; i<=d; i++)
        os << ob.vV[i] << ", ";
    return os;
}


std::istream& operator>>( std::istream &is, const Vectori_de_vectori &ob)
{
    int d = ob.dim;
    std::cout << std::endl;
    for(int i=1; i<=d; i++)
    {
        std::cout << "Componenta " << i << std::endl;
        is >> ob.vV[i];
    }
    return is;
}


