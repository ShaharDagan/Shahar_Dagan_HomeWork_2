#include "Protein.h"
#ifndef Ribosome_H
#define Ribosome_H
#define THREE 3
class Ribosome {
public:
	Protein* create_protein(std::string &RNA_transcript) const;
};
#endif // !Ribosome
