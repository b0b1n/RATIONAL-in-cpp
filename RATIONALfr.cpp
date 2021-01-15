#include <iostream>
using namespace std;
    int PGCD(int a,int b)
    {
        int x, r,y;
        if (a>b)
        {
            x=b;
            r=a%b;
        }
        else
        {
            x=a;
            r=b%a;
        }

        while(r!=0)
        {
            y=x;
            x=r;
            r=y%x;
        }
        return x;
    }
class rationnel
{
    int n,m;
public:
    rationnel(int a=0, int b=1) ///constructeur
    {
        n=a;
        m=b;
    }
    ~rationnel() {} ///destructeur
    /***********operateurs arithmetiques :**************/
    ///operateur d'addition
    rationnel& operator+(rationnel& r)
    {
        static rationnel res;
        res.n=n*r.m+r.n*m;
        res.m=m*r.m;
        return res;
    }
    ///operateur de soustraction
    rationnel& operator-(rationnel& r)
    {
        static rationnel res;
        res.n=n*r.m-r.n*m;
        res.m=m*r.m;
        return res;
    }
    ///operateur pour negativité
    rationnel& operator-()
    {
        n=-n;
        return *this;
    }

    ///operateur de multiplication
    rationnel& operator*(rationnel& r)
    {
        static rationnel res;
        res.n=n*r.n;
        res.m=m*r.m;
        return res;
    }

    ///operateur de division
    rationnel& operator/(rationnel& r)
    {
        static rationnel res;
        res.n=n*r.m;
        res.m=m*r.n;
        return res;
    }

    ///operateur de /=
    rationnel& operator+=(rationnel& r)
    {
        *this=*(this)+r;
        return *this;
    }
    ///operateur de -=
    rationnel& operator-=(rationnel& r)
    {
        *this=*(this)-r;
        return *this;
    }
    ///operateur de *=
    rationnel& operator*=(rationnel& r)
    {
        *this=*(this)*r;
        return *this;
    }
    ///operateur de /=
    rationnel& operator/=(rationnel& r)
    {
        *this=*(this)/r;
        return *this;
    }
    /************operateurs de comparaison*****************/
    ///operateur d'egalité
    bool operator==(rationnel& r)
    {
        if(n*r.m-r.n*n==0)
            return true ;
        return false;
    }
    ///operateur de difference
    bool operator!=(rationnel& r)
    {
        return !(*(this)==r);
    }
    ///operateur de superieur strict
    bool operator>(rationnel& r)
    {

        if(n*r.m-r.n*n>0)
            return true ;
        return false;
    }
    ///operateur de superieur ou egal
    bool operator>=(rationnel& r)
    {
        if(*(this)==r||*(this)>r)
            return true;
        return false;
    }
    ///operateur d'inferieur strict
    bool operator<(rationnel& r)
    {
        return !(*(this)>=r);
    }
    ///operateur de inferieur ou égal
    bool operator<=(rationnel& r)
    {
        return!((*this)>r);
    }
    ///operateur d'affectation
    rationnel& operator=(rationnel& r)
    {
        n=r.n;
        m=r.m;
        return *this;
    }

    ///surcharge d'operateur de sortie
    friend ostream& operator<<(ostream& O, rationnel& r)
    {

        if(r.m==0) ///exemple : 1.2/0 ==> format invalid
            O <<"\t"<< r.n << "/" << r.m << " est une  " << " format invalid !!! " ;

         else if(r.n==0) ///exemple : 0/5 ==> 0
            O << "\tr  =  0" ;

         else if(r.m<0&&r.n>0) ///exemple : 3/-2.2 ==> -3/2.2
            O <<"\tr = " << -r.n<< "/"<< -r.m ;

         else if(r.m==1) ///exemple : 3.3 / 1 ==> 3.3
            O <<"\tr = " << r.n ;

         else if(r.m<0 && r.n<0) ///exemple : -4/-3 ==> 4/3
            O <<"\tr = " << -r.n << "/" << -r.m;

        else if(r.n>r.m && r.n%r.m==0) ///exemple :==> 4 / 2 ==> 2
        {
            r.n= PGCD(r.n,r.m);
            r.m=1;
            if(r.m==1)   ///condition ajouté meme ci il existe deja car il y a des ELSE
                O <<"\tr = " << r.n ;
            else
                O  <<"\tr = " << r.n<< "/" << r.m ;
        }
        else if(r.m>r.n && r.m%r.n==0) ///exemple :==> 2/4 ==> 1/2
        {
            r.m= PGCD(r.n,r.m);
            r.n=1;
            O  <<"\tr = " << r.n << "/" << r.m ;
        }
        else /// cas de il n'y a aucun aucune chose a changer
            O <<"\tr = " << r.n << "/" << r.m ;
        return O;
    }
    ///surcharge d'operateur d'ENTREE
    friend istream& operator>>(istream& I, rationnel& r)
    {
        cout << " n =\t";
        I >> r.n;
        cout << "m =\t";
        I>> r.m;
        return I;
    }
    rationnel& operator++()
    {
        rationnel tmp;
        tmp.n=1;
        *(this)+=tmp;
        return *this;
    }
    rationnel& operator++(int n)
    {
        rationnel tmp;
        tmp.n=1;
        *(this)+=tmp;
        return *this;
    }
    rationnel& operator--()
    {
        rationnel tmp;
        tmp.n=1;
        *(this)-=tmp;
        return *this;
    }
    rationnel& operator--(int n)
    {
        rationnel tmp;
        tmp.n=1;
        *(this)-=tmp;
        return *this;
    }
};


int main()
{
    rationnel a(0,2),b(4,2),c(3),d(2,4),e(2,0),f;
    cout << " rationnel avec n nul :" <<endl;
    cout << a ;
    cout << endl;
    cout << endl;
    cout << "rationnel n divisible par m :" << endl;
    cout << b ;
    cout << endl;
    cout << endl;
    cout << "rationnel avec m egal a 1 :" << endl;
    cout << c ;
    cout << endl;
    cout << endl;
    cout <<"rationnel avec m divisible par n :" << endl;
    cout << d ;
    cout << endl;
    cout << endl;
    cout << "exemple format invalid : " << endl;
    cout << e;
    cout << endl;
    cout << endl;
    cout << "ADDITION " << endl;
    cout <<"    somme de " <<a << "     et " << b << " est : " <<a+b;
    cout << endl;
    cout << endl;
    cout << "SOUSTRACTION " << endl;
    cout << "   soustraction " << b << "     moins " << c << " est : " << b-c ;
    cout << endl;
    cout << endl;
    cout << "MULTIPLICATION " << endl;
    cout << "   multiplication " << b << "     multiplie par " << c << " est : " << b*c ;
    cout << endl;
    cout << endl;
    cout << "DIVISION " << endl;
    cout << "   division " << b << "     divise par " << c << " est : " << b/c ;
    cout << endl;
    cout << endl;
    cout << "utilisation de /=" << endl;
    cout << b ;
    b/=d;
    cout << "  devient :" << b ;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "ON INCREMENTE ET DECREMENTE : " << b;
    cout<< "incrementation (post) " ;
    b++;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "incrementation (pre) " ;
    ++b;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "incrementation (post) " ;
    b--;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "incrementation (pre) " ;
    --b;
    cout << b;
    cout << endl;
    cout << endl;
    cout << "AFFECTATION " << endl;
    cout << "affectation de " <<b << "\t A " <<f<<endl;
    f=b;
    cout << "il devient \t" ;
    cout << f;
    cout << endl;
    cout << endl;


    return 0;
}
