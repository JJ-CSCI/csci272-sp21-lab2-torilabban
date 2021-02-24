//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------
//Victoria Labban
// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

//Define a class GPS that will store latitude and longitude coordinates 

class GPS {
double latitude;
double longitude;
Compass latitudeDirection;
Compass longitudeDirection;
 public:
 GPS() {
 latitude = 0.0;
 longitude = 0.0;
 latitudeDirection = Compass::S;
 longitudeDirection = Compass::E;
 

 }
 //Constructor
GPS(double lateralc, double longitudec) {
 latitude =  ((lateralc > 90) || (lateralc < 0)) ? 0 : lateralc;
 longitude = ((longitudec > 180) || (longitudec < 0)) ? 0 : longitudec;
 latitudeDirection = Compass::S;
 longitudeDirection = Compass::E;
 } 

 double getLatitude() {
 return latitude;
 }
 Compass getLatitudeDirection() {
 return latitudeDirection;
 }

 double getLongitude() {
 return longitude;
 }
 Compass getLongitudeDirection() {
 return longitudeDirection;
  }

GPS(double latit, Compass latcomp, double longit, Compass longcomp){
    latitude = latit;
    longitude = longit;
    latitudeDirection = latcomp;
    longitudeDirection = longcomp;
    if ((latit > 90) || (latit < 0)){
      latitude = 0;
      latitudeDirection = Compass::S;
    }
    if ((longit > 180 )|| (longit < 0)){
      longitude = 0;
      longitudeDirection = Compass::E;
    }
    if ((latcomp == Compass::W) || (latcomp == Compass::E)){
      latitudeDirection = Compass::S;
    }
    if ((longcomp == Compass::N || longcomp== Compass::S)){
      longitudeDirection = Compass::E;
    }
  }
};





//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
