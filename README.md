# RC_CAR_Arduino with Compass Module

In this project, I tried to incorporate the HMC5883L with the RC Car that I had made using the Arduino and other components. For this I first need to learn how the component or the Compass actually functions and what values it would give. The component actually gives us direction based on Magnetic north of the earth.

We can find a HMC5883L library in the arduino libraries itself, but I used another library created by James Sleeman. Link to his github is given below:
https://github.com/sleemanj/HMC5883L_Simple

One of the reasons that I used this library is because most of the work is done for you, as in the calibration of the compass module, computation of the actual directions from the Magnetic Directions and so on.

Like you need to just enter the Magnetic Declination of the city you are in and then choose what axis of the Compass out of x and y you need the directions to be in. Like this:

HMC5883L_Simple Compass;
Compass.SetDeclination(10, 17, 'W'); //Declination for TORONTO, CANADA  
float heading = Compass.GetHeadingDegrees();

Now, that I used the Library and can use the Compass Module with the arduino. For the connections of Compass Module to Arduino, I connected them as follows:
VCC to Vin,
GND to GND,
SCL to A5, and
SDA to A4

SCL and SDA are used the I2C communication where SCL is the clock and SDA is for the data.

Also, An important note while using the HMC5883L is that, it is prefrred to keep the component at some distance from batteries, and metals because it could deviate the readings of the module. So, for this project I kept it at a higher elevation.
