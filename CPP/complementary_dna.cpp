#include <string>

std::string DNAStrand(const std::string& dna)
{
  int i = 0;
  std::string complement;
  
  for ( i = 0; i < std::strlen(dna.c_str()); i++) {
    if (dna[i] == 'A') {
      complement += "T";
    } else if (dna[i] == 'C') {
      complement += "G";
    } else if (dna[i] == 'T') {
      complement += "A";
    } else if (dna[i] == 'G') {
      complement += "C";
    }
  }
  return complement;
}