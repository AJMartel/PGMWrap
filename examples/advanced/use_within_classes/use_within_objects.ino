#include <PGMWrap.h>

/*
  PGMWrap datatypes can be used inside classes. For instance
  allowing user created data to be passed in and used within
  the object.
  
  This example class allows passing in a pointer to a string
  created in PROGMEM using PGMWrap types. It uses a pointer
  type to access the user data.
*/

class Foo{
  public:
    Foo( int8_p *in, int length ) : userStr(in), len(length) {}

    void doStuff(){

      //Loop 'len' times printing each PROGMEM character.
      for( int i = 0 ; i < len ; ++i ){
        Serial.print( userStr[i] );
      }
    }
  private:
    int8_p *userStr;  //Pointer to PROGMEM data.
    int len;          //Length of data to print.
};

const char userProvidedData[] PROGMEM = "A string of PROGMEM data!";

void setup() {
  Serial.begin(9600);

  //Pass in data and length to foo's constructor.
  Foo foo( (int8_p*) userProvidedData, sizeof(userProvidedData) );

  //Call the function using the PROGMEM data.
  foo.doStuff();
}

void loop() {}