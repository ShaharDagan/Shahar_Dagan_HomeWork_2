#include "Ribosome.h"
/*
create the linkded list and create protein
Input:std::string &RNA_transcript
Output: the head of the list 
*/
Protein* Ribosome::create_protein(std::string &RNA_transcript) const 
{
	Protein *p = new Protein[sizeof(Protein)];
	p->init();
	bool flag = true;
	std::string codon= "";
	AminoAcid acid;
	int length = RNA_transcript.length();
	while (length>=3&&flag) 
	{
		codon= RNA_transcript.substr(0, THREE);
		acid = get_amino_acid(codon);
		if (acid == UNKNOWN) 
		{
			//deltet the memory unit 
			p->clear();
			flag = false;
			return nullptr;
		}
		else 
		{
			//add the node 
			p->add(acid);
			length -= THREE;
		}
	}
	return p;
}