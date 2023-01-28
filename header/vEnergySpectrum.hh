#ifndef VENERGYSPECTRUM_HH
#define VENERGYSPECTRUM_HH


#include "vNeutrinoSpectrum.hh"
#include "vIBD.hh"


class vEnergySpectrum
{
public:
	vEnergySpectrum(vNeutrinoSpectrum* vns, double emin, double emax)
	{
		SetNeutrinoSpectrum(vns);
		fEmin = emin;
		fEmax = emax;
	}
	virtual ~vEnergySpectrum() {}

	double operator()(double* x, double* p) const
	{
		double E = x[0];
		return fvns->GetCurrent(E) * fvibd.GetCrossSection(E);
	}

	void PrintInfo() const { fvns->PrintInfo(); }

	vNeutrinoSpectrum* GetNeutrinoSpectrum() const { return fvns; }
	void SetNeutrinoSpectrum(vNeutrinoSpectrum* vns) { fvns = vns; }

	double GetEmin() const { return fEmin; }
	double GetEmax() const { return fEmax; }
	void   SetEmin(double emin) { fEmin = emin; }
	void   SetEmax(double emax) { fEmax = emax; }

private:
	vNeutrinoSpectrum* fvns;
	vIBD fvibd;

	double fEmin;
	double fEmax;
};

#endif