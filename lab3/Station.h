#ifndef __STATION_H__
#define __STATION_H__

class Station
{
    public:
        Station(streamtype &stream, string filename);
        ~Station();
        int id;
        PassengerQueue stationQueue;

        // TODO: implement the print function in Passenger.cpp
        void print();

};

#endif
