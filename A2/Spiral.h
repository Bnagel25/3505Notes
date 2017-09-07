/*
* Ben Nagel
* U0806348
*/

#include <iostream>


class Spiral {
  private:
       double x_;
       double y_;
       double radius_;
       double center_x_;
       double center_y_;
       double spiral_angle_;
       double text_angle_;

  public:
       Spiral(double centerX, double centerY, double start_radius);
       double get_text_x();
       double get_text_y();
       double get_spiral_angle();
       double get_text_angle();
       void increment_position();

       Spiral& operator++();
       Spiral& operator++(int);

       friend std::ostream& operator <<(std::ostream& output, Spiral sp);
};
