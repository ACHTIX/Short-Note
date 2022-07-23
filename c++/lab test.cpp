#include <iostream>
using namespace std;

class Transportation
{
    public:
    
        //----data memberที่จะนำไปดัดแปลง----
        virtual float fare() = 0;
};

class Taxi: public Transportation
{
    private:
    
        double distance;
        
    public:
    
        //----consturctor----
        Taxi (double distance = 0) : Transportation() 
        {
            if(distance < 0)
            {
                this -> distance = 0;
            }
            else
            {
                this -> distance = distance;
            }
        }
        
        //----ระยะทาง----
        void setDistance(double distance)
        {
            if(distance < 0)
            {
                this -> distance = 0;
            }
            else
            {
                this -> distance = distance;
            }
        }
        
        //----ค่ารถ----
        float fare() 
        {
            return 35 + (this->distance) * 2;
        }
};

class BmtaBus : public Transportation
{
    public:
    
        //----constructor----
        BmtaBus() : Transportation() {}
            float fare() 
            {
                return 6.5;
            }

};

class BTS : public Transportation
{
    private:
    
        //----data member----
        int station;
        
    public:
    
        //----consturctor----
        BTS(int station = 0) : Transportation()
        {
            if (station < 0) 
            {
                this->station = 0;
            }
            else 
            {
                this->station = station;
            }
        }
        
        //----จำนวนสถานี----
        void setStation(int station)
        {
            if (station < 0)
            {
                this->station = 0;
            }
            else
            {
                this->station = station;
            }
        }
        
        //----ค่ารถ----
        float fare() 
        {
            return 15 + (station * 5);
        }
   

};

class Passenger
{
    private:
    
        //----data member ค่ารถ----
        double totalFare; 
    
    public: 
    
        //----กำจัด0----
        Passenger(double totalFare = 0) 
        {
            if (this->totalFare < 0) 
            {
                this->totalFare = 0;
            }    
            else 
            {
                this->totalFare = totalFare;
            }
        }; 

        //----เพิ่มช่องทางการเดินทาง----
        void addTransport(Transportation &type) 
        {
            this->totalFare += type.fare();
        } 
    
        //----ใช้ตัวแปรในprivate----    
        double getTotalFare() 
        {
            return this->totalFare;
        }    

};

int main()
{
    Passenger passenger;
    while(1) {
        char transportType;
        cin >> transportType;
        if (transportType == 'A') {
            Taxi *taxi = new Taxi();
            double distance;
            cin >> distance;
            
taxi->setDistance(distance); 
            passenger.addTransport(*taxi); 

        } else if (transportType == 'B') {
            BmtaBus *bus = new BmtaBus();
            
passenger.addTransport(*bus);

        } else if (transportType == 'C') {
            BTS *bts = new BTS();
            int station;
            cin >> station;
            
bts->setStation(station); 
            passenger.addTransport(*bts);

        } else {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}