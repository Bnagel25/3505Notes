/*
*  Ben Nagel
*  U0806348
*/
class HaruPDF {
  private:
      HPDF_Doc pdf_;
      HPDF_Page page_;
      HPDF_Font font_;
      char filename_[256];

  public:
      HaruPDF(char name[256]);
      void setCharacter(char character, float x, float y, float rad);
      void savePDF();
};
