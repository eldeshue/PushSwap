/*
	boj 27657, 정렬

	push swap의 심플한 버젼. 하지만 어떤 의미에서는 더 어려울 수도....
	pa, pb, ra, rb, rra, rrb의 커맨드 6종.
	스왑도 안되고, rr, rrr도 안됨.

	예상되는 커맨드의 개수 A(n) = 2n * log3(n) + n

	n이 최대 100K이고, 최대 2M개 커맨드로 해결해야 함.
	=> 분석 결과로는 아슬아슬함.

	c++ 27657.cc -g -std=c++17 -o 27657
*/
#include <iostream>
#include <vector>
#include <deque>

//
#define PA 1
#define PB 2
#define RA 3
#define RB 4
#define RRA 5
#define RRB 6

int N;	// range of the input number, [1 , N]
std::vector<int> cmdBuffer;
std::deque<int> a;	// A0
std::deque<int> b;	// A1

// basic operation
inline void pa();
inline void pb();
inline void ra();
inline void rb();
inline void rra();
inline void rrb();
const char* decodeCmd(const int& cmd);

// sort
void sort_a_base(int start, int end);
void sort_b_base(int start, int end);
void sort_a(int start, int end);
void sort_b(int start, int end);
void sort_a_first(int start, int end);

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// input
	int input;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> input;
		a.push_back(input);
	}

	/*
	N = 100000;
	for (int i = N; i >= 1; --i)
	{
		a.push_back(i);
	}
	*/

	// solve
	sort_a_first(1, N + 1);
	// output
	std::cout << cmdBuffer.size() << '\n';
	for (const int& cmd : cmdBuffer)
	{
		std::cout << decodeCmd(cmd) << '\n';
	}
}

inline void pa()
{
	if (!b.empty())
	{
		a.push_front(b.front());
		b.pop_front();
		cmdBuffer.push_back(PA);
	}
}

inline void pb()
{
	if (!a.empty())
	{
		b.push_front(a.front());
		a.pop_front();
		cmdBuffer.push_back(PB);
	}
}

inline void ra()
{
	if (!a.empty())
	{
		a.push_back(a.front());
		a.pop_front();
		cmdBuffer.push_back(RA);
	}

}

inline void rb()
{
	if (!b.empty())
	{
		b.push_back(b.front());
		b.pop_front();
		cmdBuffer.push_back(RB);
	}
}

inline void rra()
{
	if (!a.empty())
	{
		a.push_front(a.back());
		a.pop_back();
		cmdBuffer.push_back(RRA);
	}
}

inline void rrb()
{
	if (!b.empty())
	{
		b.push_front(b.back());
		b.pop_back();
		cmdBuffer.push_back(RRB);
	}
}

const char* decodeCmd(const int& cmd)
{
	if (cmd == PA)
		return "PP 1 0";	// pa
	else if (cmd == PB)
		return "PP 0 1";	// pb
	else if (cmd == RA)
		return "RO 0";		// ra
	else if (cmd == RB)
		return "RO 1";		// rb
	else if (cmd == RRA)
		return "RRO 0";		// rra
	else if (cmd == RRB)
		return "RRO 1";		// rrb
	else
		return "";
}

void sort_a_base(int start, int end)
{
	const int size = end - start;

	if (size == 2 && a[0] > a[1])
	{
		pb();
		ra();
		pa();
		rra();
	}
}

void sort_b_base(int start, int end)
{
	const int size = end - start;

	if (size == 1)
		pa();
	else if (size == 2)
	{
		if (b[0] > b[1])
		{
			pa();
			pa();
		}
		else
		{
			rb();
			pa();
			rrb();
			pa();
		}
	}
}

void sort_a(int start, int end)
{
	const int size = end - start;
	const int partSize = size / 3;
	const int secondPivot  = end - partSize;
	const int firstPivot  = secondPivot - partSize;

	// base case
	if (size < 3)
		return sort_a_base(start, end);
	// split
	for (int i = 0; i < size; ++i)
	{
		if (secondPivot <= a.front() && a.front() < end)		// big part
			ra();
		else if (firstPivot <= a.front() && a.front() < secondPivot)	// middle part
		{
			pb();
			rb();
		}
		else		// small part
			pb();
	}
	for (int i = 0; i < partSize; ++i)
	{
		rra();
		rrb();
	}
	// sort
	sort_a(secondPivot, end);
	sort_b(firstPivot, secondPivot);
	sort_b(start, firstPivot);
}

void sort_b(int start, int end)
{
	const int size = end - start;
	const int partSize = size / 3;
	const int firstPivot  = start + partSize;
	const int secondPivot  = firstPivot + partSize;

	// base case
	if (size < 3)
		return sort_b_base(start, end);
	// split
	for (int i = 0; i < size; ++i)
	{
		if (secondPivot <= b.front() && b.front() < end)		// big part
			pa();
		else if (firstPivot <= b.front() && b.front() < secondPivot)	// middle part
		{
			pa();
			ra();
		}
		else		// small part
			rb();
	}
	// sort
	sort_a(secondPivot, end);
	for (int i = 0; i < partSize; ++i)
	{
		rra();
		rrb();
	}
	sort_a(firstPivot, secondPivot);
	sort_b(start, firstPivot);
}

void sort_a_first(int start, int end)
{
	const int size = end - start;
	const int partSize = size / 3;
	const int secondPivot  = end - partSize;
	const int firstPivot  = secondPivot - partSize;

	// base case
	if (size < 3)
		return sort_a_base(start, end);
	// split
	for (int i = 0; i < size; ++i)
	{
		if (secondPivot <= a.front() && a.front() < end)		// big part
			ra();
		else if (firstPivot <= a.front() && a.front() < secondPivot)	// middle part
			pb();
		else		// small part
		{
			pb();
			rb();
		}
	}
	for (int i = 0; i < partSize; ++i)
		rra();
	// sort
	sort_a(secondPivot, end);
	sort_b(firstPivot, secondPivot);
	sort_b(start, firstPivot);
}
