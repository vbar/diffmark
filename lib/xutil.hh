// based on dom.c from XML::LibXML, which is Copyright (c) 2001
// Christian Glahn

#ifndef xutil_hh
#define xutil_hh

#include <string>
#include <libxml/tree.h>

class XDoc;

namespace xutil {

xmlNodePtr get_root_element(xmlDocPtr doc);

XDoc parse_file(const char *fname);

std::string get_node_name(xmlNodePtr n);

void append_child(xmlNodePtr ex_parent, xmlNodePtr new_child);

void remove_child(xmlNodePtr parent, xmlNodePtr child);

void remove_children(xmlNodePtr n);

// Remove all namespace declarations equivalent to top (which must
// have both local name and href and must be declared above n) from n
// and its descendants. Make them use top instead of the removed
// copies.
void unify_namespace(xmlNsPtr top, xmlNodePtr n);

std::string flatten(xmlNodePtr n);

/**
 * NS-aware way to obtain attribute value of node.
 * Similar to get_value(xmlAttrPtr a) from compare.cc but allow request property
 * of different object, not parent.
 * @TODO It seams have worth move get_value into xutil and reimplement via
 * get_prop
 *
 * @param node
 * @param attr
 * @return
 */
xmlChar * get_prop(xmlNodePtr node, xmlAttrPtr attr);

/**
 * More common variant of Target::get_scoped_name
 * For xmlAttrPtr or xmlNodePtr return string "el->ns->prefix:el->name" if ns present
 * or simple el->name
 * @TODO May be it have worth reimplement Target::get_scoped_name with default value?
 */
template<typename xmlNodeOrAttrPtrType>
const xmlChar* get_scoped_name(xmlNodeOrAttrPtrType el){
	if (el->ns){
		return reinterpret_cast<const xmlChar*>((std::string((const char*)(el->ns->prefix)) + ":" + (const char*)el->name).c_str());
	}
	else return el->name;
}

}

#endif

