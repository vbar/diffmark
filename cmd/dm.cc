#include "diff.hh"
#include "nspace.hh"
#include "xdoc.hh"
#include "xutil.hh"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#if 0
#define TRACE(trace_arg) std::cerr << trace_arg << std::endl
#else
#define TRACE(trace_arg)
#endif

using std::cout;
using std::cerr;
using std::endl;
using std::string;

static void print_diff(const char *from_file, const char *to_file);
static XDoc make_diff(const XDoc &d1, const XDoc &d2); 
static string get_unique_prefix(xmlNodePtr m, xmlNodePtr n);

int main(int argc, char **argv)
{
    int rv = -1;

    if (argc != 3) {
	cerr << "dm usage: " << argv[0] << " from_file to_file" << endl;
	return rv;
    }

    LIBXML_TEST_VERSION
    xmlKeepBlanksDefault(0);

    try {
	print_diff(argv[1], argv[2]);
	rv = 0;
    } catch (string &x) {
	cerr << "dm: " << x << endl;
    }

    xmlCleanupParser();

    return rv;
}

static void print_diff(const char *from_file, const char *to_file)
{
    XDoc d1 = xutil::parse_file(from_file);
    XDoc d2 = xutil::parse_file(to_file);
    XDoc diff = make_diff(d1, d2);

    xmlChar *mem = 0;
    int size = 0;
    xmlDocDumpFormatMemory(diff, &mem, &size, 1);
    
    std::copy(reinterpret_cast<char *>(mem),
	reinterpret_cast<char *>(mem + size),
	std::ostream_iterator<char>(cout));

    xmlFree(mem);
}

static XDoc make_diff(const XDoc &d1, const XDoc &d2)
{
    xmlNodePtr m = xutil::get_root_element(d1);
    xmlNodePtr n = xutil::get_root_element(d2);

    Diff dm(diffmark::get_unique_prefix(m, n), diffmark::nsurl);
    return dm.diff_nodes(m, n);
}
