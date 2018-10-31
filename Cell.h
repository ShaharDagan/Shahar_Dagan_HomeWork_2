#include "Nucleus.h"
#include "Ribosome.h"
#include "Mitochondrion.h"
class Cell 
{
private:
	Nucleus _nucleus;
	Ribosome _ribosome;
	Mitochondrion _mitochondrion;
	Gene _glocus_receptor_gene;
	unsigned int _atp_units;
public:
	void init(const std::string dna_sequence, const Gene glucose_receptor_gene);
	bool get_ATP();
};