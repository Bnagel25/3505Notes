/*
* Ben Nagel
* U0806348
*/

#include <string.h>
#include <stdio.h>
#include "Spiral.h"
#include "hpdf.h"
#include "HaruPDF.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
/*
  Takes command line arguments and makes a HARUPDF Spiral
*/
  if (argc < 2) {
    cout << "Please Supply Text" << endl;
    return 0;
  }

  //TODO: Experiment
  Spiral spiral(210, 350, 90);
  char* title = (char*) "spiralPDF";
  HaruPDF haru_pdf(title);

  char inputted_text[256];
  strcpy(inputted_text, argv[1]);

  for (int i = 0; i < strlen(inputted_text); i++) {
    spiral.increment_position();
    haru_pdf.setCharacter(inputted_text[i],
                          spiral.get_text_x(),
                          spiral.get_text_y(),
                          spiral.get_text_angle());
  }

  haru_pdf.savePDF();

  return 0;
}
