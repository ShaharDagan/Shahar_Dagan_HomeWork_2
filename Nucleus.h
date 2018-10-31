#include <string>
#include <iostream>
#ifndef Gene_H
#define Gene_H
class Gene
{
private:
	unsigned int _start;//start index the gene begin
	unsigned int _end;//end index the gene ends
	bool _on_complementary_dna_strand;//if the gene is on the complementary dna strand
public:
	void init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand);
	unsigned int get_start() const;
	unsigned int get_end() const;
	bool is_on_complementary_dna_strand() const ;
};
#endif
#ifndef Nucleus_H
#define Nucleus_H
class Nucleus
{
private:
	std::string _DNA_strand;//D.N.A data of the cell
	std::string _complementary_DNA_strand; // his complement
public:
	//builds the complement DNA and stores in complementary_DNA_strand
	void init(const std::string dna_sequence);
	std::string get_RNA_transcript(const Gene& gene) const;
	std::string get_reversed_DNA_strand() const;
	unsigned int get_num_of_codon_appearances(const std::string& codon) const;
};
#endif 
