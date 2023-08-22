#ifndef VBETASPECTRUM_HH
#define VBETASPECTRUM_HH


#include "vNeutrinoSpectrum.hh"
#include <vector>

enum FFmethod
{
    EXACT,
    HALL,
    NONREL
};

class vBetaSpectrum : public vNeutrinoSpectrum
{
public:
	void PrintInfo() const override;
	
	double GetCurrent(double E) const override;
	double GetBetaSpectrum(double T, double Q, double Z_f, double normalization, bool anti = false) const;

	void SetActivity(double activity) { fActivity = activity; } // The unit of Activity should be /day
	double GetActivity() const { return fActivity; }
    double GetFermiFunction(double T, double Z, double A, bool anti=false);
    std::vector<double> GetQValues() { return fQValue; }
    std::vector<double> GetZdaughter() { return fZdaughter; }
    std::vector<double> GetA() { return fA; }
    std::vector<double> GetContribution() { return fContribution; }
    std::vector<double> GetNormalization() { return fNormalization; }

    TComplex gamma_complex(double, double);
    double gamma_complex_mag2(double, double);

    void SetFermiApproxMethod(FFmethod method) { fFermiApproxMethod = method; }
    void SetFFreduced(bool FFreduced) { fFFreduced = FFreduced; }
    bool fFFreduced = false;
    FFmethod fFermiApproxMethod = EXACT;

protected:
	void SetVectorSize(int size) { fVectorSize = size; }
	void SetQValues(std::vector<double> qValue) { fQValue = qValue; }
	void SetZdaughter(std::vector<double> Z_f) { fZdaughter = Z_f; }
    void SetA(std::vector<double> A) { fA = A; }
	void SetContribution(std::vector<double> cont) { fContribution = cont; }
	void SetNormalization(std::vector<double> norm) { fNormalization = norm; }

private:
	double fActivity;
	
	int fVectorSize;
	std::vector<double> fQValue;
	std::vector<double> fZdaughter;
    std::vector<double> fA;
	std::vector<double> fContribution;
	std::vector<double> fNormalization;
};

#endif
