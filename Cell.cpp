#include "Cell.h"
/*
Initalize the fields of the cell class
Input:const std::string dna_sequence, const Gene glucose_receptor_gene
Output:none
*/
void Cell::init(const std::string dna_sequence, const Gene glucose_receptor_gene) 
{
	
	this->_nucleus.init(dna_sequence);
	this->_mitochondrion.init();
	this->_glocus_receptor_gene = _glocus_receptor_gene;
}
/*
create protien list
and get the rna transcript
Input:none
OUput:true / false - if we can produce atp
*/
bool Cell::get_ATP() 
{
	std::string rna =this->_nucleus.get_RNA_transcript(this->_glocus_receptor_gene);
	Protein *list = this->_ribosome.create_protein(rna);
	if (list == nullptr) 
	{
		std::cerr << "Error create protein";
		exit(1);
	}
	//insert and set glucose
	this->_mitochondrion.insert_glucose_receptor(*list);
	this->_mitochondrion.set_glucose(50);
	if (this->_mitochondrion.produceATP(50)) 
	{
		this->_atp_units = 100;
		return true;
	}
	else
	{
		return false;
	}
}

