#include <assert.h>
#include <vector>
#include <iostream>
#include "testlcs.hh"

using namespace std;

#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void test_longest_common_subsequence();
void test(int num,
    const char *a0,
    const char *b0,
    const char *res);
void test2(int num);

int main(int argc, char *argv[])
{
    cout << argv[0] << endl;

    test_longest_common_subsequence();

    test(2, "aaa", "aaaa", "= = = +a ");
    test(3, "cba", "cba", "= = = ");
    test(4, "ab", "12", "-a +1 -b +2 ");
    test(5, "axyz", "bvw", "-a +b -x +v -y +w -z ");
    test(6, "", "", "");
    test(7, "", "abc", "+a +b +c ");
    test(8, "abc", "", "-a -b -c ");

    test(9, "az", "a", "= -z ");
    test(10, "a", "az", "= +z ");
    test(11, "abc", "c", "-a -b = ");
    test(12, "abc", "axc", "= -b +x = ");
    test(13, "axyc", "avwc", "= -x +v -y +w = ");
    test(14, "xyc", "vwc", "-x +v -y +w = ");

    test(15,
	"abcehjlmnp",
	"bcdefjklmrst", 
	"-a = = +d = -h +f = +k = = -n +r -p +s +t ");

    test2(16);
    test(17, "abcde", "ae", "= -b -c -d = ");
    test(18, "ae", "abcde", "= +b +c +d = ");
    test(19, "vxae", "wyabcde", "-v +w -x +y = +b +c +d = ");
    test(20, "xae", "abcde", "-x = +b +c +d = ");
    test(21, "ae", "xabcde", "+x = +b +c +d = ");
    test(22, "aev", "xabcdewx", "+x = +b +c +d = -v +w +x ");
}

#if 0
void test_get_eq_pos()
{
    const char *b0[] = { "b", "c" };
    std::vector<string> b(b0, b0 + ARRSIZE(b0));

    lcsimpl::TPosMap bmatches =
	lcsimpl::get_eq_pos<string, std::vector<string> >(
	    b, 0, b.size() - 1);
    assert(bmatches.size() == 2);

    int index = 0;
    for (lcsimpl::TPosMap::const_iterator i = bmatches.begin();
	i != bmatches.end();
	++i) {
	assert(i->first == b[index]);
	assert(i->second.size() == 1);
	assert(i->second[0] == index);

	++index;
    }

    cout << "ok 1" << endl;
}
#endif

void test_longest_common_subsequence()
{
    const char *a0[] = { "a", "b", "c", "e", "h", "j", "l",
			 "m", "n", "p" };
    std::vector<string> a(a0, a0 + ARRSIZE(a0));

    const char *b0[] = { "b", "c", "d", "e", "f", "j", "k",
			 "l", "m", "r", "s", "t" };
    std::vector<string> b(b0, b0 + ARRSIZE(b0));

    lcsimpl::TSparseVector matchvector =
	lcsimpl::longest_common_subsequence<string, std::vector<string> >(
	    a, b);

    assert(matchvector.size() == 6);

    int key_seq[] = { 1, 2, 3, 5, 6, 7 };
    int val_seq[] = { 0, 1, 3, 5, 7, 8 };
    int index = 0;
    for (lcsimpl::TSparseVector::const_iterator i = matchvector.begin();
	i != matchvector.end();
	++i) {
	assert(i->first == key_seq[index]);
	assert(i->second == val_seq[index]);

	++index;
    }

    cout << "ok 1" << endl;
}

std::vector<string> vectorize(const char *v0)
{
    std::vector<string> v;
    while (*v0) {
	string s;
	s += *v0;
	v.push_back(s);

	++v0;
    }

    return v;
}

void test(int num,
    const char *a0,
    const char *b0,
    const char *res)
{
    std::vector<string> a = vectorize(a0);
    std::vector<string> b = vectorize(b0);

#if 0
    lcsimpl::TSparseVector matchvector =
	lcsimpl::longest_common_subsequence<string, std::vector<string> >(
	    a, b);
    for (lcsimpl::TSparseVector::const_iterator i = matchvector.begin();
	 i != matchvector.end();
	 ++i)
    {
	cout << i->first << " -> " << i->second << endl;
    }
#endif

    TestLCS tl;
    tl.traverse_balanced(a, b);
    if (tl.get_result() == res) {
	cout << "ok " << num << endl;
    } else {
	cout << tl.get_result() << endl;
	assert(false);
    }
}

void test2(int num)
{
    const char *a0[] = { "abc", "def", "yyy", "xxx", "ghi", "jkl" };
    std::vector<string> a(a0, a0 + ARRSIZE(a0));

    const char *b0[] = { "abc", "dxf", "xxx", "ghi", "jkl" };
    std::vector<string> b(b0, b0 + ARRSIZE(b0));

    TestLCS tl;
    tl.traverse_balanced(a, b);
    assert(tl.get_result() == "= -def +dxf -yyy = = = ");

    cout << "ok " << num << endl;
}
