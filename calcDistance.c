#include "GPS.h"


extern double currentLat ;
extern double currentLong ;
extern double distanceDiff ;

double ToDegree(double value) {
    double result=0;
    int degree = (int)value / 100;
    double minutes = value-(double)degree*100;
    result = degree+ (minutes/60);

    return result;


}

double degToRad(double degree) {    // function to convert from degree to radian
    return degree * (PI / 180.0);
}


// function to calculate distance between two points using data given from the GPS
double GPS_getDistance(double currentLat,double currentLong,double previousLat,double previousLong){
    double lat1 = degToRad(currentLat);
    double long1 = degToRad(currentLong);
    double lat2 = degToRad(previousLat);
    double long2 = degToRad(previousLong);
    double latdiff = lat2 - lat1;
    double longdiff = long2 - long1;

    double a= pow(sin(latdiff/2),2)+cos(lat1)*cos(lat2)*pow(sin(longdiff/2),2); // Haversine formula: a = sin²(?f/2) + cos f1 · cos f2 · sin²(??/2)
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
		distanceDiff = 6371000*c ;
    return 6371000*c;   //in meters
}

