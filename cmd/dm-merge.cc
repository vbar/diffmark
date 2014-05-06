#include "merge.hh"
#include "nspace.hh"
#include "xdoc.hh"
#include "xutil.hh"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

static void print_merge(const char *src_file, const char *diff_file);
static XDoc merge_diff(const XDoc &src_doc, const XDoc &diff_doc);

int main(int argc, char **argv)
{
    int rv = -1;

    if (argc != 3) {
	cerr << "dm usage: " << argv[0] << " src_file diff_file" << endl;
	return rv;
    }

    LIBXML_TEST_VERSION
    xmlKeepBlanksDefault(0);

    try {
	print_merge(argv[1], argv[2]);
	rv = 0;
    } catch (string &x) {
	cerr << "dm-merge: " << x << endl;
    }

    xmlCleanupParser();

    return rv;
}

static void print_merge(const char *src_file, const char *diff_file)
{
    XDoc d1 = xutil::parse_file(src_file);
    XDoc d2 = xutil::parse_file(diff_file);
    XDoc diff = merge_diff(d1, d2);

    xmlChar *mem = 0;
    int size = 0;
    xmlDocDumpFormatMemory(diff, &mem, &size, 1);
    
    std::copy(reinterpret_cast<char *>(mem),
	reinterpret_cast<char *>(mem + size),
	std::ostream_iterator<char>(cout));

    xmlFree(mem);
}

static XDoc merge_diff(const XDoc &src_doc, const XDoc &diff_doc)
{
    Merge builder(diffmark::nsurl, src_doc);
    return builder.merge(xutil::get_root_element(diff_doc));
}
