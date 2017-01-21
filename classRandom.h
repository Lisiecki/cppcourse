

class LCG {
//protected so that Uniform.cpp can get these params
protected:
unsigned long long int a;
unsigned long long int c;
unsigned long long int m;
unsigned long long int Xn;

public:
/*
*	Default constructor
*/
LCG():a(1103515245ULL),c(12345),m(1<<30),Xn(1){};

/*
*	Constructor with choosen values. Initialize seed X0 as Xn as well
*/
LCG(unsigned long long int l_a, unsigned long long int i_c, unsigned long long int l_m):a(l_a),c(i_c),m(l_m),Xn(1){};

/*
*	Set seed X0
*/
void setSeed(unsigned long long int x0) 
{
	Xn = x0;
}

/* 
*	Overload the operator() to return Xn+1
*/
unsigned long long int operator()()
{
	// recurrence relation
	return Xn = (a*Xn+c) % m; 
}
};
