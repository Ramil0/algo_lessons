#include <iostream> 
using namespace std; 

struct Board
{
	int m, // horizontal (x)
		n; // vertical (y) 
	char* data;

	Board() : m(0), n(0), data(NULL) 
	{
	}

	Board(int m, int n=0) // "��������"
	{
		if (m > 0) if (n == 0) n = m; // square board 
		// 
		this->m = m;
		this->n = n;
		data = new char[m*n]; 
		Chess_Init();
	}

	inline void Free()
	{
		if (data) delete[] data; 
		data = NULL; 
		m = n = 0; 
	}

	~Board() 
	{
		Free();
	}

	inline char& /* rw */ operator ()(int x, int y) { return data[y*m+x]; }
	inline const char& /* rw */ operator ()(int x, int y) const { return data[y*m+x]; }

	inline void Print(ostream& O)
	{
		O << "Board(" << n << " x " << m << ") -------------------------" << endl; 
		for (int y = n-1; y >= 0; y--)
		{
			for (int x = 0; x < m; x++)
				O << (*this)(x,y); 
			O << endl; 
		}
	}

	const Board& operator =(const Board& board) // x = (y = z) // �� == z
	{
		Free();
		m = board.m;
		n = board.n;
		data = new char[m*n]; 
		memcpy(data, board.data, n*m*sizeof(*(board.data))); // sizeof(int*) != sizeof(int&) = sizeof(int) // � ������
		return board;
	}

	Board(const Board& board) : m(0), n(0), data(NULL) 
	{
		*this = board; 
	}

	// ==============================================================================================
	// Chess 

	void Chess_Init()
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
				(*this)(x,y) = '.'; 
		}
	}

}; // !!! 