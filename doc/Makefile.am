##process this file with automake to produce Makefile.in

EXTRA_DIST = diffmark.html diffmark.xml addlink.xslt

DOCBOOK = /usr/share/sgml/docbook/xsl-stylesheets/html/docbook.xsl

dist-hook: diffmark.html index.html
	-rm redo.always

diffmark.html: diffmark.xml
	xsltproc ${DOCBOOK} diffmark.xml > diffmark.html

index.html: diffmark2.xml
	xsltproc ${DOCBOOK} diffmark2.xml > index.html

diffmark2.xml: diffmark.xml addlink.xslt redo.always
	xsltproc --stringparam version ${VERSION} addlink.xslt diffmark.xml > diffmark2.xml

redo.always:
	touch redo.always

