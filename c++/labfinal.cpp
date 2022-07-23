/*
#include <iostream>
using namespace std;

class Vegetable
{
    private:

        //----data member----//
        string name;
        double water;
    
    public:

        //----consturctor----//
        Vegetable(string name, double water = 0)
        {
            this -> name;
            this -> water;
        }

        //----ชื่อผัก----
        string GetName()
        {
            return name;
        }

        //----ปริมาณน้ำ----
        double water(int volume)
        {
            return volume += this -> water;
        };

        int GetVolume()
        {
            return volume;
        }

        //----เก็บเกี่ยว----
        int IsReadyToPick()
        {
            if(this -> volume == water)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
};

class Farm : public Vegetable
{
    public:
        void Plant(Vegetable *vegetable)
        {
            return plant;
        };

        void Pick()
        {
            return IsReadyToPick;
        };
};*/



/*ข้อ5
#include <iostream>
using namespace std;

class Movie
{
    private:
        string name;

    public:
        Movie(string name)
        {
            this -> name;
        }

        string GetName()
        {
            return name;
        }

        int GiveStar(int star)
        {
            if(star <= 5 && star >= 1 )
            {
                return star;
            }
        }

        void AverageStar()
        {
            star 
        }

};*/


/*ข้อ6
#include <iostream>
using namespace std;

class TaekwondoPlayer
{
    private:
        string name;
    
    public:
        string GetName()
        {
            return name;
        }

        int SetWin(int w)
        {
            if(w < 0)
            {
                w = 0;
            }
            else
            {
                return w;
            }
        }
        
        int SetTie(int t)
        {
            if(t < 0)
            {
                t = 0;
            }
            else
            {
                return t;
            }
        }

        int SetLoss(int l)
        {
            if(l < 0)
            {
                l = 0;
            }
            else
            {
                return l;
            }
        }

        void TotalPoints()
        {
            if(w >= 3 && t >= 1)
            {
                return l = 0;
            }
            else
            {
                return w , t , l;
            }
        }

        void DisplayGraph()
        {

        }
};*/

/*ข้อ4
#include <iostream>
using namespace std;

class Vegetable
{
    private:

        //----data member----//
        string name;
        double water;
    
    public:

        //----consturctor----//
        Vegetable(string name, double water = 0)
        {
            this -> name;
            this -> water;
        }

        //----ชื่อผัก----
        string GetName()
        {
            return name;
        }

        //----ปริมาณน้ำ----
        double Vegetable::water(int volume)
        {
            return volume += water;
        }

        //----เก็บเกี่ยว----
        int IsReadyToPick()
        {
            if(this -> volume == water)
            {
                printf("1");
            } 
            else
            {
                printf("0");
            }
        }
};*/

//ข้อ3
#include <iostream>
using namespace std;

class Person
{
    private:

        //----data member----//
        void name;
        double salary;
    
    public:

        //----constructor----//
        Person (void name, double salary);

        //----getter setter----//
        void GetName()
        {
            return name;
        }

        double GetSalary()
        {
            return salary;
        }

        //----member function----//
        
        //----เงินเดือน----
        double IncomeYearly()
        {
            return (this -> salary) * 12;
        }

        //----ภาษี----
        double Tax(double rate)
        {
            return (rate / 100) * (this -> salary);
        }
};

int main() {
    
    Person kwan("Kwan", 1000);

    cout << kwan.GetName() << endl;
    cout << kwan.GetSalary() << endl;

    cout << kwan.IncomeYearly() << endl;

    cout << kwan.Tax(10) << endl;

}
