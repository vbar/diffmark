#include "testlcs.hh"

using std::string;

void TestLCS::on_match()
{
    result += "= ";
}

void TestLCS::on_insert(std::string n)
{
    result += '+';
    result += n;
    result += ' ';
}

void TestLCS::on_delete(std::string m)
{
    result += '-';
    result += m;
    result += ' ';
}
