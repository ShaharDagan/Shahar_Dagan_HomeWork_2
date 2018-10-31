#include "Mitochondrion.h"

/*
Initalize the mitochondrion sets the glocuse level 
and the has glocuse receptor field 
Input:none
Output:none
*/
void Mitochondrion::init() 
{
	this->_glocuse_level = 0;
	this->_has_glocuse_receptor = false;
}
/*
checks if the atp has glocuse receptor and the glocuse unit above 50 
Input:const int glocuse_unit 
Output:true or false
*/
bool Mitochondrion::produceATP(const int glocuse_unit) const 
{
	if (_has_glocuse_receptor&&glocuse_unit>=50) 
	{
		return true;
	}
	return false;
}
/*
sets the glocuse level to the glocuse units(update the field)
Input:const unsigned int glocuse_units
Output:none 
*/
void Mitochondrion::set_glucose(const unsigned int glocuse_units) 
{
	this->_glocuse_level = glocuse_units;
}
/*
check if the list is from the structure of ALANINE,LEUCINE,GLYCINE,HISTIDINE,LEUCINE,PHENYLALANINE,AMINO_CHAIN_END 
Input:const Protein & protein
Output:none
*/
void Mitochondrion::insert_glucose_receptor(const Protein & protein) 
{
	//array containing the order of the amino acids 
	AminoAcid arr[] = { ALANINE,LEUCINE,GLYCINE,HISTIDINE,LEUCINE,PHENYLALANINE,AMINO_CHAIN_END };
	AminoAcidNode * curr = protein.get_first();
	int i = 0;
	bool flag = true;
	//check if the list has the appropriate order of amino acids
	while (curr != NULL&&flag)
	{
		//sets the flag to false if the data is diffrent from what needed
		if (curr->get_data() != arr[i]) 
		{
			flag = false;
		}
		i++;
		curr = curr->get_next();
	}
	this->_has_glocuse_receptor = flag;
}
