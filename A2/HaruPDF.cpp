/*
*  Ben Nagel
*  U0806348
*/
// TODO: Change all _dataMembers to datamembers_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
#include "HaruPDF.h"
#include <iostream>
using namespace std;


HaruPDF::HaruPDF(char name[256]) {
/*
  Initializes a HaruPDF page
  *** Class implementation taken heavily from pdfExample.cpp ***
  param: name: (char[256]) name of file + ".pdf"
*/
  strcpy(filename_, name);
  strcat(filename_, ".pdf");

  pdf_ = HPDF_New(NULL, NULL);
  page_ = HPDF_AddPage(pdf_);
  HPDF_Page_SetSize(page_, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
  font_ = HPDF_GetFont(pdf_, "Helvetica", NULL);
  HPDF_Page_SetTextLeading(page_, 20);
  HPDF_Page_SetGrayStroke(page_, 0);
  HPDF_Page_BeginText(page_);
  font_ = HPDF_GetFont(pdf_, "Courier-Bold", NULL);
  HPDF_Page_SetFontAndSize(page_, font_, 20);
}

void HaruPDF::setCharacter(char character, float x, float y, float rad) {
/*
  Sets the character into the HaruPDF pdf file

  param: character: (char) character to be written
  param: x: (float) x coordinate for character
  param: y: (float) y coordinate for character
  param: rad: (float) angle of character placement in radians
*/
  // Add null terminator to character
  char buf[2];
  buf[0] = character;
  buf[1] = 0;

  HPDF_Page_SetTextMatrix(page_, cos(rad),
                          sin(rad), -sin(rad),
                          cos(rad), x, y);

  HPDF_Page_ShowText(page_, buf);
}

void HaruPDF::savePDF() {
/*
  Saves PDF of HaruPDf object and cleans up the object
*/
  HPDF_Page_EndText(page_);
  HPDF_SaveToFile(pdf_, filename_);
  HPDF_Free(pdf_);
}
