/*
 *  Ben Nagel
 *  U0806348
 */

#include "Spiral.h"
#include <math.h>
#include <iostream>

using namespace std;


Spiral::Spiral(double centerX, double centerY, double start_radius) {
/*
  Spiral Inintialier
  param: centerX: (double) X coordinate of the center of spiral
  param: centerY: (double) Y coordinate of the center of spiral
  param: start_radius: (double) Starting radius for spiral,
                       minumum of 45 will be enforced
*/
 //  _radius = start_radius < 45.0 ? 45.0 : start_radius;
  radius_ = start_radius;
  if(start_radius < 45.0) {
    radius_ = 45.0;
  }
  center_x_ = centerX;
  center_y_ = centerY;
  x_ = centerX;
  y_ = centerY;

  spiral_angle_ = 180.0;
  text_angle_ = 180.0;
}

double Spiral::get_text_x() {
  /*
    Returns the X-Value of the current position
    ret: (double) X-Value of current position
   */
  return x_;
}

double Spiral::get_text_y() {
  /*
    Returns the Y-Value of the current position
    ret: (double) Y-Value of current position
  */
  return y_;
}

double Spiral::get_spiral_angle() {
  /*
    Returns the Spiral Angle
    ret: (double) Spiral Angle of current position
  */
  return spiral_angle_;
}

double Spiral::get_text_angle() {
  /*
    Returns the Character Angle  of the current position
    ret: (double) Character Angle of current position
  */
  return text_angle_;
}

Spiral& Spiral::operator++() {
  /*
    Moves the Spiral to the next position
   */
  this->increment_position();
  return *this;
}

Spiral& Spiral::operator++(int) {
  /*
    Moves the Spiral to the next position
  */
  Spiral sp = *this;
  ++(*this);
  return sp;
}

void Spiral::increment_position() {
  /*
    Moves the Spiral to the next position
  */
  text_angle_ = (spiral_angle_ - 90) / 180 * M_PI;
  float rad = spiral_angle_ / 180 * M_PI;
  x_ = center_x_ + cos(rad) * radius_;
  y_ = center_y_ + sin(rad) * radius_;

  radius_ += 1;
  spiral_angle_ -= 10;
}

std::ostream& operator<<(std::ostream& output, Spiral sp) {
  /*
    Provides a way to print out Spiral Info
    param: output: (ostream) std ostream output
    param: sp: (Spiral) Spiral of which to get data
  */
  output << "Center (X, Y): (" << sp.center_x_ << ',' << sp.center_y_ << ')'
         << "Angle" << sp.text_angle_;
  return output;
}
