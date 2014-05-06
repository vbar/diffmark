#include "compare.hh"
#include <libxml/tree.h>
#include <assert.h>

void test1();
void test2();

int main(int argc, char *argv[])
{
    test1();
    test2();
}

void test1()
{
    xmlNodePtr m = xmlNewNode(0,
	reinterpret_cast<const xmlChar *>("node"));
    xmlNodePtr n = xmlNewNode(0,
	reinterpret_cast<const xmlChar *>("node"));

    int c = compare(m, n, true);
    assert(!c);

    xmlFree(n);
    xmlFree(m);
}

void test2()
{
    xmlNodePtr m = xmlNewNode(0,
	reinterpret_cast<const xmlChar *>("node"));
    xmlSetProp(m,
	reinterpret_cast<const xmlChar *>("with"),
	reinterpret_cast<const xmlChar *>("attr"));

    xmlNodePtr n = xmlNewNode(0,
	reinterpret_cast<const xmlChar *>("node"));
    xmlSetProp(n,
	reinterpret_cast<const xmlChar *>("with"),
	reinterpret_cast<const xmlChar *>("other value"));

    int c = compare(m, n, true);
    assert(c < 0);

    xmlFree(n);
    xmlFree(m);
}
