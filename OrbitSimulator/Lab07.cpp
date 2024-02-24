/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/
#define _USE_MATH_DEFINES
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <cmath>
#include <math.h>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      //ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
       
       ptGPS.setMetersX(0);
       ptGPS.setMetersY(42164000.0);

      //ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
      GPSdx = -3100.0;
      GPSdy = 0.0;
   }

   //Position ptHubble;
   //Position ptSputnik;
   //Position ptStarlink;
   //Position ptCrewDragon;
   //Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
   double GPSdx;
   double GPSdy;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;
   int R = 6378000;
   double G = 9.80665;

   ////
   //// accept input
   ////

   //// move by a little
   //if (pUI->isUp())
   //   pDemo->ptShip.addPixelsY(1.0);
   //if (pUI->isDown())
   //   pDemo->ptShip.addPixelsY(-1.0);  // We don't need to accept input at this point
   //if (pUI->isLeft())
   //   pDemo->ptShip.addPixelsX(-1.0);
   //if (pUI->isRight())
   //   pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic (in this case logic to rotate the satellite
   //
   
   // Compute Height Above Earth's Surface
   double h = sqrt(pow(pDemo->ptGPS.getMetersX(), 2.0) + pow(pDemo->ptGPS.getMetersY(), 2.0) - R);
   cout << "Height above the earth: " << h << endl;

   // Compute the magnitude of the acceleration
   double g = G * pow((R / (R + h)), 2.0);
   cout << "Magnitude of Acceleration: " << g << endl;

   // Compute Direction of Gravity Pull
   double d = atan2(0.0 - pDemo->ptGPS.getMetersX(),0.0 - pDemo->ptGPS.getMetersY());
   cout << "Direction of Gravity Pull: " << d << endl;

   // Horizontal component of acceleration
   double ddx = g * sin(d * (180.0 / M_PI));
   cout << "DDX: " << ddx << endl;

   // Vertical component of acceleration
   double ddy = g * cos(d * (180.0 / M_PI));
   cout << "DDY: " << ddy << endl;

   // Horizontal component of velocity
   pDemo->GPSdx = pDemo->GPSdx + ddx * 48.0; 
   cout << "DX: " << pDemo->GPSdx << endl; 

   // Vertical component of velocity
   pDemo->GPSdy = pDemo->GPSdy + ddy * 48.0;
   cout << "DY: " << pDemo->GPSdy << endl;

   // New Horizontal and Vertical Distance Formula
   double x = pDemo->ptGPS.getMetersX() + pDemo->GPSdx * 48.0 + ((0.5 * ddx) * pow(48.0, 2));
   double y = pDemo->ptGPS.getMetersY() + pDemo->GPSdy * 48.0 + ((0.5 * ddy) * pow(48.0, 2));
   cout << "New x: " << x << "     New y: " << y << endl;
   cout << endl;

   pDemo->ptGPS.setMetersX(x);
   pDemo->ptGPS.setMetersY(y);

   cout << pDemo->ptGPS.getMetersX() << endl;
   cout << pDemo->ptGPS.getMetersY() << endl;

   // rotate the earth
   pDemo->angleEarth += ( - (2.0 * M_PI / 30.0) * (1440.0 / 86400.0));
   


   //pDemo->angleShip += 0.02; // We don't need a ship a this point
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   //gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   //gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   //gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);  
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);  // Satellite we need



   // draw parts (we don't need parts right now)
   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments (we don't need fragments either)
   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   //gout.drawStar(pDemo->ptStar, pDemo->phaseStar); //Assignment doesn't specify we need stars

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
