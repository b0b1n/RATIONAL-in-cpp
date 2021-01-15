#include <iostream>
using namespace std;
    ///function that returns the biggest cummon divider of 2 numbers
    int PGCD(int a,int b) ///we'll be using this function later in a case of the output function
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
class rational
{
    int n,m;  ///a rationnal is written like n/m
public:
    rational(int a=0, int b=1) ///constructor
    {
        n=a;
        m=b;
    }
    ~rational() {} ///destructor
    /***********arithmetic operators:**************/
    ///the ADDITIOPN operator
    rational& operator+(rational& r)
    {
        static rational res;
        res.n=n*r.m+r.n*m;
        res.m=m*r.m;
        return res;
    }
    ///the SUSTRACTION operator
    rational& operator-(rational& r)
    {
        static rational res;
        res.n=n*r.m-r.n*m;
        res.m=m*r.m;
        return res;
    }
    ///the NEGATION operator
    rational& operator-()
    {
        n=-n;
        return *this;
    }

    ///the MULTIPLYING operator
    rational& operator*(rational& r)
    {
        static rational res;
        res.n=n*r.n;
        res.m=m*r.m;
        return res;
    }

    ///the DIVISION operator
    rational& operator/(rational& r)
    {
        static rational res;
        res.n=n*r.m;
        res.m=m*r.n;
        return res;
    }

    ///the  /= operator
    rational& operator+=(rational& r)
    {
        *this=*(this)+r;
        return *this;
    }
    ///the  -= operator
    rational& operator-=(rational& r)
    {
        *this=*(this)-r;
        return *this;
    }
    ///the *= operator
    rational& operator*=(rational& r)
    {
        *this=*(this)*r;
        return *this;
    }
    ///the /= operator
    rational& operator/=(rational& r)
    {
        *this=*(this)/r;
        return *this;
    }
    /************the COMPARAISON operators*****************/
    ///the EQUAL operator
    bool operator==(rational& r)
    {
        if(n*r.m-r.n*n==0)
            return true ;
        return false;
    }
    ///the DIFFERENCE operator
    bool operator!=(rational& r)
    {
        return !(*(this)==r);
    }
    ///the BIGGER THAN operator
    bool operator>(rational& r)
    {

        if(n*r.m-r.n*n>0)
            return true ;
        return false;
    }
    ///the BIGGER THEN OR EQUAL operator
    bool operator>=(rational& r)
    {
        if(*(this)==r||*(this)>r)
            return true;
        return false;
    }
    ///the SMALLER THAN operator
    bool operator<(rational & r)
    {
        return !(*(this)>=r);
    }
    ///the SMALLER THAN OR EQUAL operator
    bool operator<=(rational& r)
    {
        return!((*this)>r);
    }
    ///the ASSIGNMENT operator
    rational& operator=(rational& r)
    {
        n=r.n;
        m=r.m;
        return *this;
    }

    ///the OUTPUT operator
    friend ostream& operator<<(ostream& O, rational& r)
    {

        if(r.m==0) ///exemple : 1.2/0 ==> invalid format
            O <<"\t"<< r.n << "/" << r.m << " is an  " << " invalid format !!! " ;

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
            if(r.m==1)   ///condition added even if it already exists ,becaucar it exists in an ELSE
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
        else ///the case where there is nohing to change
            O <<"\tr = " << r.n << "/" << r.m ;
        return O;
    }
    ///the INPUT operator
    friend istream& operator>>(istream& I, rational& r)
    {
        cout << " n =\t";
        I >> r.n;
        cout << "m =\t";
        I>> r.m;
        return I;
    }
    rational& operator++()
    {
        rational tmp;
        tmp.n=1;
        *(this)+=tmp;
        return *this;
    }
    rational& operator++(int n)  /// "n" added to use ++ POST
    {
        rational tmp;
        tmp.n=1;
        *(this)+=tmp;
        return *this;
    }
    rational& operator--()
    {
        rational tmp;
        tmp.n=1;
        *(this)-=tmp;
        return *this;
    }
    rational& operator--(int n) ///"n" added to use ++ POST
    {
        rational tmp;
        tmp.n=1;
        *(this)-=tmp;
        return *this;
    }
};


int main()
{
    rational a(0,2),b(4,2),c(3),d(2,4),e(2,0),f;
    cout << " rational whit a null n:" <<endl;
    cout << a ;
    cout << endl;
    cout << endl;
    cout << "rational where n is dividable by m :" << endl;
    cout << b ;
    cout << endl;
    cout << endl;
    cout << "rational with m equal to 1 :" << endl;
    cout << c ;
    cout << endl;
    cout << endl;
    cout <<"rational where m is dividable by n :" << endl;
    cout << d ;
    cout << endl;
    cout << endl;
    cout << "exemple of an invalid format: " << endl;
    cout << e;
    cout << endl;
    cout << endl;
    cout << "ADDITION " << endl;
    cout <<"    the addition of " <<a << "     and " << b << " is : " <<a+b;
    cout << endl;
    cout << endl;
    cout << "SOUSTRACTION " << endl;
    cout << "   the soustraction of " << b << "     minus " << c << " is : " << b-c ;
    cout << endl;
    cout << endl;
    cout << "MULTIPLICATION " << endl;
    cout << "   the mmultiply of  " << b << "     and " << c << " is : " << b*c ;
    cout << endl;
    cout << endl;
    cout << "DIVISION " << endl;
    cout << "   the division of " << b << "     by " << c << " is : " << b/c ;
    cout << endl;
    cout << endl;
    cout << "use of /=" << endl;
    cout << b ;
    b/=d;
    cout << "  becomes :" << b ;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "we increment and decrement : " << b;
    cout<< "incrementing (post) " ;
    b++;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "incrementing (pre) " ;
    ++b;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "decrementing (post) " ;
    b--;
    cout << b;
    cout << endl;
    cout << endl;
    cout<< "decreenting (pre) " ;
    --b;
    cout << b;
    cout << endl;
    cout << endl;
    cout << "ASSIGNMENT " << endl;
    cout << "the assignment of " <<b << "\t to " <<f<<endl;
    f=b;
    cout << "becomes \t" ;
    cout << f;
    cout << endl;
    cout << endl;


    return 0;
}
