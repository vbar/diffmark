#ifndef testlcs_hh
#define testlcs_hh

#include "lcs.hh"
#include <string>

class TestLCS : public LCS<std::string>
{
public:
    std::string get_result() const;

private:
    virtual void on_match();
    virtual void on_insert(std::string n);
    virtual void on_delete(std::string m);

    std::string result;
};

inline std::string TestLCS::get_result() const
{
    return result;
}

#endif
